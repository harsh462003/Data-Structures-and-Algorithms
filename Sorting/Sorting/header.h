#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdint.h>
#include <stddef.h>

void selection_sort(int arr[], size_t len);
void bubble_sort(int arr[], size_t len);
void insertion_sort(int arr[], size_t len);
void merge_sort(int arr[], size_t left, size_t right);
void quick_sort(int arr[], int low, int high);

#endif // __HEADER_H__

