#include <iostream>
#include <conio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>

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
            cout << f << ",";
            q.pop();

            for (int nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
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
    Graph g(7);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    cout << "Traversal order is: ";

    cout << "\nUsing BFS => ";
    g.bfs(1);

    cout << "\nUsing DFS =>";
    g.dfs(1);

    getch();
    return 0;
}
