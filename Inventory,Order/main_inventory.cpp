#include "Inventory.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "\033[33mUsage: " << argv[0] << " <file> <id> <name> <quantity>\033[0m\n";
        return 1;
    }

    std::string file = argv[1];
    std::string id = argv[2];
    std::string name = argv[3];
    int quantity = std::stoi(argv[4]);

    Inventory inv;
    inv.loadFromFile(file);
    inv.addOrUpdateProduct(Product(id, name, quantity));
    inv.saveToFile(file);

    std::cout << "\033[32mProduct added/updated successfully.\033[0m\n";
    return 0;
}
