//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    // Function to calculate the sum of the last n nodes in a linked list
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // If n is less than or equal to 0, return 0
        if (n <= 0)
            return 0;

        int sum = 0, temp = 0;
        struct Node *ref_ptr, *main_ptr;
        ref_ptr = main_ptr = head;

        // Calculate the sum of the first n nodes
        while (ref_ptr != NULL && n--) {
            sum += ref_ptr->data;
            ref_ptr = ref_ptr->next;
        }

        // Calculate the sum of the remaining nodes
        while (ref_ptr != NULL) {
            temp += main_ptr->data;
            sum += ref_ptr->data;
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }

        // Return the sum of the last n nodes
        return (sum - temp);
    }
};

//{ Driver Code Starts.

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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends