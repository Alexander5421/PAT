#include<iostream>
using namespace std;
bool palindrome(string input){
    string reverse="";
    for (auto i = input.rbegin(); i != input.rend(); i++)
    {
        reverse += *i;
    }
    if (reverse==input)
    {
        return 1;
    }
    return 0;
}
string reverse(string input){
    string reverse="";
    for (auto i = input.rbegin(); i != input.rend(); i++)
    {
        reverse += *i;
    }
    return reverse;
}
int main(int argc, char const *argv[])
{

    string C_string;
    cin >> C_string;
     if (palindrome(C_string))
        {
            cout << C_string << " is a palindromic number."<<endl;
            system ("pause");
            return 0;
        }
    


    long long A,B,C;

   
    // 10 time iteration

    for (size_t i = 0; i < 10; i++)
    {
        A = stoll(C_string);
        string C_reverse=reverse(C_string);
        B = stoll(C_reverse);
        C = A + B;
        cout << C_string << " + " << C_reverse << " = " << C<<endl;
        C_string = to_string(C);
        if (palindrome(C_string))
        {
            cout << C_string << " is a palindromic number."<<endl;
            system ("pause");
            return 0;
        }
    }
     cout << "Not found in 10 iterations.";
        system ("pause");
    return 0;
}
