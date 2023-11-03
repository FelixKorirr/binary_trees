#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node after rotation.
 * korir codes
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	x = tree->left;
	y = x->right;
	x->right = tree;
	tree->left = y;
	if (y != NULL)
		y->parent = tree;
	y = tree->parent;
	tree->parent = x;
	x->parent = y;
	if (y != NULL)
	{
		if (y->left == tree)
			y->left = x;
		else
			y->right = x;
	}

	return (x);
}
