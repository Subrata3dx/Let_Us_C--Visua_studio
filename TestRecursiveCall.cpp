// TestRecursiveCall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    vector<int>v;
    int i = 0;
    int kthSmallest(TreeNode* root, int k)
    {
        if (root == NULL)
            return 0;
        inorder(root);

        return v[k - 1];
     }

    void inorder(TreeNode* root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        cout << root->val << " \t" << "Suman" << "  Subrata" << endl;
        inorder(root->right);

        //cout << root->val << " \t" << "Suman" << "  Subrata" << endl;

    }

    void printIn(TreeNode* root)
    {
        if (root == NULL)
            return;
        printIn(root->left);
        cout<<root->val<<"\t";
        printIn(root->right);        

    }
};

int main()
{
    TreeNode* l = new TreeNode(10);
    TreeNode* r = new TreeNode(30);
    TreeNode* t = new TreeNode(20, l, r);
   
    
    Solution s;
    int x = s.kthSmallest(t, 3);
    cout << endl;

    s.printIn(t);

    cout << endl;

    cout << x;
    return 0;
}


