#include "binary_trees.h"
#include "limits.h"

size_t get_height(const binary_tree_t *tree);
int avl_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, function must return 0, else return height.
 * korir codes
 */
size_t get_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, x = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		x = tree->right ? 1 + height(tree->right) : 1;
		return ((l > x) ? l : x);
	}
	return (0);
}

/**
 * avl_helper - Check if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: value of the smallest node visited thus far.
 * @high: value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 * korir codes
 */
int avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t l, r, d;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
		{
			return (0);
		}
		l = height(tree->left);
		r = height(tree->right);
		d = l > r ? l - r : r - l;
		if (d > 1)
		{
			return (0);
		}
		return (avl_helper(tree->left, low, tree->n - 1) &&
			avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 * korir codes
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (avl_helper(tree, INT_MIN, INT_MAX));
}
