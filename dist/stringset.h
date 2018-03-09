#pragma once
#ifndef _STRLL_H_
#define _STRLL_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct _str_node{
    char *str; //the value that will be stored
    struct _str_node *next; //pointer to next quentry struct or tail
    struct _str_node *prev; //pointer to previouse quentry struct or head
};

typedef struct _str_node strll; //typical handle for head of strll
typedef struct _str_node strll_entry;
typedef struct _str_node strll_tail;

#define ishead(ll) ll->prev ? 0 : 1
//#define istail(ll) ll->next ? 0 : 1


strll* strll_new();
void strll_free_entry(strll_entry*);
void strll_free(strll*);
strll_entry* strll_new_entry(char*); //allocates a new strll_entry struct containing char
//strll_tail* strll_get_tail(strll*);
//strll* strll_get_head(strll*);
int strll_has_entry(strll*, char*);
int strll_isempty(strll_entry*);


void strll_insert(strll*, char*); //inserts at the front of the list
int strll_delete(strll*, char*); //delete element containing char* if it exists
int strll_isempty(strll*);

//queue interface
//int strll_enqueue(strll*, char*); //insert at the back of the list
//int strll_dequeue(strll_entry*); //remove from the front of the list

void strll_print(strll_entry *q);

#endif //_STRLL_H_
//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//

#ifndef STRINGSET_STRINGSET_H
#define STRINGSET_STRINGSET_H



#define STRSET_DEFAULT 0

struct string_set{
    unsigned int num_buckets; //the number of linked lists allocated
    unsigned int num_elements; //the actual number of elements allocated
    strll **strll_array; //array of nodes
    float load_factor;
};
typedef struct string_set stringset;
stringset* stringset_new(unsigned int initial_size, float load_factor);
void stringset_free(stringset **str_set);
void stringset_add(stringset **str_set, char *str);
int stringset_remove(stringset **str_set, char* string);
int stringset_contains(stringset **str_set, char *str);
void stringset_rehash(stringset **str_set);
float stringset_load_value(stringset **str_set);
//int stringset_copy(stringset *dest, stringset *src);
//int stringset_deepcopy(stringset *dest, stringset *src);
void stringset_free_lite(stringset **str_set);



unsigned long hash_code(stringset **str_set, const char *str);

#endif //STRINGSET_STRINGSET_H

strll* strll_new(){
    strll *head = (strll*)malloc(sizeof(strll));

	if (!head)
		return NULL;

    head->str = NULL;
    head->next = NULL;
    head->prev = NULL; //head always points to tail
    return head;
}
void strll_free_entry(strll_entry *entry){
    free(entry->str);
	free(entry);
}
void strll_free(strll *ll){
    if (!ll->next) {
        strll_free_entry(ll);
        return;
    }
    strll_free(ll->next);
    strll_free_entry(ll);
}

int strll_has_entry(strll *ll, char *entry){
    if (!ll) return 0;
    if (ishead(ll)) return strll_has_entry(ll->next, entry);
    if (strcmp(ll->str, entry) == 0) return 1;
    return strll_has_entry(ll->next, entry);
}



	/*int result;*/
	/*strll_entry *current = q;*/
	/*strll_entry *next;*/
	/*while (current->pid != FUTQ_TAIL){*/
		/*next = current->qnext;*/
		/*result = strll_free_entry(current);*/
		/*if (result == SYSERR)*/
			/*return result;*/

		/*current = next;*/
	/*}*/
	/*return strll_free_entry(current);*/
/*}*/

void strll_insert(strll *ll, char *new_string) {
    strll_entry *new_entry = strll_new_entry(new_string);

    if (!ll->next) { // There is nothing after the head
        ll->next = new_entry;
        new_entry->prev = ll;
        new_entry->next = NULL;
    } else { // There is an element after the head
        strll_entry *after = ll->next;

        new_entry->next = after;
        after->prev = new_entry;
        ll->next = new_entry;
        new_entry->prev = ll;
    }
}


