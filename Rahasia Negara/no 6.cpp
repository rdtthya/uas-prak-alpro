#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> array = {1,2,3,4,5,6,7,8,9,10};
  int jumlahGenap = 0;
  int jumlahGanjil = 0;

  for (int i = 0; i < array.size(); i++){
    if (array[i] % 2 == 0){
      jumlahGenap++;
    }
    else{
      jumlahGanjil++;
    }
  }

  cout << "Jumlah elemen genap : " << jumlahGenap << endl;
  cout << "Jumlah elemen ganjil : " << jumlahGanjil << endl;

  return 0;
}