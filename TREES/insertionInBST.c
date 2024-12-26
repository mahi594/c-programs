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




int isBST(struct Node *root)
{
    static struct Node * prev=NULL;
    if (root != NULL)
    {
        if(! isBST(root->left))  //Recursively check the left subtree by calling isBST(root->left). If the left subtree is not a BST, return 0.
        {
            return 0;
        }
        if(prev!=NULL&& root->data<=prev->data)
        {
            return 0;
        }

        prev=root;
        return isBST(root->right);

    }
    else{
        return 1;   // If root == NULL, the function returns 1 because an empty tree is a valid BST.
    }
}

struct Node*search(struct Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;

    }
    else if(root->data==key)
    {
        return root;

    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else
    {

  return search(root->right,key);
    }
      
    
}

void insert(struct Node* root,int key)
{
    struct Node* prev=NULL;
    while(root!=NULL)  //The function uses a while loop to traverse the tree from the root until it reaches a NULL pointer (an empty spot).

    {
        prev=root;
        if(key==root->data)
        {
            return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    struct node* new= createNode(key);
    if(key< prev->data)    //parent node's value (prev->data).
    {
        prev->left=new;  //If key < prev->data, the new node becomes the left child of the parent.Otherwise, it becomes the right child.
    }
    else{
        prev->right=new;

    }
} 

struct Node*inorderPredecessor(struct Node* root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct Node*deleteNode(struct Node* root,int value)
{
    struct Node* iPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        free(root);
        return NULL;
    }

    //search for the node to be delted
   if(value<root->data)
   {
    root->left=deleteNode(root->left,value);
   } 
   else if(value>root->data)
   {
    root->right=deleteNode(root->right,value);
   } 
   //when the node is found
   else{
     iPre=inorderPredecessor(root); 
     root->data=iPre->data;
     deleteNode(root->left,iPre->data);
   }
   return root;
}

int main()
{

    // 2.
    // constructing the root node
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

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
    if (isBST(p)) {
        printf("The tree is a Binary Search Tree.\n");
    } else {
        printf("The tree is NOT a Binary Search Tree.\n");
    }
   int key = 4;
    struct Node *result = search(p, key);
    if (result != NULL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not found\n");
    }
    insert(p,7);
     printf("Inorder traversal after insertion: ");
    inorder(p);
    printf("\n");
    deleteNode(p,1);
    printf("\n");
    printf("data is %d\n",p->data);
    inorder(p);

    return 0;
}
