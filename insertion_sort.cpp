#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    //if(n==1) return;
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void insertion_sort_recursive(int arr[], int n){
   
    if(n<=1) return;
    insertion_sort_recursive(arr,n-1);
    int key = arr[n];
    int j = n - 2;
    while(j>=0&&arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;

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
    insertion_sort(arr,n);
    cout<<"Sorted array : ";
    print_arr(arr,n);
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr)/sizeof(arr[0]);
    insertion_sort_recursive(arr2,n2);
    cout<<"Recursively sorted array : ";
    print_arr(arr,n);

}