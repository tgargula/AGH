#include <iostream>
#include <list>
#include <stack>

using namespace std;

void DFS(list<int> *graph, stack<int> &packets, short *visited, int v, bool &flag) {

    visited[v] = 1;
    while(!graph[v].empty()) {
        int u = graph[v].front();
        graph[v].pop_front();
        if(visited[u] == 1) { flag = true; return; }
        if(visited[u] == 0) DFS(graph, packets, visited, u, flag);
    }
    packets.push(v);
    visited[v] = 2;

}

void printGraph(list<int> *graph, int n) {

    for(int i = 0; i < n; i++) {
        cout << i << ": ";
        while(!graph[i].empty()) {
            cout << graph[i].front() << " ";
            graph[i].pop_front();
        }
        cout << endl;
    }

}

int main() {

    int n, k;
    cin >> n >> k;
    
    /* Lista sąsiedztwa jako reprezentacja grafu */
    list<int> *graph = new list<int>[n];
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    stack<int> packets;
    short *visited = new short[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            bool flag = false;
            DFS(graph, packets, visited, i, flag);
            if(flag) {
                delete[] visited;
                delete[] graph;
                cout << "CYCLE" << endl;
                return 0;
            }
        }
    }

    cout << "OK" << endl;

    while(!packets.empty()) {
        cout << packets.top() << " ";
        packets.pop();
    }
    cout << endl;

    delete[] visited;
    delete[] graph;

    return 0;

}