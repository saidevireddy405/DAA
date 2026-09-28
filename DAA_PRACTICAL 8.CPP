#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

// DFS function
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    // Visit all connected nodes
    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

// BFS function
void BFS(int start, vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    // Start from the given vertex
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Visit all connected nodes
        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int vertices, edges;

    // Get number of vertices
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create graph
    vector<vector<int>> graph(vertices);

    // Get number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Get edges
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Get starting vertex
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // ---------------- DFS ----------------

    vector<bool> visited(vertices, false);

    auto dfsStart = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);

    auto dfsEnd = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(dfsEnd - dfsStart);

    // ---------------- BFS ----------------

    auto bfsStart = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    BFS(start, graph);

    auto bfsEnd = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(bfsEnd - bfsStart);

    // ---------------- Result ----------------

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns";

    return 0;
}