// don't need it now
/*int strll_delete(strll *ll, char *str_to_del) {*/
    /*while (ll) {*/
        /*if (strcmp(ll->str, str_to_del) == 0) {*/
            /*strll_entry *ll_prev = ll->prev;*/
            /*if (!ll->next) {*/
                /*ll_prev->next = NULL;*/
                /*strll_free_entry(ll);*/
            /*} else {*/
                /*ll_prev->next = ll->next;*/
                /*ll->next->prev = ll_prev;*/
                /*strll_free_entry(ll);*/
            /*}*/
        /*} else {*/
            /*ll = ll->next;*/
        /*}*/
    /*}*/
/*}*/

strll_entry* strll_new_entry(char *entry_string){
    strll_entry *entry = (strll_entry*) malloc(sizeof(strll_entry));
    entry->str = (char*) malloc(strlen(entry_string) + 1);
    strcpy(entry->str, entry_string);
	return entry;
}
/*strll_entry* strll_get_tail(strll *q){*/
	/*if (q->pid == FUTQ_HEAD)*/
		/*return q->qprev; //should always be a pointer to head*/
	/*if (q->pid == FUTQ_TAIL) //this is just sainity checking*/
		/*return q;*/

	/*return strll_get_tail(q->qnext);	//so is this*/
/*}*/
/*strll_entry* strll_get_head(strll *q){*/
	/*if (q->pid == FUTQ_HEAD)*/
		/*return q; //should always be a pointer to head*/

	/*return strll_get_head(q->qprev);	// sanity check*/
/*}*/

/*void strll_enqueue(strll* q, pid32 pid){*/
	/*strll_tail *tail = strll_get_tail(q);*/
	/*strll_entry *new_entry = strll_newentry(pid);*/
	/*strll_entry *before_new = tail->qprev;*/

	/*tail->qprev = new_entry;*/
	/*new_entry->qnext = tail;*/
	/*new_entry->qprev = before_new;*/
	/*before_new->qnext = new_entry;*/

/*}*/
/*pid32 strll_dequeue(strll *q){*/
	/*strll *head = strll_get_head(q);*/
	/*strll_entry *rmv = head->qnext;*/

	/*head->qnext = rmv->qnext;*/
	/*rmv->qnext->qprev = head;*/

	/*pid32 ret = rmv->pid;*/
	/*strll_free_entry(rmv);*/

	/*return ret;*/
/*}*/
int strll_isempty(strll *ll){
    if (!ll->prev && !ll->next)
        return 1;
    return 0;
}
void strll_print(strll *ll){
    if (!ll) {
        printf("[NULL]\n");
        return;
    } else if (!ll->prev) {
        printf("[HEAD]-->");
    } else {
        printf("[%s]-->", ll->str);
    }
    strll_print(ll->next);
}
//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//


#define STRSET_DEFAULT_INIT_SIZE 100
#define STRSET_DEFAULT_LOAD_FACTOR 0.75f

stringset* stringset_new(unsigned int initial_size, float load_factor){
    stringset *str_set = (stringset*) malloc(sizeof(stringset)); //allocate the pointer for the whole string set
    str_set->num_buckets = initial_size ? initial_size : STRSET_DEFAULT_INIT_SIZE; //if the initial size is 0, then make it 100

    str_set->strll_array = (strll**)malloc((sizeof(strll*) * str_set->num_buckets)); // allocate the pointer for the node_array
    str_set->load_factor = (load_factor <= 0) ? STRSET_DEFAULT_LOAD_FACTOR : load_factor;
    str_set->num_elements = 0;
    unsigned int i = 0;
    for (i = 0; i < str_set->num_buckets; i++) {
        str_set->strll_array[i] = strll_new(); //intilize all the linked lists
    }

    return str_set;
}

void stringset_free(stringset **str_set){
    int i = 0;
    for (i = 0; i < (*str_set)->num_buckets; i++){
        strll_free((*str_set)->strll_array[i]);
    }
    free((*str_set)->strll_array);
    free(*str_set);
}

