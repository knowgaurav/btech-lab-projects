#include <iostream>
#include <conio.h>
#include <set>
#include <vector>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});
        if (undir)
            l[v].push_back({wt, u});
    }

    void dijkshtra(int src)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);

        s.insert({0, src});
        dist[src] = 0;

        while (!s.empty())
        {
            auto min = s.begin();
            int node = min->second;
            int wt = min->first;
            s.erase(min);

            for (auto nbr : l[node])
            {
                int nbr_node = nbr.second;
                int edge_weight = nbr.first;

                if (wt + edge_weight < dist[nbr_node])
                {
                    auto f = s.find({edge_weight, nbr_node});
                    if (f != s.end())
                        s.erase(f);

                    dist[nbr_node] = wt + edge_weight;
                    s.insert({dist[nbr_node], nbr_node});
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << "Min Distance from " << src << " to " << i << " = " << dist[i] << endl;
    }
};

int main()
{
    int v = 5, e = 6;

    Graph g(v);

    // g.addEdge(0, 1, 2);
    // g.addEdge(0, 3, 3);
    // g.addEdge(0, 5, 2);
    // g.addEdge(1, 2, 2);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 2);
    // g.addEdge(2, 4, 2);
    // g.addEdge(3, 4, 4);
    // g.addEdge(4, 5, 3);

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 7);

    g.dijkshtra(2);

    getch();
    return 0;
}