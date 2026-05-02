#include <bits/stdc++.h>
using namespace std;

int calc(string s) {
    stack<int> st;

    int result = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        }

        else if (s[i] == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        }

        else if (s[i] == '(') {
            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }

        else if (s[i] == ')') {
            result += sign * num;
            num = 0;

            int oldSign = st.top();
            st.pop();

            int oldResult = st.top();
            st.pop();

            result = oldResult + oldSign * result;
        }
    }

    result += sign * num;

    return result;
}

int main() {
    string s;
    getline(cin, s);

    cout <<calc(s);

    return 0;
}
//(1+(4+5+2)-3)+(6+8) 
//=23
