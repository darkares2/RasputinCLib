#include "unity.h"

extern void test_array_simple();
extern void test_array_sequence_delete_middle_expect_others_intact();
extern void test_array_realloc_and_delete_all();

int main(void) {
   UNITY_BEGIN();
   RUN_TEST(test_array_simple);
   RUN_TEST(test_array_sequence_delete_middle_expect_others_intact);
   RUN_TEST(test_array_realloc_and_delete_all);
   return UNITY_END();
}
