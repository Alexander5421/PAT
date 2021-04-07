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
//ping ying of digit
const string py[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const string bignumber[5] = {"Yi", "Wan", "Qian", "Bai", "Shi"};
int main(int argc, char const *argv[])
{
    bool special_zero=false; // when it's true we need output a zero if we face a non-zero value
    int edgecase = 0;
    string number;
    int index = 0;
    string output=""; 
    cin >> number;
    int size = number.size();
    if(number[0]=='-'){
        size--;
        output+="Fu ";
        index++;
    }
    if (size==9){
        output+=py[number[index]-'0']+" ";
        output+=bignumber[0]+" ";
        index++;
        size--;
    }
    switch (size)
    {
    case 8:
        if (number[index]=='0'){
            special_zero = true;
            edgecase++;
        }else
        {
            output+=py[number[index]-'0']+" ";
            output+=bignumber[2]+" "; //qiang
        }
        index++;
    case 7:
        if (number[index]=='0'){
            special_zero = true;
            edgecase++;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            output+=bignumber[3]+" "; //bai
        }
        index++;

    case 6:
        if (number[index]=='0'){
            special_zero = true;
            edgecase++;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            output+=bignumber[4]+" "; //shi
        }
        index++;
    case 5:
        if (number[index]=='0'){
            special_zero = true;
            edgecase++;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            
        }
        if (edgecase!=4)
        {
            output+=bignumber[1]+" "; //wang
            special_zero = 0; // 
        }
        
  
        index++;
    case 4:   
        if (number[index]=='0'){
            special_zero = true;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            output+=bignumber[2]+" "; //qian
        }
        index++;        
     case 3:
        if (number[index]=='0'){
            special_zero = true;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            output+=bignumber[3]+" "; //bai
        }
        index++; 
     case 2:  
         if (number[index]=='0'){
            special_zero = true;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            output+=bignumber[4]+" "; //shi
        }
        index++; 
     case 1:
        if (size==1)
        {
            output+=py[number[index]-'0']+" ";
            break;
        }
        
          if (number[index]=='0'){
            special_zero = true;
        }else
        {   
            if (special_zero)
            {
                output += py[0]+" ";
                special_zero = 0;
            }
            
            output+=py[number[index]-'0']+" ";
            
        }
     
    
    default:
        break;
    }
    if (output.back()==' '){
        output.erase(output.size()-1);
    }

    cout << output;
    system("pause");
    return 0;
   
}
