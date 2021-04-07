#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void LCA(int u,int v,vector<int>preorder,vector<int>inorder){
    // first locate the root;
    int root = preorder[0];
    int location;
    if (u<root && v>root)
    {
        printf("LCA of %d and %d is %d", u, v, root);
        return;
    }
    if (u==root)
    {
        printf("%d is an ancestor of %d." ,u, v);
        return;
    }
    if (v==root)
    {
        printf("%d is an ancestor of %d." ,v, u);
        return;
    }// u==v?
    
      for (int i = 0; i < inorder.size(); i++)
    {
        if (root==inorder[i])
        {
            location = i;
        }
    }
    if (v<root&&u<root)
    {
        auto it = preorder.begin() + 1;

        vector<int> next_preorder(it, it+location);
        vector<int> next_inorder(inorder.begin(), inorder.begin()+location);

        return LCA(u, v, next_preorder, next_inorder);
    }
     if (v>root&&u>root)
    {
        

        vector<int> next_preorder(preorder.begin()+location+1, preorder.end());
        vector<int> next_inorder(inorder.begin()+location+1, inorder.end());

        return LCA(u, v, next_preorder, next_inorder);
    }
     

    
    
    

    // // auto it=find(inorder.begin(),inorder.end(),root);
  
        
    // }
    // if

    
}
int main(int argc, char const *argv[])
{
    int M, N;
    cin >> M >> N;
    vector<int> preorder;
    set<int> keys;
    //get the preorder
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
         preorder.push_back(temp);
         keys.insert(temp);
    }
    //sort
    vector<int> inorder( preorder);

    sort(inorder.begin(), inorder.end()); // asending
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u>>v;
        bool f1, f2;
        f1 = false;
        f2 = false;
        if (keys.find(u)==keys.end()){
            f1 = true;   /// u not found
        }
        if (keys.find(v)==keys.end()){
            f2 = true;   /// v not found
        }
        if (f1&&f2)
        {
            cout << "ERROR: " << u << " and " << v << " are not found.";

        }else if (f1)
        {
            cout << "ERROR: " << u << " is not found.";
        }else if (f2)
        {
            cout << "ERROR: " << v << " is not found.";
            /* code */
        }else if (u==v)
        {
             printf("%d is an ancestor of %d." ,u, v);
        }
        
        else
        {
            LCA(u, v, preorder, inorder);
        }
        

        
        

        
    
        
    }

    

    return 0;
}
