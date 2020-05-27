project(TestLib)

cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")

find_library(
            RANLUX_LIBRARY NAMES ranluxpp
             HINTS  ${CMAKE_BINARY_DIR}/../
) 

message(STATUS "Found JlCxx at ${JlCxx_location}")

add_library(ranluxpp_julia SHARED ./src/ranluxpp_julia)
target_include_directories(ranluxpp_julia PUBLIC ./inc/)
target_link_libraries(ranluxpp_julia JlCxx::cxxwrap_julia ${RANLUX_LIBRARY})

install(TARGETS
  ranluxpp_julia
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION lib)