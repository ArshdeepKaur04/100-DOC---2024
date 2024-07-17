/*
Question:
"Distance Summation" on HackerRank
You are given a tree with N vertices. The i-th edge connects vertices ui and vi bidirectionally. Additionally, you
are given an integer sequence A = (A1,..., AN).

Here, define f(i, j) as follows:
- If Ai = Aj, then f(i, j) is the minimum number of edges you need to traverse to move from vertex i to vertex j. 
- If Ai != Aj, then f(i, j) = 0

Calculate the value of the given expression.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
int A[MAXN];

int bfs(int start, int target) {
    vector<int> distance(MAXN, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) {
            return distance[node];
        }

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return -1; // Should not happen if the tree is connected
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sum = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[i] == A[j]) {
                sum += bfs(i, j);
            }
        }
    }

    cout << sum << endl;

    return 0;
}