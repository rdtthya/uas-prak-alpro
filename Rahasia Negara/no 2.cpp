#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> array = {2, 4, 6, 8, 10};

    if (array.size() >= 3) {
        int elemenKe3 = array[2];
        cout << "Elemen ke-3 dari array adalah: " << elemenKe3 << endl;
    } else {
        cout << "Array tidak memiliki elemen ke-3." << endl;
    }

    return 0;
}
