cmake_minimum_required(VERSION 3.25)
project(final_practice)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES Main/*.cpp Main/*.h)

add_executable(final_practice ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE Main/)
