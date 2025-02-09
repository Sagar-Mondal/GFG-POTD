//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findMaxUtil(Node *root, int &res) {
        // Base case for recursion.
        if (root == NULL)
            return 0;

        // l and r store maximum path sum going recursively through left and
        // right subtrees of root(current node) respectively.
        int l = findMaxUtil(root->left, res);
        int r = findMaxUtil(root->right, res);

        // max path sum for parent call of root. This path must
        // include at most one child of root.
        int max_single = max(max(l, r) + root->data, root->data);

        // max_top represents the sum when the node under consideration is the root
        // of the max sum path and no ancestors of root are there in max sum path.
        int max_top = max(max_single, l + r + root->data);

        // Storing the maximum result.
        res = max(res, max_top);

        return max_single;
    }

    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        findMaxUtil(root, res);

        // Returning the result.
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends