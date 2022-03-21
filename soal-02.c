/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursion
*Percobaan        : -
*Hari dan Tanggal : Rabu, 23 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>


// Menghitung jumlah botol minuman yang bisa kita dapatkan dari
// jumlah botol kosong yang dimiliki saat ini dan rate konversi
// botol kosong ke botol baru
int countBotol(int botol, int konversi)
{
	// Saat jumlah botol sudah lebih sedikit dari rate konversi
	if (botol < konversi)
		return 0;

	// Jumlah botol baru yang akan didapat setelah penukaran
	int botol_baru = botol/konversi;
	
	// Sisa botol yang tidak dapat ditukarkan
	int sisa_botol = botol%konversi;

	return botol_baru + countBotol(botol_baru + sisa_botol, konversi);
}


// Menghitung jumlah sisa botol yang tidak dapat lagi ditukarkan dengan
// botol baru
int countSisaBotol(int botol, int konversi)
{
	// Saat jumlah botol sudah lebih sedikit dari rate konversi
	if (botol < konversi)
		return botol;

	// Jumlah botol baru yang akan didapat setelah penukaran
	int botol_baru = botol/konversi;
	
	// Sisa botol yang tidak dapat ditukarkan
	int sisa_botol = botol%konversi;

	return 0 + countSisaBotol(botol_baru + sisa_botol, konversi);
}


// Program utama
int main()
{
	// Deklarasi variabel-variabel yang akan digunakan
	int uang, harga, konversi, botol, sisa_uang, sisa_botol;
	
	// Input jumlah uang, harga satu botol minuman, dan rate konversi
	printf("Masukkan jumlah uang: ");
	scanf("%d", &uang);
	printf("Masukkan harga satu botol minuman: ");
	scanf("%d", &harga);
	printf("Masukkan rate konversi botol kosong ke botol baru: ");
	scanf("%d", &konversi);
	
	// Jika uang yang dimiliki lebih sedikit dari harga satu botol minuman
	if (uang < harga)
		printf("\nUang anda tidak cukup untuk membeli apapun!");
		
	else{
		// Jumlah botol yang dapat kita beli di awal dengan uang
		botol = uang/harga;
		
		// Sisa uang yang tidak dapat digunakan lagi untuk membeli botol minuman
		sisa_uang = uang%harga;
		
		// Cetak output jumlah botol, sisa uang, dan sisa botol
		printf("\nJumlah maksimal minuman: %d botol", botol + countBotol(botol, konversi));
		
		if (sisa_uang == 0)
			printf("\nTidak ada sisa uang");
			
		else
			printf("\nSisa uang: %d", sisa_uang);
		
		printf("\nSisa botol: %d", countSisaBotol(botol, konversi));
	}
	
	return 0;
}
