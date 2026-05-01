cmake_minimum_required(VERSION 3.14)
project(CalculatorTests LANGUAGES CXX)

# logos-module-builder auto-detects this file and creates the
# checks.<system>.unit-tests + packages.<system>.unit-tests targets.
# Run with `nix build '.#unit-tests' -L`.
include(LogosTest)

logos_test(
    NAME calculator_tests
    MODULE_SOURCES ../src/calculator_impl.cpp
    TEST_SOURCES
        main.cpp
        test_calculator.cpp
)
