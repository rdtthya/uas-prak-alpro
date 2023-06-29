#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rakbuku {
	private :
		string noRak;
		string lokasi;
		vector<Buku> bukuDiRak;
		
	public :
		Rakbuku(string noRak, string lokasi){
			this->noRak = noRak;
			this->lokasi = lokasi;
		}
		string getNoRak(){
			return noRak;
		}
		string getLokasi(){
			return lokasi;
		}
		void tambahBuku(Buku book){
			bukuDiRak.push_back(book);
		}
		void hapusBuku(string nama){
			for (auto book = bukuDiRak.begin(); book != bukuDiRak.end(); book++){
				if ((*book).getJudul() == nama){
					bukuDiRak.erase(book);
					break;
				}
			}
		}
		void listBuku(){
			garis();
			cout << "Buku-buku yang terdapat pada rak " << noRak << ": " << endl;
			for (Buku book : bukuDiRak){
				book.infoBuku();
				cout << "Nomor Rak\t: " << noRak << endl;
				cout << "Lokasi\t\t: " << lokasi << endl;
			}
		}
};