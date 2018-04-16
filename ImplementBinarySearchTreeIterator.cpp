/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> v;
    int i;
    
public:
    BSTIterator(TreeNode *root) {
        i=0;
        vector<TreeNode*> stack;
        while(stack.size()>0||root!=NULL){
            if(root){
                stack.push_back(root);
                root=root->left;
            }else{
                root=stack.back();
                stack.pop_back();
                v.push_back(root->val);
                root=root->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i<v.size();
    }

    /** @return the next smallest number */
    int next() {
        return v[i++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */