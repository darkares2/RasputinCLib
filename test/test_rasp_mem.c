#include "rasp_mem.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

typedef struct {
    int num;
    int other;
} Test_item;

void test_array_simple() {
    RaspArray *array = rasp_array_init(sizeof(Test_item));
    Test_item item;
    item.num = 1;
    item.other = 2;
    rasp_array_add(array, &item);
    rasp_array_delete(array, 0);
    rasp_array_free(array);
}

void test_array_realloc_and_delete_all() {
    RaspArray *array = rasp_array_init(sizeof(Test_item));
    for(int idx = 0; idx < 500; ++idx) {
        Test_item item;
        item.num = idx;
        item.other = idx + 1;
        rasp_array_add(array, &item);
    }
    int idx = 500;
    while(idx-- > 0) {
        Test_item *ptr = array->data;
        TEST_ASSERT_EQUAL(500-(idx+1), ptr[0].num);
        rasp_array_delete(array, 0);
    }
    TEST_ASSERT_EQUAL(0, array->array_length);
    rasp_array_free(array);
}

void test_array_sequence_delete_middle_expect_others_intact() {
    RaspArray *array = rasp_array_init(sizeof(Test_item));
    for(int idx = 0; idx < 10; ++idx) {
        Test_item item;
        item.num = idx;
        item.other = idx + 1;
        rasp_array_add(array, &item);
    }
    rasp_array_delete(array, 4);
    TEST_ASSERT_TRUE(array->array_length == 9);
    Test_item *ptr = array->data;
    for(int idx = 0; idx < array->array_length; ++idx) {
        if (idx < 4)
            TEST_ASSERT_EQUAL(idx, ptr[idx].num);
        else
            TEST_ASSERT_EQUAL(idx+1, ptr[idx].num);
    }
    rasp_array_free(array);
}
