#include<iostream>
#include<vector>
using namespace std;
class edge{
    public:
        int left, right;
};
int a[10000][10000]={0};

int main(int argc, char const *argv[])
{
    int N, M,K;
    cin >> N>>M;

    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2]=1;
        a[v2][v1]=1;
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        int total_degree=0;
        int a1[10000][10000]={};
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                a1[j][k] = a[j][k];
            }
            
        }
        for (int x = 0; x < n; x++)
        {
            
            int v1;

            
            
            cin >> v1;
            for (int j = 0; j < N; j++)
            {
                total_degree += a1[v1][j];
                a1[j][v1] = 0;
            }
            
        }
        if (total_degree==M)
        {
            cout << "Yes"<<endl;
        }else
        {
            cout << "No"<<endl;
            /* code */
        }
        
        
    }
    
    
    

    return 0;
}
