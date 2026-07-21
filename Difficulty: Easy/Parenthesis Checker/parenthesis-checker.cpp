class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // opening brackets -> push
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // closing brackets -> check match
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) {
                    return false; // nothing to match with
                }
                
                char top = st.top();
                st.pop();
                
                if (ch == ')' && top != '(') return false;
                if (ch == '}' && top != '{') return false;
                if (ch == ']' && top != '[') return false;
            }
            // operators, letters, digits -> ignore, don't affect bracket matching
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
                     isalpha(ch) || isdigit(ch)) {
                continue;
            }
        }
        
        return st.empty();
    }
};