//TODO Arranjar empates

#include <chrono>
#include <algorithm>
#include <map>
#include "../makeOutput.h"
#include "../algorithms.h"

void dynamic_programming_maps(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    std::vector<bool> &usedItems
)
{

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();

    int d = 0;

    //map will look like this {[n_pallets, capacity], res}
    std::map<std::pair<int, int>, int> maxValue;
    for (int i = 0; i < n_pallets + 1; i++){
        for(int j = 0; j < capacity + 1; j++){
            maxValue.insert({{i, j}, 0});
        }
    }
    
    //step 2: Compute the DP using maxValue(i, k)' function of a) - "Recursion"
    for(int i = 1; i < n_pallets; i++){

        for(int k = 0; k <= capacity; k++){

            std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            d = duration.count();

            if(d >= 10000000){break;}

            if(weights[i] > k){
                maxValue.at({i,k}) = maxValue.at({i-1, k});
            }

            else{
                int aux = values[i] + maxValue.at({i - 1,k - weights[i]});
                
                if(aux > maxValue.at({i - 1,k})) {
                    maxValue.at({i,k}) = aux;
                }
                else{
                    maxValue.at({i,k}) = maxValue.at({i - 1,k});
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

        if(maxValue.at({i,remainingWeight}) != maxValue.at({i - 1,remainingWeight})) {
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