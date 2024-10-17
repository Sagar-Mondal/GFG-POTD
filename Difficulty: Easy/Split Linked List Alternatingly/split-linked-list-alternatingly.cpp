//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    void append(struct Node** headRef, int newData) {
        struct Node* new_node = new Node(newData);
        struct Node* last = *headRef;

        if (*headRef == NULL) {
            *headRef = new_node;
            return;
        }
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }

    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        struct Node* a = NULL;
        struct Node* b = NULL;
        struct Node* current = head; // Initialize current as head

        // Iterate through the list
        while (current != NULL) {
            append(&a, current->data); // Append current node's data to list a
            current = current->next;   // Move current to the next node

            // If current is not NULL, append its data to list b and move current to the
            // next node
            if (current != NULL) {
                append(&b, current->data);
                current = current->next;
            }
        }
        return {a, b};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends