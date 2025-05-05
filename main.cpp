#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include "read_files.cpp"
#include "test.cpp"
#include "algorithms/backtracking.cpp"
#include "algorithms/brute-force.cpp"
#include "algorithms/dynamic_programming_arrays.cpp"
#include "algorithms/dynamic_programming_hash-maps.cpp"
#include "algorithms/greedy_approximation.cpp"
#include "algorithms/integer_linear_programming.cpp"

void manage(int n,
    std::vector<std::tuple<std::string, std::string>> truck,
    std::vector<std::tuple<std::string, std::string, std::string>> pallets
){

    switch(n) {
        case 1:
            brute_force(truck, pallets);
            break;
        case 2:
            backtracking();
            break;
        case 3:
            dynamic_programming_arrays();
            break;
        case 4:
            dynamic_programming_hash_maps();
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

    std::vector<std::tuple<std::string, std::string>> truck;

    std::vector<std::tuple<std::string, std::string, std::string>> pallets;

    std::cout << "Input the number of the file (from 1 to 10) with information about the truck and the pallets.\n";

    std::string n;
    std::cin >> n;

    truck = read_truck(n);
    if(truck.empty()){
        return 0;
    }

    pallets = read_pallets(n);
    if(pallets.empty()){
        return 0;
    }

    std::cout << "Choose the algorithmic approach you wish to take:\n1. Brute-Force\n2. Backtracking\n3. Dynamic Programming (using arrays)\n4. Dynamic Programming (using hash-maps)\n5. Greedy Approach (approximation)\n6. Interger Linear Programming\n";

    std::string algorithm;
    std::cin >> algorithm;
    int option = std::stoi(algorithm);

    if(option <= 0 || option > 6){
        std::cout << "Invalid option.\n";
        return 0;
    }

    manage(option, truck, pallets);

    //test(truck, pallets);

    return 0;
    
}