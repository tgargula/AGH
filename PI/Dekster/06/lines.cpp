#include <iostream>
#include <list>
#include <stack>

using namespace std;

void DFS (list<int>* graph, stack<int> &line, int v) {

    while (!graph[v].empty()) {
        int u = graph[v].front();
        graph[v].remove(u);
        graph[u].remove(v);
        DFS(graph, line, u);
    }
    line.push(v);

}

void divideLines (stack<int> &lines, stack<int>* line, int howManyPaths) {

    for (int i = 0; i < howManyPaths; i++) {
        lines.pop();
        do {
            line[i].push(lines.top());
            lines.pop();
        } while (lines.top() != 0);
    }

}

void printLine (stack<int> &line) {

    cout << line.size() << " ";
    while (!line.empty()) {
        cout << line.top() << " ";
        line.pop();
    }
    cout << endl;

}

int main() {

    int Z;
    cin >> Z;

    for (int i = 0; i < Z; i++) {
        int n, m;
        cin >> n >> m;
        int N = n+1;
        
        /* Tworzymy listę sąsiedztwa jako sposób implementacji grafu */
        list<int> *graph = new list<int>[N];

        /* Wczytujemy wartości */
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        /* Tworzymy dodatkowy wierzchołek i łączymy go z wierzchołkami, które są niepatrzystego stopnia
            Tak zmieniony graf jest grafem Eulera */
        for (int j = 1; j < N; j++) {
            if (graph[j].size() %2 == 1) {
                graph[0].push_back(j);
                graph[j].push_back(0);
            }
        }

        /* Obliczamy liczbę linii, korzystając z faktu, że wynosi ona stopień dodatkowego
            wierzchołka / 2 – w przypadku grafu, który pierwotnie nie był cyklem Eulera;
            albo jeden – jeśli pierwotny graf był cyklem Eulera */
        int howManyPaths = graph[0].size() / 2;
        bool isEulerCycle = false;
        if (howManyPaths == 0) { isEulerCycle = true; howManyPaths = 1; }
        cout << howManyPaths << endl;

        if (isEulerCycle) {
            stack<int> line;
            DFS(graph, line, 1);
            printLine(line);
        } else {
            stack<int> lines;
            DFS(graph, lines, 0);
            stack<int>* line = new stack<int>[howManyPaths];
            divideLines(lines, line, howManyPaths);
            for (int j = 0; j < howManyPaths; j++) printLine(line[j]);
            delete[] line;
        }

        delete[] graph;

    }

    return 0;

}