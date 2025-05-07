void greedy(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    std::vector<bool> &usedItems
)
{
    std::vector<int> P(n_pallets);

    // Initialize the index vector P
    for (unsigned int i = 0; i < n_pallets; ++i) {
        P[i] = i;
    }

    // Sort indices by value-to-weight ratio in descending order
    std::sort(P.begin(), P.end(), [&](int i, int j) {

        return  static_cast<double>(weights[i]) < static_cast<double>(weights[j]);
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

    output(capacity, n_pallets, weights, values, usedItems);

    return;
}