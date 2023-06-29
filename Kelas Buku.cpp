#include <iostream>
#include <string>

using namespace std;

void garis(){
	cout << "=============================================" << endl;
}

class Buku {
	private :
		string judul;
		string penulis;
		string penerbit;
		string genre;
		double denda;
		bool pinjam = false;
		int terpinjam = 0;

	public :
		Buku (string judul, string penulis, string penerbit, string genre, double denda){
			this->judul = judul;
			this->penulis = penulis;
			this->penerbit = penerbit;
			this->genre = genre;
			this->denda = denda;
		}

		void infoBuku(){
			garis();
			cout << "Judul Buku\t: " << judul << endl;
			cout << "Author\t\t: " << penulis << endl;
			cout << "Penerbit\t: " << penerbit << endl;
			cout << "Genre\t\t: " << genre << endl;
			cout << "Status\t\t: ";
			if (pinjam == true) {
				cout << "Tidak tersedia" << endl;
			} 
			else {
				cout << "Tersedia" << endl;
			}
		}
		void tambahTerpinjam(){
			terpinjam++;
		}
		void setTerpinjam(int x){
			terpinjam += x;
		}
		int getTerpinjam(){
			return terpinjam;
		}
		string getJudul(){
			return judul;
		}
		string getPenulis(){
			return penulis;
		}
		string getPenerbit(){
			return penerbit;
		}
		string getGenre(){
			return genre;
		}
		bool getPinjam(){
			return pinjam;
		}
		void setPinjam(bool x){
			pinjam = x;
		}
		double getDenda(){
			return denda;
		}

};