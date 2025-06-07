#pragma once
#include <string>

class Product {
public:
    std::string id;
    std::string name;
    int quantity;

    Product() = default;
    Product(std::string id, std::string name, int quantity);
    
    std::string toString() const;
    static Product fromString(const std::string& line);
};