#include <stdio.h>
#include <assert.h>
#include <matrix.h>
#include "criterion/criterion.h"

#define TEST_TIMEOUT 30

/**
 * Write all student test cases inside of this file
 */

TestSuite(student_suite, .timeout = TEST_TIMEOUT);

Test(student_suite, name_of_test, .description = "description of test")
{
}