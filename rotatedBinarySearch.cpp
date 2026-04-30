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
// best time complexity but can't handle duplicates
// int peak_pos(vector<int>&v , int l , int h , int n){
//     if (l == h)
//     return h;
    
//     int mid = (l+h)/2;
//     if (v[mid] > v[(mid + 1)%n])
//         return mid;


//     if (v[mid] > v[h]){
//         l = mid + 1;
//         return peak_pos(v,l,h,n);
//     }
//     else if (v[mid] < v[h]) {
//         h = mid;
//         return peak_pos(v,l,h,n);
//     }
//     else{
//         h--;
//         return peak_pos(v,l,h,n);
//     } 
    
// }

int main() {
    cout << "Hello, World!" << endl;
    vector<int>v =  {2 , 2, 2 , 2 , 3 , 2 , 2};
    int peak = 0;
    for (int i = 1 ; i < v.size(); i++){
        if (v[peak] <= v[i]){
            comp_cnt++;
            peak = i;
        }
    }
    // int peak = peak_pos(v , 0,v.size()-1,v.size());
    cout<<peak<<"\n";
    cout << search_rotated(v , 3 , peak)<<"\n";
    cout << "Element To Element Comparison: "<<comp_cnt;
    return 0;
}