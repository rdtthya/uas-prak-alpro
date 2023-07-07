#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> array = {3,7,10,13,16};

  for (int i = 0; i < array.size(); i++){
    array[i] += 5;
  }

  cout << "Jumlah array setelah ditambah 5 : ";
  for (int i = 0; i < array.size(); i++){
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}