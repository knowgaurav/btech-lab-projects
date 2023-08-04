#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>

using namespace std;

#define N 5
#define INF INT_MAX

class Node
{
public:
    vector<pair<int, int>> path;
    int matrix_reduced[N][N];
    int cost;
    int vertex;
    int level;
};

Node *newNode(int matrix_parent[N][N], vector<pair<int, int>> const &path, int level, int i, int j)
{
    Node *node = new Node;
    node->path = path;
    if (level != 0)
        node->path.push_back(make_pair(i, j));
    memcpy(node->matrix_reduced, matrix_parent,
           sizeof node->matrix_reduced);
    for (int k = 0; level != 0 && k < N; k++)
    {
        node->matrix_reduced[i][k] = INF;
        node->matrix_reduced[k][j] = INF;
    }

    node->matrix_reduced[j][0] = INF;
    node->level = level;
    node->vertex = j;
    return node;
}

void reduce_row(int matrix_reduced[N][N], int row[N])
{
    fill_n(row, N, INF);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < row[i])
                row[i] = matrix_reduced[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && row[i] != INF)
                matrix_reduced[i][j] -= row[i];
}

void reduce_column(int matrix_reduced[N][N], int col[N])
{
    fill_n(col, N, INF);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < col[j])
                col[j] = matrix_reduced[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && col[j] != INF)
                matrix_reduced[i][j] -= col[j];
}

int cost_calculation(int matrix_reduced[N][N])
{
    int cost = 0;

    int row[N];
    reduce_row(matrix_reduced, row);

    int col[N];
    reduce_column(matrix_reduced, col);

    for (int i = 0; i < N; i++)
        cost += (row[i] != INT_MAX) ? row[i] : 0,
            cost += (col[i] != INT_MAX) ? col[i] : 0;

    return cost;
}

void printPath(vector<pair<int, int>> const &list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list[i].first + 1 << " -> ";

    cout << list[0].first + 1;
}

class comp
{
public:
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

int solve(int adjacensyMatrix[N][N])
{
    priority_queue<Node *, vector<Node *>, comp> pq;
    vector<pair<int, int>> v;
    Node *root = newNode(adjacensyMatrix, v, 0, -1, 0);
    root->cost = cost_calculation(root->matrix_reduced);
    pq.push(root);
    while (!pq.empty())
    {
        Node *min = pq.top();
        pq.pop();
        int i = min->vertex;
        if (min->level == N - 1)
        {
            min->path.push_back(make_pair(i, 0));
            printPath(min->path);
            return min->cost;
        }

        for (int j = 0; j < N; j++)
        {
            if (min->matrix_reduced[i][j] != INF)
            {
                Node *child = newNode(min->matrix_reduced, min->path,
                                      min->level + 1, i, j);

                child->cost = min->cost + min->matrix_reduced[i][j] + cost_calculation(child->matrix_reduced);

                pq.push(child);
            }
        }

        delete min;
    }

    return -1;
}

int main()
{
    int adjacensyMatrix[N][N] =
        {
            {INF, 7, 3, 12, 8},
            {3, INF, 6, 14, 9},
            {5, 8, INF, 6, 18},
            {9, 3, 5, INF, 11},
            {18, 14, 9, 8, INF}};

    cout << "Path is: ";
    int cost = solve(adjacensyMatrix);
    cout << "\n\nCost is: " << cost;

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// vector<int> ans;

// int reduce(vector<vector<int>> &adj) {
//     int cost = 0;
//     for(int i=0; i<adj.size(); i++) {
//         int minRow = *min_element(adj[i].begin(), adj[i].end());
//         if(minRow == INT_MAX)
//             continue;

//         cost += minRow;

//         for(int j=0; j<adj[0].size(); j++) {
//             if(adj[i][j] != INT_MAX)
//                 adj[i][j] -= minRow;
//         }
//     }

//     for(int j=0; j<adj[0].size(); j++) {
//         int minCol = INT_MAX;
//         for(int i=0; i<adj.size(); i++) {
//             minCol = min(minCol, adj[i][j]);
//         }
//         if(minCol == INT_MAX)
//             continue;

//         cost += minCol;

//         for(int i=0; i<adj.size(); i++) {
//             if(adj[i][j] != INT_MAX)
//                 adj[i][j] -= minCol;
//         }
//     }

//     return cost;
// }

// vector<vector<int>> transformRow(vector<vector<int>> adj, int i) {
//     for(int j=0; j<adj[0].size(); j++)
//         adj[i][j] = INT_MAX;

//     return adj;
// }

// vector<vector<int>> transformColumn(vector<vector<int>> adj, int i) {
//     for(int j=0; j<adj[0].size(); j++)
//         adj[j][i] = INT_MAX;

//     return adj;
// }

// void findPath(vector<vector<int>> adj, int start, int cost, vector<bool> visited) {
//     visited[start] = true;
//     vector<vector<int>> transformed = transformRow(adj, start);

//     pair<int, int> minPair = {0, INT_MAX};

//     for(int i=0; i<adj[0].size(); i++) {
//         if(visited[i] || adj[start][i] == INT_MAX)
//             continue;

//         vector<vector<int>> colTransformed = transformColumn(transformed, i);
//         colTransformed[i][start] = INT_MAX;

//         int c = reduce(colTransformed) + adj[start][i];

//         if(c < minPair.second)
//             minPair = {i, c};
//     }

//     if(minPair.second == INT_MAX)
//         return;

//     ans.push_back(minPair.first);
//     transformed[minPair.first][start] = INT_MAX;
//     transformed = transformColumn(transformed, minPair.first);

//     findPath(transformed, minPair.first, cost+minPair.second, visited);
// }

// int main() {
//     cout << "Enter the number of vertices: ";
//     int n;  cin>>n;

//     vector<vector<int>> adj (n, vector<int> (n, INT_MAX));

//     cout << "Enter the adjacency matrix" << endl;
//     for(auto &vec: adj) {
//         for(auto &it: vec) {
//             cin >> it;
//             if(it == -1)
//                 it = INT_MAX;
//         }
//     }

//     vector<vector<int>> adj1 = adj;
//     int initialReduction = reduce(adj);
//     vector<bool> visited (n, false);

//     ans.push_back(0);

//     findPath(adj, 0, initialReduction, visited);

//     cout << "\nMin Path for salesman: ";
//     for(const auto &it: ans)
//         cout << it << " -> ";

//     cout << 0 << endl;
//     ans.push_back(0);

//     int start = 0, sum=0;
//     for(int i=1; i<ans.size(); i++) {
//         sum += adj1[start][ans[i]];
//         start = ans[i];
//     }

//     cout << "Min Cost = " << sum << endl;
// }