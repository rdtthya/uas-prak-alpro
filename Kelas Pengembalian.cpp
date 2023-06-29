#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Pengembalian {
	private :
		Peminjaman* peminjaman;
		int tanggalKembali;
		int bulanKembali;
		int tahunKembali;
		double denda, totalDenda;
		
	public :
		Pengembalian(Peminjaman* peminjaman, int dd, int mm, int yy){
			this->peminjaman = peminjaman;
			tanggalKembali = dd;
			bulanKembali = mm;
			tahunKembali = yy;
		}
		void setDenda(){
			denda = peminjaman->getDenda();
		}
		double getDenda(){
			return denda;
		}
		int hitungMasaPeminjaman(){
		    struct tm pinjamTime = {0};
		    pinjamTime.tm_mday = peminjaman->getTanggalPinjam();
		    pinjamTime.tm_mon = peminjaman->getBulanPinjam() - 1;
			pinjamTime.tm_year = peminjaman->getTahunPinjam() - 1900;
		    
		    struct tm kembaliTime = {0};
		    kembaliTime.tm_mday = tanggalKembali;
		    kembaliTime.tm_mon = bulanKembali - 1;
		    kembaliTime.tm_year = tahunKembali - 1900;

		    time_t pinjamSeconds = mktime(&pinjamTime);
		    time_t kembaliSeconds = mktime(&kembaliTime);
		
		    double durasiSeconds = difftime(kembaliSeconds, pinjamSeconds);
		
		    int durasiHari = (durasiSeconds / (60 * 60 * 24));
		    
		    return durasiHari;
		}
		void hitungDenda(){
			int durasi = hitungMasaPeminjaman();
				if (durasi > 14) {
					totalDenda = denda * (durasi-14);
					cout << "Denda yang dikenakan : Rp. " << totalDenda << ",-" << endl;	
				}

			}
			
		
		void reportDenda(){
				Buku* book = peminjaman->getBukuPinjam();
				int durasi = hitungMasaPeminjaman();
				int hariPerbedaan = durasi - 14;
				
				cout << "Pengembalian buku " << (*book).getJudul() << "\t\t";
				if (durasi > 14) {
					cout << "(Terlambat " << hariPerbedaan << " hari)" << endl;
				}
				else {
					cout << "(Tidak terlambat)" << endl;
				}	
		}
		void kembali(){
			garis();			
				Buku* book = peminjaman->getBukuPinjam();
				(*book).setPinjam(false);
				setDenda();
				(*peminjaman).setComplete(true);
	
				cout << "Buku " << (*book).getJudul() << " berhasil dikembalikan!" << endl;
			reportDenda();
			hitungDenda();
		}
		
};