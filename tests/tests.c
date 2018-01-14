#include <stdio.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../node.h"
#include "../stringset.h"
#include "../util.h"

node *next, *first, *n, *nodelist;

int node_test_suite_init(){
    next = node_new("goodbye", NULL); //last in list
    first = node_new("hello", next); //first in list
    n = node_new("hello", NULL);
    nodelist = node_new("list", NULL);
    return 0;
}
int node_test_suite_cleanup(){
    node_free(next);
    node_free(first);
    node_free(n);
    node_free_list(nodelist);
    return 0;
}

void test_node_new__node_free(){
    CU_ASSERT_STRING_EQUAL("hello", n->string);
    CU_ASSERT_PTR_NULL(n->next);
}
void test_linked_nodes(){
    CU_ASSERT_STRING_EQUAL("hello", first->string);
    CU_ASSERT_EQUAL(strcmp("goodbye", next->string), 0);
    CU_ASSERT_EQUAL(next, first->next);
    CU_ASSERT_PTR_NULL(next->next);
}

void test_node_list_insert_after(){
    node *tmp = list_insert_new_after(nodelist, "tacos");
    CU_ASSERT_EQUAL(tmp, nodelist->next);
    CU_ASSERT_PTR_NULL(nodelist->next->next);
}

int main(){
    CU_initialize_registry(); //must call first

    //node tests
    CU_pSuite node_suite = CU_add_suite("Node Tests", &node_test_suite_init, &node_test_suite_cleanup);
    if(node_suite == 0){
        puts("successfully added suite");
    }
    CU_ADD_TEST(node_suite, test_node_new__node_free);
    CU_ADD_TEST(node_suite, test_linked_nodes);
    CU_ADD_TEST(node_suite, test_node_list_insert_after);
    CU_basic_run_suite(node_suite);
    //end node tests




    CU_cleanup_registry();
}
