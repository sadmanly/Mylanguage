cmake_minimum_required(VERSION 2.8)

project(json)

#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(SRC_LIST json.cpp json_u.cpp)

ADD_LIBRARY(json SHARED ${SRC_LIST})
ADD_LIBRARY(jsons STATIC ${SRC_LIST})

install(TARGETS json jsons
LIBRARY DESTINATION ../../lib
ARCHIVE DESTINATION ../../lib)

file(REMOVE ../../include/json_u.h ../../include/json.h)
file(INSTALL json_u.h json.h DESTINATION ../../include)