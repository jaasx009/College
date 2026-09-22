#include<iostream>
using namespace std;
class Matrix{
    private:
        int n,*arr;
    public:
        Matrix(int size){
            n=size;
            arr = new int[n*(n+1)/2];
        }
        void setDiagonal(int i,int j,int x){
            if(i==j) arr[i]=x;
        }
        void setLower(int i,int j,int x){
            if(i>=j) arr[i*(i+1)/2+j]=x;
        }
        void setUpper(int i,int j,int x){
            if(i<=j) arr[n*i-(i*(i-1)/2)+(j-i)]=x;
        }
        void setSymmetric(int i,int j,int x){
            (i>=j)?arr[i*(i+1)/2+j]=x:arr[j*(j+1)/2+i]=x;
        }
        int getDiagonal(int i,int j){
            return (i==j)?arr[i]:0;
        }
        int getLower(int i,int j){
            return (i>=j)?arr[i*(i+1)/2+j]:0;
        }
        int getUpper(int i,int j){
            return (i<=j)?arr[n*i-i*(i-1)/2+(j-i)]:0;
        }
        int getSymmetric(int i,int j){
            return (i>=j)?arr[i*(i+1)/2+j]:arr[j*(j+1)/2+i];
        }
        void display(int type){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(type==1) cout<<getDiagonal(i,j)<<" ";
                    else if(type==2) cout<<getLower(i,j)<<" ";
                    else if(type==3) cout<<getUpper(i,j)<<" ";
                    else if(type==4) cout<<getSymmetric(i,j)<<" ";
                }
                cout<<endl;
            }
        }
        ~Matrix(){delete[] arr;}
};
int main(){
    int n,choice,x;
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    Matrix M(n);
    cout<<"1. Diagonal Matrix.";
    cout<<"\n2. Lower Triangular Matrix.";
    cout<<"\n3. Upper Triangular Matrix.";
    cout<<"\n4. Symmetric Matrix.";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Enter the elements : ";
            for(int i=0;i<n;i++){
                cin>>x;
                M.setDiagonal(i,i,x);
            }
            M.display(1);
            break;
        case 2:
            cout<<"Enter the elements : ";
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++){
                    cin>>x;
                    M.setLower(i,j,x);
                }
            }
            M.display(2);
            break;
        case 3:
            cout<<"Enter the elements : ";
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    cin>>x;
                    M.setUpper(i,j,x);
                }
            }
            M.display(3);
            break;
        case 4:
            cout<<"Enter the elements : ";
            for(int i=0;i<n;i++){
                for (int j=0;j<=i;j++){
                    cin>>x;
                    M.setSymmetric(i,j,x);
                }
            }
            M.display(4);
            break;
        default:
            cout<<"Invalid Choice.";
    }
    return 0;
}