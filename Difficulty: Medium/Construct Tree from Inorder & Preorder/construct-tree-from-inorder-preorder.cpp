//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findIndex(vector<int> &arr, int start, int target) {
        int i = 0;
        while (arr[start + i] != target)
            i++;
        return i;
    }
    Node *buildUtil(vector<int> &inorder, vector<int> &preorder, int inStart,
                    int preStart, int n) {
        if (n == 0)
            return NULL;
        Node *root = new Node(preorder[preStart]);
        int i = findIndex(inorder, inStart, preorder[preStart]);
        root->left = buildUtil(inorder, preorder, inStart, preStart + 1, i);
        root->right =
            buildUtil(inorder, preorder, inStart + i + 1, preStart + i + 1, n - i - 1);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        return buildUtil(inorder, preorder, 0, 0, n);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends