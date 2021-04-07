#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, M,K;
    cin >> N >> M;
    vector<pair<int, int>> edges;
    //edge
  
    for (size_t i = 0; i < M; i++)
    {   
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        edges.push_back(pair<int,int>(vertex1, vertex2));
    }

    

    cin >> K;
    for (size_t i = 0; i < K; i++)
    {
        bool k_color=true;
        set<int> color;
        vector<int> vertex(N); //index means which vertex, value means color
        for (size_t i = 0; i < N; i++)
        {
            int color_index;
            cin >> color_index;
            color.insert(color_index);
            vertex[i] = color_index;
        }
        for (auto edge: edges)
        {
            if (vertex[edge.first]==vertex[edge.second])
            {
                k_color = false;
                break;
            }
            
        }
        if (k_color)
        {
            cout << color.size() << "-coloring" << endl;
        }else
        {
            cout << "No" << endl;
        }
        

   
   }
   

   return 0;
}
