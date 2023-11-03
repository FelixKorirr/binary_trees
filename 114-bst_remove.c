#include "binary_trees.h"

bst_t *min_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * min_successor - Return the minimum value of bst.
 * @root: pointer to the root node of the BST.
 * Return: minimum value in @tree.
 * korir codes
 */
bst_t *min_successor(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_delete - Deletes a node from a bst.
 * @root: pointer to the root node of the BST.
 * @node: pointer to the node to delete from the BST.
 * Return: pointer to the root node after deletion.
 * korir codes
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *s = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
		{
			parent->left = node->right;
		}
		else if (parent != NULL)
		{
			parent->right = node->right;
		}
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
		{
			parent->left = node->left;
		}
		else if (parent != NULL)
		{
			parent->right = node->left;
		}
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	s = min_successor(node->right);
	node->n = s->n;

	return (bst_delete(root, s));
}

/**
 * remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
		{
			return (bst_delete(root, node));
		}
		if (node->n > value)
		{
			return (remove_recursive(root, node->left, value));
		}
		return (remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a bst.
 * @root: pointer to the root node of the BST.
 * @value: value to remove in the BST.
 * Return: pointer to the new root node after deletion.
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 * korir codes
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursive(root, root, value));
}
