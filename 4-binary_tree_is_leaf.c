#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is the leaf of a binary tree.
 * @node: Pointer to the node to check.
 * Return: If the node is a leaf - 1.else - 0.
 * korir codes
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
		return (0);
	}

	return (1);
}
