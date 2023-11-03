#include "binary_trees.h"

/**
 * tree_size - Measure the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: Height or 0 if tree is NULL
 * korir codes
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
		h_l = 1 + tree_size(tree->left);

	if (tree->right)
		h_r = 1 + tree_size(tree->right);

	return (h_l + h_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: pointer to the root node of the heap
 * @size: address to store the size of the array
 * Return: pointer to array in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x, *y = NULL;

	if (!heap || !size)
	{
		return (NULL);
	}

	*size = tree_size(heap) + 1;

	y = malloc(sizeof(int) * (*size));

	if (!y)
	{
		return (NULL);
	}

	for (x = 0; heap; x++)
		y[x] = heap_extract(&heap);

	return (y);
}
