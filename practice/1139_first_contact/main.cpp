#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;
bool a[300][300]; // 邻接矩阵
struct person
{
    int id; // also contain the informaioin about gender negative is girl
    int index=-1; // position in vertex array;
};

vector<person> v;
unordered_set<int> unqiue_people; // the reason use a set is when we record the person by relationship, there will be many repeat, so we need a set to make sure person are unique

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        person person1, person2;
        cin >> person1.id>>person2.id;
        int size = unqiue_people.size();
        unqiue_people.insert(person1.id);
        if (unqiue_people.size()>size)  // new person
        {
            person1.index = v.size();
            v.push_back(person1);
            
        }
        size = unqiue_people.size();
        unqiue_people.insert(person2.id);
          if (unqiue_people.size()>size)  // new person
        {
            person2.index = v.size();
            v.push_back(person2);
            
        }
        // mark in the martix;
        a[person1.index][person2.index] = true;
        a[person2.index][person1.index] = true;

    }
    unqiue_people.clear();
    // till now, we put people in the vector and based on the index in the vector,we create the matrix to store edge;
    int k;
    cin >> k;
    n = v.size();
    for (int i = 0; i < k; i++)
    {
        int A_id, B_id;
        cin >> A_id >> B_id;
        person A, B;
        for (int i = 0; i < v.size(); i++)// find two guy
        {
            if (v[i].id==A_id)
            {
                A = v[i];
                break;
            }

            
        }
          for (int i = 0; i < v.size(); i++)// find two guy
        {
            if (v[i].id==B_id)
            {
                B = v[i];
                break;
            }
            
        }
        if (A.index==-1||B.index==-1)
        {
            cout << 0 << endl;      // one of A,B don't have any friends
            continue;
        }
        vector<int> A_friends;  // store the index of A's friend
        vector<int> B_friends;  // store the index of B
        for (int i = 0; i < n; i++)
        {
            if(a[A.index][i]){
                if ((A.index<0 && v[i].index<0) || (A.index>=0 && v[i].index>=0))
                 A_friends.push_back(i);
                
            }
        }
         for (int i = 0; i < n; i++)
        {
            if ((B.index<0 && v[i].index<0) || (B.index>=0 && v[i].index>=0))
                B_friends.push_back(i);
            
        }
        for (auto C:A_friends)
        {
            vector
            for (int i = 0; i < n; i++){
                if(a[C][i])
            }
        }
        
        
    
    }
    


    return 0;
 }
 