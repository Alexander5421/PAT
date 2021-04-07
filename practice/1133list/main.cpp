#include<iostream>
#include<vector>
using namespace std;
class listnode
{
  
public:
    int index, next, data;
};

listnode a[100001];

int main(int argc, char const *argv[])
{
    int start, N, K;
    cin >> start >> N >> K;
    vector<listnode> origin,answer;
    for (int i = 0; i < N; i++)
    {
        int Address, Data, Next;
        cin >> Address >> Data >> Next;
        a[Address].index = Address;
        a[Address].data = Data;
        a[Address].next = Next;
    }
    
    // i is the address
    for (int i = start; i !=-1; i=a[i].next)
    {
        origin.push_back(a[i]);
    }
    // put content in v to answer;
    answer.resize(N);
    int j=0;
    for (int i = 0; i < N; i++)
    {
        if (origin[i].data<0)
        {
            answer[j] = origin[i];
            j++;
        }
        
    }
    for (int i = 0; i < N; i++)
    {
         if (origin[i].data>=0&&origin[i].data<=K)
        {
            answer[j] = origin[i];
            j++;
        }
    }
    for (int i = 0; i < N; i++)
    {
          if (origin[i].data>K)
        {
            answer[j] = origin[i];
            j++;
        }
    }
    for (int i = 0; i < N-1;i++)
    {
        listnode node = answer[i];
        printf("%05d %d %05d\n",node.index,node.data,answer[i+1].index);
    }
    listnode lastnode = answer[N-1];
        printf("%05d %d %d\n",lastnode.index,lastnode.data,-1);

       // system("pause");

        return 0;
}
