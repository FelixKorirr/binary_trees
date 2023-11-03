#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, function must return 0, else return height.
 * korir codes
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x = 0, y = 0;

		x = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		y = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((x > y) ? x : y);
	}
	return (0);
}
