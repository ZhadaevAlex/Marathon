#include <iostream>
#include <ctime>

using namespace std;

//Замена чисел
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

//Пузырьковый метод (оптимизированный)
int bubbleSortOpt(int* arr, int length) {
    int operations = 0;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1 - i; ++j) {
            operations++;

            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }

    return operations;
}

int main()
{
    cout << "Александр Жадаев" << endl;

    long beginTime = clock();
    int n; //Кол-во отелей
    cin >> n;

    int *rating = new int[n]; //Рейтинги
    int *ratingSort = new int[n]; //Рейтинги, отсортированные по возрастанию
    int *star = new int[n]; //Звезды

    int s = 0;
    int j = 0;
    for (int i = 0 ; i < n; ++i) {
        //Ввод
        cin >> rating[i];

        //Заполнение отсортированного массива начальными значениями
        ratingSort[i] = rating[i];

        //Формирование упорядоченного по возрастанию массива со звездами
        if (j == n / 5) {
            s++;
            j = 0;
        }

        j++;

        star[i] = s + 1;
    }

    //Сортировка массива
    bubbleSortOpt(ratingSort, n);

    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (rating[i] == ratingSort[j])
                cout << star[j] << " ";

    cout << endl;

    delete[] rating;
    delete[] ratingSort;
    delete[] star;

    long endTime = clock();

    long resultTime = endTime - beginTime;

    cout << "Количество тактов: " << resultTime << endl;

    return 0;
}
