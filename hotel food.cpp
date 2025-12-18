#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct FoodItem {
    string name;
    double price;
};

struct Order {
    string customerName;
    vector<FoodItem> items;
    double totalAmount;
};

void displayMenu(const vector<FoodItem>& menu) {
    cout << "------- Menu -------" << endl;
    for (vector<FoodItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
        cout << it->name << " - Birr: " << it->price << endl;
    }
    cout << "---------------------" << endl;
}

void addFoodItem(vector<FoodItem>& menu) {
    FoodItem item;
    cout << "Enter food name: ";
    cin.ignore();
    getline(cin, item.name);
    cout << "Enter food price: Birr: ";
    cin >> item.price;

    menu.push_back(item);
    cout << "Food item added successfully!" << endl;
}

void removeFoodItem(vector<FoodItem>& menu) {
    string itemName;
    cout << "Enter the name of the food item to remove: ";
    cin.ignore();
    getline(cin, itemName);

    for (vector<FoodItem>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->name == itemName) {
            menu.erase(it);
            cout << "Food item removed successfully!" << endl;
            return;
        }
    }

    cout << "Food item not found!" << endl;
}

Order placeOrder(const vector<FoodItem>& menu) {
    Order order;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, order.customerName);

    string itemName;
    char choice;
    do {
        cout << "Enter item name: ";
        getline(cin, itemName);

        bool found = false;
        for (vector<FoodItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
            if (it->name == itemName) {
                order.items.push_back(*it);
                order.totalAmount += it->price;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid item name! Please try again." << endl;
        }

        cout << "Add another item? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return order;
}

void displayOrder(const Order& order) {
    cout << "------- Order Details -------" << endl;
    cout << "Customer Name: " << order.customerName << endl;
    cout << "Items Ordered: " << endl;
    for (vector<FoodItem>::const_iterator it = order.items.begin(); it != order.items.end(); ++it) {
        cout << it->name << " - Birr: " << it->price << endl;
    }
    cout << "Total Amount: Birr: " << order.totalAmount << endl;
    cout << "-------------------------------" << endl;
}

int main() {
    vector<FoodItem> menu;
    menu.push_back(FoodItem{"Dinich", 39.99});
    menu.push_back(FoodItem{"Bread", 14.99});
    menu.push_back(FoodItem{"Agelgil", 119.99});
    menu.push_back(FoodItem{"Mahberawi", 110.99});
    menu.push_back(FoodItem{"Key Wat", 79.99});
    menu.push_back(FoodItem{"Fifir", 49.99});
    menu.push_back(FoodItem{"Minchet", 89.99});
    menu.push_back(FoodItem{"Monbolino", 9.99});

    int choice;
    do {
    	cout << "-------====******** YUUNIVARSIITII HARAMAAYAA *************====-------" << endl;
    	cout << "------- =======Name of group of students======= -------" << endl;
    	cout << "\n 1.Ebrahim Beker IDNo:- 356/14 \n 2.Lemi Wakuma:- 479/14 \n 3.Elias Cherenat:-357/17  \n 4.Henok Guta:-370/14 -------" << endl;
    	cout << "------- ***=========HARAMAYA UNIVERSITY==========*** -------" << endl;
        cout << "------- ********Hotel ***Food Ordering ****Management System********** -------" << endl;
        cout << "1. Add new food item" << endl;
        cout << "2. Remove a food item" << endl;
        cout << "3. Display menu" << endl;
        cout << "4. Place an order" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFoodItem(menu);
                break;
            case 2:
                removeFoodItem(menu);
                break;
            case 3:
                displayMenu(menu);
                break;
            case 4: {
                Order order = placeOrder(menu);
                cout << endl;
                displayOrder(order);
                break;
            }
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

