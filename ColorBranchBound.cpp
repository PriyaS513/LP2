/* 
Input:  graph = {0, 1, 1, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1},
                         {1, 0, 1, 0}
Output: Solution Exists: Following are the assigned colors: 1  2  3  2
*/

#include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include<set>
using namespace std; 

class Graph {
    public:
    int V;
    vector<vector<int>> graph;


    Graph(int vertices) : V(vertices) {
        graph.resize(V, vector<int>(V, 0));
    }

    bool isSafe(int v, vector<int>& color, int c) {
        for (int i = 0; i < V; ++i) {
            if (graph[v][i] && color[i] == c) {
                return false;
            }
        }
        return true;
    }

    bool graphColoringUtil(int m, vector<int>& color, int v) {
        if (v == V) {
            return true;
        }

        for (int c = 1; c <= m; ++c) {
            if (isSafe(v, color, c)) {
                color[v] = c;
                if (graphColoringUtil(m, color, v + 1)) {
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int m) {
        vector<int> color(V, 0);
        if (!graphColoringUtil(m, color, 0)) {
            cout << "Solution does not exist\n";
            return false;
        }

        cout << "Solution exists and the colors are:\n";
        for (int c : color) {
            cout << c << " ";
        }
        cout << "\n";
        return true;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;
    Graph g(vertices);

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> g.graph[i][j];
        }
    }

    int m;
    cout << "Enter the number of colors: ";
    cin >> m;
    g.graphColoring(m);

    return 0;
}
/*
Enter the number of vertices in the graph: 4
Enter the adjacency matrix of the graph:
0
1
1
1
1
0
1
0
1
1
0
1
1
0
1
0
Enter the number of colors: 3
Solution exists and the colors are:
1 2 3 2 
*/