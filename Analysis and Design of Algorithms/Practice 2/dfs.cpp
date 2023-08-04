#include <iostream>
#include <conio.h>
#include <list>
#include <vector>

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

    void dfshelper(int src, vector<bool> &visited, vector<int> &ans)
    {
        visited[src] = true;
        ans.push_back(src);

        for (int nbr : l[src])
            if (!visited[nbr])
                dfshelper(nbr, visited, ans);
    }

    void dfs(int src)
    {
        vector<int> ans;
        vector<bool> visited(V, false);

        dfshelper(src, visited, ans);

        for (int nbr : ans)
            cout << nbr << ", ";
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

    // cout << "\nUsing BFS => ";
    // g.bfs(1);

    cout << "\nUsing DFS =>";
    g.dfs(1);

    getch();
    return 0;
}