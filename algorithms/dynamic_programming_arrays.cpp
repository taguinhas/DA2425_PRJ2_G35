//TODO Arranjar empates

#include <chrono>
#include "../makeOutput.h"
#include "../algorithms.h"

void dynamic_programming_arrays(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
)
{
    std::chrono::time_point start = std::chrono::high_resolution_clock::now();

    int d = 0;

    //step 1: Initialize DP table (2D matrix) - using Base cases
        //using item = 0 (base case)
    std::vector<int> aux(capacity + 1, 0);
    std::vector<std::vector<int>> maxValue(n_pallets + 1, aux);
    
    //step 2: Compute the DP using maxValue(i, k)' function of a) - "Recursion"
    for(int i = 1; i < n_pallets; i++){
        
        for(int k = 0; k <= capacity; k++){

            std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            d = duration.count();

            if(d >= 10000000){break;}

            if(weights[i] > k){
                maxValue[i][k] = maxValue[i-1][k];
            }

            else{
                int aux = values[i] + maxValue[i - 1][k - weights[i]];
                
                if(aux > maxValue[i - 1][k]) {
                    maxValue[i][k] = aux;
                }
                else{
                    maxValue[i][k] = maxValue[i - 1][k];
                }
            }
        }
    }

    if(d >= 10000000){
        std::cout << "The program was terminated as it took longer than 10 seconds.\n";

        return;
    }

    //step 3: Build the Solution
    int remainingWeight = capacity;
    for(int i = n_pallets - 1; i > 0; i--){

        if(remainingWeight == 0) {break;}

        if(maxValue[i][remainingWeight] != maxValue[i - 1][remainingWeight]) {
            for(int a = 0; a < n_pallets; a++){
                if(values[a] == values[i] && weights[a] == weights[i]){
                    if(!usedItems[a]){
                        usedItems[a] = true;
                        remainingWeight -= weights[a];
                        break;
                    }
                }
            }
        }

    }

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    d = duration.count();

    output(capacity, n_pallets, weights, values, usedItems, d);

}