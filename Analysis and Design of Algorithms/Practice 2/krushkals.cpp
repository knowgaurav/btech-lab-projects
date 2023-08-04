#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s1];
            }
            else
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

class Graph
{
    int V;
    vector<vector<int>> edgeList;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int u, int v, int wt)
    {
        edgeList.push_back({wt, u, v});
    }

    void krushkals()
    {
        sort(edgeList.begin(), edgeList.end());

        int ans = 0;
        DSU s(V);

        for (auto edge : edgeList)
        {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (s.find(u) != s.find(v))
            {
                s.unite(u, v);
                ans += wt;
            }
        }

        cout << "Cost of MST = " << ans << endl;
    }
};

int main()
{
    Graph g(6);

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

    g.krushkals();

    getch();
    return 0;
}