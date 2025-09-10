#include <stdio.h>
#include "header.h"

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void print_pass(const char* algo, int arr[], size_t len, int pass) {
    printf("%s - Pass %d: ", algo, pass);
    for (size_t i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Selection Sort
void selection_sort(int arr[], size_t len) {
    for (size_t i = 0; i < len - 1; ++i) {
        size_t min = i;
        for (size_t j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
        print_pass("Selection Sort", arr, len, i + 1);
    }
}

// Bubble Sort
void bubble_sort(int arr[], size_t len) {
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
        print_pass("Bubble Sort", arr, len, i + 1);
    }
}

// Insertion Sort
void insertion_sort(int arr[], size_t len) {
    for (size_t i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        print_pass("Insertion Sort", arr, len, i);
    }
}

// Merge Sort helper
static void merge(int arr[], size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    int L[n1], R[n2];

    for (size_t i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (size_t j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

