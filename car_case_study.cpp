#include <iostream>
#define MAX 10
using namespace std;

class ParkingGarage {
    string stack[MAX];
    int top;

public:
    ParkingGarage() {
        top = -1;
    }

    // Car Enters - PUSH
    void carEnters(string carNumber) {
        if (top == MAX - 1) {
            cout << "Garage is Full! Cannot park " << carNumber << endl;
            return;
        }
        top++;
        stack[top] = carNumber;
        cout << carNumber << " parked inside garage.\n";
    }

    // Car Leaves - POP
    void carLeaves() {
        if (top == -1) {
            cout << "Garage is Empty! No cars to leave.\n";
            return;
        }
        cout << stack[top] << " left the garage.\n";
        top--;
    }

    // Display all parked cars (Top to Bottom)
    void display() {
        if (top == -1) {
            cout << "Garage is Empty.\n";
            return;
        }
        cout << "\nGarage Status (Exit <- Top):\n";
        cout << "-----------------------------\n";
        for (int i = top; i >= 0; i--) {
            cout << "| " << stack[i] << " |\n";
        }
        cout << "-----------------------------\n";
        cout << "-> Entry
