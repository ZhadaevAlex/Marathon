#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Количество суммируемых чисел за пределами диапазона от 1 до 100" << endl;
        return 1;
    }

    int sum = 0;
    while (n > 0) {
        int number = 0;
        cin >> number;

        if (number >= 1 && number <= 100) {
            sum += number;
            n--;
        }
    }

    cout << sum << endl;

    return 0;
}
