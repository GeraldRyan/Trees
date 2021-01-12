#include <stdio.h>
#include <stdlib.h>

// make

struct BinaryRree
{
  struct BinaryTree *left;
  struct BinaryTree *right;
  int num_nodes;
};

// struct node
// {
//   int val;
//   struct node lchild;
//   struct node rchild;
// };



struct BinaryTree *make_tree(void)
{
  struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
  struct node* root = malloc(sizeof(struct node));
  tree->root = *root;

  return ;
}

void rebalance_tree(struct BinaryRree* tree){

}