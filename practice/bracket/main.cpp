#include<stack>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    stack<char> depth;
    int dep = 0;
    for (auto character : s)
    {
        if (character=='(')
        {
            depth.push(1);
        }
        if (character==')')
        {
            depth.pop();
        }
        if (dep<depth.size())
        {
            dep = depth.size();
        }
        
    }
    cout<< dep;
    return 0;
}

