#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
	struct node *prev;
};

struct list
{
	struct node *head;
	struct node *tail;
};

typedef struct list t_list;
typedef struct node t_node;

void	init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}

t_node	*new_node(int n)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->num = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_list *list, t_node *node)
{
	t_node *temp;

	temp = list->head;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		while(temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
		list->tail = node;
	}
}

int	pop(t_node *node)
{
	int	ret;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	ret = node->num;
	free(node);
	return (ret);
}

void print(t_list *list, int n)
{
	int	i;
	t_node *temp;

	i = 1;
	temp = list->head;
	printf("<");
	while (temp)
	{
		printf("%d", temp->num);
		if (i < n)
			printf(", ");
		temp = temp->next;
		i++;
	}
	printf(">");
}

void	free_all(t_list *list)
{
	t_node *temp;

	while (list->head)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
}

int	main()
{
	int	n, k;
	t_list list;
	t_list print_list;
	t_node *cur;

	init_list(&list);
	init_list(&print_list);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		push(&list, new_node(i));
	list.head->prev = list.tail;
	list.tail->next = list.head;
	cur = list.head;
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= k; i++)
			cur = cur->next;
		push(&print_list, new_node(pop(cur->prev)));
	}
	print(&print_list, n);
	free_all(&print_list);
	return (0);
}