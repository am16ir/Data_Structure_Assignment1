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
    for (int i = 0 ; i < n ; i++){
        for (int j = n; j > i; j--){
            comp++;
            if (v[j] < v[j - 1]){
                swaps++;
                swap(v[j] , v[j-1]);
            }
        }
    }
}


int main() {
    cout<<"Enter Size of the array: ";
    int n;
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the array: ";
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    bubble_sort(v,n/2);
    selection_sort(v,n/2 + 1, n);

    int bitonic_element = v[0];
    for (int i = 1;i < v.size();i++){
        if (v[i] < v[i-1]){
            bitonic_element = v[i-1];
            break;
        }
    } 
    cout<<"bitonic array: ";
    for (int x : v)cout<<x<<" ";
    cout<<"\nEnter a target to search: ";
    int target;
    cin>>target;

    bool found = 0;
    for (int i = 0;i<n;i++){
        if (v[i] == target){
            cout<<"Found at index "<<i<<"\n";
            found = 1;
            break;
        }
    }
    if (!found)cout<<-1<<"\n";
    cout<<"bitonic element: "<<bitonic_element<<"\n";
    cout<<"number of comparisons: "<<comp<<" and swaps :"<<swaps<<"\n";
    return 0;
}