// tests/math_tests.cpp
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "math_functions.h"
#include <stdexcept>

TEST_CASE("Square root of positive numbers", "[math]") {
    REQUIRE(compute_square_root(25.0) == 5.0);
    REQUIRE(compute_square_root(0.0) == 0.0);
    REQUIRE(compute_square_root(1.0) == 1.0);
}

TEST_CASE("Square root throws on negative input", "[math]") {
    REQUIRE_THROWS_AS(compute_square_root(-1.0), std::invalid_argument);
    REQUIRE_THROWS_AS(compute_square_root(-100.0), std::invalid_argument);
}

TEST_CASE("Square root of non-perfect square", "[math]") {
    REQUIRE(compute_square_root(2.0) == Catch::Approx(1.41421356237).epsilon(0.001));
    REQUIRE(compute_square_root(10.0) == Catch::Approx(3.16227766017).epsilon(0.001));
}

