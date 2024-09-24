int connectSticks(vector<int>& sticks) {
  priority_queue<int, vector<int>, greater<int>> qu(sticks.begin(), sticks.end());
  int result = 0;
  while (qu.size() > 1) {
    int a = qu.top(); qu.pop();
    int b = qu.top(); qu.pop();
    result += a + b;
    qu.push(a + b);
  }
  return result;
}