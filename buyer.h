#ifndef BUYER_H
#define BUYER_H

#include <cstddef>
#include <string>
#include <iostream>
#include "bank_customer.h"

using namespace std;

class Buyer {
private:
    int id;
    string name;
    BankCustomer* account;   // pakai pointer, bukan reference

public:
    // Constructor default (biar bisa bikin vector<Buyer>)
    Buyer() : id(0), name(""), account(nullptr) {}

    // Constructor dengan parameter (pakai pointer)
    Buyer(int id, const string& name, BankCustomer* account0)
        : id(id), name(name), account(account0) {}

    // Getter
    int getId() const { return id; }
    string getName() const { return name; }
    BankCustomer* getAccount() { return account; }

    // Setter
    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setAccount(BankCustomer* acc) { account = acc; }

    // Display function for Buyer details
    void display() const {
        cout << "Buyer ID: " << id
             << ", Name: " << name << endl;
        if (account) account->display();
        else cout << "No account linked" << endl;
    }
};

#endif // BUYER_H
