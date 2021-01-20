#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {

        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{

    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();

    root->right = buildTree();
    return root;
}

void print(node *root)
{ //+ L R
    if (root == NULL)
    {
        return;
    }

    //else, print the root followed by children
    cout << root->data << "   ";
    print(root->left);
    print(root->right);
}

void printIn(node *root)
{ // L + R
    if (root == NULL)
    {
        return;
    }

    //else, print the root followed by children
    print(root->left);
    cout << root->data << "   ";

    print(root->right);
}

void printPost(node *root)
{
    if (root == NULL)
    {
        return;
    }

    //else, print the root followed by children
    print(root->left);
    print(root->right);
    cout << root->data << "   ";
}

int main()
{
    node *root = buildTree();
    print(root);
    cout << endl;

    printIn(root);
    cout << endl;

    printPost(root);
    cout << endl;
    return 0;
}