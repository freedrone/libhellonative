cmake_minimum_required(VERSION 3.16)
project(libsrc)

set(CMAKE_CXX_STANDARD 20)
set(ENV{BOOST_ROOT} "boost")

include_directories(BEFORE "src/java")
include_directories(BEFORE "src/python")

# include headers for Java
include_directories(BEFORE "$ENV{JAVA_HOME}\\include")
include_directories(BEFORE "$ENV{JAVA_HOME}\\include\\win32")
include_directories(BEFORE "$ENV{JAVA_HOME}\\include\\win32\\bridge")

# include headers for Boost & Python
find_package(Boost 1.73.0 EXACT REQUIRED)
include_directories(BEFORE "$ENV{PYTHONPATH}" "${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

add_library(
        libsrc
        SHARED
        src/library.cpp src/library.h
)
target_link_libraries(libsrc ${Boost_LIBRARIES})
set_target_properties(libsrc
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "./_lib"
        LIBRARY_OUTPUT_DIRECTORY "./_lib"
        RUNTIME_OUTPUT_DIRECTORY "./_bin"
)
