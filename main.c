/*==============================================================================
* Title: Sorting an array of strings 
*
* Author: Dawid Wesierski
* Language: C
* To Compile: gcc 11.2.0
* Version: 0.1.0.0
* Date: 18.07.2022 
*
* ------------------------------------------------------------------------------
* 
* Description:
* this program shows the implementation the algorithm that sorts an array of 
*strings in 4 diffrent ways one of them is lexicographic_sort (that takes the|
*dictionary approach when you sort by the order of the letters)
* 
*=============================================================================*/

#include "sort_array.h"

int main() 
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    return 0;
}