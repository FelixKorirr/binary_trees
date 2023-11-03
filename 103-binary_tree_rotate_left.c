#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node after rotation.
 * korir codes
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	x = tree->right;
	y = x->left;
	x->left = tree;
	tree->right = y;
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
