#include <bits/stdc++.h>

using namespace std;

string postfix(string input){
    string ans = "";
    stack<char>st;

    for (int i = 0;i<input.size();i++){
        if ((input[i] - '0') <= 9 && (input[i] - '0') >= 0){
            ans+=input[i];
        }
        else if (input[i] == '+' || input[i] == '-'){
            if (!st.empty() && st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.push(input[i]);
        }

        else if (input[i] == '(' )st.push(input[i]);

        else if (input[i] == ')'){
            while(st.top() != '('){
                char c = st.top();
                st.pop();
                ans+=c;
            }
            st.pop();
        }
    }
    while (!st.empty()){
        char c = st.top();
        st.pop();
        ans+=c;
    }
    return ans;
}

int ans(string s){
    stack<int>st;
    for (int i = 0 ; i< s.size();i++){
        if (s[i] == '+' || s[i] == '-'){
            int y = st.top() ; st.pop();
            if (st.empty()){
                st.push(-1); // handles unary op 
                continue;
            }
            int x = st.top() ; st.pop();

            if (s[i] == '+')st.push(x+y);
            else st.push(x-y);
        }
        else st.push(s[i] - '0');
    }
    return st.top();
}

int main() {
    string input = "(1+(4+5+2)-3)-(6+8)"; // 9 - 14 = -5
    string input2 = "-1-(2+3)"; // -6

    string post = postfix(input);
    cout<<post<<"\n";
    int res = ans(post);
    cout<<res<<"\n";
    return 0;
}