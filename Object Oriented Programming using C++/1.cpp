#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void dfs(int currentNode, vector<vector<int>> &edges, int parentNode){
    cout << currentNode << " ";

    for(int neighbour : edges[currentNode]){
        if(neighbour != parentNode){
            dfs(neighbour, edges, currentNode);
        }
    }
}

int main()
{
    init_code();

    int n; cin>>n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());

    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, edges, -1);

    return 0;
}