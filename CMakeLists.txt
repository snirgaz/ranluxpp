project(ranluxpp CXX ASM)

cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ASM_COMPILER as)
find_package(JlCxx)

message(${CMAKE_BINARY_DIR}/../)

find_library(ranluxpp_LIBRARY
  NAMES ranluxpp
  PATHS ${CMAKE_BINARY_DIR}/../
  NO_DEFAULT_PATH
)

get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")

message(STATUS "Found JlCxx at ${JlCxx_location}")


add_library(ranluxpp_julia SHARED src/ranluxpp_julia.cxx
                            )
                            
target_include_directories(ranluxpp_julia PUBLIC inc)

target_link_libraries(ranluxpp_julia JlCxx::cxxwrap_julia ${ranluxpp_LIBRARY})

install(TARGETS
  ranluxpp_julia
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION lib)