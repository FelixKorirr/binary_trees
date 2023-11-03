#include "binary_trees.h"

/**
 * array_to_bst - Build a binary search tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in @array.
 * Return: Pointer to the root node of the created BST, else NULL.
 * korir codes
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
			{
				return (NULL);
			}
		}
	}

	return (tree);
}
