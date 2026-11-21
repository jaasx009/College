//WAP to sort a list of elements. Give user the option to perform sorting using Insertion sort, Bubble sort or Selec on sort.
#include<iostream>
using namespace std;
class sort{
    private:
        int* arr;
        int n;
    public:
        sort(){
            arr = NULL;
            n = 0;
        }
        void getdata(){
            delete[] arr;
            arr = NULL;
            n = 0;
            cout<<"Enter the size of the array : ";
            cin>>n;
            arr = new int[n];
            cout<<"Enter the elements : ";
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
        }
        void display(){
            cout<<"The array elements are : \n";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void BubbleSort(){
            bool pass = true;
            for(int i=0;i<n-1&&pass==true;i++){
                pass = false;
                for(int j=0;j<n-1-i;j++){
                    if(arr[j]>arr[j+1]){
                        int t = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = t;
                        pass = true;
                    }
                }
            }
        }
        void SelectionSort(){
            for(int i=0;i<n-1;i++){
                int min = arr[i],pos = i;
                for(int j=i+1;j<n-1;j++){
                    if(arr[j]<min){
                        min = arr[j];
                        pos = j;
                    }
                }
                if(i!=pos){
                    int t = arr[i];
                    arr[i] = arr[pos];
                    arr[pos] = t;
                }
            }
        }
        void InsertionSort(){
            for(int i = 1;i<n;i++){
                int j = i-1;
                int key = arr[i];
                while(j>=0&&arr[j]>key){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;                
            }
        }
};
int main(){
    sort s;
    while(1){
        cout<<"1. Bubble Sort.\n";
        cout<<"2. Insertion Sort.\n";
        cout<<"3. Selection Sort.\n";
        cout<<"0. Exit.\n";
        cout<<"Enter your choice : ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                s.getdata();
                s.BubbleSort();
                s.display();
                break;
            case 2:
                s.getdata();
                s.InsertionSort();
                s.display();
                break;
            case 3:
                s.getdata();
                s.SelectionSort();
                s.display();
                break;
            case 0:
                cout<<"You have exited the program.\n";
                return 0;
            default:
                cout<<"Invalid choice.\n";
        }
    }
    return 0;
}











































