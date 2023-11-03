#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);
int get_balance(const binary_tree_t *tree);
avl_t *insert_avl_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * get_height - Measure the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, function must return 0, else return height.
 * korir codes
 */
size_t get_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t x = 0, y = 0;

		x = tree->left ? x + binary_tree_height(tree->left) : x;
		y = tree->right ? x + binary_tree_height(tree->right) : x;
		return ((x > y) ? x : y);
	}
	return (0);
}

/**
 * get_balance - Measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: If tree is NULL, return 0, else return balance factor.
 * korir codes
 */
int get_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * insert_avl_recursive - Insert a value into an AVL tree recursively.
 * @tree: double pointer to the root node of the AVL tree.
 * @parent: parent node of the current working node.
 * @new: double pointer to store the new node.
 * @value: value to insert into the AVL tree.
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *insert_avl_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int b;

	if (*tree == NULL)
	{
		return (*new = binary_tree_node(parent, value));
	}

	if ((*tree)->n > value)
	{
		(*tree)->left = insert_avl_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
		{
			return (NULL);
		}
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert_avl_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
		{
			return (NULL);
		}
	}
	else
		return (*tree);

	b = balance(*tree);
	if (b > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (b > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Insert a value into an AVL tree.
 * @tree: double pointer to the root node of the AVL tree.
 * @value: value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_avl_recursive(tree, *tree, &new, value);
	return (new);
}
