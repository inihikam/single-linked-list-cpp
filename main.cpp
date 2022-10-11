#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void insertTengah(int databaru){
    system("cls");
    int pilih;
    cout<<" ============================"<<endl;
    cout<<" =     Pilih Mode Insert    ="<<endl;
    cout<<" =  1. Insert Before        ="<<endl;
    cout<<" =  2. Insert After         ="<<endl;
    cout<<" ============================"<<endl;
    cin >> pilih;
    switch (pilih){
        case 1: system("cls");{
            TNode *baru;
            TNode *bantu;
            TNode *prebantu;
            baru = new TNode;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int before;
                cout << "Memasukkan sebelum data : ";
                cin >> before;
                bantu = head;
                prebantu = bantu;
                baru->data = databaru;
                bool find = false;
                do{
                    if (before == bantu->data){
                        baru->next = prebantu->next;
                        prebantu->next = baru;
                        find = true;
                        cout << "Data Masuk\n";
                    }
                    
                    prebantu = bantu;
                    bantu = bantu->next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data yang dicari tidak ada!";
                }
            }
        
            break;
        }
        case 2: system("cls");{
            TNode *baru;
            TNode *bantu;
            baru = new TNode;
            baru->data = databaru;
            baru->next = NULL;
            if (head == NULL){
                head = baru;
                tail = baru;
            } else {
                int after;
                cout << "Memasukkan setelah data : ";
                cin >> after;
                bantu = head;
                bool find = false;
                do{
                    if (after == bantu->data){
                        baru->next = bantu->next;
                        bantu->next = baru;
                        find = true;
                        cout << "Data Masuk\n";
                    }
                    
                    bantu = bantu->next;
                } while (bantu != NULL);

                if (find == false){
                    cout << "Sorry Data yang dicari tidak ada!";
                }
            }
            break;
        }
        default: system("cls");{
            cout << "\nMaaf pilihan tidak ada!";
            break;
        }
    }
}

void insertBelakang(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->data<<" ";
                bantu=bantu->next;
            }
        }else cout <<"Masih kosong\n";
}

void cariData(){
    if (head == NULL){
        cout << "Sorry Data Kosong";
    } else {
        TNode *bantu;
        int cari;
        cout << "Masukkan isi data : ";
        cin >> cari;
        bool find = false;
        bantu = head;

        do{
            if (cari == bantu->data){
                cout << "Data " << bantu->data << " Ketemu!";
                find = true;
            }
            bantu = bantu->next;
        } while (bantu != NULL);

        if (find == false){
            cout << "Sorry Data tidak ada";
        }
    }
}

void hapusDepan()
{

    TNode *hapus;
    int d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->data;
            head=head->next;
            delete hapus;
        }else
        {
            d=tail->data;
            head=tail=NULL;
        }
    cout<<d<<"terhapus";
    }else cout<<"Masih kosong\n";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    do{
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    } while (bantu != NULL);
    
    head = NULL;
    cout << "Data Clear\n";
}

main()
{
    int pil, databaru;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Tengah         ="<<endl;
        cout<<" = 3. Insert Belakang       ="<<endl;
        cout<<" = 4. Delete Depan          ="<<endl;
        cout<<" = 5. Cari Data             ="<<endl;
        cout<<" = 6. Tampil Data           ="<<endl;
        cout<<" = 7. Clear                 ="<<endl;
        cout<<" = 8. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru;
                insertDepan(databaru);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru;
                insertTengah(databaru);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru;
                insertBelakang(databaru);
                break;
            }
            case 4: system("cls");{
                hapusDepan();
                break;
            }
            case 5: system("cls");{
                cariData();
                break;
            }
            case 6: system("cls");{
                tampil();
                break;
            }
            case 7: system("cls");{
                clear();
                break;
            }
            case 8: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    } while (pil!=7);
}