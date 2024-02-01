class Solution {
 public:
  bool isOperator(string& s) {
    if (s == "+" || s == "-" || s == "*" || s == "/") return true;
    return false;
  }

  int calc(int& a, int& b, string& op) {
    if (op == "+")
      return a + b;
    else if (op == "-")
      return a - b;
    else if (op == "*")
      return a * b;
    else
      return a / b;
  }

  int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++) {
      bool op = isOperator(tokens[i]);
      if (op) {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        int next = calc(second, first, tokens[i]);
        st.push(next);
      } else
        st.push(stoi(tokens[i]));
    }
    return st.top();
  }
};