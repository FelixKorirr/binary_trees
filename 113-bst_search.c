#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: Pointer to the root node of the BST to search.
 * @value: Value to search for in the BST.
 * Return: If tree is NULL or the value not found, NULL.
 *         else, pointer to the node containing the value.
 * korir codes
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
		{
			return ((bst_t *)tree);
		}
		if (tree->n > value)
		{
			return (bst_search(tree->left, value));
		}
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
