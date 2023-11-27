cmake_minimum_required(VERSION 3.0.2)
project(ethzasl_apriltag2)

#catkin_simple(ALL_DEPS_REQUIRED)

add_definitions("-fPIC -O3")
find_package(Threads)

find_package(OpenCV REQUIRED)

if ("!${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # The clang compiler (on osx) is somehow much more strict
  # than the compilers on ubuntu and so this does not seem
  # possible on OSX just yet.
  add_definitions( -Werror )
endif()

#############
# LIBRARIES #
#############
file(GLOB SOURCE_FILES "src/*.cc")

add_library(${PROJECT_NAME}
  ${SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT}
    ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(${PROJECT_NAME} PRIVATE
  deps/eigen-3.4.0
)

#############
## EXAMPLES #
#############
#if(NOT APPLE)
#  cs_add_executable(apriltags_demo
#    src/example/apriltags_demo.cpp src/example/Serial.cpp
#  )
#  target_link_libraries(apriltags_demo ${PROJECT_NAME} v4l2)
#endif()

###########
## EXPORT #
###########
#cs_install()
#cs_export()
