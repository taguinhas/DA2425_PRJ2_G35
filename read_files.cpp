std::vector<std::tuple<std::string, std::string>> read_truck(std::string truck){

    if(truck.length() < 3){
        int nt = std::stoi(truck);
        if(nt >= 1 && nt < 10){
            truck = "TruckAndPallets_0"+truck;
        }
    
        else if(nt == 10){
            truck = "TruckAndPallets_"+truck;
        }
    }

    std::ifstream file("data/"+ truck + ".csv");

    if(!file.is_open()){
        std::cerr << "File with number " << truck << " doesn't exist!" << std::endl;
    }

    std::vector<std::tuple<std::string, std::string>> data;
    std::string aux, line;

    while (getline(file, line)){
        
        std::stringstream row(line);

        std::vector<std::string> help;
        help.clear();

        while(getline(row, aux, ',')){
            while(aux[0] == ' '){aux.erase(0, 1);}
            while(aux[aux.size() - 1] == ' '){aux.erase(aux.size() - 1);}
            help.push_back(aux);
        }

        std::tuple<std::string, std::string> 
        list(help[0], help[1]);

        data.push_back(list);

    }

    return data;

}

std::vector<std::tuple<std::string, std::string, std::string>> read_pallets(std::string pallets){

    if(pallets.length() < 3) {
        int pt = std::stoi(pallets);
        if(pt >= 1 && pt < 10){
            pallets = "Pallets_0"+pallets;
        }
    
        if(pt == 10){
            pallets = "Pallets_"+pallets;
        }
    }

    std::ifstream file("data/"+ pallets + ".csv");

    if(!file.is_open()){
        std::cerr << "File with number " << pallets << " doesn't exist!" << std::endl;
    }

    std::vector<std::tuple<std::string, std::string, std::string>> data;
    std::string aux, line;

    while (getline(file, line)){
        
        std::stringstream row(line);

        std::vector<std::string> help;
        help.clear();

        while(getline(row, aux, ',')){
            while(aux[0] == ' '){aux.erase(0, 1);}
            while(aux[aux.size() - 1] == ' '){aux.erase(aux.size() - 1);}
            help.push_back(aux);
        }

        std::tuple<std::string, std::string, std::string> 
        list(help[0], help[1], help[2]);

        data.push_back(list);

    }

    return data;

}