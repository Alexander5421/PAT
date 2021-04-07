#include <algorithm>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include<stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;



// 根据先序中序

string ret="";

class treenode
{
public:
    int value=0;
    bool left_test = true; // first time, we add the child to the left
    treenode *left=NULL;
    treenode *right=NULL;
    treenode(int value) : value(value){}; 
};
void post(treenode *root){
    if (root==NULL){
        return;
    }
    post(root->left);
    post(root->right);
    ret += to_string(root->value);
    ret += " ";
}

int main(int argc, char const *argv[])
 {


int n;
treenode *root=NULL; // binary tree root;
treenode *just_pop=NULL;
cin >> n;
stack<treenode *> s;
for (int i = 0; i < 2*n; i++)
{
    string input;
    cin >> input;
    int value;
    if (input=="Push")
    {
        cin >> value;
       // treenode* prev = s.top();
        treenode *curr = new treenode(value);
        

        if (root!=NULL){
            treenode *prev;
            if (just_pop==NULL){
                 prev= s.top();
            }else
            {
                prev = just_pop;
                just_pop = NULL;
            }
            
            if (prev->left_test){
                prev->left = curr;
                prev->left_test = false;
            }else

            {
                prev->right = curr;
            }
              // connect
           
        }else
        {
            root = curr;
        }
        
        s.push(curr); 
        

    }else{
        just_pop = s.top();
        s.pop();
        }
    

}       //pop
post(root);
 if (ret.back()==' '){
        ret.erase(ret.size()-1);
    }
cout << ret;
system("pause");

}
