#include "sort_array.h"

int lexicographic_sort(const char* b, const char* a)
{
    int size;
    int i;
    bool equal = false;

    if (strlen(b) > strlen(a))
        size = strlen(a);
    else
        size = strlen(b);

    for(i=0; i<size; i++)
    {
        if(a[i] > b[i])
            return 1;

        else if(a[i] < b[i])
            return 0;
    }

    if(strlen(b) > strlen(a))
        return 0;
    else
        return 1;

    return 0;
}


int lexicographic_sort_reverse(const char* a, const char* b)
{
    return (lexicographic_sort(b,a));
}


int count_distinct_characters(const char* a)
{
    int i;
    int size = strlen(a);
    int counter = 0;
    bool switches_alphabet[26] = { false };

    for(i=0;i<size;i++)
    {
        if(switches_alphabet[((int)(a[i] - 'a'))])
            continue;

        switches_alphabet[a[i] - 'a'] = true;
        counter++;
    }

    return counter;
}


int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
    int counter = 0;

    int i;
    bool switches_alphabet[25];

    int size_a = count_distinct_characters(a);
    int size_b = count_distinct_characters(b);

    if(size_a > size_b)
        return 0;
    else if(size_a < size_b)
        return 1;
    else
        return lexicographic_sort(a,b);
}


int sort_by_length(const char* a, const char* b)
{
    if(strlen(a) < strlen(b))
        return 1;
    else if (strlen(a) > strlen((b)))
        return 0;
    else
        return lexicographic_sort (a,b);
}


void swap(void** one, void** two)
{
    void *aux;
    aux = *one;
    *one = *two;
    *two = aux;
}


//we are using last element as Pivot
int quick_sort_part(char** arr,int p, int q,
                    int (*cmp_func)(const char* a, const char* b))
{
    char* pivot = arr[q];
    int i = (p -1);
    int j;

    for(j=p; j<=q - 1; j++)
    {
        if(cmp_func(arr[j],pivot))
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[q]);
    return (i+1);
}


void quick_sort(char** arr,const int p, const int q,
                int (*cmp_func)(const char* a, const char* b))
{
    int pivot;
    if (p < q)
    {
        pivot = quick_sort_part(arr, p, q,cmp_func);
        quick_sort(arr, p, pivot-1, cmp_func);
        quick_sort(arr, pivot+1, q, cmp_func);
    }
}


void string_sort(char** arr,const int len,
                int (*cmp_func)(const char* a, const char* b))
{
    quick_sort(arr, 0,len -1,cmp_func);
}