//TODO Arranjar empates

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

    int j = 0;
    for(auto a : maxValue){
        for (auto i : a){
            j++;
        }
    }

    
    //step 2: Compute the DP using maxValue(i, k)' function of a) - "Recursion"
    for(int i = 1; i < n_pallets; i++){

        if(d >= 500000){break;}
        
        for(int k = 0; k <= capacity; k++){

            std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            d = duration.count();

            if(d >= 500000){break;}

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

    if(d >= 500000){
        std::cout << "The program was terminated as it took longer than 0.5 seconds.\n";

        return;
    }

    //step 3: Build the Solution
    int remainingWeight = capacity;
    for(int i = n_pallets - 1; i > 0; i--){

        if(remainingWeight == 0) {break;}

        if(maxValue[i][remainingWeight] != maxValue[i - 1][remainingWeight]) {
            usedItems[i] = true;
            remainingWeight -= weights[i];
        }

    }

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    d = duration.count();

    output(capacity, n_pallets, weights, values, usedItems, d);

}