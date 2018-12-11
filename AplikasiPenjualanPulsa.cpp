#include<bits/stdc++.h>
#define True 1
#define False 0

using namespace std;

typedef char typeinfo;
typedef struct typequeue *typeptr;
struct data
{
    char nama[30], noHp[13];
    int jumlahPulsa;
};
struct simpan
{
    char nama[30], noHp[13];
    int jumlahPulsa;
};
struct typequeue
{
    typeptr prev;
    typeptr next;
    data info;
    simpan info2;
};
typeptr qdepan, qbelakang, qdepan1,qbelakang1;
void buatqueue();
int queuekosong();
void enqueue(char nama2[], char noHp2[], int jumlahPulsa2);
void dequeue();
void cetakqueue();
void cetakqueueRiwayat();
void batal();
int No=0, NoHistori=0;

char namaHapus[30];

int main()
{
    int pilMenu, jumlahPulsa2, no;
    char nama2[30], noHp2[13], ulang;
    do
    {
        no = 1;
        system("cls");
        if(!queuekosong())
        {
            cetakqueue();
        }

        cout << endl;
        cout << "=============================\n";
        cout << "     ANDROMEDA CELLULAR\n";
        cout << "-----------------------------\n";
        cout << "\nMENU :\n";
        cout << "1. Beli Pulsa\n2. Daftar Pembeli\n3. Kirim Pulsa\n4. Riwayat Pengiriman\n5. Pembatalan Pembelian\n6. Exit\n\n";
        cout << "==============================\n";
        cout << "Pilih [1...6]\t";
        cin >> pilMenu;
        cout << endl;
        switch(pilMenu)
        {
        case 1 :
            {
                if(queuekosong())
                {
                    buatqueue();
                }

                while(no == 1)
                {
                    if(!queuekosong())
                    {
                        cetakqueue();
                    }
                    No++;
                    cout << "Beli Pulsa\n";
                    cout << "Input data :\n";
                    cout << "   Nama\t\t: "; cin.ignore();cin.getline(nama2,sizeof(nama2));
                    cout << "   No HP\t: "; cin >> noHp2;
                    cout << "   Jumlah Pulsa : "; cin >> jumlahPulsa2;
                    enqueue(nama2, noHp2, jumlahPulsa2);
                    cout << "Tekan 1 untuk menambah pembelian : "; cin >> no;
                    system("cls");
                }
            }
            break;
        case 2:
            {
                if(!queuekosong())
                {
                    cetakqueue();
                }
                else
                    cout << "Tidak ada pembeli!!" << endl;
            }
            break;
        case 3:
            {
                if(!queuekosong())
                {
                    dequeue();
                }
                else
                    cout << "Tidak ada pembeli!!" << endl;
            }
            break;
        case 4:
            {
                if(NoHistori!=0)
                    cetakqueueRiwayat();
                else
                    cout << "Belum ada pembeli!" << endl;
            }
            break;
        case 5:
            {
                if(!queuekosong())
                {
                    batal();
                    cout << "Tidak jadi membeli!!" << endl;
                }
                else
                    cout << "Belum ada Pembeli!!" << endl;
            }
            break;
        case 6:
            exit(0);
            break;
        default :
            cout << "Input Salah!!!" << endl;
            break;
        } cout << "\nIngin Kembali ke menu? (y/t) "; cin >> ulang;
    } while(ulang == 'Y'||ulang == 'y');
}

void buatqueue()
{
    qdepan = (typequeue *) malloc(sizeof(typequeue));
    qdepan = NULL;
    qbelakang = qdepan;
    //Riwayat
    qdepan1 = (typequeue *) malloc(sizeof(typequeue));
    qdepan1 = NULL;
    qbelakang1 = qdepan;
}

int queuekosong()
{
    if(qdepan == NULL)
    {
        return(True);
    }
    else
        return(False);
}

