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
    int *ratingSort = new int[n]; //Рейтинги, отсортированные по возрастанию
    int *star = new int[n]; //Звезды

    int k = 0;
    int min = 0;
    int max = 0;
    int m = 0;
    for (int i = 0 ; i < n; ++i) {
        //Ввод
        cin >> rating[i];
        m++;

        //Формирование массива с отсортированным рейтингом
        for (int j = 0; j < m; ++j) {
            if ()
        }
        ratingSort[i] = rating[i];

        if (ratingSort[i] < min) {
            min = i;
        }

        if (ratingSort[i] > ratingSort[max]) {
            max = i;
        }

        //Формирование упорядоченного по возрастанию массива со звездами
        for (int j = 0; j < n / 5; j++) {
            star[k] = i + 1;
            k++;
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
