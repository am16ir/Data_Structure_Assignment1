#include <bits/stdc++.h>
using namespace std;

vector<int> nxtgrtr(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;
        int cur = nums[idx];

        while (!st.empty() && st.top() <= cur) {
            st.pop();
        }

        if (i < n && !st.empty()) {
            ans[idx] = st.top();
        }

        st.push(cur);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = nxtgrtr(nums);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}