#include <iostream>
#include <vector>
using namespace std;
// return 1 if max_heap -1 if min_heap 0 if not a heap
//

void postorder(vector<int> &heap,int index,string& output){
    if (index>=heap.size()){
        return ;
    }
    postorder(heap,index* 2,output);
    postorder(heap,index* 2+1,output);
    output += to_string(heap[index]);
    output += " ";
}

int whether_heap(vector<int> heap){
    if (heap.size()<=2){
        return -1;
    }
    int ret = heap[1] > heap[2] ? 1 : -1;

    // 最后一个i 可能溢出
    // for (int i = 1; i < ((heap.size()-1)/2); i++)
    // {
    //     // test whether max heap
    //     if (ret==1){
    //         if (heap[i]>heap[2*i]&&heap[i]>heap[2*i+1])
    //         {
    //             continue;
    //             // this internal node follow the rule of heap
    //         }else
    //         {
    //             return 0;
    //             // not a heap
    //         }
            
    //     // test whether min heap    
    //     }else
    //     {
    //         if (heap[i]<heap[2*i]&&heap[i]<heap[2*i+1])
    //         {
    //             continue;
    //             // this internal node follow the rule of heap
    //         }else
    //         {
    //             return 0;
    //             // not a heap
    //         }
    //     }
        
    // }
    for (int i = 2; i < heap.size(); i++)
    {
        if (ret==1)
        {
            
            if (heap[i]<heap[i/2])
            {
                continue;
            }else
            {
                return 0;
            }    /* code */
        }else
        {
               if (heap[i]>heap[i/2])
            {
                continue;
            }else
            {
                return 0;
            }    /* code */
        }
        
        
        
        
        
    }
    
    return ret;
}
int main(int argc, char const *argv[])
{
    int ret;
    int M, N;
    cin >> M >> N;
    // M test cases
    for (int i = 0; i < M; i++)
    {
        // N key
        vector<int> heap(N+1,0);
        //input
        for (int i = 1; i < N+1; i++)
        {
            /* code */
            cin >> heap[i];
        }
        ret=whether_heap(heap);
        // output;
        switch (ret)
        {
        case 1:
            cout << "Max Heap" << endl;

            break;
        case 0:
            cout << "Not Heap" << endl;
            break;
        case -1:
            cout << "Min Heap" << endl;
            break;
        default:
            break;
        }
        string output="";
        postorder(heap, 1, output);
        cout << output.substr(0, output.size() - 1) << endl;
    }
    system("pause");
    return 0;
}
