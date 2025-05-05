std::vector<bool> knapsackBF(std::vector<int> values, std::vector<int> weights, int n, int maxWeight, std::vector<bool> usedItems) {
    
    std::vector<bool> curCandidate(n, 0);

    // Iterate over all the candidates
    bool foundSol = false;
    int maxValue; // value of the best solution found so far
    while (true) {
        // Verify if the candidate is a solution
        int totalValue = 0;
        int totalWeight = 0;
        for(int k = 0; k < n; k++) {
            totalValue += values[k]*curCandidate[k];
            totalWeight += weights[k]*curCandidate[k];
        }
        if(totalWeight <= maxWeight) {
            // Check if the solution is better than the previous one (or if it's the first one)
            if(!foundSol || totalValue > maxValue) {
                foundSol = true;
                maxValue = totalValue;
                for(int k = 0; k < n; k++) {
                    usedItems[k] = curCandidate[k];
                }
            }
        }

        // Get the next candidate
        int curIndex = 0;
        while(curCandidate[curIndex]) {
            curIndex++;
            if(curIndex == n) break;
        }
        if(curIndex == n) break;
        for(int i = 0; i < curIndex; i++) {
            curCandidate[i] = false;
        }
        curCandidate[curIndex] = true;
    }
    return usedItems;
}

void brute_force(
    std::vector<std::tuple<std::string, std::string>> truck,
    std::vector<std::tuple<std::string, std::string, std::string>> pallets
)
{
    std::vector<int> values;
    std::vector<int> weights;

    int n = std::stoi(std::get<1>(truck[1]));
    int maxWeight = std::stoi(std::get<0>(truck[1]));

    std::vector<bool> usedItems(n, 0);

    int i=0;
    for(std::tuple<std::string, std::string, std::string> p : pallets){
        if (i==0){
            i++;
            continue;
        }
        values.push_back(std::stoi((std::get<2>(p))));
        weights.push_back(std::stoi((std::get<1>(p))));
    }

    std::vector<bool> res = knapsackBF(values, weights, n, maxWeight, usedItems);

    i = 0;
    for(std::tuple<std::string, std::string, std::string> p : pallets){
        if (i==0){
            i++;
            continue;
        }
        if(i > 0 && res[i-1]){
            i++;
            std::cout << std::get<0>(p) << ", " << std::get<1>(p) << ", " << std::get<2>(p) << "\n";
        }
        else{
            i++;
        }
    }

}