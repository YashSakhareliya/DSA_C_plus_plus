#include <iostream>

using namespace std;

// create class for heap

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size = size+1;
        arr[size] = data;

        int index = size;
        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }

    // deletion in heap
    void deleteVal(){
        if(size == 0){
            cout<<"No value present heap"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            int leftIndex = i*2;
            int rightIndex = i*2+1;

            if(leftIndex < size && arr[leftIndex] > arr[i]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex] > arr[i]){
                swap(arr[i], arr[rightIndex]);
                i =rightIndex;
            }else{
                return;
            }
        }
    }
};
int main() {
    
    heap a;
    a.insert(50);
    a.insert(55);
    a.insert(30);
    a.insert(60);
    a.insert(10);
    a.print();
    cout<<endl;

    a.deleteVal();
    a.print();
    return 0;
}

