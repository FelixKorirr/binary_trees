#include "binary_trees.h"

/**
 * get_bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 * korir codes
 */
void get_bal(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
	{
		return;
	}
	if ((*tree)->left == NULL && (*tree)->right == NULL)
	{
		return;
	}
	get_bal(&(*tree)->left);
	get_bal(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * next_successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 * korir codes
 */
int next_successor(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = next_successor(node->l);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}

}
/**
 *remove_node - function that removes a node
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = next_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
	{
		return (NULL);
	}
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
	{
		return (NULL);
	}
	get_bal(&root_a);
	return (root_a);
}
