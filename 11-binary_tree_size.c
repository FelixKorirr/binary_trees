#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure its size.
 * Return: Size of the tree.
 * korir codes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t x = 0;

	if (tree)
	{
		x += 1;
		x += binary_tree_size(tree->left);
		x += binary_tree_size(tree->right);
	}
	return (x);
}
