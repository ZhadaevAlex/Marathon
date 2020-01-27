#include <iostream>

using namespace std;

//Замена чисел
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    int operations = 0;
    int n; //Кол-во отелей
    cin >> n;

    int *rating = new int[n]; //Рейтинги
    int *ratingSort = new int[n]; //Рейтинги, отсортированные по воззрастанию
    int *star = new int[n]; //Звезды

    //Ввод
    for (int i = 0 ; i < n; ++i) {
        cin >> rating[i];
    }

    //
    for (int i = 0; i < n; i++) {
        ratingSort[i] = rating[i];
    }

    //Формирование упорядоченного по возрастанию массива со звездами
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 5; j++) {
            star[k] = i + 1;
            k++;
        }
    }

    //Сортировка массива с рейтингами
    //Пузырьковый метод (НЕоптимизированный)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            operations++;
            if (ratingSort[j] > ratingSort[j + 1]) {
                swap(&ratingSort[j], &ratingSort[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (rating[i] == ratingSort[j]) {
                cout << star[j] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}
