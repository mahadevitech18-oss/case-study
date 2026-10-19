#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> shoppingList;
    int choice;
    string item;

    do {
        cout << "\n--- Shopping List Menu ---\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Search item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                cin >> item;
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin >> item;
                {
                    auto it = find(shoppingList.begin(),
                                   shoppingList.end(), item);
                    if (it != shoppingList.end()) {
                        shoppingList.erase(it);
                        cout << "Item removed successfully!\n";
                    } else {
                        cout << "Item not found!\n";
                    }
                }
                break;

            case 3:
                cout << "Enter item to search: ";
                cin >> item;
                if (find(shoppingList.begin(),
                         shoppingList.end(), item)
                    != shoppingList.end()) {
                    cout << "Item found!\n";
                } else {
                    cout << "Item not found!\n";
                }
                break;

            case 4:
                cout << "Shopping List:\n";
                if (shoppingList.empty()) {
                    cout << "List is empty!\n";
                } else {
                    for (const string &x : shoppingList) {
                        cout << x << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
