#pragma once
#include "Product.hpp"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Product> products;

public:
    void loadFromFile(const std::string& path);
    void saveToFile(const std::string& path) const;
    
    void addOrUpdateProduct(const Product& product);
    bool processOrder(const std::string& id, int quantity);
};