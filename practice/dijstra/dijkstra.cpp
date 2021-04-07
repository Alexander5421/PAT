#include <iostream>
#include<queue>

using namespace std;
#define max 10000


class vertex{
    public:
        int index = 0; // index in the vertexs vector;
        int distance = max;
        int parent = -1;

        friend bool operator<(vertex a, vertex b) // define what is priority_queue;
        {
            if (a.distance > b.distance)
            {
                return true;
            }else
            {
                return false;
            }
    }
    
};

// matrix to store the edges
int edges[501][501];
// print all the vertex by bfs order

vector<int> neighbor(vector<vector<int>> graph, int vertex){
    vector<int> neighbors;
    for (size_t i = 0; i < graph[vertex].size(); i++)
    {
        if (graph[vertex][i]!=0)
        {
            neighbors.push_back(i);
        }
        
        
    }

    return neighbors;
}
// the vertexs will be changed and we can get shorest path from vertexs

void Dijkstra(vector<vector<int>> graph,int src,vector<vertex>& vertexs){

    // 初始化
    vertexs[src].distance = 0;
    vertexs[src].parent = src; //self loop
    vector<bool> visited(vertexs.size());
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }
    
    priority_queue<vertex> q;
    q.push(vertexs[src]);
    

    // while 直到优先队列为空 或者找到终点 看情况
    while (!q.empty())
    {
        
        vertex curr=q.top();
        if(visited[curr.index]){
            q.pop();
            continue;
        }
        q.pop();
        visited[curr.index] = 1;

        vector<int> neighbors = neighbor(graph, curr.index);
        for (int i = 0; i < neighbors.size(); i++)
        {
            vertex& n = vertexs[neighbors[i]];
            if (!visited[n.index])   
            {
                 if (n.distance>curr.distance + graph[curr.index][n.index]){
                     //update
                     n.parent = curr.index;
                     n.distance = curr.distance + graph[curr.index][n.index];
                     q.push(n);
                 }
            }
            
            
            
        }
        

    }
    

}


int main(int argc, char const *argv[])
{
    
    int N  ;
    cin >> N;
    vector<vertex> vertexs(N);
    vector<vector<int>> graph(N);
    //initialize
    for (size_t i = 0; i < N; i++)
    {
        graph[i].resize(N, 0);
    }
    for (int i = 0; i < N; i++)
    {
        vertexs[i].index = i;
    }
    
    // add edge
    int m;
    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        int v1, v2;
        int length;
        cin >> v1 >> v2>>length;
        graph[v1][v2] = length;
        graph[v2][v1] = length;
    }
    Dijkstra(graph,0,vertexs);

    return 0;
}
