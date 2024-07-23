//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node* root1, Node* root2) {
        Node* head1 = nullptr;
        Node* head2 = nullptr;
        
        convertIntoSortedDLL(root1, &head1);
        convertIntoSortedDLL(root2, &head2);
        
        Node* res = mergeLinkedList(head1, head2);
        
        vector<int> result;
        while (res != nullptr) {
            result.push_back(res->data);
            res = res->right;
        }
        
        return result;
    }
    void convertIntoSortedDLL(Node* root, Node** head) {
        if (root == nullptr) {
            return;
        }
 
        convertIntoSortedDLL(root->right, head);
        root->right = *head;
 
        if (*head != nullptr) {
            (*head)->left = root;
        }
 
        *head = root;
 
        convertIntoSortedDLL(root->left, head);
    }
    Node* mergeLinkedList(Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
 
        while (true) {
            if (head1 == nullptr) {
                tail->right = head2;
                break;
            }
 
            if (head2 == nullptr) {
                tail->right = head1;
                break;
            }
 
            if (head1->data <= head2->data) {
                tail->right = head1;
                head1->left = tail;
                head1 = head1->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                head2 = head2->right;
            }
 
            tail = tail->right;
        }
        Node* res = dummy->right;
        if (res != nullptr) {
            res->left = nullptr;
        }
        
        delete dummy;
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends