#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
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
                rank[s1] += rank[s2];
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
    vector<pair<int, int>> *l;
    vector<vector<int>> edgelist;

public:
    // Constructor
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    // Adding edges
    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
        edgelist.push_back({w, x, y});
    }

    // Prim's Algorithm
    int primsAlgo(int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        bool *visited = new bool[V]{0};
        int ans = 0;

        Q.push({0, 0}); // weight, node

        while (!Q.empty())
        {
            // Getting the edge with minimum weight
            auto min_edge = Q.top();
            // Poping the element
            Q.pop();
            // Adjacent Node and edge weight
            int to = min_edge.second;
            int weight = min_edge.first;

            // If it is visited then don't do any opertion
            if (visited[to] == 1)
                continue;

            // else add the edge weight to the ans i.e. selecting that edge in the MST
            ans += weight;
            visited[to] = 1; // Marking the adjacent node as visited

            // Pushing all the unvisited nbrs into the priority queue
            for (auto nbr : l[to])
            {
                if (visited[nbr.first] == 0)
                    Q.push({nbr.second, nbr.first});
            }
        }

        // return the cost of the MST
        return ans;
    }

    int kruskalsAlgo()
    {
        sort(edgelist.begin(), edgelist.end());

        int ans = 0;

        DSU d(V);

        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (d.find(x) != d.find(y))
            {
                d.unite(x, y);
                ans += w;
            }
        }

        return ans;
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

    cout << "\n\nCost of the MST for the given graph using Prim's Algo = " << g.primsAlgo(0);
    cout << "\n\nCost of the MST for the given graph using Krushkal's Algo = " << g.kruskalsAlgo();

    // Ans = 15

    getch();
    return 0;
}