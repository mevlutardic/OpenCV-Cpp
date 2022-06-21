cmake_minimum_required(VERSION 3.0)

project(Readimage VERSION 0.1.1)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME} main.cpp )

target_link_libraries( ${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} )