// int stringset_check(stringset *str_set, const char *str) {
//     unsigned long hashcode = hash_code(str_set, str);
//     node *tmp = str_set->node_array[hashcode];
//     while (tmp) {
//         if (strcmp(tmp->string, str) == 0)
//             return 1;
//         tmp = tmp->next;
//     }
//     return 0;
// }
// float stringset_load_value(stringset *str_set){
//     return str_set->load_factor * (float)str_set->node_array_length;
// }

void stringset_add(stringset **str_set, char *str) {

    unsigned long hashcode = hash_code(str_set, str);
    strll *ll = (*str_set)->strll_array[hashcode];
    strll_insert(ll, str);

}

int stringset_contains(stringset **str_set, char *str) {
    unsigned long hashcode = hash_code(str_set, str);
    strll *ll = (*str_set)->strll_array[hashcode];
    return strll_has_entry(ll, str);
}



// int stringset_remove(stringset *str_set, const char *str) {
//     unsigned long hashcode = hash_code(str_set, str) % str_set->node_array_length;
//     node *tmp = str_set->node_array[hashcode];
//     node *prev = NULL;
//     while (tmp) {
//         if(strcmp(tmp->string, str) == 0) {
//             if (prev){
//                 str_set->node_array[hashcode] = tmp->next;
//                 node_free(tmp);
//                 str_set->num_elements--;
//                 return 1;
//             }

//             list_remove_node(prev, tmp, str);
//             str_set->num_elements--;
//             return 1;
//         }
//         prev = tmp;
//         tmp = tmp->next;
//     }
//     return 0; // no such element existed, and hence was not removed
// }
// //int stringset_deepcopy(stringset *dest, stringset *src) {
// //    if (dest->node_array_length <= src->node_array_length)
// //        return 0;
// //
// //    return 0; //delete this
// //}

// /**
//  * Utility that copies one stringset's pointers into another one
//  * *NOTE* This does not actually copy the string set's elements, just pointers to them,
//  * use stringset_deepcopy if you want to actually copy the elements
//  * @param dest pointer to the string set that we are going to copy into
//  * @param src pointer to string set we are copying
//  * @return 0 if the dest string set's size is smaller than the src's, 1 otherwise
//  */
// //int stringset_copy(stringset *dest, stringset *src) {
// //    if (dest->node_array_length < src->node_array_length)
// //        return 0;
// //    int i;
// //    for (i = 0; i < src->node_array_length; i++){
// //        dest->node_array[i] = node_new_ptr();
// //        dest->node_array[i] = src->node_array[i];
// //    }
// //    dest->num_elements = src->num_elements;
// //    return 1;
// //}

// /**
//  * Doubles the size of the stringset and rehashes all of the elements inside it to fit the new size
//  * @param str_set The string set to rehash
//  */
// void stringset_rehash(stringset *str_set) {
//     puts("rehashing");
//     unsigned int num_elements = str_set->num_elements;
//     stringset *new_str_set = stringset_new(str_set->node_array_length * 2,
//                                            str_set->load_factor); //stringset double the size of original
//     int i;
//     for (i = 0; i < str_set->node_array_length; i++){
//         node *tmp = str_set->node_array[i];
//         while (tmp) { //loop as long as tmp->next isn't NULL
//             unsigned long new_hash = hash_code(new_str_set, tmp->string); // get the new hash according to new size
//             //check to see if the new stringset's node_array entry new_hash is NULL
//             node *next = tmp->next; //save tmp's next because we are going to reassign the pointer
//             if (new_str_set->node_array[new_hash]) { //case that it is NOT NULL
//                 node_list_insert_before(tmp, new_str_set->node_array[new_hash]); //we want it to go before the node thats already there
//             } else { // case that that node_array entry IS NULL
//                 new_str_set->node_array[new_hash] = tmp;
//                 tmp->next = NULL; //null because we know that this is the first in the list
//             }
//             tmp = next;
//         }
//     }
//     str_set->num_elements = num_elements;
//     str_set->node_array_length = new_str_set->node_array_length;
//     free(str_set->node_array);
//     str_set->node_array = new_str_set->node_array;
//     free(new_str_set);
// }

unsigned long hash_code(stringset **str_set, const char *str) { /* copied djb2 hashing algorithm */
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % (*str_set)->num_buckets;
}
