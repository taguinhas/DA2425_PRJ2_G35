#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include "read_files.cpp"
#include "test.cpp"

std::vector<std::tuple<std::string, std::string>> read_t_truck() {
    std::string input;
    std::vector<std::string> current;
    std::vector<std::tuple<std::string, std::string>> final;
    std::cin >> input;
 
    while (input.length()!=1) { 
        std::string value = "";

        for(char c : input){
            if(c==','){
                current.push_back(value);
                value = "";
            }
            else{
                value += c;
            }
        }

        current.push_back(value);
        std::tuple<std::string, std::string> help(current[0], current[1]);
        final.push_back(help);
        current = {};

        std::cin>>input;
    }
    return final;
}

std::vector<std::tuple<std::string, std::string, std::string>> read_t_pallets() {
    std::string input;
    std::vector<std::string> current;
    std::vector<std::tuple<std::string, std::string, std::string>> final;
    std::cin >> input;
 
    while (input.length()!=1) { 
        std::string value = "";

        for(char c : input){
            if(c==','){
                current.push_back(value);
                value = "";
            }
            else{
                value += c;
            }
        }

        current.push_back(value);
        std::tuple<std::string, std::string, std::string> help(current[0], current[1], current[2]);
        final.push_back(help);
        current = {};

        std::cin>>input;
    }
    return final;
}

int main() {

    //automatic running (batch mode)

    std::vector<std::tuple<std::string, std::string>> truck = read_truck("TruckAndPallets_01");

    std::vector<std::tuple<std::string, std::string, std::string>> pallets = read_pallets("Pallets_01");

    std::cout << "Do you wish to load the trucks and pallets by:\n1. Reading from files\n2. Writing in the command line\n3. Don't use the terminal, result in output.txt\n";
    
    int option;
    std:: cin >> option;

    if (option == 1){
        std::cout << "Input the name of the file with information about the trucks.\n(If the intended truck is any of the given examples, you may simply type its number, from 1 to 10)\n";

        std::string ntruck;
        std::cin >> ntruck;
        truck = read_truck(ntruck);



        std::cout << "Input the name of the file with information about the pallets.\n(If the intended truck is any of the given examples, you may simply type its number, from 1 to 10)\n";

        std::string npallets;
        std::cin >> npallets;
        pallets = read_pallets(npallets);

    }
    else if (option == 2){
        std::cout << "Please introduce the truck values as exemplified in the provided csv files. Press any one key to end.\n";
        truck = read_t_truck();

        std::cout << "Please introduce the pallets values as exemplified in the provided csv files. Press any one key to end.\n";
        pallets = read_t_pallets();
    }
    else if (option == 3){
        std::cout << "Result is in output.txt.\n";
    }
    else{
        std::cout << "Invalid option.\n";
        return 0;
    }

    if(truck.empty()){
        std::cout << "The truck file could not be read.\n";
        return 0;
    }

    if(pallets.empty()){
        std::cout << "The pallets file could not be read.\n";
        return 0;
    }

    test(truck, pallets);

    std::cout << std::endl;

    return 0;
    
}