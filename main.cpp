#include <iostream>

using namespace std;

int main()
{
    int jml_sample, jml_elemen;
    cout << "-- UJI COBA PROGRAM NAIVE BAYES --\n\n";
    cout << "Tentukan Jumlah Sample : "; cin >> jml_sample;
    cout << "Masukkan Jumlah Elemenya : "; cin >> jml_elemen;
    cout << "\n\n";

    string dataset[jml_sample][jml_elemen];
    string var_dataset[jml_elemen];

    //Melakukan Input Variabel
    for(int i=0; i<jml_elemen; i++){
        cout << "Elemen ke - " << i+1 << " : "; cin >> var_dataset[i];
    }

    cout << "\n\n";
    //Melakukan Input Dataset
    for(int i=0; i<jml_sample; i++){
            cout << "Masukkan Dataset ke - " << i+1 << endl;
        for(int z=0; z<jml_elemen; z++){
            cout << "Untuk Variabel - " << var_dataset[z] << " : "; cin >> dataset[i][z];
        }
        cout << "\n";
    }

    //Menentukan jumlah yang yes dan no
    float jml_yes=0.0;
    float jml_no=0.0;
    for(int i=0; i<jml_sample; i++){
        if(dataset[i][jml_elemen-1] == "yes"){
            jml_yes=jml_yes+1.0;
        }
        else{
            jml_no=jml_no+1.0;
        }
    }

    cout << "\n\n";
    cout << "Jumlah dari Yes adalah : " << jml_yes << endl;
    cout << "Jumlah dari No adalah : " << jml_no << endl;

    cout << "\n\n";

    //Menginputkan data yang mau diuji
    cout << "== DATA YANG HENDAK DIUJI ==\n\n";
    string data_uji[jml_elemen];
    string lanjut;
    do{
        for(int i=0; i<jml_elemen-1; i++){
            cout << "Masukkan nilai untuk variabel " << var_dataset[i] << " : "; cin >> data_uji[i];
        }
        cout << "\nAda lagi ? "; cin >> lanjut;
        cout << "\n\n";
    }while(lanjut!="Tidak");

    //Menampilkan Proses yang dikerjakan program
    cout << "== INI MERUPAKAN PROSES PERHITUNGAN YANG DILAKUKAN ==\n\n";

    //Menampilkan yang cocok dengan kondisi data uji
    float jumlah = 0.0;
    for(int i=0; i<jml_elemen-1; i++){
        cout << "Jumlah dari variabel yang memiliki nilai " << data_uji[i] << " adalah : ";
        for(int z=0; z<jml_sample; z++){
            if(dataset[z][i] == data_uji[i]){
                jumlah++;
            }
        }
        cout << jumlah;
        jumlah=0.0;
        cout << "\n";
    }

    cout << "\n\n";

    //Menampilkan data yang cocok dengan kondisi data uji + hasil diharapkan
    float hasil_variabel_yes;
    float hasil_variabel_no;

    double hasil_yang_yes[jml_elemen];
    double hasil_yang_no[jml_elemen];
    cout << "== PERHITUNGAN DENGAN PENYESUAIAN VARIABEL HASIL ==\n\n";
    for(int i=0; i<jml_elemen-1; i++){
            hasil_variabel_yes=0.0;
            hasil_variabel_no=0.0;
        for(int z=0; z<jml_sample; z++){
            if(dataset[z][i] == data_uji[i] && dataset[z][jml_elemen-1] == "yes"){
                hasil_variabel_yes=hasil_variabel_yes+1.0;
            }
            else if(dataset[z][i] == data_uji[i] && dataset[z][jml_elemen-1] == "no"){
                hasil_variabel_no=hasil_variabel_no+1.0;
            }
        }
        cout << "P(" << var_dataset[i] << " " << data_uji[i] << " | " << var_dataset[jml_elemen-1] << " = yes) = " << hasil_variabel_yes << "/" << jml_yes;
        hasil_yang_yes[i]=hasil_variabel_yes/jml_yes;
        cout << " = " << hasil_yang_yes[i];
        cout << endl;

        cout << "P(" << var_dataset[i] << " " << data_uji[i] << " | " << var_dataset[jml_elemen-1] << " = no) = " << hasil_variabel_no << "/" << jml_no;
        hasil_yang_no[i]=hasil_variabel_no/jml_no;
        cout << " = " << hasil_yang_no[i];
        cout << endl;

    }


    //Mencari hasil dari total yes dan no
    float total_yes=1.0;
    float total_no=1.0;
    for(int i=0; i<jml_elemen-1; i++){
        total_yes=total_yes*hasil_yang_yes[i];
        total_no=total_no*hasil_yang_no[i];
    }
        cout << "\n\n";
        cout << "Total Yes awal : " << total_yes << endl;
        cout << "Total No awal : " << total_no << endl;

        total_yes=total_yes*(jml_yes/jml_sample);
        total_no=total_no*(jml_yes/jml_sample);

        cout << "Total Yes akhir : " << total_yes << endl;
        cout << "Total No akhir : " << total_no << endl;

    //Memasukkan nilai variabel hasil
    string hasil_akhir;
    if(total_yes<total_no){
        hasil_akhir="no";
    }
    else{
        hasil_akhir="yes";
    }

    cout << "\n\n";

    //Menampilkan data hasil perhitungan
    cout << "== DATA SETELAH DILAKUKAN PERHITUNGAN ==\n\n";
    for(int i=0; i<jml_elemen-1; i++){
        cout << "Nilai untuk variabel - " << var_dataset[i] << " : " << data_uji[i] << endl;
    }
        cout << "Nilai untuk variabel - " << var_dataset[jml_elemen-1] << " : " << hasil_akhir << endl;

    return 0;
}
