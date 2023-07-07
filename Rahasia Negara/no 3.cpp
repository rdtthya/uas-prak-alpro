#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> array = {1,2,3,4,5,6};

  cout << "Menampilkan semua elemen : ";
  for (int i = 0; i < array.size(); i++){
    cout << array[i] << " ";
  }

  return 0;
}