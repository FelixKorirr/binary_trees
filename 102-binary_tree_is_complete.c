#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push_node(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop_levelorder(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 *         else, a pointer to the new node
 * korir codes
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *n;

	n = malloc(sizeof(levelorder_queue_t));
	if (n == NULL)
	{
		return (NULL);
	}

	n->node = node;
	n->next = NULL;

	return (n);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: pointer to the head of the queue.
 * korir codes
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *x;

	while (head != NULL)
	{
		x = head->next;
		free(head);
		head = x;
	}
}

/**
 * push_node - Push a node to the back of a queue.
 * @node: binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: double pointer to the tail of the queue.
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push_node(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *n;

	n = create_node(node);
	if (n == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = n;
	*tail = n;
}

/**
 * pop_levelorder - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop_levelorder(levelorder_queue_t **head)
{
	levelorder_queue_t *t;

	t = (*head)->next;
	free(*head);
	*head = t;
}
/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: pointer to the root node of the tree to traverse.
 * Return: If the tree is NULL or not complete, 0.else, 1.
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char f = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (f == 1)
			{
				free_queue(head);
				return (0);
			}
			push_node(head->node->left, head, &tail);
		}
		else
			f = 1;
		if (head->node->right != NULL)
		{
			if (f == 1)
			{
				free_queue(head);
				return (0);
			}
			push_node(head->node->right, head, &tail);
		}
		else
			f = 1;
		pop_levelorder(&head);
	}
	return (1);
}
