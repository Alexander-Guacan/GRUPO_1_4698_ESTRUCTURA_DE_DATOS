#include "QueueVarianceCalculator.hpp"
#include <cmath>

int QueueVarianceCalculator::elementsQuantity(Queue<NUMBER> *&queue) {
    return queue->size();
}

double QueueVarianceCalculator::average(Queue<NUMBER> *&queue) {
    double summation{};

    Iterator<NUMBER> *iterator = queue->getIterator();

    while (iterator->hasNext()) {
        summation += *(iterator->next());
    }

    return (!queue->isEmpty()) ? (summation / static_cast<double>(elementsQuantity(queue))) : 0;
}

double QueueVarianceCalculator::calculate(Queue<NUMBER> *&queue) {
    double summation{};

    Iterator<NUMBER> *iterator = queue->getIterator();
    while (iterator->hasNext()) {
        NUMBER element = *(iterator->next());
        summation += std::pow((static_cast<double>(element) - average(queue)), 2);
    }

    return (!queue->isEmpty()) ? (summation / static_cast<double>(elementsQuantity(queue))) : 0;
}