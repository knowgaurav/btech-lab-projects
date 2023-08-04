#include <iostream>
#include <conio.h>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool undir = true)
    {
        l[u].push_back(v);
        if (undir)
            l[v].push_back(u);
    }

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = 1;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();

            for (int nbr : l[f])
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
        }
    }

    void dfshelper(int node, bool visited[])
    {
        visited[node] = true;
        cout << node << ",";

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
                dfshelper(nbr, visited);
        }

        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfshelper(source, visited);
    }
};

int main()
{
    cout << "<--- Breadth First Search --->" << endl;

    Graph g(9);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.bfs(1);
    g.dfs(1);

    getch();
    return 0;
}