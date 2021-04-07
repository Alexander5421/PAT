#include <algorithm>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


// 根据后序，中序遍历构建二叉树。


int post[50];
int inorder[50];


class treenode
{
public:
    int value=0;
    treenode *left=NULL;
    treenode *right=NULL;
};


//all function share two same array, the index locate each function subpostorder and subright order.
treenode* buildTree(int order_left_index,int order_rigth_index,int post_left_index,int post_right_index){
    //base case
    if ( order_left_index>order_rigth_index || post_left_index>post_right_index)   //leaf
    {
        return NULL;
    }
    treenode *root = new treenode;
    root->value = post[post_right_index];
    
    int index;
    // find the last element in the post order postion in inorder array.
    for (int i = order_left_index; i <=order_rigth_index; i++)
    {
        if (post[post_right_index]==inorder[i])
        {
            index = i;
            break;
        }
        
    }
    int numleft = index - order_left_index;

    root->left=buildTree(order_left_index, order_left_index + numleft - 1, post_left_index, post_left_index + numleft - 1); //left
    root->right=buildTree(index + 1, order_rigth_index, post_left_index + numleft, post_right_index - 1);
    return root; //right
}
// can print the tree by level_order by using bfs method;
string BFS(treenode* root){
    queue<treenode*> q;
    q.push(root);
    string ret="";
    while (!q.empty())
    {
        treenode *temp = q.front();
        ret += to_string(temp->value);

        ret += " ";
        q.pop();
        if (temp->left!=NULL)
        {
            q.push(temp->left);
        }
         if (temp->right!=NULL)
        {
            q.push(temp->right);
        }
        
        
        
        }

    return ret;
}


int main(int argc, char const *argv[])
 {


int n;
treenode *root; // binary tree root;
cin >> n;
for (int i = 0; i < n; i++)
{
    cin >> post[i];
}

for (int i = 0; i < n; i++)
{
    cin >> inorder[i];
}
root=buildTree(0, n - 1, 0, n - 1);


string output=BFS(root);
  if (output.back()==' '){
        output.erase(output.size()-1);
    }
cout << output;

return 0;
}
