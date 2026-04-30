#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int>v={1, 2, 3, 4 ,3};
    int n = v.size();
    
    vector<int>ans(n);
    for (int i = 0;i < n;i++){
        int x = -1;
        for (int j = (i+1)%n; j != i ; j = (j+1)%n){
            if (v[j] > v[i]){
                x = v[j];
                break;
            }
        }
        ans[i] = x;
    }
    
    for(int x : ans){
        cout<<x<<" ";
    }
    return 0;
}