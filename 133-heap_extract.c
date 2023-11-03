#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: Height or 0 if tree is NULL
 * korir codes
 */
 
size_t binary_tree_height(const heap_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		h_l = 1 + tree_height(tree->left);
	}

	if (tree->right)
	{
		h_r = 1 + tree_height(tree->right);
	}

	if (h_l > h_r)
	{
		return (h_l);
	}
	return (h_r);
}
/**
 * tree_size_height - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_height(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		h_l = 1 + tree_size_height(tree->left);
	}

	if (tree->right)
		h_r = 1 + tree_size_height(tree->right);

	return (h_l + h_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: last node in traverse
 * @height: height of tree
 * Return: Nothing
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
	{
		return;
	}

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 * korir codes
 */
void heapify(heap_t *root)
{
	int x;
	heap_t *i, *j;

	if (!root)
	{
		return;
	}

	i = root;

	while (1)
	{
		if (!i->left)
			break;
		if (!i->right)
			j = i->left;
		else
		{
			if (i->left->n > i->right->n)
				j = i->left;
			else
				j = i->right;
		}
		if (i->n > j->n)
			break;
		value = i->n;
		i->n = j->n;
		j->n = x;
		i = j;
	}
}
