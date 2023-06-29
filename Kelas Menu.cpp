#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Kelas Buku.cpp"
#include "Kelas Rakbuku.cpp"
#include "Kelas Anggota.cpp"
#include "Kelas Peminjaman.cpp"
#include "Kelas Pengembalian.cpp"

using namespace std;

class Menu {
	private :
		vector<Anggota> dataAnggota;
		vector<Buku> daftarBuku;
		vector<Rakbuku> daftarRak;
		vector<Peminjaman*> daftarPeminjaman;
		bool idNotFound = true;
		bool login = false;
		string idUser;
	
	public :
		void setIdUser(string id){
			idUser = id;
		}
		string getId(){
			return idUser;
		}
		bool getLogin(){
			return login;
		}
		Anggota getPeminjam(){
			for (Anggota a : dataAnggota){
				if (a.getNoReg() == idUser){
					Anggota peminjam = a;
					return peminjam;
				}
			}
		}
		Buku getBukuByJudul(string judulBuku){
			for (Buku book : daftarBuku){
				if (book.getJudul() == judulBuku){
					Buku bukuPinjam = book;
					return bukuPinjam;
				}
			}
		}
		Peminjaman getPinjamanByNoPinjam(string noPinjam){
			for (Peminjaman* pinjam : daftarPeminjaman){
				if ((*pinjam).getNoPinjam() == noPinjam){
					return *pinjam;
				}
			}
		}
		Rakbuku getRakByNomor(string nomorRak) {
	        for (Rakbuku rak : daftarRak) {
	            if (rak.getNoRak() == nomorRak) {
	                return rak;
	            }
	        }
	    }
		void tambahDataAnggota(Anggota a1){
			dataAnggota.push_back(a1);
		}
		void tambahDaftarBuku(Buku book){
			daftarBuku.push_back(book);
		}
		void tambahDaftarRak(Rakbuku rak){
			daftarRak.push_back(rak);
		}
		void tambahDaftarPeminjaman(Peminjaman* pnjm){
			daftarPeminjaman.push_back(pnjm);
		}
		vector<Buku> sortBuku(vector<Buku> buku){
   			int n = buku.size();
    		for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (buku[j].getTerpinjam() < buku[j + 1].getTerpinjam()) {
                	// Tukar posisi elemen jika urutan tidak sesuai
                	swap(buku[j], buku[j + 1]);
            		}
        		}
    		}
    		return buku;
		}
		void topBuku(){
			int i = 1;
			cout << "==========BUKU TERLARIS==========" << endl;
			for (Buku buku : sortBuku(daftarBuku)){
				cout << i << ". " << buku.getJudul() << endl;
				i++;
			}
		}
		bool sistemLogin(){
			Anggota* user;
			string id, pw;
			cout << "Masukkan Nomor Registrasi dan Password anda!" << endl;
			cout << "No. Reg\t\t: ";
			cin >> id;
			for (Anggota a : dataAnggota){
				if (a.getNoReg() == id){
					setIdUser(id);
					cout << "Password\t: ";
					cin >> pw;
					if (a.getPassword() == pw){
						login = true;
						idNotFound = false;
						cout << "Login berhasil!" << endl;
						break;
					}
					else {
						idNotFound = false;
						cout << "Password salah! Silahkan coba lagi!" << endl;
						break;
						}	
					}
				}
				if(idNotFound){
					cout << "Nomor Registrasi tidak ditemukan!" << endl;
			}
			return login;
		}
		bool permission(){
			bool otorisasi;
			for (Anggota a : dataAnggota){
				if (idUser == a.getNoReg()){
					otorisasi = a.getOtorisasi();
				}
			}
			return otorisasi;
		}
		void daftarMenu(){
			bool login = sistemLogin();
			bool otorisasi = permission();
			
			if(login){
				//garis();
				int pilihan;
				bool ulang = true;
				while (ulang){
				cout << "Selamat Datang" << endl;
				cout << "1. Daftar Buku" << endl;
				cout << "2. Pinjam Buku" << endl;
				cout << "3. Kembalikan Buku" << endl;
				cout << "4. Rekomendasi Buku" << endl;
				cout << "5. Pendaftaran Anggota" << endl;
				cout << "6. Hapus Anggota" << endl;
				cout << "7. Daftar Anggota" << endl;
				cout << "8. Pendaftaran Buku" << endl;
				cout << "9. Hapus Buku" << endl;
				cout << "10. Tambah Rak" << endl;
				cout << "11. Hapus Rak" << endl;
				cout << "12. Daftar Rak" << endl;
				cout << "13. Daftar Transaksi Peminjaman" << endl;
				cout << "14. Keluar" << endl;
				cout << "Ketik angka untuk menu yang ingin anda akses : ";
				cin >> pilihan;
				
				if (pilihan == 1){
					garis();
					for (Rakbuku rak : daftarRak){
						rak.listBuku();
					}
				}
				if (pilihan == 2){
					string judulBuku, noPinjam;
					int tanggalPinjam, bulanPinjam, tahunPinjam;
					Anggota peminjam = getPeminjam();
					
					cout << "Masukkan nomor peminjaman : ";
					cin >> noPinjam;
					cout << "Silahkan masukan nama buku yang anda ingin pinjam : ";
					cin >> judulBuku;
					Buku bukuPinjam = getBukuByJudul(judulBuku);
					cout << "Masukkan tanggal peminjaman : ";
					cin >> tanggalPinjam;
					cout << "Masukkan bulan peminjaman : ";
					cin >> bulanPinjam;
					cout << "Masukkan tahun pinjam : ";
					cin >> tahunPinjam;
					Peminjaman pj(noPinjam, tanggalPinjam, bulanPinjam, tahunPinjam, &peminjam, &bukuPinjam);
						bool cek = bukuPinjam.getPinjam();
						if (cek){
							cout << "Buku tidak tersedia! Silahkan pilih buku lainnya!" << endl;
						} 
					tambahDaftarPeminjaman(&pj);
					pj.pinjam();
				}
				if (pilihan == 3){
					string noPinjam, judulBuku;
					int tanggalKembali, bulanKembali, tahunKembali;
					cout << "Masukkan Nomor Peminjaman : ";
					cin >> noPinjam;
					for (Peminjaman* pnjm : daftarPeminjaman){
					if ((*pnjm).getNoPinjam() == noPinjam){
						cout << "Masukkan judul buku yang ingin dikembalikan : ";
						cin >> judulBuku;
						cout << "Masukkan tanggal pengembalian : ";
						cin >> tanggalKembali;
						cout << "Masukkan bulan pengembalian : ";
						cin >> bulanKembali;
						cout << "Masukkan tahun pengembalian : ";
						cin >> tahunKembali;
						Pengembalian kmbl(pnjm, tanggalKembali, bulanKembali, tahunKembali);
						kmbl.kembali();
						break;
					}
					}
					}

				if (pilihan == 4){
					topBuku();
				}
        if (pilihan == 5){
          if (otorisasi&& idUser == "a"){
            string noReg, password, nama, noHP, email, alamat;
            cout << "Masukan Nomor Registrasi :";
            cin >> noReg;
            cout << "Masukan Password :";
            cin >> password;
            cout << "Masukan Nama :";
            cin >> nama;
            cout << "Masukan Nomor HP :";
            cin >> noHP;
            cout << "Masukan Email :";
            cin >> email;
            cout << "Masukan Alamat :";
            cin >> alamat;
            Anggota x(noReg, password, nama, noHP, email, alamat);
            dataAnggota.push_back(x);
            cout << "Anggota Berhasil ditambahkan" << endl;
          }
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
        }
        if (pilihan == 6){
          if (otorisasi&& idUser == "a"){
            string noReg;
            cout << "Masukan Nomor Registrasi yang ingin dihapus :";
            cin >> noReg;
            bool temu = false;
            for (auto a = dataAnggota.begin(); a != dataAnggota.end(); a++){
              if ((*a).getNoReg() == noReg){
                dataAnggota.erase(a);
                temu = true;
                break;
              }
              }
              if (temu){
              cout << "Anggota Berhasil dihapus" << endl;
              }
              else{
                cout << "Anggota tidak ditemukan" << endl;
              }
            }
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
          }
					}

        if (pilihan == 7){
          if (otorisasi&& idUser == "a"){
            for (Anggota a : dataAnggota){
              a.infoAnggota();
            }
          }
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
        }
        if (pilihan == 8){
          if (otorisasi&& idUser == "a"){
            string judul, penulis, penerbit, genre;
            double denda;
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Penulis Buku :";
            cin >> penulis;
            cout << "Masukan Penerbit Buku :";
            cin >> penerbit;
            cout << "Masukan Genre Buku :";
            cin >> genre;
            cout << "Masukan Denda Buku :";
            cin >> denda;
            Buku b(judul, penulis, penerbit, genre, denda);
            daftarBuku.push_back(b);
            cout << "Buku Berhasil ditambahkan" << endl;
          }
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
        }
        if (pilihan == 9){
          if (otorisasi&& idUser == "a"){
            string judul;
            cout << "Masukan Judul Buku yang ingin Anda Hapus : ";
            cin >> judul;
            bool ketemu = false;
            for (auto book = daftarBuku.begin(); book != daftarBuku.end(); book++){
              if ((*book).getJudul() == judul){
                daftarBuku.erase(book);
                ketemu = true;
                break;
              }
            }
            if (ketemu){
              cout << "Buku Berhasil dihapus" << endl;
            }
            else{
              cout << "Buku Tidak ditemukan" << endl;
            }
          }
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
          }

				if (pilihan == 10) {
					if (otorisasi&& idUser == "a") {
						string nomor, lokasi;
						cout << "Masukkan Nomor Rak : ";
						cin >> nomor;
						cout << "Masukkan Lokasi Rak : ";
						cin >> lokasi;
						Rakbuku rak(nomor, lokasi);
						tambahDaftarRak(rak);
					}
          else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
				}
				if (pilihan == 11) {
					if (otorisasi&& idUser == "a") {
						string nomor;
						cout << "Masukkan Nomor Rak yang ingin dihapus : ";
						cin >> nomor;
						bool found = false;
						for (int i = 0; i < daftarRak.size(); i++) {
							if (daftarRak[i].getNoRak() == nomor) {
								daftarRak.erase(daftarRak.begin() + i);
								found = true;
								break;
							}
						}
						if (found) {
							cout << "Rak dengan Nomor " << nomor << " telah dihapus." << endl;
						}
						else {
							cout << "Rak dengan Nomor " << nomor << " tidak ditemukan." << endl;
						}
					}
					else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
				}
				if (pilihan == 12) {
					if (otorisasi&& idUser == "a") {
						cout << "Daftar Rak: " << endl;
						for (Rakbuku rak : daftarRak) {
							cout << "Nomor Rak: " << rak.getNoRak() << ", Lokasi: " << rak.getLokasi() << endl;
						}
					}
					else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
			}
				if (pilihan == 13){
					if (otorisasi && idUser == "a"){
						for (Peminjaman* pj : daftarPeminjaman){
							(*pj).tampilkanPeminjaman();
						}
					}
					else {
						cout << "Anda tidak memiliki izin untuk mengakses menu ini." << endl;
					}
				}
				if (pilihan == 14){
					ulang = false;
				}
			}
		}
		}
};


