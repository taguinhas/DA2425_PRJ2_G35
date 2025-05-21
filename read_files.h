#ifndef READ_FILES_H
#define READ_FILES_H

#include <iostream>
#include <vector>

void read_truck(
    int n,
    int &capacity,
    int &n_pallets
);

void read_pallets(
    int n,
    std::vector<int> &weights,
    std::vector<int> &values
);

#endif