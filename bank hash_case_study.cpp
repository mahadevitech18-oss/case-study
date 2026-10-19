#include <iostream>
using namespace std;
#define SIZE 10

class BankHashTable {
    int table[SIZE];
    bool occupied[SIZE];
public:
    BankHashTable() {
        for(int i=0;i<SIZE;i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    int hashFunction(int accNo) {
        return accNo % SIZE;
    }

    void insert(int accNo) {
        int index = hashFunction(accNo);
        int originalIndex = index;
        
        // Linear probing for collision
        while(occupied[index]) {
            cout << "Collision at index " << index << " for acc " << accNo << " -> probing next" << endl;
            index = (index + 1) % SIZE;
            if(index == originalIndex) {
                cout << "Hash Table Full!" << endl;
                return;
            }
        }
        table[index] = accNo;
        occupied[index] = true;
        cout << "Account " << accNo << " stored at index " << index << endl;
    }

    void search(int accNo) {
        int index = hashFunction(accNo);
        int originalIndex = index;
        int count = 0;
        while(count < SIZE) {
            if(!occupied[index]) break;
            if(table[index] == accNo) {
                cout << "Account " << accNo << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            count++;
        }
        cout << "Account " << accNo << " not found" << endl;
    }

    void display() {
        cout << "\n--- Bank Hash Table ---" << endl;
        cout << "Index | Account No" << endl;
        for(int i=0;i<SIZE;i++) {
            if(occupied[i])
                cout << "  " << i << "   |   " << table[i] << endl;
            else
                cout << "  " << i << "   |   EMPTY" << endl;
        }
        cout << "-----------------------" << endl;
    }
};

int main() {
    BankHashTable bank;
    int n, accNo;
    cout << "Enter number of accounts: ";
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cout << "Enter account number " << i+1 << ": ";
        cin >> accNo;
        bank.insert(accNo);
    }
    
    bank.display();
    
    int searchAcc;
    cout << "\nEnter account to search: ";
    cin >> searchAcc;
    bank.search(searchAcc);
    
    return 0;
}
