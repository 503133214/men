#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int n){
    cout<<"arr now is ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void randomArr(int arr[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
}
int main(){
    return 0;
}