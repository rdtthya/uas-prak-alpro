#include <iostream>
#include <vector>
using namespace std;

void cariMaxMin(vector<int> array, int& max, int& min) {
    if (array.size() > 0) {
        max = array[0];
        min = array[0];

        for (int i = 1; i < array.size(); i++) {
            if (array[i] > max) {
                max = array[i];
            }
            if (array[i] < min) {
                min = array[i];
            }
        }
    }
}

int main() {
    vector<int> array = {10, 5, 20, 15, 30};
    int max, min;

    cariMaxMin(array, max, min);

    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;

    return 0;
}
