void output(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values,
    std::vector<bool> &usedItems
)
{
    for(int i = 0; i < n_pallets; i++){
        if(usedItems[i]){
            std::cout << i+1 << ", " << weights[i] << ", " << values[i] << "\n";
        }
    }

    return;
}