#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char *path;
	int len;
	struct node *link;
} node_t;

int main(void)
{
	node_t *head, *c_ptr;
	char *env, *tok;
	void addnode(node_t *head, char *str);

	env = getenv("PATH");

	head = malloc(sizeof(node_t));
	if (head == NULL)
	{
		perror("Error");
		exit(1);
	}
	tok = strtok(env, ":");

	head->path = strdup(tok);
	head->len = strlen(tok);
	head->link = NULL;

	while (tok != NULL)
	{
		addnode(head, tok);
		tok = strtok(NULL, ":");
	}

	c_ptr = head;
	while (c_ptr != NULL)
	{
		printf("%s\n", c_ptr->path);
		c_ptr = c_ptr->link;
	}
	return (0);
}
void addnode(node_t *head, char *str)
{
	node_t *new = malloc(sizeof(node_t));
	node_t *ptr = head;

	if (new == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}
	new->path = strdup(str);
	new->len = strlen(str);
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = new;
}
