//TODO Arranjar empates

void greedy(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
)
{

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    
    std::vector<int> P(n_pallets);

    // Initialize the index vector P
    for (unsigned int i = 0; i < n_pallets; ++i) {
        P[i] = i;
    }

    // Sort indices by value-to-weight ratio in descending order
    std::sort(P.begin(), P.end(), [&](int i, int j) {

        return  static_cast<double>(weights[i] / values[i]) < static_cast<double>(weights[j] / values[j]);
    });

    int maxValue = 0;
    int totalWeight = 0;

    // Greedy selection of items
    for (int i = 0; i < n_pallets; ++i) {
        int idx = P[i];
        if (totalWeight + weights[idx] <= capacity) {
            totalWeight += weights[idx];
            maxValue += values[idx];
            usedItems[idx] = true;
        }
    }

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    int d = duration.count();

    output(capacity, n_pallets, weights, values, usedItems, d);

    return;
}