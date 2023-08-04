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
            auto it = s.begin();
            int node = it->second;
            int nodeDist = it->first;
            s.erase(it);

            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (nodeDist + currentEdge < dist[nbr])
                {
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    dist[nbr] = nodeDist + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        for (int i = 0; i < V; i++)
            cout << "Minimum Distance from " << src << " to " << i << " = " << dist[i] << endl;

        return dist[dest];
    }
};

int main()
{
    int v, e;
    cout << "Enter the number of vertex: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph g(v);

    cout << endl;

    for (int i = 0; i < e; i++)
    {
        int to, from, wt;
        cout << "Enter the nodes and weight b/w them: ";
        cin >> to >> from >> wt;
        g.addEdge(to, from, wt);
    }

    int src, dest;
    cout << "\nEnter the src vertex: ";
    cin >> src;
    cout << "Enter the dest vertex: ";
    cin >> dest;

    cout << endl;
    int minDist = g.dijkshtra(src, dest);

    // cout << "\nMinimum Distance = " << minDist;

    getch();
    return 0;
}