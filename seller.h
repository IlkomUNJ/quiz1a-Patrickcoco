#pragma once
#include "buyer.h"
#include "item.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Seller : public Buyer {
private:
    int sellerId;
    string sellerName;
    vector<Item> items;

public:
    Seller() = default;

    Seller(Buyer buyer, int sellerId, const string& sellerName)
        : Buyer(buyer.getId(), buyer.getName(), buyer.getAccount()) {
        this->sellerId = sellerId;
        this->sellerName = sellerName;
    }

    virtual ~Seller() = default;

    int getSellerId() const { return sellerId; }
    string getSellerName() const { return sellerName; }

    void addNewItem(int newId, const string& newName, int newQuantity, double newPrice) {
        items.emplace_back(newId, newName, newQuantity, newPrice);
    }

    void updateItem(int itemId, const string& newName, int newQuantity, double newPrice) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.alterItemById(itemId, newName, newQuantity, newPrice);
            }
        }
    }

    void makeItemVisibleToCustomer(int itemId) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.setDisplay(true);
                break;
            }
        }
    }

    void display() const {
        cout << "Seller ID: " << sellerId
             << ", Seller Name: " << sellerName
             << ", Base Buyer Name: " << Buyer::getName() << endl;

        if (items.empty()) {
            cout << "  No items yet." << endl;
        } else {
            cout << "  Items:" << endl;
            for (const auto& item : items) {
                cout << "    ";
                item.display();
            }
        }
    }
};
