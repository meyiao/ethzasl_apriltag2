add_executable(AprilTagDemo Demo.cc)
target_link_libraries(AprilTagDemo
        ${PROJECT_NAME}
)
target_include_directories(AprilTagDemo PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/deps/eigen-3.4.0
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/imgs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})