#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>
#include "read_files.cpp"
#include "test.cpp"
#include "makeOutput.cpp"
#include "algorithms/backtracking.cpp"
#include "algorithms/brute-force.cpp"
#include "algorithms/dynamic_programming_arrays.cpp"
#include "algorithms/dynamic_programming_hash-maps.cpp"
#include "algorithms/greedy_approximation.cpp"
#include "algorithms/integer_linear_programming.cpp"

void manage(
    int n,
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
)
{
    std::vector<bool> usedItems(n_pallets, false);

    switch(n) {
        case 1:
            brute_force(capacity, n_pallets, weights, values, usedItems);
            break;
        case 2:
            knapsackBT(values, weights, n_pallets, capacity, usedItems);
            break;
        case 3:
            dynamic_programming_arrays(values, weights, n_pallets, capacity, usedItems);
            break;
        case 4:
            dynamic_programming_hash_maps(values, weights, n_pallets, capacity, usedItems);
            break;
        case 5:
            greedy();
            break;
        case 6:
            integer_linear_programming();
            break;
      }
}

int main() {

    std::cout << "Input the number of the file (from 1 to 10) with information about the truck and the pallets.\n";

    std::string number = "";
    std::cin >> number;

    int capacity = 0;
    int n_pallets = 0;

    read_truck(number, capacity, n_pallets);

    std::vector<int> weights = {};
    std::vector<int> values = {};

    read_pallets(number, weights, values);

    std::cout << "Choose the algorithmic approach you wish to take:\n1. Brute-Force\n2. Backtracking\n3. Dynamic Programming (using arrays)\n4. Dynamic Programming (using hash-maps)\n5. Greedy Approach (approximation)\n6. Interger Linear Programming\n";

    std::string algorithm = "";
    std::cin >> algorithm;
    int option = std::stoi(algorithm);

    if(option <= 0 || option > 6){
        std::cout << "Invalid option.\n";
        return 0;
    }

    test(capacity, n_pallets, weights, values);

    manage(option, capacity, n_pallets, weights, values);

    return 0;
    
}