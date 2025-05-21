#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>

void manage(
    int n,
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
);

void ask_algorithm(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
);

void ask_pallets(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
);

#endif