#include <iostream>
#include <conio.h>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void prims(int src)
    {
        vector<bool> visited(V, false);
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        Q.push({0, src});

        while (!Q.empty())
        {
            auto min = Q.top();
            Q.pop();

            int to = min.second;
            int edge_wt = min.first;

            if (visited[to] == true)
                continue;

            ans += edge_wt;
            visited[to] = true;

            for (auto x : l[to])
            {
                if (!visited[x.first])
                    Q.push({x.second, x.first});
            }
        }

        cout << "Cost of MST = " << ans << endl;
    }
};

int main()
{

    cout << "<--- Prims Algorithm Implementation --->" << endl
         << endl;

    int v = 6, e = 10;

    // cout << "Enter the no. of vertices and edges: ";
    // cin >> v >> e;

    Graph g(v);

    // cout << "\nEnter the edges (x,y,w): " << endl;

    // for (int i = 0; i < e; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x - 1, y - 1, w);
    // }

    g.addEdge(1 - 1, 2 - 1, 6);
    g.addEdge(1 - 1, 4 - 1, 5);
    g.addEdge(1 - 1, 3 - 1, 1);
    g.addEdge(2 - 1, 3 - 1, 5);
    g.addEdge(2 - 1, 5 - 1, 3);
    g.addEdge(3 - 1, 5 - 1, 6);
    g.addEdge(3 - 1, 4 - 1, 5);
    g.addEdge(3 - 1, 6 - 1, 4);
    g.addEdge(4 - 1, 6 - 1, 2);
    g.addEdge(5 - 1, 6 - 1, 6);

    g.prims(0);

    getch();
    return 0;
}