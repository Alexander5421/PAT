#include <iostream>
using namespace std;

bool isprime(int n){
    if (n<2)
    {
        return false;
    }
    for (int i = 2; i*i <=n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
        
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string input;

    cin >> input;
    bool final = true;
    for (int i = 0; i < 8; i++)
    {
        string temp = input.substr(i, 8 - i);
        int test = stoi(temp);
        cout << temp << " ";
        if (isprime(test))
        {
            cout << "Yes" << endl;
        }else
        {
            cout << "No" << endl;
            final = false;
        }
        
        
    }
    if (final)
    {
        cout << "All Prime!" << endl;
    }
    
    return 0;


}

             50                             60                               60
           /     \         delete(50)      /   \        delete(50)          /   \   
          40      70       --------->    40    70       --------->        40    70   
                 /  \                         /  \                              /  \
                60   80                      50   80                           65  80 
                 \                            \
                  65                          65

         