#include <bits/stdc++.h>

using namespace std;

int comp , swaps;

void selection_sort(vector<int>&v , int start , int n){
    for (int i = start ;i < n ; i++){
        int greatest = i;
        for (int j = i+1 ; j < n ;j++){
            comp++;
            if (v[greatest] < v[j]) {
                greatest = j;
            }
        }
        swap (v[greatest] , v[i]);
        swaps++;
    }
}


void bubble_sort(vector<int>&v , int n){
    bool swapped;
    for (int i = 0 ; i < n ; i++){
        swapped = false;
        for (int j = n; j > i; j--){
            comp++;
            if (v[j] < v[j - 1]){
                swaps++;
                swap(v[j] , v[j-1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void bitonic_sort(vector<int>&v , int n){
    bubble_sort(v , n/2);
    selection_sort(v , n/2 + 1 , n);
}

void print_bitonic_array(vector<int>&v , int n){
    cout << "Bitonic array: ";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i != n - 1) cout << ", ";
    }
}

int linear_search(vector<int>&v , int target){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> v = {8, 1, 4, 12, 6, 3, 7, 3, 9};
    int n = v.size();

    bitonic_sort(v , n);

    int bitonic_element = max(v[n / 2], v[n / 2 + 1]);
    cout<< "Bitonic element: " << bitonic_element << endl;

    print_bitonic_array(v , n);

    cout << endl;
    cout << "Number of comparisons: " << comp << endl;
    cout << "Number of swaps: " << swaps << endl;

    cout << "Target(12) at the bitonic point: ";
    int res = -1;
    res = linear_search(v , 12);
    cout << res << endl;

    cout << "Target(8) in the left half: ";
    res = linear_search(v , 8);
    cout << res << endl;

    cout << "Target(3) in the right half: ";
    res = linear_search(v , 3);
    cout << res << endl;

    cout << "Target(2) not present in the array: ";
    res = linear_search(v , 2);
    cout << res << endl;

    cout << "Target(3) is duplicate element ";
    res = linear_search(v , 3);
    cout << res << endl;

    return 0;
}