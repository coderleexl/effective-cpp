cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(effective-cpp VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(googletest-release-1.11.0)

# 收集头文件
file(GLOB HEADERS ./*.hpp ./*.h)
file(GLOB SOURCES ./*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# 链接gtest库
target_link_libraries(${PROJECT_NAME}  gtest gtest_main)

# 添加包含目录
#target_include_directories(${PROJECT_NAME}  PRIVATE googletest-release-1.11.0/googletest/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
