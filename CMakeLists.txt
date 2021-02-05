cmake_minimum_required(VERSION 3.5)

SET (THIS_COM "${PROJECT_SOURCE_DIR}/" )
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_BINARY_DIR}/Configuration.h)

add_executable(file_log main.cpp src/save_file.cpp)
target_include_directories(file_log PUBLIC ${CMAKE_SOURCE_DIR}/include)