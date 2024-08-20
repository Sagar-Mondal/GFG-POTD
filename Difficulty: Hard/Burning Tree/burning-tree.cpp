//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
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
//User function Template for C++

/*
struct Node {
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
    Node* markParents(Node* root, unordered_map<Node*, Node*>& parent_track, int target) {
        queue<Node*> queue;
        queue.push(root);
        Node* res = nullptr;
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.pop();
            if (node->data == target) res = node;
            if (node->left) {
                parent_track[node->left] = node;
                queue.push(node->left);
            }
            if (node->right) {
                parent_track[node->right] = node;
                queue.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        Node* target_node = markParents(root, parent_track, target);

        unordered_map<Node*, bool> visited;
        queue<Node*> queue;
        queue.push(target_node);
        visited[target_node] = true;
        int time = 0;
        while (!queue.empty()) {
            int size = queue.size();
            bool burned = false;
            for (int i = 0; i < size; i++) {
                Node* node = queue.front();
                queue.pop();
                if (node->left && !visited[node->left]) {
                    burned = true;
                    visited[node->left] = true;
                    queue.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    burned = true;
                    visited[node->right] = true;
                    queue.push(node->right);
                }
                if (parent_track[node] && !visited[parent_track[node]]) {
                    burned = true;
                    visited[parent_track[node]] = true;
                    queue.push(parent_track[node]);
                }
            }
            if (burned) time++;
        }
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends