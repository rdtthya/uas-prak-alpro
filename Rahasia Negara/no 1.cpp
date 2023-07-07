#include <iostream>
#include <vector>
using namespace std;

int cariIndeks(vector<int> arr, int angka) {
    int indeks = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == angka) {
            indeks = i;
            break;
        }
    }
    return indeks;
}

int main() {
    vector<int> array = {2, 4, 6, 8, 10};
    int angka = 8;
    int indeks = cariIndeks(array, angka);
    cout << "Angka " << angka << " berada pada indeks " << indeks << endl;
    }