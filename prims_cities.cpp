#include <iostream>
using namespace std;
#define INF 9999
#define V 4

int main() {
    // Adjacency Matrix - Roads between cities
    int graph[V+1][V+1] = {0};
    graph[1][2] = graph[2][1] = 10; // City 1-2 cost 10
    graph[1][3] = graph[3][1] = 6;  // City 1-3 cost 6
    graph[1][4] = graph[4][1] = 5;  // City 1-4 cost 5
    graph[2][4] = graph[4][2] = 15; // City 2-4 cost 15
    graph[3][4] = graph[4][3] = 4;  // City 3-4 cost 4
    
    bool visited[V+1] = {false};
    visited[1] = true; // Start from City 1
    int edges = 0, totalCost = 0;
    
    cout << "=== Govt Project - Connect All Cities ===" << endl;
    cout << "Cities: 4" << endl;
    cout << "\nMinimum roads required:" << endl;
    cout << "From - To | Cost" << endl;
    cout << "----------------" << endl;
    
    while(edges < V-1) {
        int min = INF, x=0, y=0;
        for(int i=1; i<=V; i++) {
            if(visited[i]) {
                for(int j=1; j<=V; j++) {
                    if(!visited[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i; y = j;
                    }
                }
            }
        }
        cout << "  " << x << "  -  " << y << "  |  " << min << endl;
        totalCost += min;
        visited[y] = true;
        edges++;
    }
    
    cout << "----------------" << endl;
    cout << "\nMinimum total cost to connect all cities: " << totalCost << endl;
    cout << "\nExplanation:" << endl;
    cout << "Selected roads: 4-3 (4) + 1-4 (5) + 1-2 (10) = 19" << endl;
    cout << "This connects all 4 cities with minimum cost!" << endl;
    
    return 0;
}
