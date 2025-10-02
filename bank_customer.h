#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include <string>
#include <iostream> // supaya bisa pakai cout

using namespace std;

class BankCustomer {
private:
    int id;
    string name;
    double balance;

public:
    BankCustomer(int id, const string& name, double balance)
        : id(id), name(name), balance(balance) {}

    // Getter
    int getId() const;
    string getName() const;
    double getBalance() const;

    // Setter
    void setName(const string& name);
    void setBalance(double balance);

    // Operasi saldo
    void addBalance(double amount);
    bool withdrawBalance(double amount);

    // Cetak info singkat
    void printInfo() const;

    // Cetak detail lengkap
    void display() const {
        cout << "Customer ID: " << id
             << ", Name: " << name
             << ", Balance: " << balance << endl;
    }
};

#endif // BANK_CUSTOMER_H
