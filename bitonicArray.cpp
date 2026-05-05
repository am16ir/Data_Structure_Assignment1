#include <iostream>
#include <vector>

using namespace std;

void selectionSortDescending(std::vector<int>& arr, int left, int right) {
    int n = right;
    for (int i = left; i < n - 1; i++) {
        int max_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            swap(arr[i], arr[max_idx]);
        }
    }
}

void bubbleSort(vector<int>& arr, int left, int mid) {
    int n = mid + 1;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void bitonicSort(vector<int>& arr) {
    int n = arr.size();
    int mid = n/2;
    bubbleSort(arr, 0, mid);
    selectionSortDescending(arr, mid+1, n);
}

int linearSearch(vector<int>& v, int target) {
    for(int i = 0;i<v.size();i++) {
        if(v[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> v = {15, 2, 8, 1, 7, 4, 6, 3};
    bitonicSort(v);
    int bitonic = max(v[v.size()/2], v[(v.size()/2) + 1]);
    cout<<"BITONIC POINT (value = "<<bitonic<<")"<<endl;
    cout<<"BITONIC sorted array:"<<endl;
    for(int el: v) cout<<el<<' ';

    int bPnt = linearSearch(v, 15);
    cout<<'\n'<<bPnt;


    return 0;
}
