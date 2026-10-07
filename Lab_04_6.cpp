#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h> // Потрібно для кодування кирилиці в консолі Windows

using namespace std;

int main() {
    // Налаштування виводу UTF-8 в консолі Windows
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Завдання 4.6 (Варіант 3) ===" << endl << endl;

    // 1. Спосіб while(...) { ... while(...) {...} ... }
    {
        double S = 0.0;
        int i = 1;
        while (i <= 15) {
            double P = 1.0;
            int k = 1;
            while (k <= i) {
                P *= sqrt((double)k);
                k++;
            }
            S += (sin(10.0 * i) + cos(10.0 * i)) / P;
            i++;
        }
        cout << "1) Вкладені цикли while:      S = " << fixed << setprecision(8) << S << endl;
    }

    // 2. Спосіб do { ... do { ... } while(...); ... } while(...);
    {
        double S = 0.0;
        int i = 1;
        do {
            double P = 1.0;
            int k = 1;
            do {
                P *= sqrt((double)k);
                k++;
            } while (k <= i);
            S += (sin(10.0 * i) + cos(10.0 * i)) / P;
            i++;
        } while (i <= 15);
        cout << "2) Вкладені цикли do...while: S = " << fixed << setprecision(8) << S << endl;
    }

    // 3. Спосіб for з інкрементом (++): for(...; ...; i++)
    {
        double S = 0.0;
        for (int i = 1; i <= 15; i++) {
            double P = 1.0;
            for (int k = 1; k <= i; k++) {
                P *= sqrt((double)k);
            }
            S += (sin(10.0 * i) + cos(10.0 * i)) / P;
        }
        cout << "3) Вкладені цикли for (++):   S = " << fixed << setprecision(8) << S << endl;
    }

    // 4. Спосіб for з декрементом (--): for(...; ...; i--)
    {
        double S = 0.0;
        for (int i = 15; i >= 1; i--) {
            double P = 1.0;
            for (int k = i; k >= 1; k--) {
                P *= sqrt((double)k);
            }
            S += (sin(10.0 * i) + cos(10.0 * i)) / P;
        }
        cout << "4) Вкладені цикли for (--):   S = " << fixed << setprecision(8) << S << endl;
    }

    return 0;
}