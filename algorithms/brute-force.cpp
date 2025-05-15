void brute_force(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values,
    std::vector<bool> &usedItems
)
{   

    int d = 0;
    
    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    
    std::vector<bool> curCandidate(n_pallets, false);

    bool foundSol = false;
    int maxValue = 0;
    while (d < 10000000) {

        std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        d = duration.count();

        int totalValue = 0;
        int totalWeight = 0;

        for(int k = 0; k < n_pallets; k++) {
            totalValue += values[k]*curCandidate[k];
            totalWeight += weights[k]*curCandidate[k];
        }

        if(totalWeight <= capacity) {

            if(!foundSol || totalValue > maxValue) {
                foundSol = true;
                maxValue = totalValue;
                for(int k = 0; k < n_pallets; k++) {
                    usedItems[k] = curCandidate[k];
                }
            }

            else if(totalValue == maxValue && std::count(curCandidate.begin(), curCandidate.end(), 1) < std::count(usedItems.begin(), usedItems.end(), 1)) {
                maxValue = totalValue;
                for(int k = 0; k < n_pallets; k++) {
                    usedItems[k] = curCandidate[k];
                }
            }

        }

        int curIndex = 0;

        while(curCandidate[curIndex]) {
            curIndex++;
            if(curIndex == n_pallets) {break;}
        }

        if(curIndex == n_pallets) {break;}

        for(int i = 0; i < curIndex; i++) {
            curCandidate[i] = false;
        }

        curCandidate[curIndex] = true;
    }

    if(d >= 10000000){
        std::cout << "The program was terminated as it took longer than 10 seconds.\n";

        return;
    }

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    d = duration.count();

    output(capacity, n_pallets, weights, values, usedItems, d);

    return;

}