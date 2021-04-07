#include <iostream>
#include<queue>

using namespace std;

// print all the vertex by bfs order
vector<int> neighbor(vector<vector<int>> graph, int vertex){
    vector<int> neighbors;
    for (size_t i = 0; i < graph[vertex].size(); i++)
    {
        if (graph[vertex][i]==1)
        {
            neighbors.push_back(i);
        }
        
        
    }

    return neighbors;
}

void BFS(vector<vector<int>> graph, int i)
{
    vector<bool> visited(5);   // base on index judge whether the vertex visited before
    priority_queue<int> q;
    q.push(i);
    visited[i]= true;
    while (!q.empty())
    {
        int curr = q.top();
        q.pop();
        cout << curr << " ";
        vector<int> neighbors = neighbor(graph,curr);
        // push all it's unvisited neighbors
        for (auto neighbor:neighbors)
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
            
        }
        
        
    }
    
}

int main(int argc, char const *argv[])
{
    int N = 5;
    vector<vector<int>> graph(N);
    //initialize
    for (size_t i = 0; i < N; i++)
    {
        graph[i].resize(N, 0);
    }
    // add edge
    int m;
    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    BFS(graph,0);

    return 0;
}
