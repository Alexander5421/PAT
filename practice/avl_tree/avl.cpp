
#include<iostream>
using namespace std;

class treenode
{
public:
    int value=0;
    treenode *left=NULL;
    treenode *right=NULL;
    
};
int height(treenode* n){
    if (n==NULL){
        return -1;
    }else
    {
        return max(height(n->left), height(n->right)) + 1;
    }
    
}

treenode *reconstrction(treenode *A, treenode *B, treenode *C, treenode *T0, treenode *T1, treenode *T2, treenode *T3){
    B->left = A;
    B->right = C;
    A->left = T0;
    A->right = T1;
    C->left = T2;
    C->right = T3;
    return B;

}

// the parameter v is the node which is first unbalanced.
treenode* left_rotation(treenode* v){       
    treenode *A = v;
    treenode *B = A->right;             
    A->right = B->left;
    B->left = A;
    return B;
}
// another implementation of roatation
treenode * right_rotation(treenode* v){
     treenode *C = v;
     treenode *B = C->left;
     treenode *A = B->left;
     treenode *T0 = A->left;
     treenode *T1 = A->right;
     treenode *T2 = B->right;
     treenode *T3 = C->right;
     return reconstrction(A, B, C, T0, T1, T2, T3);

}
treenode * left_right_rotation(treenode* v){
     treenode *C = v;
     treenode *B = v->left->right;
     treenode *A = v->left;
     treenode *T0 = A->left;
     treenode *T1 = B->left;
     treenode *T2 = B->right;
     treenode *T3 = C->right;
     return reconstrction(A, B, C, T0, T1, T2, T3);
}
treenode * right_left_rotation(treenode* v){
     treenode *C = v->right;
     treenode *B = v->right->left;
     treenode *A = v;
     treenode *T0 = A->left;
     treenode *T1 = B->left;
     treenode *T2 = B->right;
     treenode *T3 = C->right;
     return reconstrction(A, B, C, T0, T1, T2, T3);
    
}

treenode* insert(int value,treenode* curr) { 
    if (curr==NULL)
    {
        treenode *temp = new treenode;
        temp->value = value;
        return temp;
    }else if (curr->value<value)        // 当前值小于插入值 插入右边
    {
        curr->right=insert(value, curr->right);
        int left_height = height(curr->left);
        int right_height = height(curr->right);
        if ((left_height-right_height)==-2)
        {   
            if(value>curr->right->value){
                return left_rotation(curr);
            }else
            {
                return right_left_rotation(curr);
            }
        }
        
    }else   // (curr->value>value)      // 插入左边
    {
        curr->left=insert(value, curr->left);
         int left_height = height(curr->left);
        int right_height = height(curr->right);
           if ((left_height-right_height)==2)
        {   
            if(value<curr->left->value){
                return right_rotation(curr);
            }else
            {
                return left_right_rotation(curr);
            }
        }
        
    }
    return curr;

}

int main(int argc, char const *argv[])
{
    treenode *root = NULL;
    // avl
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        root=insert(temp, root);
    }
    cout << root->value;
    system("pause");
    return 0;

}
