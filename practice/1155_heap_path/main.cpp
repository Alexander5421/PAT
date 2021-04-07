#include<iostream>
#include<vector>
using namespace std;
const int maxn=1005;
vector<int> v(maxn);
vector<int> vf;
int n;
void f(int s){//打印经过第s节点的所有路径
    // leaf
    vf.push_back(v[s]);
    if((s*2>n)&&(s*2+1>n)){
        
        for(int i=0;i<vf.size();i++){
            if(i!=0)printf(" ");
            printf("%d",vf[i]);
        }
        printf("\n");
    vf.pop_back();
        return;
    
    }
   if (s*2+1<n)
   {
       f(s * 2 + 1);
   }
   if (s*2){
        f(s * 2);
   }
   
    
    
    vf.pop_back();
}
int main(){
    int minheap=1,maxheap=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(i>1 && v[i/2]<v[i])maxheap=0;
        if(i>1 && v[i/2]>v[i])minheap=0;
    }
    f(1);
    if(minheap==1)printf("Min Heap\n");
    else printf("%s\n",maxheap==1?"Max Heap":"Not Heap");
    return 0;
}