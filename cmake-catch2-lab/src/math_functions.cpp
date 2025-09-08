#include "math_functions.h"
#include <cmath>
#include <stdexcept>

double compute_square_root(double number) {
    if (number < 0) {
        throw std::invalid_argument("Negative input not allowed");
    }
    return std::sqrt(number);
}

