#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        //swap
        char temp;
        temp = s.front();
        s[0] = s.back();
        *(--s.end()) = temp;
        
    }
};
struct foo
{
      /* data */
    char x;
    float y;
};


int main(int argc, char const *argv[])
{
    vector<char> s = {'a', 'b'};
    Solution Solution1;
    Solution1.reverseString(s);
    for (auto i : s)
    {
        cout << i;
    }
    struct foo f;
    f.x;

    return 0;
}
