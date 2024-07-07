// early stop, if every element is in a proper order

#include <iostream>

using namespace std;
void bubble_sort(int arr[], int n){
    bool flag = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                flag = 0;
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;

            }
        }
        if(flag==1) break;
    }
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