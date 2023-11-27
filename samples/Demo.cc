#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include "apriltags/TagDetector.h"
#include "apriltags/Tag36h11.h"

int main(int argc, char** argv) {
    // create tag detector
    AprilTags::TagDetector tagDetector(AprilTags::tagCodes36h11);
    std::cout << "Tag detector created!\n";

    for (int n = 0; n < 5; n++) {
        std::string imgPath = "./imgs/" + std::to_string(n) + ".jpg";
        cv::Mat img = cv::imread(imgPath, cv::IMREAD_GRAYSCALE);
        cv::resize(img, img, img.size() / 4);

        // detect tags
        std::vector<AprilTags::TagDetection> detections = tagDetector.extractTags(img);
        std::cout << "img " << n << ", tags: " << detections.size() << "\n";

        // draw tags on image
        cv::Mat cimg;
        cv::cvtColor(img, cimg, cv::COLOR_GRAY2BGR);
        for (const auto & detection : detections) {
            detection.draw(cimg);
        }
        cv::imshow("img", cimg);
        cv::waitKey();
    }










    return 0;
}