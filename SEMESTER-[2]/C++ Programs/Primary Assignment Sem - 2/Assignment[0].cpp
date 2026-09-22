/* Write a program to search an element from a list. Give user the op on to perform Linear 
or Binary search. */
#include<iostream>
using namespace std;
class Search{
    private:
        int *arr,n,key;
    public:
        Search(){
            arr=NULL;
            n=0;
            
        }
        void GetData(){
            cout<<"Enter the size : ";
            cin>>n;
            cout<<"Enter the array elements : "<<endl;
            arr=new int[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
        }
        int LinearSearch(){
            cout<<"Enter the key value : ";
            cin>>key;
            for(int i=0;i<n;i++){
                if(key==arr[i])
                    return i+1;
            }
            return -1;
        }
        int BinarySearch(){
            cout<<"Enter the key value : ";
            cin>>key;
            int low=0;
            int high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(key==arr[mid])
                    return mid+1;
                else if(key<arr[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            return -1;
        }
        ~Search(){
            delete[] arr;
        }
};
int main(){
    Search s;
    int choice,res;
    do{
        cout<<"1. Linear Search."<<endl;
        cout<<"2. Binary Search."<<endl;
        cout<<"3. To Quit The Program."<<endl;
        cout<<"Enter you choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                s.GetData();
                res=s.LinearSearch();
                break;
            case 2 :
                cout<<"To do the Binary Search Enter the array elements in ascending order --- "<<endl;
                s.GetData();
                res=s.BinarySearch();
                break;
            case 3 :
                cout<<"You have exited the program.";
                break;
            default :
                cout<<"Invalid choice.";
        }
        if((choice==1)||(choice==2)){
            if(res==-1)
                cout<<"Value is not found.";
            else
                cout<<"The Key Value is at "<<res<<" position."<<endl;
        }
    }while(choice!=3);
    
    return 0;
}