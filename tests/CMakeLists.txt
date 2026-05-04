cmake_minimum_required(VERSION 3.14)
project(LondonTimeFetcherTests LANGUAGES CXX)

# logos-module-builder auto-detects this file and creates the
# checks.<system>.unit-tests + packages.<system>.unit-tests targets.
# Run with `nix build '.#unit-tests' -L`.
include(LogosTest)

logos_test(
    NAME london_time_fetcher_tests
    MODULE_SOURCES ../src/london_time_fetcher_impl.cpp
    TEST_SOURCES
        main.cpp
        test_london_time_fetcher.cpp
)
