#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void read_truck(int n, int &capacity, int &n_pallets){

    std::string truck = "";

    if(n < 10){truck = "TruckAndPallets_0"+std::to_string(n);}
    else{truck = "TruckAndPallets_"+std::to_string(n);}

    std::ifstream file("data/"+ truck + ".csv");

    if(!file.is_open()){
        std::cerr << "File " << truck << " doesn't exist! Please try again." << std::endl;
        return;
    }

    std::string aux = "";
    std::string line = "";

    int i = 0;
    while (getline(file, line)){
        
        std::stringstream row(line);

        std::vector<std::string> help = {};

        while(getline(row, aux, ',')){
            while(aux[0] == ' '){aux.erase(0, 1);}
            while(aux[aux.size() - 1] == ' '){aux.erase(aux.size() - 1);}
            help.push_back(aux);
        }

        if(i == 0){i++;continue;}
        else{
            capacity = std::stoi(help[0]);
            n_pallets = std::stoi(help[1]);
        }

        help.clear();

    }

}

void read_pallets(int n, std::vector<int> &weights, std::vector<int> &values){

    weights = {};
    values = {};
    
    std::string pallets = "";

    if(n < 10){pallets = "Pallets_0"+std::to_string(n);}
    else{pallets = "Pallets_"+std::to_string(n);}

    std::ifstream file("data/"+ pallets + ".csv");

    if(!file.is_open()){
        std::cerr << "File " << pallets << " doesn't exist! Please try again." << std::endl;
        return;
    }

    std::string aux = "";
    std::string line = "";

    int i = 0;
    while (getline(file, line)){
        
        std::stringstream row(line);

        std::vector<std::string> help = {};

        while(getline(row, aux, ',')){
            while(aux[0] == ' '){aux.erase(0, 1);}
            while(aux[aux.size() - 1] == ' '){aux.erase(aux.size() - 1);}
            help.push_back(aux);
        }

        if(i == 0){i++;continue;}
        else{
            weights.push_back(std::stoi(help[1]));
            values.push_back(std::stoi(help[2]));
        }

        help.clear();

    }

}