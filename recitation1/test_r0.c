#include <string.h>
#include <criterion/criterion.h>
#include "r0.h"

// This test is part of the math suite to test addition
Test(math, addition) {
    cr_assert_eq(add(2, 3), 5, "2 + 3 should equal 5");
}
