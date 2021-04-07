#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct edge
{
    int region1;
    int region2;
};

int main(int argc, char const *argv[])
{
    int N,R,K; // N the number of regions
    //R (≥0), the number of neighboring relations
    //and K (0<K≤N), the number of species of animals.
    cin >> N >> R >> K;
    vector<edge> edges;
    // get all the relationships
    for (int i = 0; i < R; i++)
    {
        int r1, r2;
        cin >> r1 >> r2;
        edge temp;
        temp.region1 = r1;
        temp.region2 = r2;
        edges.push_back(temp);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        // each test
        set<long int> specials;
        vector<int> distribution(N);
        for (int j = 0; j < N; j++)
        {
            //record the distribution first;
            int temp;
            cin >> temp;

            distribution[j] = temp;
            specials.insert(temp);
        }
        // check number of specials;
        if (specials.size()<K)
        {
            cout << "Error: Too few species." << endl;
            continue; // next test
        }else if (specials.size()>K)
        {
            cout << "Error: Too many species." << endl;
            continue;
        }else
        {
             // check every edge
             bool flag = false;
             for (auto single_edge : edges)
             {

                 if (distribution[single_edge.region1-1] == distribution[single_edge.region2-1])
                 {
                     cout << "No" << endl;
                     flag = true;
                     break;
                 }
                
            }
            if (!flag)
            {
                cout << "Yes" << endl;
            }
            
             
        }
        
        
        
       
        
        

    }
    

    return 0;
}
