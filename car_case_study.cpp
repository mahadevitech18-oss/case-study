#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class ParkingGarage {
    string stack[MAX];
    int top;
public:
    ParkingGarage(){
        top = -1;
    }
    void carEnters(string carNumber){
        if(top == MAX-1){
            cout << "Garage is Full!" << endl;
            return;
        }
        top++;
        stack[top] = carNumber;
        cout << carNumber << " parked" << endl;
    }
    void carLeaves(){
        if(top == -1){
            cout << "Garage is Empty!" << endl;
            return;
        }
        cout << stack[top] << " left the garage" << endl;
        top--;
    }
    void display(){
        if(top == -1){
            cout << "Garage is Empty" << endl;
            return;
        }
        cout << "\nGarage Status:" << endl;
        for(int i=top; i>=0; i--){
            cout << "| " << stack[i] << " |" << endl;
        }
        cout << "Top car leaves first - LIFO" << endl;
    }
};

int main(){
    ParkingGarage pg;
    int choice;
    string carNo;
    do{
        cout << "\n--- Parking Garage ---" << endl;
        cout << "1. Car Enters" << endl;
        cout << "2. Car Leaves" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter Car Number: ";
                cin >> carNo;
                pg.carEnters(carNo);
                break;
            case 2:
                pg.carLeaves();
                break;
            case 3:
                pg.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }while(choice != 4);
    return 0;
}







    
