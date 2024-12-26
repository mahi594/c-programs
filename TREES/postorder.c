// left->right->root

// root->left->right

#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;                                 // creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // allocting memory in tre heap
    n->data = data;                                 // setting data
    n->right = NULL;                                // setting the left and right null
    n->left = NULL;
    printf("Node created with data: %d\n", data);
    return n; // finally returning the created node
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
       
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
       
        inorder(root->left);
         printf("%d ", root->data);
        inorder(root->right);
       
    }
}

int main()
{
    // 1.
    //     //parent node
    //     struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    //     p->left=NULL;
    //     p->right=NULL;

    // //left children
    //     struct Node*p1=(struct Node*)malloc(sizeof(struct Node));
    //     p1->left=NULL;
    //     p1->right=NULL;
    // //right children
    //     struct Node*p2=(struct Node*)malloc(sizeof(struct Node));
    //     p2->left=NULL;
    //     p2->right=NULL;

    //     //linking them
    //     p->left=p1;
    //     p->right=p2;

    // 2.
    // constructing the root node
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    // linking them
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Postorder traversal: ");
    postorder(p);
    printf("\n");
     printf("Preorder traversal: ");
    preorder(p);
    printf("\n");
    printf("inorder traversal: ");
    inorder(p);
    printf("\n");
    return 0;
}
