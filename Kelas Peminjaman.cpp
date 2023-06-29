#include <iostream>
#include <string>
#include <random>

using namespace std;

class Peminjaman {
	private :
		string noPinjam;
		int tanggalPinjam;
		int bulanPinjam;
		int tahunPinjam;
		Anggota* peminjam;
		Buku* bukuPinjam;
		double denda;
		bool complete = false;

	public :
		Peminjaman(string noPinjam, int dd, int mm, int yy, Anggota* a, Buku* book){
			this->noPinjam = noPinjam;
			tanggalPinjam = dd;
			bulanPinjam = mm;
			tahunPinjam = yy;
			peminjam = a;
			bukuPinjam = book;
		}
		bool getComplete(){
			return complete;
		}
		void setComplete(bool x){
			complete = x;
		}
		string getNoPinjam(){
			return noPinjam;
		}
		int getTanggalPinjam(){
			return tanggalPinjam;
		}
		int getBulanPinjam(){
			return bulanPinjam;
		}
		int getTahunPinjam(){
			return tahunPinjam;
		}
		Buku* getBukuPinjam(){
			return bukuPinjam;
		}
		Anggota* getPeminjam(){
			return peminjam;
		}
		void setDenda(){
			denda = (*bukuPinjam).getDenda();
		}
		double getDenda(){
			return denda;
		}
		void tampilkanPeminjaman(){
			garis();
			cout << "Nomor Peminjaman\t: " << noPinjam << endl;
			cout << "Tanggal Peminjaman\t: " << tanggalPinjam << "-" << bulanPinjam << "-" << tahunPinjam << endl;
			cout << "Nama Peminjam\t\t: " << (*peminjam).getNama() << endl;
			cout << "Judul Buku\t\t: " << (*bukuPinjam).getJudul() << endl;
			cout << "Status\t\t\t: ";
			if (complete){
				cout << "Selesai" << endl;
			}
			else {
				cout << "Sedang berlangsung" << endl;
			}
		}
		void pinjam(){
			garis();
			setDenda();
			(*bukuPinjam).setPinjam(true);
			(*bukuPinjam).tambahTerpinjam();
			cout << "Nomor transaksi\t: " << noPinjam << " (HARAP DICATAT!)" << endl;
			cout << "Buku " << (*bukuPinjam).getJudul() << " berhasil dipinjam!" << endl;
			cout << "Kembalikan dalam maksimal 14 hari!" << endl;
		}
		
};