void enqueue(char nama2[], char noHp2[], int jumlahPulsa2)
{
    typeptr NB;
    NB = (typequeue *) malloc(sizeof(typequeue));
    strcpy(NB->info.noHp,noHp2);
    strcpy(NB->info.nama,nama2);
    NB->info.jumlahPulsa = jumlahPulsa2;
    if (qdepan == NULL)
    {
        qdepan = NB;
    }
    else
        qbelakang->next = NB;

    qbelakang = NB;
    qbelakang->next = NULL;
}

void dequeue()
{
    typeptr hapus;
    if (queuekosong())
    {
        cout << "Queue masih kosong!!";
    }
    else
    {
        hapus = qdepan;
        qdepan = hapus->next;
        {
            typeptr NB;
            NB = (typequeue *) malloc(sizeof(typequeue));
            strcpy(NB->info2.noHp,hapus->info.noHp);
            strcpy(NB->info2.nama,hapus->info.nama);
            NB->info2.jumlahPulsa = hapus->info.jumlahPulsa;
            if (qdepan1 == NULL)
                qdepan1 = NB;
            else
                qbelakang1->next = NB;

            qbelakang1 = NB;
            qbelakang1->next = NULL;
            NoHistori++;
        }//Riwayat
        free(hapus);
        No--;
        cout << "Pulsa BERHASIL DIKIRIM ke " << qbelakang1->info2.nama << endl;
    }
}

void cetakqueue()
{	typeptr bantu;
	int i = 0;
 	bantu = qdepan;
	cout << "\n\t\t\t=====DAFTAR PEMBELI=====" << endl << endl;
	cout << setw(4) << "No" << setw(10) << "Nama" << setw(20) << "No HP" << setw(30) << "Jumlah Pembelian" << endl;
  	do
    {
        i++;
        cout << setw(4) << i << setw(10) << bantu->info.nama << setw(25) << bantu->info.noHp << setw(17) << bantu->info.jumlahPulsa << endl;
        bantu = bantu->next;

  	} while(bantu != NULL && i != No);
  	cout << "\nJUMLAH ANTRIAN : " << No;
  	cout << endl << endl;
}

void cetakqueueRiwayat()
{
    typeptr bantu;
	int i = 0;
 	bantu = qdepan1;
	cout << "\n\t\t\t=====RIWAYAT PENGIRIMAN=====" << endl;
	cout << setw(4) << "No" << setw(10) << "Nama" << setw(20) << "No HP" << setw(30) << "Jumlah Pembelian" << endl;
  	do
    {
        i++;
        cout << setw(4) << i << setw(10) << bantu->info2.nama << setw(20) << bantu->info2.noHp << setw(30) << bantu->info2.jumlahPulsa << endl;
        bantu = bantu->next;

  	} while(bantu != NULL && i != NoHistori);
  	cout << "\nJUMLAH ANTRIAN : " << No;
  	cout << endl << endl;
}

void batal()
{
    typeptr hapus;
    if (queuekosong())
    {
        cout << "Queue masih kosong !";
    }
    else
    {
        hapus = qbelakang;
        strcpy(namaHapus,hapus->info.nama);
        if(hapus==qdepan)
        {
            free(hapus);
            qdepan=qbelakang=NULL;

        }
        else
        {
            qbelakang = hapus->prev;
       /*
            typeptr NB;
            NB = (typequeue *) malloc(sizeof(typequeue));
            strcpy(NB->info2.noHp,hapus->info.noHp);
            strcpy(NB->info2.nama,hapus->info.nama);
            NB->info2.jumlahPulsa = hapus->info.jumlahPulsa;
            if (qbelakang1 == NULL)
                qbelakang1 = NB;
            else
                qdepan1->next = NB;
            qdepan1 = NB;
            qdepan1->next = NULL;*/
            free(hapus);
            qbelakang->next=NULL;

        }
        No--;
        cout << "\n" << namaHapus << " ";
	 }
}
