#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;
struct edge
{
    int goods1;
    int goods2;
    edge(int a, int b) : goods1(a), goods2(b){};
};

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<edge> incompatible;
    for (int i = 0; i < N; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        incompatible.push_back(edge(t1, t2));
    }
    for (int i = 0; i < M; i++) // each list
    {
        int K;
        cin >> K;
        set<int> list;
        for (int j = 0; j < K; j++) //item on the list
        {
            int v;
            cin >> v;
            list.insert(v);
            
        }
        //check;
        bool flag = 0;
        for (edge e:incompatible)
        {
            if (list.count(e.goods1)&&list.count(e.goods2))   // both in the list
            {
                cout << "No" << endl;
                flag= 1;
                break;
            }
            
            
        }
        if (!flag)
        {
            cout << "Yes" << endl;
        }
        
        
        
    }
    
    
    return 0;
}