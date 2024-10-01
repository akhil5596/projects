#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> iPair;
void shortestPath(int src, vector<vector<iPair>> &adj, int V)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Vertex\t\tDistance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}
int main()
{
    int V = 9;
    vector<vector<iPair>> adj(V);
    adj[0].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(7, 8));
    adj[1].push_back(make_pair(0, 4));
    adj[1].push_back(make_pair(2, 8));
    adj[1].push_back(make_pair(7, 11));
    adj[2].push_back(make_pair(1, 8));
    adj[2].push_back(make_pair(3, 7));
    adj[2].push_back(make_pair(5, 4));
    adj[2].push_back(make_pair(8, 2));
    adj[3].push_back(make_pair(2, 7));
    adj[3].push_back(make_pair(4, 9));
    adj[3].push_back(make_pair(5, 14));
    adj[4].push_back(make_pair(3, 9));
    adj[4].push_back(make_pair(5, 10));
    adj[5].push_back(make_pair(2, 4));
    adj[5].push_back(make_pair(3, 14));
    adj[5].push_back(make_pair(4, 10));
    adj[5].push_back(make_pair(6, 2));
    adj[6].push_back(make_pair(5, 2));
    adj[6].push_back(make_pair(7, 1));
    adj[6].push_back(make_pair(8, 6));
    adj[7].push_back(make_pair(0, 8));
    adj[7].push_back(make_pair(1, 11));
    adj[7].push_back(make_pair(6, 1));
    adj[7].push_back(make_pair(8, 7));
    adj[8].push_back(make_pair(2, 2));
    adj[8].push_back(make_pair(6, 6));
    adj[8].push_back(make_pair(7, 7));

    int source = 0;
    shortestPath(source, adj, V);

    return 0;
}
