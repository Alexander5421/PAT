#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int> numbers;
    set<int> kickied_players;
    int a, b;
    cin >> a>> b;
    numbers.insert(a);
    numbers.insert(b);


    int N, M;
    cin >> N>>M;
    
    vector<int> players[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            players[i].push_back(temp);
        }
        
        
    }
    
    // every round;
    for (int i = 0; i < M; i++)
    {
        vector<int> kicked;
        for (int j = 0; j < N; j++)
        {   
            if (kickied_players.find(j)!=kickied_players.end()){
                continue; // ignore
            }
            
            int number=players[j][i];

            if (numbers.find(number)!=numbers.end()){
                // already exist
                kickied_players.insert(j);
                kicked.push_back(j);
            }else
            {
                // not exist yet
                // check whether is a diffirence

                bool f1=false;
                for (auto element : numbers)
                {
                    int sum = element + number;
                    if (numbers.find(sum)!=numbers.end())
                    {
                        // is a differece
                        f1 = true;
                        numbers.insert(number);
                    }
                
                    
                    
                }
                // not a difference;
                if (!f1)
                {
                   kickied_players.insert(j);
                   kicked.push_back(j);
                }
                
                
            }
            
            

        }
        if (!kicked.empty())
        {
            sort(kicked.begin(), kicked.end());
            cout << "Round #" << i+1 << ":";
            for (int x = 0; x < kicked.size(); x++)
            {
                cout << " " << kicked[x]+1;
            }
            cout << " is out." << endl;
            //  cout << "Round #" << i+1 << ":";
            // cout << " " << kicked[0]+1;
            // cout << " is out." << endl;
            
        }
        

        
    }
    if (kickied_players.size()==N)
    {
        cout << "No winner." << endl;
    }else
    {
        vector<int> winner(N,1);
        for (auto elment : kickied_players)
        {
            winner[elment]= 0;
        }
        cout << "Winner(s):";
        for (int y = 0; y < N; y++)
        {
            if (winner[y])
            {
                cout << " " << y+1;
            }
            
        }
        
        
        
    }
    
    
    

    // int temp;
    // cin >> temp;

    return 0;
}
