#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * find_max - goes through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, else 0
 * korir codes
 **/
int find_max(const binary_tree_t *tree)
{
	int x = 1, y = 1;

	if (!tree)
	{
		return (0);
	}
	if (!tree->left && !tree->right)
	{
		return (1);
	}
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		x = find_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		y = find_max(tree->right);
	}
	return (x && y);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 * korir codes
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
	{
		return (0);
	}

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
	{
		return (0);
	}
	return (find_max(tree));
}
