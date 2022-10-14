#include <bits/stdc++.h>
using namespace std;
int indegree[6];
int weight[6][6];
void AddEdge(int adj[6][6], int u, int v, int num)
{
    adj[u][v] = 1;
    weight[u][v] = num;
    indegree[v]++;
}
vector<int> v;
void TopologicalSort(int adj[6][6],int indegree[])
{
    queue<int> q;
    bool visited[6];
    for (int i = 0; i < 6;i++)
    {
        visited[i] = false;
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        v.push_back(a);
        visited[a] = true;
        for (int i = 0; i < 6;i++)
        {
            if(adj[a][i]==1&&visited[i]==false)
            {
                visited[i] = true;
            }
                indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
}
int dist[6];
void Shortest(int adj[6][6], int u)
{
    dist[u] = 0;
    for (int i = 0; i < 6;i++)
    {
        for (int j = 0; j < 6;j++)
        {
            if(adj[v[i]][j]==1)
            {
                if(dist[j]>dist[v[i]]+weight[v[i]][j])
                {
                    dist[j] = dist[v[i]] + weight[v[i]][j];
                }
            }
        }
    }
}
int main()
{
    int n;
    // cin >> n;
    int adj[6][6];
    for (int i = 0; i < 6; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < 6; i++)
    {
        dist[i] = INT_FAST16_MAX;
    }
    for (int i = 0; i < 6;i++)
    {
        for (int j = 0; j < 6;j++)
        {
            weight[i][j] = 0;
            adj[i][j] = -1;
        }
    }
    AddEdge(adj, 0, 1, 2);
    AddEdge(adj, 1, 2, 3);
    AddEdge(adj, 2, 3, 6);
    AddEdge(adj, 0, 4, 1);
    AddEdge(adj, 4, 2, 2);
    AddEdge(adj, 4, 5, 4);
    AddEdge(adj, 5, 3, 1);
    TopologicalSort(adj, indegree);
    Shortest(adj, 0);
    // distance of each node from 0 node;
    for (int i = 0; i < 6;i++)
    {
        cout << dist[i] << " ";
    }
}
