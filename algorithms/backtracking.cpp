void knapsackRec(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, unsigned int curIndex, unsigned int curValue, bool curItems[], unsigned int* maxValue, bool usedItems[]) {
    //todos os n itens foram testados no branch atual?
    if (curIndex == n) {
        //encontrei uma solução melhor?
        if (curValue > *maxValue) {
            *maxValue = curValue;
            for (unsigned int i = 0; i < n; i++) {
                usedItems[i] = curItems[i];
            }
        }
    }
    else {
        //tentar incluir o item atual
        if (weights[curIndex] <= maxWeight) {
            curItems[curIndex] = true;
            knapsackRec(values, weights, n, maxWeight-weights[curIndex], curIndex + 1, curValue+values[curIndex], curItems, maxValue, usedItems);
        }

        //explore the path where we do not insert this object
        curItems[curIndex] = false;
        knapsackRec(values, weights, n, maxWeight, curIndex + 1, curValue, curItems, maxValue, usedItems);
    }
}

unsigned int knapsackBT(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    unsigned int maxValue = 0;
    bool curItems[1000];

    for (unsigned int i = 0; i < n; i++) {
        curItems[i] = false;
    }

    //encontrar possíveis soluções usando BackTracking
                                            //curIndex, curValue
    knapsackRec(values, weights, n, maxWeight, 0, 0, curItems, &maxValue, usedItems);

    return maxValue;
}

void backtracking(){
    std::cout << "Chose Backtracking\n";
}