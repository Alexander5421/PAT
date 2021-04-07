#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int address, data, next;
};
node a[100001];


int main(int argc, char const *argv[])
{
    int start1, start2, N;
    cin>>start1>>start2>> N;
    for (int i = 0; i < N; i++)
    {
        int index;
        
        cin >> index;
        a[index].address = index;
        cin >> a[index].data >> a[index].next;
    }
    // get all the node
    // sort to find two list
    vector<node> L1,L2,answer;
    for (int i = start1; i!=-1; i=a[i].next)
    {
        L1.push_back(a[i]);
    }
    
    for (int i = start2; i!=-1; i=a[i].next)
    {
        L2.push_back(a[i]);
    }
    
    if (L1.size()>L2.size())
    {
        int j = L2.size()-1;
        int i = 0;
        while (j>=0)
        {

            answer.push_back(L1[i++]);
            answer.push_back(L1[i++]);
            answer.push_back(L2[j--]);

        }
        // add remain i;
        while (i<L1.size())
        {
            answer.push_back(L1[i++]);
            
        }
        
    }else
    {
        int j = L1.size()-1;
        int i = 0;
        while (j>=0)
        {

            answer.push_back(L2[i++]);
            answer.push_back(L2[i++]);
            answer.push_back(L1[j--]);

        }
        // add remain i;
        while (i<L2.size())
        {
            answer.push_back(L2[i++]);
            
        }
    }
    
        for (int i = 0; i < answer.size()-1;i++)
        {
           node node1 = answer[i];
            printf("%05d %d %05d\n",node1.address,node1.data,answer[i+1].address);
        }
        node lastnode = answer[answer.size()-1];
            printf("%05d %d %d\n",lastnode.address,lastnode.data,-1);

         system("pause");            

    return 0;
}
