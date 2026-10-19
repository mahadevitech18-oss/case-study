#include <iostream>
#define MAX 10
using namespace std;

class BrowserHistory {
    string stack[MAX];
    int top;
public:
    BrowserHistory() { top = -1; }

    void visit(string page) {
        if(top == MAX-1) {
            cout << "History Full!" << endl;
            return;
        }
        top++;
        stack[top] = page;
        cout << "Visited: " << page << endl;
    }

    void back() {
        if(top == -1) {
            cout << "No history!" << endl;
            return;
        }
        cout << "Back from: " << stack[top] << endl;
        top--;
    }

    void currentPage() {
        if(top == -1) {
            cout << "No page open" << endl;
        } else {
            cout << "Current top page: " << stack[top] << endl;
        }
    }

    void display() {
        if(top == -1) {
            cout << "History Empty" << endl;
            return;
        }
        cout << "\n--- Browser History (Top = Latest) ---" << endl;
        for(int i=top; i>=0; i--) {
            cout << "| " << stack[i] << " |" << endl;
        }
        cout << "--------------------------------------" << endl;
    }
};

int main() {
    BrowserHistory bh;
    
    // Given Input
    bh.visit("google.com");
    bh.visit("youtube.com");
    bh.visit("abcsc.com");
    bh.visit("facebook.com");
    
    bh.display();
    
    cout << "\nPressing Back once:" << endl;
    bh.back();
    bh.display();
    
    cout << "\nPressing Back twice:" << endl;
    bh.back();
    bh.currentPage(); // Answer: youtube.com
    
    bh.display();
    return 0;
}
