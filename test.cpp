#include <iostream>
#include <vector>

void test(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
)
{
    std::cout << "Truck has " << capacity << " capacity and there are " << n_pallets << " pallets\n";

    for(int i = 1; i <= n_pallets; i++){
        std::cout << "Pallet number " << i << " has weight " << weights[i-1] << " and profit " << values[i-1] << "\n";
    }

    return;
}