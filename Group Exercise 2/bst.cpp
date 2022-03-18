#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rand_arr(int arr[], int length) {
	srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (100 + 1);          // return random natural numbers within [0, 100]
    }
}
 

struct node {
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do
// inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
 
/* A utility function to
insert a new node with given key in
 * BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
 
/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}



 
// Driver Code
int main() {
    struct node* root = NULL;

    // -----> uncomment to enable the random mode for the elements
    //int length = 30;
   	// int elements[length];
    //rand_arr(elements, length);
    
    int elements[30] = {114,85,135,198,61,12,82,190,144,129,3,84,129,117,32,194,40,53,29,52,58,92,58,10,117,72,116,107,192
};

    for (int i = 0; i < 30; ++i) {
    	root = insert(root, elements[i]);
    }
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    // MENU
 	int choice;
    do {
        printf("\n\nEnter the number corresponding action you want to do with the binary search tree above\n");
        cout << "(1) Search a node" << endl << "(2) Insert a node" << endl << "(3) Delete a node" << endl;
        cout << "Your choice is (1, 2, 3)? : ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3) 
            cout << "Undefined choice. Please try again!";
        
        
        } while (choice != 1 && choice != 2 && choice != 3);
    

    if (choice == 1) {
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
    else if (choice == 2) {
    	struct node* i_root = NULL;
    	int insert_element;

    	cout << "Enter the node you want to insert: ";
    	cin >> insert_element;

    	i_root = insert(root, insert_element);
 
    	cout << "\nInorder traversal of the modified tree \n";
    	inorder(i_root);

    }  
    else if (choice == 3) {
    	struct node* del_root = NULL;
    	int del_element;

    	cout << "Enter the node you want to insert: ";
    	cin >> del_element;

    	cout << "Delete " << del_element << endl;
    	del_root = deleteNode(root, del_element);

        cout << "\nInorder traversal of the modified tree \n";
    	inorder(del_root);    
    }
 
    return 0;
}
 