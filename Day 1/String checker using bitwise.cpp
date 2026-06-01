#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int lf = 0;
    int uf = 0;
    int nf = 0;

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            lf |= (1 << (ch - 'a'));
        } else if (ch >= 'A' && ch <= 'Z') {
            uf |= (1 << (ch - 'A'));
        } else if (ch >= '0' && ch <= '9') {
            nf |= (1 << (ch - '0'));
        }
    }

    int alpha = (1 << 26) - 1;
    int nums = (1 << 10) - 1;

    if (lf == alpha &&
        uf == alpha &&
        nf == nums) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
