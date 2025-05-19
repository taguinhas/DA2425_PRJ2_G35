#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>

inline void output(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values,
    std::vector<bool> &usedItems,
    int duration
)
{
    for(int i = 0; i < n_pallets; i++){
        if(usedItems[i]){
            std::cout << i+1 << ", " << weights[i] << ", " << values[i] << "\n";
        }
    }

    std::cout << "The algorithm took " << duration << " microseconds.\n";

    return;
}

#endif