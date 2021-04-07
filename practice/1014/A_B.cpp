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
const int INF=0x3f3f3f3f;

int main(int argc, char const *argv[])
{
    int A,B;
    float polynomial[1001];
    // initialize the array
    for (size_t i = 0; i < 1001; i++)
    {
        polynomial[i] = 0;
    }
    
    scanf("%d", &A);
    for (int i = 0; i < A; i++)
    {
        int key;
        float value;
        scanf("%d%f", &key, &value);
        polynomial[key] += value;



    }
    scanf("%d", &B);
    for (int i = 0; i < B; i++)
    {
        int key;
        float value;
        scanf("%d%f", &key, &value);
        polynomial[key] += value;



    }
    //output size
    int size = 0;
    for (int i = 0; i < 1001; i++)
    {
        if(polynomial[i]!=0)
        {
            size++;
        }
        
    }
    cout << size;
    for (int i = 1000; i >= 0; i--)
    {
          if(polynomial[i]!=0)
        {
            //cout <<setprecision(1)<< " " << i << " " << polynomial[i];
            printf(" %d %.1f",i,polynomial[i]);
        }
    }
    

    return 0;

}