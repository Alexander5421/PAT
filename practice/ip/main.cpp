#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s) {
        // write code here
        
        int length=s.length();
        // divide into four part
        
       vector<string> a;
       a=divide(s, 4);
       return a;      
        
    }
    // return all possible devide case
    // time should bigger than 0
    vector<string> divide(string s,int time){
        vector<string>result;
        int length=s.length();
        if((length>time*3)||(length<time)){
            vector<string> a;
            return a;    //return a empty vector 
        }
        int max=255;
        int min=0;
        if (time==1)
        {
            int test=stoi(s.substr(0),NULL,10);
             if (test<=max && test>=min){
                 if (s.substr(0).length()>1 && s.front()=='0')
                 {
                     return result;
                 }
                 
               result.push_back(s.substr(0));    
           }
           return result;
        }
        
        for (int i=1;i<=3&&i<=length;i++){
           int test=stoi(s.substr(0,i),NULL,10);

           if (test<=max && test>=min&& time>1){
               if (s.substr(0,i).length()>1 && s.front()=='0')
                 {
                     continue;
                 }
               vector <string> possible=divide(s.substr(i),time-1);
               if (possible.empty()){
                   continue; 
               }else{
                    for (auto number : possible)
                    {
                        result.push_back(s.substr(0,i)+'.'+number);
                    }
               }
               
           }
        //    if (test<=max && test>=min&& time==1){
        //        result.push_back(s.substr(0,i));    
        //    }
        }
        return result;
        
    }
};







int main(int argc, char const *argv[])
{
    Solution a;
    vector<string> res;
    string s;
    cin >> s;
    res=a.restoreIpAddresses(s);
    for (auto s1 : res)
    {
        cout << s1<<endl;
    }
    
    return 0;
}
