#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "header.h"

// Utility to check if an array is sorted
int is_sorted(int arr[], size_t len) {
    for (size_t i = 1; i < len; ++i) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}

// Utility to print arrays
void print_array(const char* label, int arr[], size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test_sorting_algorithms() {
    int original[] = {64, 34, 25, 12, 22, 11, 90};
    size_t len = sizeof(original) / sizeof(original[0]);
    int arr[10];

    // Selection Sort
    memcpy(arr, original, sizeof(original));
    selection_sort(arr, len);
    assert(is_sorted(arr, len));
    print_array("Selection Sort", arr, len);

    // Bubble Sort
    memcpy(arr, original, sizeof(original));
    bubble_sort(arr, len);
    assert(is_sorted(arr, len));
    print_array("Bubble Sort", arr, len);

    // Insertion Sort
    memcpy(arr, original, sizeof(original));
    insertion_sort(arr, len);
    assert(is_sorted(arr, len));
    print_array("Insertion Sort", arr, len);

    // Merge Sort
    memcpy(arr, original, sizeof(original));
    merge_sort(arr, 0, len - 1);
    assert(is_sorted(arr, len));
    print_array("Merge Sort", arr, len);

    // Quick Sort
    memcpy(arr, original, sizeof(original));
    quick_sort(arr, 0, len - 1);
    assert(is_sorted(arr, len));
    print_array("Quick Sort", arr, len);
}

int main() {
    test_sorting_algorithms();
    printf("All sorting algorithm tests passed!\n");
    return 0;
}
