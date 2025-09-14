#include <stdio.h>
#include <stdbool.h>
#define ARR_LENGTH 10

void arr_swap(int *arr, int from_pos, int target_pos)
{
    if (from_pos < 0 || from_pos >= ARR_LENGTH) return;
    if (target_pos < 0 || target_pos >= ARR_LENGTH) return;

    int temp = arr[from_pos];
    arr[from_pos] = arr[target_pos];
    arr[target_pos] = temp;
}

bool arr_is_in(int *arr, int val)
{
    for (int i = 0; i < ARR_LENGTH; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}

// By delete, I want to set some value to -1
void arr_delete(int *arr, int pos)
{
    if (pos < 0 || pos >= ARR_LENGTH) return;
    arr[pos] = -1; // *(arr + pos) = -1; does the same thing
}

void arr_insert(int *arr, int pos, int val)
{
    if (pos < 0 || pos >= ARR_LENGTH) return;
    arr[pos] = val; // *(arr + pos) = val; does the same thing
}

// This moves all non zero values up to the front
void arr_colasce (int *arr) {
    int write_index = 0;

    for (int i = 0; i < ARR_LENGTH; i++) {
        if (arr[i])
            arr[write_index++] = arr[i];
    }

    while (write_index < ARR_LENGTH) {
        arr[write_index++] = 0;
    }

}

int main()
{
    int arr[ARR_LENGTH] = {0};

    arr_insert(arr, 2, 42);
    arr_insert(arr, 5, 99);

    arr_swap(arr, 2, 5);
    arr_delete(arr, 5);

    arr_colasce(arr);

    printf("Array: ");
    for (int i = 0; i < ARR_LENGTH; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Is 42 in array? %s\n", arr_is_in(arr, 42) ? "yes" : "no");
    printf("Is 99 in array? %s\n", arr_is_in(arr, 99) ? "yes" : "no");
    return 0;
}
