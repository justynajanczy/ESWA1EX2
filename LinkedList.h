#pragma once

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdint.h>


typedef enum
{
	LINKED_LIST_OK,
	LINKED_LIST_EMPTY,
	LINKED_LIST_NOT_FOUND,
	LINKED_LIST_NULL,
	LINKED_LIST_ERROR
}list_returnCode_t;

typedef struct LinkedList* linkedlist_t; //Abstract Data Type
typedef struct ListNode* list_node_t;

linkedlist_t linked_list_create(void);//
list_returnCode_t linked_list_destroy(linkedlist_t self);//
list_returnCode_t linked_list_add_item(linkedlist_t list, void* item);//
void* linked_list_pull_item(linkedlist_t self);//
void* linked_list_peekItemByIndex(linkedlist_t self, uint16_t index);//
list_returnCode_t linked_list_remove_item(linkedlist_t self, void* item);
uint16_t linked_list_no_of_items(linkedlist_t self);
void linked_list_print_elements(linkedlist_t self);//



#endif