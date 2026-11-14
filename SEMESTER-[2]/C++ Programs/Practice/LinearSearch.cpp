#include<iostream>
using namespace std;
class Search{
    private:
        int *arr,n,key;
    public:
        Search(){
            arr = nullptr;
            n = 0;
            key = 0;
        }
        void getdata(){
            cout<<"Enter the size : ";
            cin>>n;
            cout<<"Enter the array elements : ";
            arr = new int[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
        }
        int LinearSearch(){
            cout<<"Enter the key element : ";
            cin>>key;
            for(int i=0;i<n;i++){
                if(arr[i]==key){
                    return i+1;
                }
            }
            return -1;
        }
        ~Search(){
            delete[] arr;
        }
};
int main(){
    int res;
    Search s;
    s.getdata();
    res = s.LinearSearch();
    if(res==-1){
        cout<<"Value not found.";
        return 0;
    }
    else{
        cout<<"The value is at "<<res<<" position.";
        return 0;
    }
}