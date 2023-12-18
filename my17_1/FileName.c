#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>

void sort_bubble(int* ptrarr, int n);
void sort_shaker(int* ptrarr, int n);
void sort_vibor(int* ptrarr, int n);
void sort_vstavka(int* ptrarr, int n);

int main() 
{
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int arr[100];
    printf("Введите массив: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    sort_bubble(arr, n);
    printf("Пузырьковая сортировка:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort_shaker(arr, n);
    printf("Шейкерная сортировка:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort_selection(arr, n);
    printf("Сортировка выбором:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort_insertion(arr, n);
    printf("Сортировка вставками:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_bubble(int* ptrarr, int n) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (ptrarr[j] > ptrarr[j + 1]) 
            {
                temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

void sort_shaker(int* ptrarr, int n) 
{
    int temp;
    int left = 0, right = n - 1;
    while (left <= right) {
        for (int i = left; i < right; i++) 
        {
            if (ptrarr[i] > ptrarr[i + 1]) 
            {
                temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) 
        {
            if (ptrarr[i] < ptrarr[i - 1]) 
            {
                temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
            }
        }
        left++;
    }
}

void sort_vibor(int* ptrarr, int n) 
{
    int min_index, temp;
    for (int i = 0; i < n - 1; i++) 
    {
        min_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (ptrarr[j] < ptrarr[min_index]) 
            {
                min_index = j;
            }
        }
        temp = ptrarr[i];
        ptrarr[i] = ptrarr[min_index];
        ptrarr[min_index] = temp;
    }
}

void sort_vstavka(int* ptrarr, int n) 
{
    int key, j;
    for (int i = 1; i < n; i++) 
    {
        key = ptrarr[i];
        j = i - 1;
        while (j >= 0 && ptrarr[j] > key) 
        {
            ptrarr[j + 1] = ptrarr[j];
            j = j - 1;
        }
        ptrarr[j + 1] = key;
    }
}