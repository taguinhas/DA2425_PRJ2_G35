#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <chrono>
#include <unordered_map>
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
            greedy(values, weights, n_pallets, capacity, usedItems);
            break;
        case 6:
            integer_linear_programming();
            break;
      }
}

void ask_algorithm(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
)
{
    int option = 0;
    do {
        std::cout << "Choose the algorithmic approach you wish to take:\n1. Brute-Force\n2. Backtracking\n3. Dynamic Programming (using arrays)\n4. Dynamic Programming (using hash-maps)\n5. Greedy Approach (approximation)\n6. Interger Linear Programming\n";

        std::string algorithm = "";
        
        std::cin >> algorithm;
        
        try{int n = std::stoi(algorithm);}
        catch (std::invalid_argument&){
            std::cerr << "Error: A number wasn't detected. Please try again.\n";
            continue;
        }
        catch (std::out_of_range&){
            std::cerr << "Error: The number inserted is too large or too small. Please try again.\n";
            continue;
        }
        
        option = std::stoi(algorithm);

        if(option <= 0 || option > 6){
            std::cout << "Invalid option. Please insert a valid option\n";
        }
    }
    while (option <= 0 || option > 6);

    test(capacity, n_pallets, weights, values);

    manage(option, capacity, n_pallets, weights, values);
}

void ask_pallets(
    int &capacity,
    int &n_pallets,
    std::vector<int> &weights,
    std::vector<int> &values
)
{

    do{
        std::cout << "Input the number of the file with information about the truck and the pallets.\n";

        std::string number = "";

        std::cin >> number;

        try{int n = std::stoi(number);}
        catch (std::invalid_argument&){
            std::cerr << "Error: A number wasn't detected. Please try again.\n";
            continue;
        }
        catch (std::out_of_range&){
            std::cerr << "Error: The number inserted is too large or too small. Please try again.\n";
            continue;
        }

        int n = std::stoi(number);

        read_truck(n, capacity, n_pallets);

        read_pallets(n, weights, values);

    }
    while(capacity == 0 || n_pallets == 0 || weights.empty() || values.empty());

    ask_algorithm(capacity, n_pallets, weights, values);

}

int main() {

    int option = 0;

    int capacity = 0;
    int n_pallets = 0;
    std::vector<int> weights = {};
    std::vector<int> values = {};

    ask_pallets(capacity, n_pallets, weights, values);

    do {
        std::cout << "Do you wish to repeat the program?\n1. Yes, using the same truck and pallets.\n2. Yes, using different truck and pallets.\n3. Close program.\n";

        std::string program = "";
        
        std::cin >> program;
        
        try{int n = std::stoi(program);}
        catch (std::invalid_argument&){
            std::cerr << "Error: A number wasn't detected. Please try again.\n";
            continue;
        }
        catch (std::out_of_range&){
            std::cerr << "Error: The number inserted is too large or too small. Please try again.\n";
            continue;
        }
        
        option = std::stoi(program);

        if(option <= 0 || option > 3){
            std::cout << "Invalid option. Please insert a valid option\n";
        }

        if(option == 1){
            ask_algorithm(capacity, n_pallets, weights, values);
        }

        if(option == 2){
            ask_pallets(capacity, n_pallets, weights, values);
        }

        if(option == 3){
            return 0;
        }
    }
    while (option != 3);

    return 0;
    
}