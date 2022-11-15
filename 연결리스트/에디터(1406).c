#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_list
{
	char 	alpha;
	struct s_list *next;
	struct s_list *prev;
};

typedef struct s_list t_list;

t_list	*new_node(char c)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node == NULL)
		exit(1);
	node->alpha = c;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_list(t_list **head, t_list **cur, t_list *node)
{
	if ((*cur)->prev != NULL)
	{
		node->prev = (*cur)->prev;
		(*cur)->prev->next = node;
	}
	else
		*head = node;
	node->next = *cur;
	(*cur)->prev = node;
}

void	del_list(t_list **head, t_list **cur)
{
	t_list *temp;

	if ((*cur)->prev == NULL)
		return ;
	else
	{
		temp = (*cur)->prev;
		if (temp->prev != NULL)
			temp->prev->next = *cur;
		// 뒤의 노드를 삭제하고 그 뒤의 노드와 이어주려할때 그 뒤의 노드가 존재하는지 여부를 체크해야한다.~~~~~~!!!~!!!~
		else
			*head = *cur;
		(*cur)->prev = temp->prev;
		free(temp);
	}
}

void	free_all(t_list *head)
{
	t_list *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	print_all(t_list *head)
{
	while (head->next)
	{
		printf("%c", head->alpha);
		head = head->next;
	}
	// 구현상 마지막에 dummy node가 하나있는데 그것까지 출력되도록 설계되어있어
	// 틀린 결과가 나왔음.
}

int	main()
{
	int		m, length;
	char	order[4];
	char	str[100001];
	// 100000까지 받으니까 +1로 100000. 끝의 null문자 고려(?)
	t_list	*cur;
	t_list	*head;

	cur = new_node(0);
	head = cur;
	scanf("%[^\n]%*c", str);
	//scanf("%[^\n]", str); -> \n입력받을때까지 계속 문자열입력받음.s가 오면 안됨.
	length = strlen(str);
	for (size_t i = 0; i < length; i++)
		add_list(&head, &cur, new_node(str[i]));
	// 기존에 i < strlen(str)로 했을때 매번 strlen이 실행되서 시간초과가 나옴.
	// strlen을 한번만 실행하도록 lenth에 값을 저장하고 진행시 시간초과 안나왔음.
	scanf("%d%*c", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%[^\n]%*c", order);
		if (order[0] == 'L')
		{
			if (cur->prev != NULL)
				cur = cur->prev;
		}
		else if (order[0] == 'D')
		{
			if (cur->next != NULL)
				cur = cur->next;
		}
		else if (order[0] == 'B')
		{
			if (cur->prev != NULL)
				del_list(&head, &cur);
		}
		else if (order[0] == 'P')
			add_list(&head, &cur, new_node(order[2]));
	}
	print_all(head);
	free_all(head);
	return (0);
}