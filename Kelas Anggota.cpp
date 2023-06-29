#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Anggota {
	private :
		string noReg;
		string password;
		string nama;
		string noHP;
		string email;
		string alamat;
		bool otorisasi = false;

	public :
		Anggota (string noReg, string password, string nama, string noHP, string email, string alamat){
			this->noReg = noReg;
			this->password = password;
			this->nama = nama;
			this->noHP = noHP;
			this->email = email;
			this->alamat = alamat;
		}
		void infoAnggota(){
			garis();
			cout << "Nomor Registrasi : " << noReg << endl;
			cout << "Nama\t: " << nama << endl;
			cout << "Nomor HP\t: " << noHP << endl;
			cout << "Email\t: " << email << endl;
			cout << "Alamat\t: " << alamat << endl;
		}
		string getNoReg(){
			return noReg;
		}
		string getPassword(){
			return password;
		}
		string getNama(){
			return nama;
		}
		string getNoHP(){
			return noHP;
		}
		string getEmail(){
			return email;
		}
		string getAlamat(){
			return alamat;
		}
		bool getOtorisasi(){
			return otorisasi;
		}
		void setOtorisasi(bool x){
			otorisasi = x;
		}
};