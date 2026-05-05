#include <iostream>
#include <vector>
#include <stack>



using namespace std;

vector<int> nextGrtr(vector<int>& v) {
    int n = v.size();
    vector<int> out(n, -1);
    stack<int> st;
    for(int i = 0;i<2*n;i++) {
        int curr = v[i%n];

        while(!st.empty() && curr > v[st.top()]) {
            out[st.top()] = curr;
            st.pop();
        }

        if(i<n) st.push(i);
    }
    return out;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the array:";
    for(int i = 0;i<n;i++) {
        cin>>nums[i];
    }
    vector<int> out = nextGrtr(nums);
    for(int el: out) cout<<el<<' ';
    return 0;
}