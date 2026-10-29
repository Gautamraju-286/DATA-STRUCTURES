C

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an element into BST
struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search an element in BST
struct Node* search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Main function
int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, n, value, key, i;

    do
    {
        printf("\n----- BINARY SEARCH TREE -----\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++)
                {
                    printf("Enter element: ");
                    scanf("%d", &value);
                    root = insert(root, value);
                }

                printf("BST created successfully.\n");
                break;

            case 2:
                if (root == NULL)
                    printf("\nPlease create the BST first.\n");
                else
                {
                    printf("\nInorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("\nPlease create the BST first.\n");
                else
                {
                    printf("\nPreorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("\nPlease create the BST first.\n");
                else
                {
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL)
                {
                    printf("\nPlease create the BST first.\n");
                }
                else
                {
                    printf("Enter the element to search: ");
                    scanf("%d", &key);

                    result = search(root, key);

                    if (result != NULL)
                        printf("\nKEY %d is found in the BST.\n", key);
                    else
                        printf("\nKEY %d is not found in the BST.\n", key);
                }
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
