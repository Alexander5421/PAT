#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    const int Min = -100000000;
    const int Max = 100000000;

    int N, M;
    scanf("%d %d", &N, &M);
   // cin >> N >> M;
    vector<int> input;
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        input.push_back(temp);
    }

    // init
    int out_so_far = 0;
    vector<int> internal_m;
    
    for (int i = 0; i < M; i++)
    {
        internal_m.push_back(input[i]);

    }
    int point = M;
    int pre = Min; // last output
    string run = "";
    int index=0;
    while (out_so_far != N)
    {
        // each run;
        //int index=0;
        sort(internal_m.begin(), internal_m.end());
        bool flag = true;
        for (int i = index; i < internal_m.size(); i++)
        {
            if (internal_m[i] < pre)
            {
                index++;
                continue;
            }else// internal >=pre
           {
               run += to_string(internal_m[i]); // output one
               run += " ";
               pre = internal_m[i];
               if (point>=N)
               {
                   internal_m.erase(internal_m.begin() + i);
                   flag = false;
                    out_so_far++;
                     
                    break;

               }
               
               internal_m[i] = input[point++];

               //index = i+1;
               flag = false;
               out_so_far++;
               break;
           }
           
           
       }
       if (flag) // end of this run
       {
           run = run.substr(0, run.size() - 1);
           cout << run << endl;
           run = "";
           pre = Min;
           index = 0;
       }
       
       
       
           
       
   }
   if (run.size()!=0)
   {
       run = run.substr(0, run.size() - 1);
       cout << run << endl;

   }
   
   
    
    


    return 0;
}
