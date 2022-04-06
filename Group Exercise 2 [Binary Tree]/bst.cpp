#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void rand_arr(int arr[], int length)
{
    srand(time(NULL));
    for (int i = 0; i < length; ++i)
    {
        arr[i] = rand() % (100 + 1);          // return random natural numbers within [0, 100]
    }
}


struct node
{
    int key;
    struct node* left;
    struct node* right;
};


struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

struct node* search(struct node* root, int key)
{

    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}


struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(struct node* root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void printHelper(node* root, string indent, bool last)
{
    if (root != nullptr)
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

        cout << root->key << endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}


// =================== MAIN FUNCTION =======================
int main()
{
    struct node* root = NULL;

    // -----> uncomment to enable the random mode for the elements
    //int length = 30;
    // int elements[length];
    //rand_arr(elements, length);

    int elements[30] = { 114,85,135,198,61,12,82,190,144,129,3,84,129,117,32,194,40,53,29,52,58,92,58,10,117,72,116,107,192
    };

    for (int i = 0; i < 30; ++i)
    {
        root = insert(root, elements[i]);
    }

    // cout << "Inorder traversal of the given tree \n";
    // inorder(root);

    cout << "Tree visualizing:" << endl;
    printHelper(root, "", true);

    // MENU
    int choice;
    do
    {
        printf("\n\nEnter the number corresponding action you want to do with the binary search tree above\n");
        cout << "(1) Search a node" << endl << "(2) Insert a node" << endl << "(3) Delete a node" << endl;
        cout << "Your choice is (1, 2, 3)? : ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3)
            cout << "Undefined choice. Please try again!";


    } while (choice != 1 && choice != 2 && choice != 3);


    if (choice == 1)
    {
        struct node* search_res = NULL;
        int s_node;

        cout << "Enter the node you want to search: ";
        cin >> s_node;

        search_res = search(root, s_node);
        if (search_res != NULL)
            cout << "\n-->The given binary contains this node\n" << endl;
        else
            cout << "\n-->Can't find the node\n" << endl;
    }
    else if (choice == 2)
    {
        struct node* i_root = NULL;
        int insert_element;

        cout << "Enter the node you want to insert: ";
        cin >> insert_element;

        i_root = insert(root, insert_element);

        cout << "\nTree visualizing: \n";
        printHelper(i_root, "", true);
        //inorder(i_root);

    }
    else if (choice == 3)
    {
        struct node* del_root = NULL;
        int del_element;

        cout << "Enter the node you want to delete: ";
        cin >> del_element;

        cout << "Delete " << del_element << endl;
        del_root = deleteNode(root, del_element);

        cout << "\nTree visualizing: \n";
        //inorder(del_root);
        printHelper(del_root, "", true);

    }

    system("pause");

    return 0;
}
