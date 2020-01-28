#include <iostream>

using namespace std;

int main()
{
    int countPeople = 0;
    cin >> countPeople;
    int call[100];
    int count = 0;

    for (int i = 0; i < countPeople; i++) {
        cin >> call[i];
    }

    for (int i = 0; i < countPeople; i++) {
        for (int j = i + 1; j < countPeople; j++) {
            if (call[j] == call[i]) {
                cout << i + 1 << " " << j + 1 << endl;
                break;
            }

            count++;
        }
    }

    cout << "Количество операций: " << count << endl;

    return 0;
}
