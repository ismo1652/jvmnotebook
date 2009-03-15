#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/** A node in a binary search tree */
struct _BsNode{
	struct _BsNode *left;
	struct _BsNode *right;
	int value;
};
typedef struct _BsNode BsNode;

/** A binary search tree. */
struct _BsTree{
	BsNode *root;
};
typedef struct _BsTree BsTree;


BsTree *bs_new()
{
	BsTree *tree = (BsTree*) malloc(sizeof(BsTree));
	tree->root = NULL;
	return tree;
}

** Private method used by bs_delete(). */
void
_bs_delete(BsNode *node)
{
	if(node == NULL)
		return;
	_bs_delete(node->left);
	_bs_delete(node->right);
	free(node);
}

/** Free all memory used by the binary search tree and all it's nodes. */
void
bs_delete(BsTree *tree)
{
	_bs_delete(tree->root);
	free(tree);
}




/** Private method used by bs_add(). */
BsNode *
_bs_add(BsTree *tree, BsNode *node, int value)
{
	if(node == NULL){
		node = (BsNode*) malloc(sizeof(BsNode));
		node->value = value;
		fprintf(stderr, "** Adding %d\n", value); // should use a logger here
		return node;
	}

	if(value < node->value)
		node->left = _bs_add(tree, node->left, value);
	else
		node->right = _bs_add(tree, node->right, value);

	return node;
}

/** Add a value to the tree. */
void
bs_add(BsTree *tree, int value)
{
	tree->root = _bs_add(tree, tree->root, value);
}


** Check if a tree contains the given *value*.
 * @return 1 if the value is in the tree and 0 if not.
 */
int
bs_contains(BsTree *tree, int value)
{
	return _bs_contains(tree->root, value);
}




/** Private method used by bs_size(). */
int
_bs_size(BsNode *node)
{
	if(node == NULL)
		return 0;
	return 1 + _bs_size(node->left) + _bs_size(node->right);
}

/**
 * @return The size of the tree.
 */
int
bs_size(BsTree *tree)
{
	return _bs_size(tree->root);
}


