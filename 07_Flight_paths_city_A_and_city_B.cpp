/*
Name - Jay Yogesh Chavan 
Class - S.E.(A)
Roll No.- 18

There are flight paths between cities. If there is a flight between city A and city B then there 
is an edge between the cities. The cost of the edge can be the time that flight take to reach 
city B from A, or the amount of fuel used for the journey. Represent this as a graph. The 
node can be represented by airport name or name of the city. Use adjacency list 
representation of the graph or use adjacency matrix representation of the graph. 
  Check whether the graph is connected or not. Justify the storage representation used. 

*/ 
#include <iostream> 
#include <limits.h> 
using namespace std; 
 
class Office { 
    int n; 
    int adjacent[10][10]; 
    string office[10]; 
 
public: 
    void input (); 
    void display (); 
    void Prims (); 
}; 
 
void Office::input () { 
    cout << "\nEnter no. of offices: "; 
    cin >> n; 
    cout << "\nEnter the names of offices: "; 
    for (int i = 0 ; i < n ; i++) 
        cin >> office[i]; 
 
    cout << "\nEnter the cost to connect the offices: \n"; 
    for (int i = 0 ; i < n ; i++) 
        for (int j = i ; j < n ; j++) { 
            if (i == j) { 
                adjacent[i][j] = 0; 
                continue; 
            } 
 
            cout << "Enter the cost to connect " << office[i] <<" and " << office[j]<< " : "; 
            cin >> adjacent[i][j]; 
            adjacent[j][i] = adjacent[i][j]; 
        } 
} 
 
void Office::display () { 
 
    for (int i = 0 ; i < n ; i++) { 
        cout << "\n"; 
        for (int j = 0 ; j < n ; j++) { 
            cout << adjacent[i][j] << "\t"; 
        } 
   } 
} 
 
void Office::Prims () { 
    int visit[n], minCost = 0, count = n - 1, minIndex, cost = 0; 
    for (int i = 0 ; i < n ; i++) 
        visit[i] = 0; 
 
    cout << "\n\nShortest path: "; 
    visit[0]=1; 
    cout << office[0] << " -> "; 
 
    while (count--) { 
        minCost = INT_MAX; 
        for (int i = 0 ; i < n ; i++) { 
            for (int j = 0 ; j < n ; j++) { 
                if (visit[i] == 1 && adjacent[i][j] != 0 && adjacent[i][j] < minCost && visit[j] == 0) { 
                    minCost = adjacent[i][j]; 
                    minIndex = j; 
                } 
            } 
        } 
        visit[minIndex]=1; 
        cout << office[minIndex] << " -> "; 
        cost = cost + minCost; 
    } 
   cout << "End"; 
    cout << "\nMinimum cost: "<<cost; 
} 
 
int main () { 
    Office o1; 
    int choice; 
    do { 
        cout << "\n\nMINIMUM SPANNING TREE" 
             << "\n1. Input data" 
             << "\n2. Display data" 
             << "\n3. Calculate minimum cost" 
             << "\nEnter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                o1.input (); 
                break; 
            case 2: 
                o1.display (); 
                break; 
            case 3: 
                o1.Prims (); 
                break; 
        } 
} while (choice != 4); 
return 0; 
}

/*
Output-
/tmp/hL1S85s7Ek.o


MINIMUM SPANNING TREE
1. Input data
2. Display data
3. Calculate minimum cost
Enter your choice: 1

Enter no. of offices: 2

Enter the names of offices: off1 
Off2

Enter the cost to connect the offices: 
Enter the cost to connect off1 and Off2 : 5


MINIMUM SPANNING TREE
1. Input data
2. Display data
3. Calculate minimum cost
Enter your choice: 2

0	5	
5	0	

MINIMUM SPANNING TREE
1. Input data
2. Display data
3. Calculate minimum cost
Enter your choice: 3


Shortest path: off1 -> Off2 -> End
Minimum cost: 5

MINIMUM SPANNING TREE
1. Input data
2. Display data
3. Calculate minimum cost
Enter your choice: 
*/