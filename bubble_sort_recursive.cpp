#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    if(n==1) return;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble_sort(arr, n-1);
}

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    cout<<"Sorted array : ";
    print_arr(arr,n);

}