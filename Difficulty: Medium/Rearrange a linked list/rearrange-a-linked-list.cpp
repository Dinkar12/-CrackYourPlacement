//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* Node structure

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
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        Node* dummy1 = new Node(0);
        Node* oddNodeHead = dummy1;
        Node* dummy2 = new Node(0);
        Node* evenNodeHead = dummy2;
        bool isEven = false;
        while(head != NULL) {
            if(isEven) {
               dummy2->next = head;
               head = head->next;
               isEven = !isEven;
               dummy2 = dummy2->next;
            } else {
                dummy1->next = head;
                head = head->next;
                isEven = !isEven;
                dummy1 = dummy1->next;
           }
       }
       dummy1->next = evenNodeHead->next;
       dummy2->next = NULL;
       head = oddNodeHead;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends