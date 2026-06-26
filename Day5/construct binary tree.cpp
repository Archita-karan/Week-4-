

class Solution {
public:

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,
                         int preStart, int preEnd,
                         int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int pos = inStart;

        while(pos <= inEnd)
        {
            if(inorder[pos] == preorder[preStart])
                break;

            pos++;
        }

        int leftNodes = pos - inStart;

        root->left = createTree(preorder, inorder,
                                preStart + 1,
                                preStart + leftNodes,
                                inStart,
                                pos - 1);

        root->right = createTree(preorder, inorder,
                                 preStart + leftNodes + 1,
                                 preEnd,
                                 pos + 1,
                                 inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return createTree(preorder,
                          inorder,
                          0,
                          preorder.size() - 1,
                          0,
                          inorder.size() - 1);
    }
};