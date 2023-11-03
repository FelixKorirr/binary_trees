#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 * korir codes
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *c, *new;

	if (tree != NULL)
	{
		c = *tree;

		if (c == NULL)
		{
			new = binary_tree_node(c, value);
			if (new == NULL)
			{
				return (NULL);
			}
			return (*tree = new);
		}

		if (value < c->n)
		{
			if (c->left != NULL)
				return (bst_insert(&c->left, value));

			new = binary_tree_node(c, value);
			if (new == NULL)
			{
				return (NULL);
			}
			return (c->left = new);
		}
		if (value > c->n)
		{
			if (c->right != NULL)
			{
				return (bst_insert(&c->right, value));
			}

			new = binary_tree_node(c, value);
			if (new == NULL)
			{
				return (NULL);
			}
			return (c->right = new);
		}
	}
	return (NULL);
}
