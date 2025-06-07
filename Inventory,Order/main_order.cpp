#include "Inventory.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "\033[33mUsage: " << argv[0] << " <file> <id> <quantity>\033[0m\n";
        return 1;
    }

    std::string file = argv[1];
    std::string id = argv[2];
    int quantity = std::stoi(argv[3]);

    Inventory inv;
    inv.loadFromFile(file);

    if (inv.processOrder(id, quantity)) {
        inv.saveToFile(file);
        std::cout << "\033[32mOrder processed successfully.\033[0m\n";
    } else {
        std::cerr << "\033[31mOrder failed: Not enough stock or product not found.\033[0m\n";
    }

    return 0;
}
