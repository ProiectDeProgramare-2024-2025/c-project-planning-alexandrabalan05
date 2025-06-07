#include "Product.hpp"
#include <sstream>

Product::Product(std::string id, std::string name, int quantity)
    : id(std::move(id)), name(std::move(name)), quantity(quantity) {}

std::string Product::toString() const {
    return id + "," + name + "," + std::to_string(quantity);
}

Product Product::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string id, name, qtyStr;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, qtyStr);
    return Product(id, name, std::stoi(qtyStr));
}