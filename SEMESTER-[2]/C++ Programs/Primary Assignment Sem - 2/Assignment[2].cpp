#include<iostream>
using namespace std;
template <class T>
class Sort{
    public:
        bool swap(T &a, T &b){
            T temp = a;
            a = b;
            b = temp;
            return true;
        }
        void InsertionSort(T arr[], int n){
            for(int i=1;i<n;i++){
                T key = arr[i];
                int j = i-1;
                while(j>=0&&arr[j]>key){
                    arr[j+1] = arr[j];
                    j = j-1;
                }
                arr[j+1] = key;
            }
        }
        void BubbleSort(T arr[], int n){
            bool p = true;
            for(int i=0;i<n-1&&p==true;i++){
                p = false;
                for(int j=0;j<n-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        p = swap(arr[j],arr[j+1]);
                    }
                }
            }
        }
        void SelectionSort(T arr[], int n){
            for(int i=0;i<n-1;i++){
                T min = arr[i];
                int pos = i;
                for(int j=i+1;j<n;j++){
                    if(min>arr[j]){
                        min = arr[j];
                        pos = j;
                    }
                }
                if(pos!=i){
                    swap(arr[i],arr[pos]);
                }
            }
        }
        void display(T arr[], int n){
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        T* getData(int &n){
            cout<<"Enter the size of the array : ";
            cin>>n;
            cout<<"Enter the array elements : ";
            T *arr = new T[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            return arr;
        }
};
int main(){
    Sort<int> obj;
    int n;
    while(1){
        cout<<"1. Insertion Sort."<<endl;
        cout<<"2. Bubble Sort."<<endl;
        cout<<"3. Selection Sort."<<endl;
        cout<<"4. Exit."<<endl;
        cout<<"Enter your choice : ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:{
                auto arr = obj.getData(n);
                obj.InsertionSort(arr,n);
                obj.display(arr,n);
                delete[] arr;
                break;
            }
            case 2:{
                auto arr = obj.getData(n);
                obj.BubbleSort(arr,n);
                obj.display(arr,n);
                delete[] arr;
                break;
            }
            case 3:{
                auto arr = obj.getData(n);
                obj.SelectionSort(arr,n);
                obj.display(arr,n);
                delete[] arr;
                break;
            }
            case 4:{
                cout<<"You have exited the program.";
                return 0;
            }
            default:
                cout<<"Invalid input.";
        }
    }
    return 0;
}
