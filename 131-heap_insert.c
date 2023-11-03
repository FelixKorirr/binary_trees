#include "binary_trees.h"

/**
 * heap_insert - Insert a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node else NULL
 * korir codes
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *f;
	int size, l, s, b, level, tmp;

	if (!root)
	{
		return (NULL);
	}
	if (!(*root))
	{
		return (*root = binary_tree_node(NULL, value));
	}
	tree = *root;
	size = binary_tree_size(tree);
	l = size;
	for (level = 0, s = 1; l >= s; s *= 2, level++)
		l -= s;

	for (b = 1 << (level - 1); b != 1; b >>= 1)
		tree = l & b ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	l & 1 ? (tree->right = new) : (tree->left = new);

	f = new;
	for (; f->parent && (f->n > f->parent->n); f = f->parent)
	{
		tmp = f->n;
		f->n = f->parent->n;
		f->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: size of the tree else 0
 * korir codes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
