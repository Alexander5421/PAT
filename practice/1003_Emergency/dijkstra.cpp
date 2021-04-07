#include <iostream>
#include<queue>

using namespace std;
#define max 10000
vector<int> parent[505];

class vertex{
    public:
        int index = 0; // index in the vertexs vector;
        int distance = max;
       
        int team = 0;

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

void Dijkstra(vector<vector<int>> graph,int src,int dest,vector<vertex>& vertexs){

    // 初始化
    vertexs[src].distance = 0;
    parent[src].push_back(src); //self loop
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
        if (curr.index==dest)
        {
            break;
        }
        

        vector<int> neighbors = neighbor(graph, curr.index);
        for (int i = 0; i < neighbors.size(); i++)
        {
            vertex& n = vertexs[neighbors[i]];
            if (!visited[n.index])   
            {
                 if (n.distance==curr.distance + graph[curr.index][n.index])
                 {
                     parent[n.index].push_back(curr.index);
                 }
                 
                 if (n.distance>curr.distance + graph[curr.index][n.index]){
                     //update
                     parent[n.index].clear();
                     parent[n.index].push_back(curr.index);
                     n.distance = curr.distance + graph[curr.index][n.index];
                     q.push(n);
                 }
            }
            
            
            
        }
        

    }
    

}
int roads(int dest,int src){
    if (dest==src)
    {
        return 1;
    }
    
    int sum=0;
    for (size_t i = 0; i < parent[dest].size(); i++)
    {
        sum+=roads(parent[dest][i],src);

    }
    return sum;
}
int max_rescue_team(int dest,int src,vector<vertex> vertexs){
    if (dest==src)
    {
        return vertexs[dest].team;
    }
    int Max = 0;
    for (size_t i = 0; i < parent[dest].size(); i++)
    {
        int temp = max_rescue_team(parent[dest][i], src, vertexs);
        if (temp>Max){
            Max = temp;
        }
    }
    return Max + vertexs[dest].team;
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

    
    // add edge
    int m,src,dest;
    cin >> m;
    cin >> src >> dest;
    for (int i = 0; i < N; i++)
    {
        vertexs[i].index = i;
        cin >> vertexs[i].team;
    }
    for (size_t i = 0; i < m; i++)
    {
        int v1, v2;
        int length;
        cin >> v1 >> v2>>length;
        graph[v1][v2] = length;
        graph[v2][v1] = length;
    }
    Dijkstra(graph,src,dest,vertexs);

    cout << roads(dest, src)<<" ";
    cout << max_rescue_team(dest, src, vertexs);
    return 0;
}
