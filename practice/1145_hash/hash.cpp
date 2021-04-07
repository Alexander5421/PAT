#include<iostream>
#include<math.h>
#include<vector>
//#include<bits/stdc++.h>
#include<string> 
using namespace std;
bool isprime(int n){
    if (n<2)
    {
        return false;
    }
    
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i==0)
        {
            return false;
        }
        
    }
    return true;
}


int main(int argc, char const *argv[])
{
    // int msize, n, m;
    // cin >> msize >> n >> m;
    // //resize msize;
    // while (!isprime(msize))
    // {
    //     msize++;
    // }
    // int Tsize = msize;
    // vector<int> table(Tsize,0);
    // //insertion
    // for (int i = 0; i < n; i++)
    // {
    //     //each insertion
    //     int input;
    //     int flag=0;
    //     cin >> input;
    //     for (int j = 0; j < Tsize; j++)
    //     {
    //        if(table[(input+j*j)%Tsize]==0){
    //            table[(input + j * j) % Tsize] = input;
    //            flag = 1;
    //            break;
    //        }
           
    //     }
    //     if (!flag)
    //     {
    //         cout << input << " cannot be inserted."<<endl;
    //     }
        
        
        
    // }
    // // search
    // int total_time = 0;
    // for (int i = 0; i < m; i++)
    // {
    //     int input;
    //     cin >> input;
    //     //i*i
    //     int time = 0;
    //     for (int j = 0; j <= Tsize; j++)
    //     {
    //          if(table[(input+j*j)%Tsize]==input){
    //              time = j+1;
    //              break;
    //        }
    //             if(table[(input+j*j)%Tsize]==0){
    //                 time = j+1;
    //                 break;
    //         }

           
    //     }
    //     // not found
    //     if (time==0)
    //     {
    //         time = Tsize+1;
    //     }
    //     total_time += time;
    // }
    // printf("%.1f", total_time / (double)m);
    // string a = "FuckSSdlkJl";
    cout << (char)toupper('s') << endl;

    return 0;
}
