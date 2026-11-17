class Solution {
public:
  bool isPal(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void solve(int start, string &s, vector<string> &curr, vector<vector<string>> &ans) {
    if (start == s.size()) {
        ans.push_back(curr);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPal(s, start, end)) {
            curr.push_back(s.substr(start, end - start + 1));
            solve(end+1, s, curr, ans);   // agla start kya hoga?
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
         vector<string>curr;
         int start=0;
         solve(start,s,curr,ans);
         return ans;
    }
};