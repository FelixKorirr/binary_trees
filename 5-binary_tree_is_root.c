#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if the node is a root of the binary tree.
 * @node: A pointer to the node to check.
 * Return: If node is the root - 1.else - 0.
 * korir codes
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}

	return (1);
}
