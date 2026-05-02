cmake_minimum_required(VERSION 3.14)
project(EthereumPriceFetcherTests LANGUAGES CXX)

# logos-module-builder auto-detects this file and creates the
# checks.<system>.unit-tests + packages.<system>.unit-tests targets.
# Run with `nix build '.#unit-tests' -L`.
include(LogosTest)

logos_test(
    NAME ethereum_price_fetcher_tests
    MODULE_SOURCES ../src/ethereum_price_fetcher_impl.cpp
    TEST_SOURCES
        main.cpp
        test_ethereum_price_fetcher.cpp
)
