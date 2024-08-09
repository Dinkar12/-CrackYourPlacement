//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
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
// User function template for C++

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
    Node* divide(Node* head) {
        // code here
        Node *oddHead = new Node(-1), *oddTail = oddHead;
        Node *evenHead = new Node(-1), *evenTail = evenHead;
        Node *curr = head, *temp;
        while (curr)
        {
            // Breaking the Link of the curr Node.
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
    
            if (temp->data & 1) // If odd Node,append to odd LinkedList
            {
                oddTail->next = temp;
                oddTail = temp;
            }
            else // If Even Node,append to even LinkedList
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        evenTail->next = oddHead->next; 
        // Appending Odd LinkedList at end of EvenLinkedList
        return evenHead->next;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends