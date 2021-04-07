#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node {int t1, t2;};
int main(int argc, char const *argv[])
{
    int N, M,K;
    cin >> N >> M;
    vector<node> v(M);
    for (size_t i = 0; i < M; i++)
    {   
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        v[i].t1 = vertex1;
        v[i].t2 = vertex2;
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
        for (node edge: v)
        {
            if (vertex[edge.t1]==vertex[edge.t2])
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
