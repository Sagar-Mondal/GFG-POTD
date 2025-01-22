//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node* sum = NULL;
        int carry = 0;
        while (num1 != NULL || num2 != NULL || carry != 0) {
            int newVal = carry;
            if (num1) {
                newVal += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                newVal += num2->data;
                num2 = num2->next;
            }
            carry = newVal / 10;
            newVal = newVal % 10;
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
        }
        while (sum != NULL && sum->data == 0) {
            Node* temp = sum;
            sum = sum->next;
            delete temp;
        }
        if (sum == NULL) {
            return new Node(0);
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends