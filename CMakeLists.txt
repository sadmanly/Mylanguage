cmake_minimum_required(VERSION 2.8)
project(MyLanguage)

add_compile_options(-std=c++11 -Wall -g) 
add_definitions(-DTESTSQL)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/include/lib)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/depend/json ${PROJECT_SOURCE_DIR}/build/json)


aux_source_directory(${PROJECT_SOURCE_DIR}/src/main SRC_LIST)

add_executable(run ${SRC_LIST})


