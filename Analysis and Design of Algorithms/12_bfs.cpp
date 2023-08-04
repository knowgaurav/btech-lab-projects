#include <iostream>
#include <conio.h>
#include <list>
#include <queue>
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

    vector<int> bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        vector<int> ans;

        q.push(source);
        visited[source] = 1;

        while (!q.empty())
        {
            int f = q.front();
            ans.push_back(f);
            q.pop();

            for (int nbr : l[f])
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
        }

        return ans;
    }
};

int main()
{
    cout << "<--- Breadth First Search --->" << endl
         << endl;

    Graph g(9);
    char arr[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};

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

    vector<int> ans = g.bfs(1);

    cout << "Traversal order is: ";

    for (int i = 0; i < ans.size(); i++)
        cout << arr[ans[i]] << " -> ";

    getch();
    return 0;
}