#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Node {
    vector <pair<Node *, int>> neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
	return n;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {
    if (v->dist > u->dist + weight) v->dist = u->dist + weight;
}

bool isCycle(Node *u, Node *v, int weight) {
    return v->dist > u->dist + weight;
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    start->dist = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            Node* edges = nodes[i];
            for (unsigned int j = 0; j < edges->neighbours.size(); j++) {
                relax(nodes[i], edges->neighbours.at(j).first, edges->neighbours.at(j).second);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        Node* edges = nodes[i];
        for (unsigned int j = 0; j < edges->neighbours.size(); j++) {
            if (isCycle(nodes[i], edges->neighbours.at(j).first, edges->neighbours.at(j).second)) return false;
        }
    }
    return true;
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    cin >> start >> end;
    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }
    
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYCLE" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NO" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}
