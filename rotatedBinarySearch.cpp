#include <iostream>
#include <vector>

using namespace std;



int updated_binary_search(vector<int>& v, int target, int& comparisons) {
    int n = v.size();
    int left = 0;
    int right = n-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(++comparisons & (v[mid] == target)) {
            return mid;
        }

        if ( (comparisons+=2) && (v[left] == v[mid] && v[mid] == v[right]) ) {
            left++;
            right--;
            continue;
        }

        if( ++comparisons && (v[left] <= v[mid])) {
            if((comparisons+=2) && (v[left] <= target && target < v[mid])){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }else {
            if ((comparisons+=2) && (v[mid] < target && target <= v[right])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1 ;
}


int main() {
    int comparisons1 = 0;
    vector<int> v = {4, 5, 6 ,6, 7, 0, 1, 2, 2, 4};
    int res = updated_binary_search(v, 2, comparisons1);

    if(res != -1) {
        cout<<"Target found at index:"<< res<<endl;
    }else {
        cout<<"Target is not found"<<endl;
    }
    cout<<"Total comparisons: "<<comparisons1<<endl;
    return 0;
}