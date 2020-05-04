#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int v;
        int p = -1;
        int d = INT32_MAX; // inf
    Node(int v) {
        this->v = v;
    }
};

class Edge {
    public:
        int w;
        Node* v;
        Edge* next;
    Edge(int w = INT32_MAX, Node* v = NULL) {
        this->w = w;
        this->v = v;
        this->next = NULL;
    }
    void addEdge(Node* v, int w) {
        Edge* edge = new Edge(w, v);
        edge->next = this->next;
        this->next = edge;
    }
};

struct CompareNodes { 
    bool operator()(Node* const& u, Node* const& v) { 
        return u->d > v->d; 
    } 
}; 

priority_queue<Node*, vector<Node*>, CompareNodes> updateQueue(priority_queue<Node*, vector<Node*>, CompareNodes> Q) {
    priority_queue<Node*, vector<Node*>, CompareNodes> newQueue;
    while(!Q.empty()) {
        newQueue.push(Q.top());
        Q.pop();
    }
    return newQueue;
}

void relax(Edge* E, Node* u) {
    Node* v = E->v;
    if (v->d > u->d + E->w) {
        v->d = u->d + E->w;
        v->p = u->v;
    }
}

int dijkstra(Edge** E, Node** V, int N, int s, int t) {
    priority_queue<Node*, vector<Node*>, CompareNodes> Q;
    V[s]->d = 0;
    for (int i = 0; i < N; i++) Q.push(V[i]);
    while (!Q.empty()) {
        Node* u = Q.top();
        Q.pop();
        while (E[u->v]->next != NULL) {
            Edge* toDelete = E[u->v];
            E[u->v] = E[u->v]->next;
            delete toDelete;
            relax(E[u->v],u);
        }
        Q = updateQueue(Q);
    }
    
    return V[t]->d;
}

int main() {

    int N, K;
    cin >> N >> K;
    int s, t;
    cin >> s >> t;
    
    Node** V = new Node*[N];
    Edge** E = new Edge*[N];
    for (int i = 0; i < N; i++) {
        V[i] = new Node(i);
        E[i] = new Edge();
    }
    
    for (int i = 0; i < K; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[v]->addEdge(V[u], w);
        E[u]->addEdge(V[v], w);
    }

    cout << dijkstra(E,V,N,s,t) << endl;

    for (int i = 0; i < N; i++) {
        delete E[i];
        delete V[i];
    }
    delete[] V;
    delete[] E;

    return 0;

}