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
// 给定树结构和value,建立平衡二叉树
class array_tree{
    public:
        int value;
        int l_child;
        int r_child;
        array_tree() : value(0){};
        //array_tree(int value) : value(value){};
};
array_tree bst[100];    // store the tree struction using array
int value[100];
int value_index = 0;
// fill the value into tree;
void inorder(int index){
    if (bst[index].l_child!=-1)
    {
        inorder(bst[index].l_child);
    }
    
    
    bst[index].value = value[value_index];
    value_index++;
    if (bst[index].r_child!=-1)
    {
        inorder(bst[index].r_child);
    }
    return;
}
string BFS(){
    queue<int> q;
    q.push(0);
    string ret="";
    while (!q.empty())
    {
        int temp = q.front();
        ret += to_string(bst[temp].value);

        ret += " ";
        q.pop();
        if (bst[temp].l_child!=-1)
        {
            q.push(bst[temp].l_child);
        }
         if (bst[temp].r_child!=-1)
        {
            q.push(bst[temp].r_child);
        }
        
        
        
        }

    return ret;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {

        cin >> bst[i].l_child;
        cin >> bst[i].r_child;

    }
    // list line input
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];

    }
    sort(value, value + n);
    //   for (int i = 0; i < n; i++)
    // {
    //     cout << value[i]<<" ";

    // }
    inorder(0); // refill the tree start from root

    string output;
    output = BFS();
     if (output.back()==' '){
        output.erase(output.size()-1);
    }
    cout << output;


    return 0;

}



