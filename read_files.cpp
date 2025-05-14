void read_truck(std::string truck, int &capacity, int &n_pallets){

    //TODO Ler mais que 1 a 10
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

void read_pallets(std::string pallets, std::vector<int> &weights, std::vector<int> &values){

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