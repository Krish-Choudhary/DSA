#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(Node *root)
{
    if (root == NULL)
        return;

    Node *current = root;
    Node *pre;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* Make current as the right child of its
            inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in the 'if' part to
            restore the original tree i.e., fix the right
            child of predecessor */
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{

    /* Constructed binary tree is
            1
           / \
          2	  3
         / \
        4   5
*/
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    MorrisTraversal(root);
    return 0;
}
