#include <iostream>
#include<math.h>
using namespace std;

bool prime(int test){
    if (test<2)
    {
        return false;
    }
    int temp = (int)sqrt(test);
    for (int i = 2; i <=temp ; i++)
    {
      
        if (test % i==0)
        {
            return false;
        }
        
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string N;
    int L, K;
    cin >> L >> K;
    cin >> N;
    for (int i = 0; i <= L-K; i++)
    {
        int test = stoi(N.substr(i, K));
        if (prime(test))
        {
            cout << N.substr(i, K);
            return 0;
        }
        
    }
    cout << "404" << endl;
    return 0;
    
}
