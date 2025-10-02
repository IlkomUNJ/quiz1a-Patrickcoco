#include <iostream>
#include "bank_customer.h"
#include "buyer.h"
#include "seller.h"
#include "bank.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
using namespace std;

int main() {
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;
    Bank bank("MyBank");

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);

        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                // TODO: implementasi login user
                break;

            case REGISTER:
                regPrompt = CREATE_BUYER;
                while (regPrompt != BACK) {
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);

                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            // TODO: buat buyer dari input
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            // TODO: buat seller dari input
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                break;

            case EXIT:
                cout << "Exiting." << endl;
                break;

            case ADMIN_LOGIN:
                cout<<"===admin login==="<<endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
                    cout << "Login successful! Welcome, Admin." << endl;

                    bool adminRunning = true;
                    while (adminRunning) {
                        cout << "\n=== Admin Menu ===" << endl;
                        cout << "1. View All Buyers" << endl;
                        cout << "2. View All Sellers" << endl;
                        cout << "3. View Details of Buyer/Seller" << endl;
                        cout << "4. Search Buyer/Seller" << endl;
                        cout << "5. Create New Buyer/Seller/Bank Account" << endl;
                        cout << "6. Remove Buyer/Seller by ID" << endl;
                        cout << "7. Back to Main Menu" << endl;

                        int adminChoice;
                        cin >> adminChoice;

                        switch (adminChoice) {
                            case 1:
                                bank.showAllBuyers();
                                break;
                            case 2:
                                bank.showAllSellers();
                                break;
                            case 3: {
                                int id;
                                cout << "Enter Buyer ID to view: ";
                                cin >> id;
                                bank.viewBuyerDetails(id);
                                cout << "Enter Seller ID to view: ";
                                cin >> id;
                                bank.viewSellerDetails(id);
                                break;
                            }
                            case 4: {
                                string searchName;
                                cout << "Enter Buyer name to search: ";
                                cin.ignore();
                                getline(cin, searchName);
                                bank.searchBuyer(searchName);

                                cout << "Enter Seller name to search: ";
                                getline(cin, searchName);
                                bank.searchSeller(searchName);
                                break;
                            }
                            case 5: {
                                cout << "\n=== Create New Account ===\n";
                                cout << "1. Create Buyer\n";
                                cout << "2. Create Seller\n";
                                cout << "Choice: ";
                                int typeChoice;
                                cin >> typeChoice;

                                if (typeChoice == 1) {
                                int id;
                                string name;
                                double balance;

                                cout << "Enter Buyer ID: ";
                                cin >> id;
                                cout << "Enter Buyer Name: ";
                                cin.ignore();
                                getline(cin, name);
                                cout << "Enter Initial Balance: ";
                                cin >> balance;


                                BankCustomer tempAcc(id, name, balance);
                                bank.addAccount(tempAcc); // simpan agar tidak hilang

                                Buyer newBuyer(id, name, &bank.getAccountById(id));
                                bank.addBuyer(newBuyer);

                                cout << "Buyer created successfully!\n";
                            }
                            else if (typeChoice == 2) {
                                int id, sellerId;
                                string name, sellerName;
                                double balance;

                                cout << "Enter Buyer ID (base): ";
                                cin >> id;
                                cout << "Enter Buyer Name (base): ";
                                cin.ignore();
                                getline(cin, name);
                                cout << "Enter Initial Balance: ";
                                cin >> balance;

                                cout << "Enter Seller ID: ";
                                cin >> sellerId;
                                cout << "Enter Seller Name: ";
                                cin.ignore();
                                getline(cin, sellerName);

                                BankCustomer tempAcc(id, name, balance);
                                bank.addAccount(tempAcc);


                                Buyer baseBuyer(id, name, &bank.getAccountById(id));
                                Seller newSeller(baseBuyer, sellerId, sellerName);
                                bank.addSeller(newSeller);

                                cout << "Seller created successfully!\n";
                            }

                                else {
                                    cout << "Invalid choice.\n";
                                }
                                break;
                            }

                            case 6: {
                                int id;
                                cout << "Enter Buyer ID to remove: ";
                                cin >> id;
                                bank.removeBuyerById(id);

                                cout << "Enter Seller ID to remove: ";
                                cin >> id;
                                bank.removeSellerById(id);
                                break;
                            }
                            case 7:
                                adminRunning = false;
                                break;
                            default:
                                cout << "Pilihan tidak valid." << endl;
                        }
                    }
                } else {
                    cout << "Login failed. Invalid credentials." << endl;
                }
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}
