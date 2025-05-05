void knapsackRec(
    std::vector<int> &values,
    std::vector<int> &weights,
    int n_pallets,
    int capacity,
    int curIndex,
    int curValue,
    std::vector<bool> curItems,
    int* maxValue,
    std::vector<bool> &usedItems
)
{
    //todos os n_pallets itens foram testados no branch atual?
    if (curIndex == n_pallets) {
        //encontrei uma solução melhor?
        if (curValue > *maxValue) {
            *maxValue = curValue;
            for (int i = 0; i < n_pallets; i++) {
                usedItems[i] = curItems[i];
            }
        }
        else if (curValue == *maxValue && std::count(curItems.begin(), curItems.end(), 1) < std::count(usedItems.begin(), usedItems.end(), 1)){
            *maxValue = curValue;
            for (int i = 0; i < n_pallets; i++){
                usedItems[i] = curItems[i];
            }
        }
    }
    else {
        //tentar incluir o item atual
        if (weights[curIndex] <= capacity) {
            curItems[curIndex] = true;
            knapsackRec(values, weights, n_pallets, capacity-weights[curIndex], curIndex + 1, curValue+values[curIndex], curItems, maxValue, usedItems);
        }

        //explore the path where we do not insert this object
        curItems[curIndex] = false;
        knapsackRec(values, weights, n_pallets, capacity, curIndex + 1, curValue, curItems, maxValue, usedItems);
    }
}

void knapsackBT(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
)
{
    int maxValue = 0;
    std::vector<bool> curItems(n_pallets, false);

    //encontrar possíveis soluções usando BackTracking
                                            //curIndex, curValue
    knapsackRec(values, weights, n_pallets, capacity, 0, 0, curItems, &maxValue, usedItems);

    output(capacity, n_pallets, weights, values, usedItems);

}