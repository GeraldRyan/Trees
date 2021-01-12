#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

struct BinaryTree
{
  int n;
  struct BinaryTree *left;
  struct BinaryTree *right;
} typedef BinaryTree;
BinaryTree *root, *ptr, *prev, *bfor, *x, *y;
int num;

void main()
{
  int ch;
  void createNewTree();
  void displayTree(BinaryTree *);
  void searchTree(BinaryTree *);
  void insertTree(BinaryTree *);
  void deleteTree(BinaryTree *);

  do
  {
    printf("\n1.CREATENEW\n2.PRINT\n3.SEARCH\n4.INSERT\n5.DELETE\n6.EXIT");
    printf("\nEnter your choice\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      createNewTree();
      break;
    }

    case 2:
    {
      displayTree(root);
      break;
    }
    case 3:
    {
      searchTree(root);
      break;
    }
    case 4:
    {
      insertTree(root);
      break;
    }

    case 5:
    {
      deleteTree(root);
      break;
    }
    }
  } while (ch < 6);
  getchar();
}

void createNewTree() // Creates a new binary tree
{
  int n, i;
  BinaryTree *temp;
  root = NULL;
  printf("Enter the number of nodes\t");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Enter the number ");
    scanf("%d", &num);
    if (root == NULL)
    {
      temp = (BinaryTree *)malloc(sizeof(BinaryTree));
      temp->n = num;
      temp->left = temp->right = NULL;
      root = temp;
    }
    else
    {
      ptr = prev = root;
      do
      {
        if (num < ptr->n)
        {
          prev = ptr;
          ptr = ptr->left;
        }
        else if (num > ptr->n)
        {
          prev = ptr;
          ptr = ptr->right;
        }
        else
        {
          prev = NULL;
          break;
        }
      } while (ptr);
      if (prev)
      {
        temp = (BinaryTree *)malloc(sizeof(BinaryTree));
        temp->n = num;
        temp->left = temp->right = NULL;
        if (temp->n < prev->n)
          prev->left = temp;
        if (temp->n > prev->n)
          prev->right = temp;
      }
      else
        printf("'%d' is already present..", num);
    }
  }
}

void displayTree(BinaryTree *ptr) // Displays the elements of the tree
{
  if (!ptr)
  {
    printf("Tree empty...");
    return;
  }
  void preorder(BinaryTree * ptr);
  printf("Root is '%d'", root->n);
  printf("\n Elements are .... ");
  preorder(root);
}

void preorder(BinaryTree *ptr)
{
  if (!ptr)
    return;
  printf("%2d ", ptr->n);
  preorder(ptr->left);
  preorder(ptr->right);
  return;
}

void searchTree(BinaryTree *ptr) // Searches a particular element
{
  if (!ptr)
  {
    if (ptr == root)
    {
      printf("Empty Tree");
      return;
    }
  }
  printf("Enter the number to search : ");
  scanf("%d", &num);

  while (ptr)
  {
    if (ptr->n == num)
    {
      printf("Search Successfull...");
      return;
    }
    else if (ptr->n < num)
      ptr = ptr->right;
    else
      ptr = ptr->left;
  }
  printf("Search UnSuccessfull...");
}

void insertTree(BinaryTree *ptr) // Insert an element
{
  BinaryTree *temp;
  if (!ptr)
  {
    printf("Tree is empty...First create & then insert... ");
    return;
  }
  ptr = prev = root;
  printf("Enter number to be inserted : ");
  scanf("%d", &num);

  do
  {
    if (num < ptr->n)
    {
      prev = ptr;
      ptr = ptr->left;
    }
    else if (num > ptr->n)
    {
      prev = ptr;
      ptr = ptr->right;
    }
    else
    {
      prev = NULL;
      break;
    }
  } while (ptr);

  if (prev)
  {
    temp = (BinaryTree *)malloc(sizeof(BinaryTree));
    temp->n = num;
    temp->left = temp->right = NULL;
    if (temp->n < prev->n)
      prev->left = temp;
    if (temp->n > prev->n)
      prev->right = temp;
    printf("'%d' is inserted...", num);
  }
  else
    printf("'%d' is already present...", num);
  return;
}

void deleteTree(BinaryTree *ptr) // Deletes a particular element
{
  if (!ptr)
  {
    if (ptr == root)
    {
      printf("Empty Tree");
      return;
    }
  }
  printf("Enter the number to be deleted : ");
  scanf("%d", &num);
  prev = ptr;

  while (ptr)
  {
    if (ptr->n == num)
    {
      if (ptr == root)
      {
        x = ptr->right;
        root = x;
        while (x->left)
          x = x->left;
        x->left = ptr->left;
        free(ptr);
        printf("'%d' is deleted...", num);
        return;
      }
      else if (!(ptr->left) && !(ptr->right))
      {
        if (prev->left == ptr)
          prev->left = NULL;
        else
          prev->right = NULL;
        free(ptr);
        printf("'%d' is deleted...", num);
        return;
      }
      else if (!(ptr->left))
      {
        if (prev->left == ptr)
        {
          prev->left = ptr->right;
          free(ptr);
        }
        else if (prev->right == ptr)
        {
          prev->right = ptr->right;
          free(ptr);
        }
        printf("'%d' is deleted...", num);
        return;
      }
      else if (!(ptr->right))
      {
        if (prev->left == ptr)
        {
          prev->left = ptr->left;
          free(ptr);
        }
        else if (prev->right == ptr)
        {
          prev->right = ptr->left;
          free(ptr);
        }
        printf("'%d' is deleted...", num);
        return;
      }
      else
      {
        x = ptr->right;
        while (x->left)
          x = x->left;
        x->left = ptr->left;
        if (prev->left == ptr)
          prev->left = ptr->right;
        else if (prev->right == ptr)
          prev->right = ptr->right;
        free(ptr);
        printf("'%d' is deleted...", num);
        return;
      }
    }
    else if (ptr->n < num)
    {
      prev = ptr;
      ptr = ptr->right;
    }
    else
    {
      prev = ptr;
      ptr = ptr->left;
    }
  }
  printf("No Such Element Found..");
}