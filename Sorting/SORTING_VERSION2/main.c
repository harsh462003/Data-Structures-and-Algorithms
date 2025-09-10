#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "header.h"

int is_sorted(int arr[], size_t len) {
    for (size_t i = 1; i < len; ++i) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}

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
    print_array("Original for Selection Sort", arr, len);
    selection_sort(arr, len);
    assert(is_sorted(arr, len));
    printf("\n");

    // Bubble Sort
    memcpy(arr, original, sizeof(original));
    print_array("Original for Bubble Sort", arr, len);
    bubble_sort(arr, len);
    assert(is_sorted(arr, len));
    printf("\n");

    // Insertion Sort
    memcpy(arr, original, sizeof(original));
    print_array("Original for Insertion Sort", arr, len);
    insertion_sort(arr, len);
    assert(is_sorted(arr, len));
    printf("\n");

    // Merge Sort (no pass display yet)
    memcpy(arr, original, sizeof(original));
    print_array("Original for Merge Sort", arr, len);
    merge_sort(arr, 0, len - 1);
    print_array("Merge Sort Result", arr, len);
    assert(is_sorted(arr, len));
    printf("\n");

    // Quick Sort (no pass display yet)
    memcpy(arr, original, sizeof(original));
    print_array("Original for Quick Sort", arr, len);
    quick_sort(arr, 0, len - 1);
    print_array("Quick Sort Result", arr, len);
    assert(is_sorted(arr, len));
    printf("\n");
}

int main() {
    test_sorting_algorithms();
    printf("All sorting tests passed!\n");
    return 0;
}

