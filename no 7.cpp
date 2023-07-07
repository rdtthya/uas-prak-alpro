#include <iostream>
#include <vector>
using namespace std;

bool isPrima(int n){
  if (n <= 1){
    return false;
  }

  for (int i = 2; i * i <= n; i++){
    if (n % i == 0){
      return false;
    }
  }

  return true;
}

void tampilkanBilanganPrima(int rentang) {
    vector<int> bilanganPrima;

    for (int i = 2; i <= rentang; i++) {
        if (isPrima(i)) {
            bilanganPrima.push_back(i);
        }
    }

    cout << "Bilangan prima antara 1 hingga " << rentang << ": ";
    for (int i = 0; i < bilanganPrima.size(); i++) {
        cout << bilanganPrima[i];
        if (i != bilanganPrima.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
}

int main() {
    int rentang = 20;

    tampilkanBilanganPrima(rentang);

    return 0;
}