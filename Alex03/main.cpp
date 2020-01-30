#include <iostream>

using namespace std;

int main()
{
    cout << "Александр Morgan" << endl;

    long beginTime = clock();
    uint8_t n = 0;
    cin >> (int&)n;
    uint8_t h[n];
    uint8_t identical = n/5;

    //Сортировка массива при вводе
    uint8_t min = 0;
    uint8_t max = 0;
    for (uint8_t i = 0; i < n; ++i) {

        cin >> (int&)h[i];

        if (h[i] < h[min]) {
            min = i;
        }

        if (h[i] > h[max]) {
            max = i;
        }
    }

    uint8_t star = 0;
    uint8_t k = 0;
    for (uint8_t i = 0; i < n; ++i) {
        if (k == 0) {
            star++;
        }

        if (k == identical - 1) {
            k = 0;
        }
        else {
            k++;
        }

        h[min] = star;
        min = max;

        for (uint8_t i = 0; i < n; ++i) {
            if (h[i] < h[min] && h[i] > star) {
                min = i;
            }
        }
    }

    for (uint8_t i = 0; i < n; ++i) {
        cout << static_cast<uint16_t>(h[i]) << ' ';
    }

    cout << endl;

    long endTime = clock();

    long resultTime = endTime - beginTime;

    cout << "Количество тактов: " << resultTime << endl;

    return 0;
}
