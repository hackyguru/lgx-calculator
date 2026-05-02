cmake_minimum_required(VERSION 3.14)
project(NotesBackendTests LANGUAGES CXX)

# logos-module-builder auto-detects this file and creates the
# checks.<system>.unit-tests + packages.<system>.unit-tests targets.
# Run with `nix build '.#unit-tests' -L`.
include(LogosTest)

logos_test(
    NAME notes_backend_tests
    MODULE_SOURCES ../src/notes_backend_impl.cpp
    TEST_SOURCES
        main.cpp
        test_notes_backend.cpp
)
