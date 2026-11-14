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
            cout<<"Enter the array size : ";
            cin>>n;
            cout<<"Enter the array elements : ";
            arr = new int[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
        }
        int BinarySearch(){
            cout<<"Enter the key value : ";
            cin>>key;
            int low = 0;
            int high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(key == arr[mid]){
                    return mid+1;
                }
                else if(key<arr[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return -1;
        }
        ~Search(){
            delete[] arr;
        }
};
int main(){
    Search s;
    int res;
    s.getdata();
    res = s.BinarySearch();
    if(res==-1){
        cout<<"Key not found.";
        return 0;
    }
    else{
        cout<<"Key found at "<<res<<" position.";
        return 0;
    }

}