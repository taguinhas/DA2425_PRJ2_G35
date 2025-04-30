void test(
    std::vector<std::tuple<std::string, std::string>> truck,
    std::vector<std::tuple<std::string, std::string, std::string>> pallets
)
{
    int i = 0;
    for(std::tuple<std::string, std::string> t : truck){
        if (i==0){
            i++;
            continue;
        }

        std::cout << "Truck has " << std::get<0>(t) << " capacity and there are " << std::get<1>(t) << " pallets\n";
    }

    i=0;
    for(std::tuple<std::string, std::string, std::string> p : pallets){
        if (i==0){
            i++;
            continue;
        }

        std::cout << "Pallet number " << std::get<0>(p) << " has weight " << std::get<1>(p) << " and profit " << std::get<2>(p) << "\n";
    }

    return;
}