vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if(m*n!=original.size()) return {};
    vector<vector<int>> res( m , vector<int> (n));
    vector<int>::iterator start = original.begin();
    for(int i = 0;i<m;i++) res[i] = vector<int>(start+i*n,start+(i+1)*n);
    return res;
}