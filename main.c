#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void func1();
void func2();
void swap(int *x, int *y);
int countWords(const char *str);
int stringlength(char str[]);
void reverseString(char *str);
void reverseArray(int *array, int size);
int sumArray(int *array, int n);
void stringcopy(char *str1, char *str2);
void sortwords();
int compare();

int main()
{
    // Opgave 1
    func1();
    // Opgave 2
    func2();
    // Opgave 3
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Opgave 4
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        printf("%d\n", *(ptr + i));
    }

    // Opgave 5
    int *number = (int *)malloc(sizeof(int));

    *number = 30;

    printf("%d\n", *number);

    free(number);

    // Opgave 6
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sumArray(arr, n));

    // Opgave 7
    char str1[] = "Hej med dig";
    char *str2 = "Kage";

    printf("%s | %s\n", str1, str2);
    stringcopy(str1, str2);
    printf("%s | %s\n", str1, str2);

    // Opgave 8
    printf("Length of string: %d\n", stringlength("Hejmeddig"));

    // Opgave 9
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    reverseArray(arr1, n1);
    for (int i = 0; i < n1; i++)
    {
        printf("%d\n", arr1[i]);
    }

    // Anden opgave 2
    char str[] = "rambuk";
    reverseString(str);
    printf("Vendt streng: %s\n", str);

    // Anden opgave 3
    int bubblesortArr[] = {64, 34, 25, 12, 22, 11, 90};
    int bubblesortN = sizeof(bubblesortArr) / sizeof(bubblesortArr[0]);
    bubbleSort(bubblesortArr, n);
    printf("Sorteret array: \n");
    for (int i = 0; i < bubblesortN; i++)
        printf("%d ", bubblesortArr[i]);

    printf("\n");

    // Anden opgave 4
    char strWithWords[] = "Hej med dig, verden!";
    printf("Antallet af ord: %d\n", countWords(strWithWords));

    // Anden opgave 5
    sortwords();

    return 0;
}

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void sortwords()
{
    char str[] = "this is a test string that can be sorted";
    char *words[MAX_WORDS];
    char *token;
    int i, n = 0;

    token = strtok(str, " ");
    while (token != NULL && n < MAX_WORDS)
    {
        words[n++] = strdup(token);
        token = strtok(NULL, " ");
    }

    qsort(words, n, sizeof(char *), compare);

    printf("Sorterede ord:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }
}

int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int countWords(const char *str)
{
    int state = 0;
    int wordCount = 0;

    while (*str)
    {
        if (isspace(*str))
        {
            state = 0;
        }
        else if (state == 0)
        {
            state = 1;
            ++wordCount;
        }
        ++str;
    }

    return wordCount;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int stringlength(char str[])
{
    const char *ptr = str;
    while (*ptr)
        ++ptr;
    return ptr - str;
}

void reverseString(char *str)
{
    char *start = str;
    char *end = str;
    while (*end)
    {
        end++;
    }
    end--;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseArray(int *array, int size)
{
    int *start = array;
    int *end = array + size - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void stringcopy(char *str1, char *str2)
{
    strcpy(str1, str2);
}

void func1()
{
    int x = 10;
    int *ptr = &x;

    *ptr = 20;

    printf("%d\n", *ptr);
}

void func2()
{
    int x = 10;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;

    **ptr2 = 30;

    printf("%d\n", **ptr2);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sumArray(int *array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}