#include <stdio.h>
#include <stdlib.h>
#define RANGE 256

//Генерируем массив случайных целых чисел от 0 до 100
void fillArray(int* arr, int len) {
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100;
}

//Печать массива
void printArray(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Замена чисел
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

//Копирование массива
void copyArray(int* arrFrom, int* arrTo, int len) {
    for (int i = 0; i < len; i++)
        arrTo[i] = arrFrom[i];
}

int getMin(int* arr, int len) {
    int res = arr[0];
    for (int i = 0; i < len; i++)
        if (arr[i] < res)
            res = arr[i];
    return res;
}

int getMax(int* arr, int len) {
    int res = arr[0];
    for (int i = 0; i < len; i++)
        if (arr[i] > res)
            res = arr[i];
    return res;
}

//Пузырьковый метод (НЕоптимизированный)
int bubbleSort(int* arr, int len) {
    int operations = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++) {
            operations++;
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }

    return operations;
}

//Пузырьковый метод (оптимизированный)
int bubbleSortOpt(int* arr, int len) {
    int operations = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            operations++;

            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }

    return operations;
}

//Шейкер
int shaker(int* arr, int len) {
    int operations = 0;

    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - 1 - i; j++) {
            operations++;
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }

        for (int j = len - 2 - i; j > i; j--) {
            operations++;
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }

    return operations;
}

//Шейкер. Вариант преподавателя
//Количество операций как у оптимизированного пузырька, но выше скорость
int shakerPrepod(int* arr, int len) {
    int operations = 0;
    int left = 1;
    int right = len - 1;
    while (left <= right) {
        for (int i = left; i < right; i++) {
            operations++;
            if (arr[i] > arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
        }
        right--;

        for (int i = right; i >= left; i--) {
            operations++;
            if (arr[i - 1] > arr[i])
                swap(&arr[i], &arr[i]);
        }
        left++;
    }
    return operations;
}

//Pigeon Hole Sort
void pigeonHoleSort(int* arr, int len) {
    //Ищем диапазон элементов массива
    int max = 0;
    int min = 0;

    if (len > 0) {
        max = arr[0];
        min = max;
    }

    for (int i = 0; i < len; i++)
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];

    //Создаем массив с количеством элементов max - min + 1
    int size = max - min + 1;

    int arrC[size];

    for (int i = 0; i < size; i++)
        arrC[i] = 0;

    for (int i = 0; i < len; i++) {
        arrC[arr[i] - min] = arr[i];
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arrC[i]) {
            arr[j] = arrC[i];
            j++;
        }
    }
}

//Пигеон. Вариант преподавателя
//Создаем вспомогательный массив, который называется частотный.
//Нулевой элемент - минимум исходного массива.
//Каждый элемент этого массива - кол-во встречающихся соотвествующих чисел основного массива относительно минимума
int pigeonPrepod(int* arr, int len) {
    int steps = 0;
    int min = getMin(arr, len);
    int max = getMax(arr, len);

    const int length = max - min + 1;
    int freq[RANGE] = {0};
    for (int i = 0; i < len; i++) {
        steps++;
        freq[arr[i] - min]++;
    }

    int arrIndex = 0;
    for (int i = 0; i < length; i++)
        for (int elem = freq[i]; elem > 0; elem--) {
            steps++;
            arr[arrIndex++]= i + min;
        }

    return steps;
}

int main(void)
{
    int size = 10;

    printf("Неоптимизированный пузырьковый метод\n");
    int arr1[10] = {9, 8, 7, 7, 6, 5, 4, 3, 2, 1};
    printArray(arr1, size);
    int oper = bubbleSort(arr1, size);
    printArray(arr1, size);
    printf("Количество операций: %d\n\n", oper);

    //-------------------------------------------------------------------------------

    printf("Oптимизированный пузырьковый метод\n");
    int arr2[10] = {9, 8, 7, 7, 6, 5, 4, 3, 2, 1};
    printArray(arr2, size);
    oper = bubbleSortOpt(arr2, size);
    printArray(arr2, size);
    printf("Количество операций: %d\n\n", oper);

    //-------------------------------------------------------------------------------

    printf("Метод шейкер\n");
    int arr3[10] = {9, 8, 7, 7, 6, 5, 4, 3, 2, 1};
    printArray(arr3, size);
    oper = shaker(arr3, size);
    printArray(arr3, size);
    printf("Количество операций: %d\n\n", oper);

    //-------------------------------------------------------------------------------

    printf("Pigeon Hole Sort\n");
    int arr4[size];
    fillArray(arr4, size);
    printArray(arr4, size);
    pigeonHoleSort(arr4, size);
    printArray(arr4, size);
    printf("\n");

    //-------------------------------------------------------------------------------

    printf("Pigeon Препод\n");
    int arr5[size];
    fillArray(arr5, size);
    printArray(arr5, size);
    oper = pigeonPrepod(arr5, size);
    printArray(arr5, size);
    printf("Количество операций: %d\n\n", oper);
    printf("\n");

    return 0;
}
