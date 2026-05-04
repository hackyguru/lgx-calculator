cmake_minimum_required(VERSION 3.14)
project(LogosLondonTimeFetcherPlugin LANGUAGES CXX)

if(DEFINED ENV{LOGOS_MODULE_BUILDER_ROOT})
    include($ENV{LOGOS_MODULE_BUILDER_ROOT}/cmake/LogosModule.cmake)
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/LogosModule.cmake")
    include(cmake/LogosModule.cmake)
else()
    message(FATAL_ERROR "LogosModule.cmake not found. Set LOGOS_MODULE_BUILDER_ROOT.")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/metadata.json
               ${CMAKE_CURRENT_BINARY_DIR}/metadata.json COPYONLY)

logos_module(
    NAME london_time_fetcher
    SOURCES
        src/london_time_fetcher_impl.h
        src/london_time_fetcher_impl.cpp
        generated_code/london_time_fetcher_qt_glue.h
        generated_code/london_time_fetcher_dispatch.cpp
    INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/generated_code
)
