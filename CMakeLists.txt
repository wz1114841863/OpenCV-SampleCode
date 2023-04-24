cmake_minimum_required(VERSION 3.15)
project(imgproc CXX)

set(CMAKE_CXX_STANDARD 14)

# OpenCV路径
set(OpenCV_DIR "D:\\OpenCV")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(examples)
add_executable(imgproc main.cpp)
target_link_libraries(imgproc ${OpenCV_LIBS})
target_link_libraries(imgproc exam)