#include "Inventory.hpp"
#include <fstream>
#include <iostream>

void Inventory::loadFromFile(const std::string& path) {
    products.clear();
    std::ifstream fin(path);
    std::string line;
    while (getline(fin, line)) {
        products.push_back(Product::fromString(line));
    }
}

void Inventory::saveToFile(const std::string& path) const {
    std::ofstream fout(path);
    for (const auto& p : products) {
        fout << p.toString() << "\n";
    }
}

void Inventory::addOrUpdateProduct(const Product& product) {
    for (auto& p : products) {
        if (p.id == product.id) {
            p.quantity += product.quantity;
            return;
        }
    }
    products.push_back(product);
}

bool Inventory::processOrder(const std::string& id, int quantity) {
    for (auto& p : products) {
        if (p.id == id && p.quantity >= quantity) {
            p.quantity -= quantity;
            return true;
        }
    }
    return false;
}