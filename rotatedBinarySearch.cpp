#include <bits/stdc++.h>

using namespace std;

int comp_cnt = 0;

int binary_search(vector<int>& v, int target, int l, int h) {
    
    if (l > h){
        comp_cnt++;
        return -1;
    } 
    
    int mid = (h + l) / 2;  
    
    if (target == v[mid]){
        comp_cnt++;
        return mid;
    } 
    
    else if (target < v[mid]){
        comp_cnt++;
        return binary_search(v, target, l, mid - 1);
    } 
    
    else {
        comp_cnt++;
        return binary_search(v, target, mid + 1, h);
    }
    
}

int search_rotated(vector<int>& v, int target, int peak){
    if (target >= v[0]){
        comp_cnt++;
        return binary_search(v , target , 0 ,peak);
    }
    else{
        comp_cnt++;
        return binary_search(v , target , peak + 1 , v.size() - 1);
    }
}

int main() {
    cout << "Hello, World!" << endl;
    vector<int>v =  {5 , 6, 6 , 6 , 7, 7 , 1 , 2, 3 ,4};
    int peak = 0;
    for (int i = 1 ; i < v.size(); i++){
        if (v[peak] <= v[i]){
            comp_cnt++;
            peak = i;
        }
    }
    cout<<peak<<"\n";
    cout << search_rotated(v , 6 , peak)<<"\n";
    cout << "Element To Element Comparison: "<<comp_cnt;
    return 0;
}