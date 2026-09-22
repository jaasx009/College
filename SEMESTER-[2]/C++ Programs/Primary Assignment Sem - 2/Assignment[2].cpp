#include<iostream>
using namespace std;
template <class T>
class Sort{
    bool swap()
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
            for(int j=0;i<n-i-1;j++){
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
            for(int j=i+1;j<n-1;j++){
                if(arr[j]<min){
                    min = arr[j];
                    pos = j;
                }
            }
            if(pos!=i){
                swap(a[i],a[pos]);
            }
        }
    }
};
