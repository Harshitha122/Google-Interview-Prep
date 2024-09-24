/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res=root->val;
        int cnt=1;
        int out=1;
        while(!q.empty()){
            int n=q.size();
            int ans=0;
            
            for(int i=1;i<=n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                ans+=tmp->val;
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            if(ans>res){
                out=cnt;
                res=max(ans,res);
            }
            cnt++;
        }
        return out;
    }
};