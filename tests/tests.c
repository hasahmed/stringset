#include <stdio.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../node.h"
#include "../stringset.h"
#include "../util.h"

int p_init(){
    //this is the function used for setup of the suite
    puts("initializing");
    return 0;
}

int p_cleanup(){
    puts("cleaning up");
    return 0;
}

int trippleNum(int num){
    return num * 3;
}

int doubleNum(int x){
    return x * 2;
}

void test_doubleNum(){
    CU_ASSERT_EQUAL(doubleNum(2), 4);
}
void test_trippleNum(){
    CU_ASSERT_EQUAL(trippleNum(2), 6);
}

int main(){
    CU_initialize_registry(); //must call first
    CU_pSuite suite = CU_add_suite("Sweet1", &p_init, &p_cleanup);
    if(suite == 0){
        puts("successfully added suite");
    }
    /*CU_pTest test1 = CU_add_test(suite, "test1", test_doubleNum);*/
    CU_ADD_TEST(suite, test_doubleNum);
    CU_pTest test2 = CU_add_test(suite, "test2", test_trippleNum);
    CU_basic_set_mode(CU_BRM_NORMAL);
    //CU_basic_run_tests();
    CU_basic_run_suite(suite);


    puts("Go to cleanup");
    CU_cleanup_registry();
}
