#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        int a, b,length,c;
        length = input.size();
        c = stoi(input);
        a = stoi(input.substr(0, length / 2));
        b = stoi(input.substr(length/2, length / 2));
       // cout << a <<" "<< b << endl;
       if (!(a*b))
       {
           cout << "No" << endl;
           continue；
       }
       
        if (c%(a*b)==0)
        {
            cout << "Yes" << endl;
        }else
        {
            cout << "No" << endl;
            /* code */
        }
        
        
    }
    


    return 0;
}