int main(){
	
	Buku buku1("Kalkulus", "Rehan", "Gramedia", "Sci-Fi", 5000);
	Buku buku2("Matdis", "Fathir", "ITB", "Romance", 7000);
	Buku buku3("Alprog", "Ridwan", "UIN", "Action", 10000);
	Buku buku4("Rahasia", "Nirwan", "ITENAS", "Non-Fiction", 8000);
	Buku buku5("Seni", "Riza", "UIN", "Art", 3000);
	buku1.setTerpinjam(5);
	buku2.setTerpinjam(7);
	buku3.setTerpinjam(10);
	buku4.setTerpinjam(1);
	buku5.setTerpinjam(2);
	Anggota admin("a", "a", "a", "a", "a", "a");
	admin.setOtorisasi(true);
	Anggota a1("000001", "riza123", "Riza", "081234567890", "riza@email.com", "bandung");
	a1.setOtorisasi(true);
	Anggota a2("000002", "rafli123", "Rafli", "081234567890", "rafli@email.com", "bandung");
	Menu menu;
	Peminjaman pj1("456", 1, 1, 2023, &a1, &buku1);
	pj1.pinjam();
	menu.tambahDaftarPeminjaman(&pj1);
	Pengembalian kmbl1(&pj1, 2, 1, 2023);
	kmbl1.kembali();
	Peminjaman pj2("789", 3, 1, 2023, &a1, &buku1);
	pj1.pinjam();
	menu.tambahDaftarPeminjaman(&pj2);
	Pengembalian kmbl2(&pj2, 4, 1, 2023);
	kmbl2.kembali();
	menu.tambahDataAnggota(a1);
	menu.tambahDataAnggota(a2);
	menu.tambahDataAnggota(admin);
	menu.tambahDaftarBuku(buku1);
	menu.tambahDaftarBuku(buku2);
	menu.tambahDaftarBuku(buku3);
	menu.tambahDaftarBuku(buku4);
	menu.tambahDaftarBuku(buku5);
	Rakbuku rak1("A1", "Lt.1");
	rak1.tambahBuku(buku1);
	rak1.tambahBuku(buku2);
	rak1.tambahBuku(buku3);
	rak1.tambahBuku(buku4);
	rak1.tambahBuku(buku5);
	menu.tambahDaftarRak(rak1);
	
	system("cls");
	menu.daftarMenu();

	return 0;
}