#include "sort_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lexicographic_sort(const char *b, const char *a)
{
    int i = 0;

    do
    {
        if(a[i] > b[i])
            return 1;

        else if(a[i] < b[i])
            return -1;

        i++;
    }while(a[i] != '\0');

    return 0;
}


int lexicographic_sort_reverse(const char *a, const char *b)
{
    return (lexicographic_sort(b,a));
}


//it counts upper and lower case characters speratly so "Aa" count = 2
//all the other characters are being ignored so "1231#*&@*" count = 0
int count_distinct_characters(const char *a)
{
    int i;
    int counter = 0;
    char char_substract;
    bool switches_alphabet_lowercase[26] = { false };
    bool switches_alphabet_uppercase[26] = { false };
    bool *switches_alphabet;

    for(i=0; a[i] != '\0'; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            char_substract = 'a';
            switches_alphabet = switches_alphabet_lowercase;
        }

        else if(a[i] >= 'A' && a[i] <= 'Z')
        {
            char_substract = 'A';
            switches_alphabet = switches_alphabet_uppercase;
        }
        else
            continue;

        if(switches_alphabet[(a[i] - char_substract)])
            continue;

        switches_alphabet[a[i] - char_substract] = true;
        counter++;
    }

    return counter;
}


int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int size_a = count_distinct_characters(a);
    int size_b = count_distinct_characters(b);

    if(size_a > size_b)
        return -1;
    else if(size_a < size_b)
        return 1;
    else
        return lexicographic_sort(a,b);
}


int sort_by_length(const char *a, const char *b)
{
    int size_a = strlen(a);
    int size_b = strlen(b);

    if(size_a < size_b)
        return 1;
    else if (size_a > size_b)
        return -1;
    else
        return lexicographic_sort (a,b);
}


void swap(void **one, void **two)
{
    void *aux;
    aux = *one;
    *one = *two;
    *two = aux;
}


//we are using last element as Pivot
int quick_sort_part(char** arr,int p, int q,
                    int (*cmp_func)(const char *a, const char *b))
{
    char* pivot = arr[q];
    int i = (p - 1);
    int j;

    for(j=p; j <= q - 1; j++)
    {
        if(cmp_func(arr[j],pivot) > 0)
        {
            i++;
            swap((void**)(&arr[i]), (void**)(&arr[j]));
        }
    }

    swap((void**)(&arr[i + 1]), (void**)(&arr[q]));
    return (i + 1);
}


void quick_sort(char **arr,const int p, const int q,
                int (*cmp_func)(const char *a, const char *b))
{
    int pivot;

    if (p < q)
    {
        pivot = quick_sort_part(arr, p, q, cmp_func);
        quick_sort(arr, p, pivot - 1, cmp_func);
        quick_sort(arr, pivot + 1, q, cmp_func);
    }
}


void string_sort(char **arr,const int len,
                 int (*cmp_func)(const char *a, const char *b))
{
    quick_sort(arr, 0, len - 1, cmp_func);
}