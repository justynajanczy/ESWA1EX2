#include "LinkedList.h"
#include "stdlib.h"
#include <stdio.h>

typedef struct ListNode
{
	void* item;
	list_node_t next;
} ListNode;

typedef struct LinkedList
{
	//int size;
	list_node_t head;
}LinkedList;

linkedlist_t linked_list_create(void)
{
	linkedlist_t _new_linked_list = (linkedlist_t)malloc(sizeof(LinkedList));/*calloc(1, sizeof(LinkedList))*/
	list_node_t _new_node = (list_node_t)malloc(sizeof(ListNode));/*calloc(1, sizeof(ListNode))*/

	//there is not enough memory
	if (NULL == _new_linked_list)
	{
		return NULL;
	}

	//_new_node->item = 'H';
	_new_node->next = NULL;
	_new_node->item = NULL;
	_new_linked_list->head = _new_node;
	//_new_linked_list->size = 0;
	return _new_linked_list;
}

list_returnCode_t linked_list_destroy(linkedlist_t self)
{
	if (NULL != self)
	{
		free(self);
	}

	//could be also "ok"
	return LINKED_LIST_EMPTY;
}

list_returnCode_t linked_list_add_item(linkedlist_t list, void* item)
{
	list_node_t temp = (list_node_t)malloc(sizeof(list_node_t));
	list_node_t p;
	temp->next = NULL;
	temp->item = item;
	if (list->head/*->item*/ == NULL)
	{
		list->head = temp;
		//printf("puste head, nowy node, %d\n", list->head->item);
	}
	else
	{
		p = list->head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
		//printf("added: %d", p->next->item);
	}
	//list->size++;
	return LINKED_LIST_OK;
}

void* linked_list_pull_item(linkedlist_t self)
{
	if (self->head->next == NULL)
	{
		void* temp = self->head->item;
		self->head->item == NULL;
		return temp;
	}
	//else if (self->head->item == NULL)
	//{
	//	return LINKED_LIST_ERROR;
	//}
	else
	{
		list_node_t curr, prev;
		curr = self->head;
		prev = self->head;
		while (curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
		}

		prev->next = NULL;
		//free(p->item);
		//p->item == NULL;
		//self->size--;
		return curr->item;
	}
}

void* linked_list_peekItemByIndex(linkedlist_t self, uint16_t index)
{
	//if (index > linked_list_no_of_items(self))
	//{
	//	return NULL;
	//}

	uint16_t index_inside = 0;
	list_node_t node = self->head;

	while (index_inside < index)
	{
		node = node->next;
		index_inside++;
	}
	return node->item;
}

list_returnCode_t linked_list_remove_item(linkedlist_t self, void* item)
{
	list_node_t next = self->head;
	list_node_t to_remove = self->head;
	list_node_t prev = self->head;

	uint16_t if_exists = 0;

	while (next->next != NULL)
	{
		if (next->next->item == item)
		{
			if_exists = 1;
			to_remove = next->next;
			prev = next;
		}
		next = next->next;
	}

	if (if_exists == 1)
	{
		if (to_remove->next != NULL)
		{
			prev->next = to_remove->next;
		}
		free(to_remove);
		return LINKED_LIST_OK;
	}
	else
	{
		return LINKED_LIST_NOT_FOUND;
	}

}



void linked_list_print_elements(linkedlist_t self)
{
	list_node_t p;
	p = self->head;
	while (p->next != NULL)
	{
		printf("element: %d\n", p->item);
		p = p->next;
	}
	printf("last element: %d\n", p->item);
}

uint16_t linked_list_no_of_items(linkedlist_t self)
{
	uint16_t length = 0;
	list_node_t currentNode = self->head;

	while (currentNode != NULL)
	{
		currentNode = currentNode->next;
		length++;
	}
	return length;
}
