#include <stdio.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../node.h"
#include "../stringset.h"
#include "../util.h"

int node_test_suite_init(){
    return 0;
}
int node_test_suite_cleanup(){
    return 0;
}

void test_node_new__node_free(){
    node *n = node_new("hello", NULL);
    CU_ASSERT_STRING_EQUAL("hello", n->string);
    CU_ASSERT_PTR_NULL(n->next);
    node_free(n);
}
void test_linked_nodes(){
    node *next = node_new("goodbye", NULL); //last in list
    node *first = node_new("hello", next); //first in list

    CU_ASSERT_STRING_EQUAL("hello", first->string);

    printf("%d\n", strcmp(next->string, "goodbye"));
    CU_ASSERT_STRING_EQUAL("goodbye", next->string);

//    CU_ASSERT_EQUAL(next, first->next);

    CU_ASSERT_PTR_NULL(next->next);
    node_free(next);
    node_free(first);
}

int main(){
    CU_initialize_registry(); //must call first
    CU_pSuite node_suite = CU_add_suite("Node Tests", &node_test_suite_init, &node_test_suite_cleanup);
    if(node_suite == 0){
        puts("successfully added suite");
    }
    CU_ADD_TEST(node_suite, test_node_new__node_free);
    CU_ADD_TEST(node_suite, test_linked_nodes);
    CU_basic_run_suite(node_suite);
    CU_cleanup_registry();
}
