# 0 "header_demo.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "header_demo.c"
# 1 "include/sf_math.h" 1
int add(int, int);
# 2 "header_demo.c" 2
# 1 "include/sf_science.h" 1
# 1 "include/sf_math.h" 1
int add(int, int);
# 2 "include/sf_science.h" 2
# 3 "header_demo.c" 2






int main(int argc, char const *argv[])
{
    int sum = add(1, 2);
    printf("Your program compiled and the ouput is: %d\n", sum);
    return 0;
}
