#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1000001];

typedef struct node
{
	char alpha;
	struct node *next;
	struct node *prev;
} t_node;

typedef struct list
{
	t_node *head;
	t_node *tail;
	int	   size;
} t_list;

t_node	*new_node(char c)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->alpha = c;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_list(t_list *list)
{
	list->head = new_node(0);
	list->tail = list->head;
	list->size = 0;
}

void	add_list(t_list *list, t_node **cur, t_node *node)
{
	node->next = (*cur)->next;
	if ((*cur)->next != NULL)
		(*cur)->next->prev = node;
	else
		list->tail = node;
	node->prev = (*cur);
	(*cur)->next = node;
	*cur = node;
	list->size++;
}

void	del_list(t_list *list, t_node **cur)
{
	t_node *temp;

	if (list->head == *cur)
		return ;
	else
	{
		(*cur)->prev->next = (*cur)->next;
		if ((*cur)->next != NULL)
			(*cur)->next->prev = (*cur)->prev;
		else
			list->tail = (*cur)->prev;
		temp = *cur;
		*cur = (*cur)->prev;
		free(temp);
		list->size--;
	}
}

void	left_cur(t_list *list, t_node **cur)
{
	if ((*cur)->prev == NULL)
		return ;
	else
		*cur = (*cur)->prev;
	if (*cur == list->head)
		list->head = *cur;
}

void	right_cur(t_list *list, t_node **cur)
{
	if ((*cur)->next == NULL)
		return ;
	else
		*cur = (*cur)->next;
	if (*cur == list->tail)
		list->tail = *cur;
}

void	print_all(t_list *list)
{
	t_node *temp;

	temp = list->head;
	temp = temp->next;
	while (temp)
	{
		printf("%c", temp->alpha);
		temp = temp->next;
	}
}

void	clear_list(t_list *list)
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
	int	n, length;
	t_list *pw_list;
	t_node *cur;

	pw_list = (t_list *)malloc(sizeof(t_list));
	//포인터로 선언을 했으니 당연히 할당을 해줘야 참조를 할 수 있다.
	if (pw_list == NULL)
		exit(1);
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1000001; j++)
			input[j] = '\0';
		init_list(pw_list);
		cur = pw_list->head;
		scanf("%[^\n]%*c", input);
		length = strlen(input);
		for (int j = 0; j < length; j++)
		{
			if (input[j] == '<')
				left_cur(pw_list, &cur);
			else if (input[j] == '>')
				right_cur(pw_list, &cur);
			else if (input[j] == '-')
				del_list(pw_list, &cur);
			else
				add_list(pw_list, &cur, new_node(input[j]));
		}
		print_all(pw_list);
		putchar('\n');
		clear_list(pw_list);
	}
	free(pw_list);
}