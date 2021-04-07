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

int gcd(int a, int b){
    if (a<b){
        int temp;
        temp = a;
        a = b;
        b = temp; //switch to macksure a>b
    }

    /*below is using recursive method */
    // if (a%b==0)
    // {
    //     return b;
    // }else
    // {
    //     return gcd(b, a % b);
    // }
    /*loop is ok too */
    while (a%b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}
/*least common mutiple 
    input int a, int b
    return the lcm of a and b 
 */
 int lcm(int a, int b){
    return a * b / gcd(a, b);
}
void simple_form(int &a, int &b){
    int gcd_ = gcd(a, b);
    a = a / gcd_;
    b = b / gcd_;
}

int main(int argc, char const *argv[])
{
    // calculate a group of number's lcm.
    int N;
    scanf("%d", &N);
    int numerator[N] ;
    int denominator[N];
    int least_common_mulitple=1;
    // read all the fraction
    for (int i = 0; i < N; i++)
    {
        scanf("%d/%d", &(numerator[i]), &(denominator[i]));
    }
    // find the lcm of the denominator
    
    
    
    for(int a :denominator){
        if (a==0)
        {
            continue;
        }
        
        least_common_mulitple = lcm(least_common_mulitple, a);
    }  // let it be a function. 

    // we do the add in the same denominator lcm
    // so we need mutiply the numerator
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int mutiply = least_common_mulitple / denominator[i];
        numerator[i] = numerator[i] * mutiply;
        sum += numerator[i];
    }
    int interger = sum / least_common_mulitple;
    int numerator_out = sum % least_common_mulitple;
   

    if (interger==0)
    {
        if (numerator_out == 0)
        {
            cout << 0;
        }else
        {
            simple_form(numerator_out, least_common_mulitple);
            if (least_common_mulitple<0){
                numerator_out = -numerator_out;
                least_common_mulitple = -least_common_mulitple;
            }
            printf("%d/%d",numerator_out , least_common_mulitple);
        }
        
        
        
    }else 

    {
        if (numerator_out == 0){
            cout << interger;

        }else
        {
            if (least_common_mulitple<0){
            numerator_out = -numerator_out;
            least_common_mulitple = -least_common_mulitple;
            }
           simple_form(numerator_out, least_common_mulitple); 
           printf("%d %d/%d", interger, numerator_out, least_common_mulitple);
        }
        
        
    }

    
    
 


    return 0;
}

