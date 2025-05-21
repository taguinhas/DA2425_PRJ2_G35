#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>

void brute_force(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values,
    std::vecotr<bool> &usedItems
);

void knapsackBT(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
);

void knapsackRec(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int capacity,
    int curIndex,
    int curValue,
    std::vector<bool> curItems,
    int* maxValue,
    std::vector<bool> &usedItems,
    auto start
);

void dynamic_programming_arrays(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
);

void dynamic_programming_maps(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    std::vector<bool> &usedItems
);

void greedy(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
);

void integer_linear_programming(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
);

#endif