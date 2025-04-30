#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include "read_files.cpp"
#include "test.cpp"

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

    test(truck, pallets);

    return 0;
    
}