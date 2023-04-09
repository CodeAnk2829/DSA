#include <bits/stdc++.h>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited) {
    cout << sv << " ";
    visited[sv] = true;
    for(int i = 0; i < n; ++i) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int** edges, int n, int sv, bool* visited) {
    queue<int> unvisitedVertex;
    unvisitedVertex.push(sv);
    visited[sv] = true;
    while(!unvisitedVertex.empty()) {
        int currentVertex = unvisitedVertex.front();
        unvisitedVertex.pop();
        cout << currentVertex << " ";
        for(int i = 0; i < n; ++i) {
            if(sv == i) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && (!visited[i])) {
                unvisitedVertex.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void DFS(int** edges, int n) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            printDFS(edges, n, i, visited);
            cout << endl;
        }
    }
    delete [] visited;
}

void BFS(int** edges, int n) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            printBFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

bool hasPathHelper(int** edges, int n, int sv, int ev, bool* visited) {
    if(edges[sv][ev] == 1) {
        return true;
    }
    visited[sv] = true;
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(sv == i) {
            continue;
        }
        if(edges[sv][i] == 1 && (!visited[i])) {
            flag = flag || hasPathHelper(edges, n, i, ev, visited);
        }
    }
    return flag;
}
bool hasPath(int** edges, int n, int sv, int ev) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    bool ans = hasPathHelper(edges, n, sv, ev, visited);
    delete [] visited;
    return ans;
}
int main() {
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i = 0; i < n; ++i) {
        edges[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; ++i) {
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }
    int sv, ev;
    cin >> sv >> ev;
    // DFS(edges, n);
    // cout << endl;
    // BFS(edges, n);
    cout << hasPath(edges, n, sv, ev) << endl;

    // Delete
    for(int i = 0; i < n; ++i) {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
