#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph
{
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        bool *visited = new bool[V]{0};
        int ans = 0;

        Q.push({0, 0});

        while (!Q.empty())
        {
            auto min = Q.top();
            Q.pop();

            int to = min.second;
            int weight = min.first;

            if (visited[to])
            {
                continue;
            }

            ans += weight;
            visited[to] = 1;

            for (auto x : l[to])
            {
                if (visited[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }

        return ans;
    }
};

int main()
{
    // cout << "<--- C++ Kruskal Algorithm --->\n\n";
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << endl;

    Graph g(v);

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cout << "Enter the nodes and weight b/w them: ";
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }

    cout << endl;

    cout << "The cost of MST using Prim's Algo is: " << g.prim_mst();

    getch();
    return 0;
}