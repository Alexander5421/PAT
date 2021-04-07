#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    bool black; // 1 black 0 red
    int value;
    node *left=NULL;
    node *right=NULL;
};
bool red_black(node* root){
    if (root==NULL)
    {
        return true;
    }
    if (!root->black)
    {
        if (root->left != NULL && !root->left->black) return false;
        if (root->left != NULL && !root->right->black) return false;

    }
    

    return (red_black(root->left) && red_black(root->right));
}
// tell us the height of a node
int height(node* root){
    if (root==NULL)
    {
        return 1;
    }
    return max(height(root->left), height(root->right)) + root->black;
}
// test whether the tree is balanced or not every node has to be balanced;
// it's better to store the height of tree in the node.
// bool balanced(node* root){
//     if (root==NULL)
//     {
//         return true;
//     }
//     int c = abs(height(root->left) - height(root->right));
//     if (c<2)
//     {
//         return (balanced(root->left) && balanced(root->right));
//     }
//     return false;
// }
bool balanced(node* root){
    if (root==NULL)
    {
        return true;
    }
    int c = height(root->left) - height(root->right);
    if (c==0)
    {
        return (balanced(root->left) && balanced(root->right));
    }
    return false;
}
node* insert(node* root,int value){
    if (root==NULL)
    {
        node *temp = new node;
        temp->value = abs(value);
        if (value<0)
        {
            temp->black = 0;
        }else{
            temp->black = 1;
        }
        
        
        return temp ;
    }else if (abs(value)>(root->value))
    {
        root->right = insert(root->right, value);
    }else
    {
        root->left = insert(root->left, value);
        
    }
    return root;
}

int main(int argc, char const *argv[])
{
   
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)// each test case
    {
        node *root = NULL;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            root = insert(root, value);
        }
        // after build tree 
        // verify
        if(balanced(root) && red_black(root)&&root->black){
            cout << "Yes" << endl;
        }else
        {
            cout << "No" << endl;
            /* code */
        }
        
    }
    



    return 0;
}

