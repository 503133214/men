#include<iostream>
#include<algorithm>
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
void insertSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bobuleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]>arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
void selectSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){
    int arr[10],n=10;
    randomArr(arr,n);
    printArr(arr,n);
    bobuleSort(arr,n);
    printArr(arr,n);
    return 0;
}