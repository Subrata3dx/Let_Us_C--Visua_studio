// InorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
};

struct Node* insert(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp -> left = temp->right = NULL;
    return temp;

}

void inorder(struct Node* root) {

    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

struct Node* BuildTree(struct Node* root, int input)
{
    if (root == NULL)
    {
        return insert(input);
    }
    if (input <= root->data)
    {
        root->left = BuildTree(root->left, input);
    }
        
    else if(input>=root->data)
    {
        root->right = BuildTree(root->right, input);
    }

    return root;
    
}


int main()
{
    struct Node* root = NULL;
    root = BuildTree(root, 10);
    BuildTree(root, 15);
    BuildTree(root, 5);
    BuildTree(root, 7);
    BuildTree(root, 11);
    inorder(root);

}

