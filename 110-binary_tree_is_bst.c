#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Check if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * @low: Value of the smallest node.
 * @high: Value of the largest node.
 * Return: 1 if the tree is a valid BST, otherwise, 0.
 * korir codes
 */
int bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
		{
			return (0);
		}
		return (bst_helper(tree->left, low, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, else 0
 * korir codes
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
