#include <iostream>
#include <conio.h>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdge(int to, int from, int wt)
    {
        l[to].push_back({wt, from});
        l[from].push_back({wt, to});
    }

    int dijkshtra(int src, int dest)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {
            auto min = s.begin();
            int node = min->second;
            int nodeDist = min->first;
            s.erase(min);

            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int edgeWeight = nbrPair.first;

                if (nodeDist + edgeWeight < dist[nbr])
                {
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                        s.erase(f);

                    dist[nbr] = nodeDist + edgeWeight;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << "Min dist from " << src << " to " << i << " = " << dist[i] << endl;
        }

        return dist[dest];
    }
};

int main()
{
    int v = 5, e = 6;

    Graph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);

    cout << "\n"
         << g.dijkshtra(0, 4) << endl;

    getch();
    return 0;
}