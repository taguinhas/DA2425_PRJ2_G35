void dynamic_programming_hash_maps(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    std::vector<bool> &usedItems
)
{
    //hash map will look like this {[n_pallets, capacity], res}

    std::unordered_map<std::pair<int, int>, int> aux;
    for (int i = 0; i < n_pallets + 1; i++){
        for(int j = 0; j < capacity + 1; j++){
            aux.insert({[i, j], 0});
        }
    }

    //!This is wrong

    
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