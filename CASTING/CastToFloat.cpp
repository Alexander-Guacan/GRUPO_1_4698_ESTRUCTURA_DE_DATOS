#include "CastToFloat.h"
#include <string>

float CastToFloat::transform(char* input) {
    return std::atof(input);
}