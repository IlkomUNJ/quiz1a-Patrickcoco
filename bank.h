#include "bank_customer.h"
#include "buyer.h"
#include "seller.h"
#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    string name;
    vector<BankCustomer> Accounts;
    vector<Buyer> Buyers;
    vector<Seller> Sellers;

public:
    Bank(const string& name) { this->name = name; }

    // ===== Account Management =====
    void addAccount(const BankCustomer& acc) { Accounts.push_back(acc); }

    void showAllAccounts() {
        cout << "\n=== All Bank Accounts ===\n";
        if (Accounts.empty()) cout << "No accounts yet.\n";
        else for (auto &acc : Accounts) acc.display();
    }
// ===== Account Helper =====
BankCustomer& getAccountById(int id) {
    for (auto &acc : Accounts) {
        if (acc.getId() == id) return acc;
    }
    throw runtime_error("Account not found!");
}

    // ===== Buyer Management =====
    void addBuyer(const Buyer& b) { Buyers.push_back(b); }

    void showAllBuyers() const {
        cout << "\n=== All Buyers ===\n";
        if (Buyers.empty()) cout << "No buyers registered yet.\n";
        else for (const auto& b : Buyers) b.display();
    }

    // ===== Seller Management =====
    void addSeller(const Seller& s) { Sellers.push_back(s); }

    void showAllSellers() const {
        cout << "\n=== All Sellers ===\n";
        if (Sellers.empty()) cout << "No sellers registered yet.\n";
        else for (const auto& s : Sellers) s.display();
    }

    // ===== Detail =====
    void viewBuyerDetails(int id) const {
        for (const auto& b : Buyers) {
            if (b.getId() == id) {
                b.display();
                return;
            }
        }
        cout << "Buyer not found!\n";
    }

    void viewSellerDetails(int id) const {
        for (const auto& s : Sellers) {
            if (s.getSellerId() == id) {
                s.display();
                return;
            }
        }
        cout << "Seller not found!\n";
    }

    // ===== Search =====
    void searchBuyer(string name) const {
        for (const auto& b : Buyers) {
            if (b.getName() == name) {
                b.display();
                return;
            }
        }
        cout << "Buyer not found!\n";
    }

    void searchSeller(string name) const {
        for (const auto& s : Sellers) {
            if (s.getSellerName() == name) {
                s.display();
                return;
            }
        }
        cout << "Seller not found!\n";
    }

    // ===== Remove =====
    void removeBuyerById(int id) {
        for (auto it = Buyers.begin(); it != Buyers.end(); ++it) {
            if (it->getId() == id) {
                Buyers.erase(it);
                cout << "Buyer removed.\n";
                return;
            }
        }
        cout << "Buyer not found!\n";
    }

    void removeSellerById(int id) {
        for (auto it = Sellers.begin(); it != Sellers.end(); ++it) {
            if (it->getSellerId() == id) {
                Sellers.erase(it);
                cout << "Seller removed.\n";
                return;
            }
        }
        cout << "Seller not found!\n";
    }
};
