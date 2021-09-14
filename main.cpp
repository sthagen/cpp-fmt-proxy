#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <array>
#include <string>
#include <sstream>

#include <doctest/doctest.h>

#include <fmt/format.h>


TEST_SUITE ("Example derived tests.") {
    TEST_CASE ("Hello 42.") {
        /* Example snippet:
         *
         * fmt::print("Hello, {}!\n", 42);
         */
        auto const payload = "Hello 42.";
        auto const sut = fmt::format("Hello {}.", 42);
        REQUIRE(sut == payload);
    }
}
