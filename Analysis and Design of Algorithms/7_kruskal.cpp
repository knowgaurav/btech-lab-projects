#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

//Disjoint Set Union
class DSU
{
    int *parent;
    int *rank;

public:
    //Constructor
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

    //Find Parent Funtion
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    //Unite Funtion
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        //Both vertices have different parents
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList;
    int V;

public:
    Graph(int v)
    {
        this->V = v;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    int kruskalMST()
    {
        //Sorting based on weights
        sort(edgeList.begin(), edgeList.end());

        int ans = 0;

        DSU s(V);
        for (auto edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            //Check whether that edge form a cycle or not
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
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
        g.addEdge(x, y, w);
    }

    cout << endl;

    cout << "The cost of MST is: " << g.kruskalMST();

    getch();
    return 0;
}