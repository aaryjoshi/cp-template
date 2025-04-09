#include<bits/stdc++.h>
typedef vector<int> vi;
int n;

vi visited(n + 1, 0), tin(n + 1, 0), low(n + 1, 0);
int timer = 0;
set<array<int, 2>> bridges;
auto getBridges = [&](int node, int parent, auto &&self)
{
    visited[node] = 1;
    tin[node] = low[node] = ++timer;
    int parentSkipped = 0;
    for (auto neigbour : graph[node])
    {
        if (neigbour == parent && parentSkipped == 0){
            parentSkipped = 1;
            continue;
        }
        if (visited[neigbour] == 1){
            low[node] = min(low[node], tin[neigbour]);
            continue;
        }
        self(neigbour, node, self);
        low[node] = min(low[node], low[neigbour]);
        if (low[neigbour] <= tin[node])
            continue;
        bridges.insert({node, neigbour});
        bridges.insert({neigbour, node});
    }
};

//for (int i = 1; i <= n; i++)
//if (visited[i] != 1) getBridges(i, 0);
