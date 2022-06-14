#include "StackVarianceCalculator.hpp"
#include <cmath>

int StackVarianceCalculator::elementsQuantity(Stack<NUMBER> *&stack) {
    return stack->size();
}

double StackVarianceCalculator::average(Stack<NUMBER> *&stack) {
    double summation{};

    Iterator<NUMBER> *iterator = stack->getIterator();

    while (iterator->hasNext()) {
        summation += *(iterator->next());
    }

    return (!stack->isEmpty()) ? (summation / static_cast<double>(elementsQuantity(stack))) : 0;
}

double StackVarianceCalculator::calculate(Stack<NUMBER> *&stack) {
    double summation{};

    Iterator<NUMBER> *iterator = stack->getIterator();
    while (iterator->hasNext()) {
        NUMBER element = *(iterator->next());
        summation += std::pow((static_cast<double>(element) - average(stack)), 2);
    }

    return (!stack->isEmpty()) ? (summation / static_cast<double>(elementsQuantity(stack))) : 0;
}