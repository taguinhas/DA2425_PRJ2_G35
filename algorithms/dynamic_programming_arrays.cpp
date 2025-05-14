//TODO Arranjar empates

void dynamic_programming_arrays(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    std::vector<bool> &usedItems
)
{
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
        for(int k = 0; k <= capacity; k++){

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

    //step 3: Build the Solution
    int remainingWeight = capacity;
    for(int i = n_pallets - 1; i > 0; i--){

        if(remainingWeight == 0) {break;}

        if(maxValue[i][remainingWeight] != maxValue[i - 1][remainingWeight]) {
            usedItems[i] = true;
            remainingWeight -= weights[i];
        }

    }

    output(capacity, n_pallets, weights, values, usedItems);
}