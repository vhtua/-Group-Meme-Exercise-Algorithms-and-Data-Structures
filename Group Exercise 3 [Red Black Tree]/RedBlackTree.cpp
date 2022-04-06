#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;
    int color;
};

typedef Node* NodePtr;

class RedBlackTree
{
private:
    NodePtr root;
    NodePtr TNULL;

    void leftRotate(NodePtr x)
    {
        NodePtr y = x->right;
        x->right = y->left;

        if (y->left != TNULL)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == TNULL)
        {
            this->root = y;
        }

        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }

        else
        {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x)
    {
        NodePtr y = x->left;
        x->left = y->right;

        if (y->right != TNULL)
        {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == TNULL)
        {
            this->root = y;
        }

        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }

        else
        {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    NodePtr searchTreeHelper(NodePtr root, int key)
    {
        if (root == TNULL || key == root->data)
        {
            return root;
        }

        if (key < root->data)
        {
            return searchTreeHelper(root->left, key);
        }

        if (key > root->data)
        {
            return searchTreeHelper(root->right, key);
        }
    }

    void fixInsertNode(NodePtr node)
    {
        NodePtr y;

        while (node->parent->color == 1)
        {
            if (node->parent == node->parent->parent->left)
            {
                y = node->parent->parent->right;

                if (y->color == 1)
                {
                    y->color = 0;
                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                }

                else
                {
                    if (node == node->parent->right)
                    {
                        node = node->parent;
                        leftRotate(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    rightRotate(node->parent->parent);
                }
            }

            else
            {
                y = node->parent->parent->left;

                if (y->color == 1)
                {
                    y->color = 0;
                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                }

                else
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        rightRotate(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    leftRotate(node->parent->parent);
                }
            }

            if (node == this->root)
            {
                break;
            }
        }

        this->root->color = 0;
    }

    void printHelper(NodePtr root, string indent, bool last)
    {
        if (root != TNULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "     ";
            }
            else
            {
                cout << "L----";
                indent += "|    ";
            }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:
    RedBlackTree()
    {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    };

    NodePtr searchTree(int key)
    {
        return searchTreeHelper(this->root, key);
    }

    void insertNode(int key)
    {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;

        NodePtr x = this->root;
        NodePtr y = TNULL;

        while (x != TNULL)
        {
            y = x;

            if (node->data < x->data)
            {
                x = x->left;
            }

            else
            {
                x = x->right;
            }
        }

        node->parent = y;

        if (y == TNULL)
        {
            this->root = node;
        }

        else if (node->data < y->data)
        {
            y->left = node;
        }

        else
        {
            y->right = node;
        }

        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;

        if (node->parent == TNULL)
        {
            node->color = 0;
            return;
        }

        if (node->parent->parent == TNULL)
        {
            return;
        }

        fixInsertNode(node);
    }

    void prettyPrint()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }
};

int* randomArray(int size)
{
    srand(time(NULL));
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    return arr;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size = 30;
    int* arr = nullptr;
    RedBlackTree rbt;

    /*rbt.insertNode(8);
    rbt.insertNode(18);
    rbt.insertNode(5);
    rbt.insertNode(15);
    rbt.insertNode(17);
    rbt.insertNode(25);
    rbt.insertNode(40);
    rbt.insertNode(80);*/

    arr = randomArray(size);
    printArray(arr, size);
    cout << endl << endl;

    for (int i = 0; i < size; i++)
    {
        rbt.insertNode(arr[i]);
    }

    delete[] arr;

    rbt.prettyPrint();

    system("pause");

    return 0;
}