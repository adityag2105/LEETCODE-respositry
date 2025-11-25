class Solution {
public:
    bool isValid(const string &s) {
        vector<char> st;
        st.reserve(s.size());              // avoid reallocations

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char t = st.back();
                // direct comparisons are faster than maps/switch in microbenchmarks
                if ((c == ')' && t != '(') ||
                    (c == ']' && t != '[') ||
                    (c == '}' && t != '{'))
                    return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
