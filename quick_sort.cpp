#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick_sort(vector<int>& arr,int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quick_sort(arr, low, pi-1);
        quick_sort(arr,pi+1,high);

    }
}

void quick_sort(vector<int>& arr){
    int n = arr.size();
    quick_sort(arr,0,n-1);
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    quick_sort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}