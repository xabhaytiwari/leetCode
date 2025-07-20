#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

class TreeTraversal {
    public:
        void preorder_traversal (Node* root) {
            /*In a preorder traversal, you visit the root node first, then recursively traverse
            its left subtree, and finally recursively traverse its right subtree*/
            if (root == nullptr) {
                return;
            }

            cout << root->data << " "; // 1. Visit Root
            preorder_traversal(root->left); // 2. Traverse Left Subtree
            preorder_traversal(root->right); // 3. Traverse Right Subtree
        }
        
        void inorder_traversal (Node* root) {
            /*In an inorder traversal, you recursively traverse the left subtree, then visit the root
            node, and finally recursively traverse the right subtree*/
            if (root == nullptr) {
                return;
            }
            inorder_traversal(root->left); // 1. Traverse Left Subtree
            cout << root->data << " "; // 2. Visit Root
            inorder_traversal(root->right); // 3. Traverse Right Subtree
        }

        void postorder_traversal (Node* root) {
            /*In a postorder traversal, you first recursively traverse the left subtree, then recursively traverse 
            the right subtreem and finally visit the root node*/
            if (root == nullptr) {
                return;
            }
            postorder_traversal(root->left); // 1. Traverse Left Subtree
            postorder_traversal(root->right); // 2. Traverse Right Subtree
            cout << root->data << " "; // 3. Visit Root
        }

        Node* buildTree () {
            Node* root = new Node(1);
            root->left = new Node(2);
            root->right = new Node(3);
            root->left->left = new Node(4);
            root->left->right = new Node(5);
            return root;
        }

};

int main() {
    TreeTraversal solution;
    Node* root = solution.buildTree();
    
    solution.preorder_traversal(root);
    cout << endl;

    solution.inorder_traversal(root);
    cout << endl;

    solution.postorder_traversal(root);
    cout << endl;
    // Remember to free memory in a real application
    // For this simple example, we'll skip complex memory deallocation
    // but in a production setting, you'd implement a destructor or a
    // postorder traversal based deletion function.

    return 0;
}