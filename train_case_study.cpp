#include <iostream>
using namespace std;

// Node structure for a Coach
struct Coach {
    string coachName;
    Coach* next;
};

Coach* head = NULL; // Train Engine - start of list

// 1. Add a coach at the beginning
void addAtBeginning(string name) {
    Coach* newCoach = new Coach();
    newCoach->coachName = name;
    newCoach->next = head;
    head = newCoach;
    cout << name << " added at beginning.\n";
}

// 2. Add a coach at the end
void addAtEnd(string name) {
    Coach* newCoach = new Coach();
    newCoach->coachName = name;
    newCoach->next = NULL;

    if (head == NULL) {
        head = newCoach;
        return;
    }
    Coach* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newCoach;
    cout << name << " added at end.\n";
}

// 3. Remove a coach by name
void removeCoach(string name) {
    if (head == NULL) {
        cout << "Train is empty! No coaches to remove.\n";
        return;
    }
    // If first coach itself is to be removed
    if (head->coachName == name) {
        Coach* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << name << " removed.\n";
        return;
    }
    Coach* temp = head;
    while (temp->next != NULL && temp->next->coachName != name) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Coach " << name << " not found!\n";
    } else {
        Coach* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << name << " removed.\n";
    }
}

// 4. Display all coaches
void display() {
    if (head == NULL) {
        cout << "Train has no coaches.\n";
        return;
    }
    cout << "\nTrain: ";
    Coach* temp = head;
    while (temp != NULL) {
        cout << temp->coachName;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int choice;
    string name;
    
    // Initial train: Coach1 -> Coach2 -> Coach3 -> Coach4
    addAtEnd("Coach1");
    addAtEnd("Coach2");
    addAtEnd("Coach3");
    addAtEnd("Coach4");

    do {
        cout << "\n--- Train Coach Management ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter coach name: ";
                cin >> name;
                addAtBeginning(name);
                break;
            case 2:
                cout << "Enter coach name: ";
                cin >> name;
                addAtEnd(name);
                break;
            case 3:
                cout << "Enter coach name to remove: ";
                cin >> name;
                removeCoach(name);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}






Ithu case:2
