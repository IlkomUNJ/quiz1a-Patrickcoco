#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    int id;
    string name;
    int quantity;
    double price;
    bool idDisplay;

public:
    Item(int id, const string& name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {
        idDisplay = false;
    }

    // Getters
    int getId() const { return id; }
    const string& getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    Item* getItem() { return this; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setPrice(double newPrice) { price = newPrice; }
    void setDisplay(bool display) { idDisplay = display; }

    void alterItemById(int itemId, const string& newName, int newQuantity, double newPrice) {
        if (id == itemId) {
            name = newName;
            quantity = newQuantity;
            price = newPrice;
        }
    }

    void updatePriceQuantity(int itemId, double newPrice, int newQuantity) {
        if (id == itemId) {
            price = newPrice;
            quantity = newQuantity;
        }
    }

    void display() const {
        cout << "Item ID: " << id
             << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: " << price << endl;
    }
};

#endif // ITEM_H
