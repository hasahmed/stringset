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

int main(){
    CU_initialize_registry(); //must call first
    CU_pSuite node_suite = CU_add_suite("Node Tests", &node_test_suite_init, &node_test_suite_cleanup);
    if(node_suite == 0){
        puts("successfully added suite");
    }
    CU_ADD_TEST(node_suite, test_node_new__node_free);
    CU_basic_run_suite(node_suite);
    CU_cleanup_registry();
}
