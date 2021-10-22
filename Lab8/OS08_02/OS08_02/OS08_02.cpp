#include <iostream>
#include <ctime>

using namespace std;

int main() {
    clock_t start = clock();
    bool f5 = true, f10 = true;

    for (int i = 0;; i++) {
        if ((clock() - start) / CLOCKS_PER_SEC == 5 && f5) {
            cout << "5 c - " << i << endl;
            f5 = false;
        }
        else if ((clock() - start) / CLOCKS_PER_SEC == 10 && f10) {
            cout << "10 c - " << i << endl;
            f10 = false;
        }
        else if ((clock() - start) / CLOCKS_PER_SEC == 15) {
            cout << "15 c - " << i << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
