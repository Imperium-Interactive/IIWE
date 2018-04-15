cmake_minimum_required(VERSION 3.8)
project(IIWE)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS}
                    ${SDL2_IMAGE_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/Game.h src/Game.cpp)
add_executable(IIWE ${SOURCE_FILES})
target_link_libraries(IIWE ${SDL2_LIBRARY}
                                ${SDL2_IMAGE_LIBRARY})
