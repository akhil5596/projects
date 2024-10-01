#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinaryTree
{
public:
    Node *root;
    BinaryTree() : root(nullptr) {}
    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }
    void visualize(Node *root, int space = 0, int height = 10)
    {
        if (root == nullptr)
        {
            return;
        }
        space += height;
        visualize(root->right, space);
        cout << endl;
        for (int i = height; i < space; i++)
        {
            cout << ' ';
        }
        cout << root->data << "\n";
        visualize(root->left, space);
    }
};
int main()
{
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);
    cout << "Binary Tree Visualization:\n";
    tree.visualize(tree.root);
    return 0;
}
