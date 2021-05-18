// Simple Single Linked List Circular
// Original by Pak Bintang Ginanjar -> https://github.com/bintangginanjar/Struktur-Data
// Modified by Me
// 1120031020 - Imam Yogaswara

#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
};

TNode *head, *tail; // deklarasi variabel pointer head dan tail untuk menunjukkan head dan tail

void init() {
    head = NULL; // 0 next 1
    tail = NULL; // 5 next 0
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert_first(int data_baru) {
    TNode *node_baru, *node_bantu;
    node_baru = new TNode;

    node_baru->data = data_baru;
    node_baru->next = node_baru;

    if (isEmpty() == 1) {
        head = node_baru;
        tail = node_baru;
        head->next = head;
        tail->next = tail;
    } else {
        node_baru->next = head;
        head = node_baru;
        tail->next = head;
    }

    cout << "Data " << data_baru << " masuk sebagai node paling depan" << endl;
}

void insert_last(int data_baru) {
    TNode *node_baru;
    node_baru = new TNode;

    node_baru->data = data_baru;
    node_baru->next = node_baru;

    if (isEmpty() == 1) {
        head = node_baru;
        tail = node_baru;
        head->next = head;
        tail->next = tail;
    } else {
        tail->next = node_baru;
        tail = node_baru;
        tail->next = head;
    }

    cout << "Data " << data_baru << " masuk sebagai node paling belakang" << endl;
}

void delete_first() {
    TNode *node_hapus;
    int d;

    if (isEmpty() == 0) {
        node_hapus = head;
        d = node_hapus->data;

        if (head != tail) {
            node_hapus = head;
            head = head->next;
            tail->next = head;
            delete node_hapus;
        } else {
            head = NULL;
            tail = NULL;
        }
		cout << "Data " << d << " berhasil dihapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void delete_last() {
    TNode *node_hapus,*node_bantu;
    int d;

    if (isEmpty() == 0) {
        if (head == tail) {
            d = tail->data;
            head = NULL;
            tail = NULL;
        } else {
            node_bantu = head;

            while (node_bantu->next != tail) {
                node_bantu = node_bantu->next;
            }

            node_hapus = tail;
            tail = node_bantu;
            d = node_hapus->data;
            tail->next = head;
            delete node_hapus;
        }
		cout << "Data " << d << " berhasil dihapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapus_semua() {
    TNode *node_bantu, *node_hapus;
    node_bantu = head;

    if (isEmpty() == 0) {
        node_bantu = head;

        while (node_bantu->next != head) {
            node_hapus = node_bantu;
            node_bantu = node_bantu->next;
            delete node_hapus;
        }

        head = NULL;
        tail = NULL;
    }

    cout << "Linked List kosong\n";
}

void show_data() {
    TNode *node_bantu;

    node_bantu = head;

    if (isEmpty() == 0) {
        do {
            cout << node_bantu->data << endl;
            node_bantu = node_bantu->next;
        } while (node_bantu != tail->next);
    } else {
        cout << "List masih kosong" << endl;
    }
}

void cariData() {
	int q;
	bool ditemukan = false;
	TNode *node_bantu;
    node_bantu = head;

    if (isEmpty() == 0) {
	    cout<<"Masukan data yang ingin dicari = ";
	    cin>>q;

        do {
        	if(q == node_bantu->data) {
        		ditemukan = true;
        		break;
			}
            node_bantu = node_bantu->next;
        } while (node_bantu != tail->next);

        if(ditemukan) {
	        cout << "Data Ditemukan : " << endl;
	        cout << node_bantu->data << endl;
		} else {
			cout << "Data Tidak Ditemukan";
		}
    } else {
        cout << "List masih kosong" << endl;
    }

}

void hapus_tertentu() {
	int q;
	bool ditemukan = false;
	TNode *node_hapus, *node_bantu;
    node_hapus = head;

    if (isEmpty() == 0) {
	    cout<<"Masukan data yang ingin dihapus = ";
	    cin>>q;

        do {
        	if(q == node_hapus->data) {
        		ditemukan = true;
        		break;
			}
            node_hapus = node_hapus->next;
        } while (node_hapus != tail->next);

        if(ditemukan) {
        	if(node_hapus == head) {
        		delete_first();
			} else if(node_hapus == tail) {
        		delete_last();
			} else {
				if(head->next == node_hapus) {
					head->next = node_hapus->next;
				} else {
					node_bantu = head;
					do {
						node_bantu = node_bantu->next;
					} while (node_bantu->next != node_hapus);

					node_bantu->next = node_hapus->next;
				}

				delete node_hapus;
				cout << "Data " << q << " berhasil dihapus" << endl;
			}
		} else {
			cout << "Data Tidak Ditemukan";
		}
    } else {
        cout << "List masih kosong" << endl;
    }

}

int main() {
    int pilihan, data_baru;

    do {
        cout<<" \n"<<endl;
        cout<<" ======================================="<<endl;
        cout<<" =         SLLC WITH HEAD & TAIL       ="<<endl;
        cout<<" =   Original by Pak Bintang Ginanjar  ="<<endl;
        cout<<" =            Modified by Me           ="<<endl;
        cout<<" =      1120031020 - Imam Yogaswara    ="<<endl;
        cout<<" ======================================="<<endl;
        cout<<" = 1. Insert First                     ="<<endl;
        cout<<" = 2. Insert Last                      ="<<endl;
        cout<<" = 3. Delete First                     ="<<endl;
        cout<<" = 4. Delete Last                      ="<<endl;
        cout<<" = 5. Tampil Data                      ="<<endl;
        cout<<" = 6. Hapus semua Data                 ="<<endl;
        cout<<" = 7. Cari Data                        ="<<endl;
        cout<<" = 8. Hapus Data Tertentu              ="<<endl;
        cout<<" = 9. Exit                             ="<<endl;
        cout<<" ======================================="<<endl;
        cout<<" Masukan pilihan : ";
        cin>>pilihan;

        if(cin.fail()){
            cout<<"\n Maaf, Inputan Harus Berupa Angka!";
            cin.clear();
            cin.ignore(1000, '\n');
		} else if (pilihan == 1) {
            cout<<"Masukan Data = ";
            cin>>data_baru;
            insert_first(data_baru);
        } else if (pilihan == 2) {
            cout<<"Masukan Data = ";
            cin>>data_baru;
            insert_last(data_baru);
        } else if (pilihan == 3) {
            delete_first();
        } else if (pilihan == 4) {
            delete_last();
        } else if (pilihan == 5) {
            show_data();
        } else if (pilihan == 6) {
            hapus_semua();
        } else if (pilihan == 7) {
            cariData();
        } else if (pilihan == 8) {
            hapus_tertentu();
        } else if (pilihan != 9) {
            cout<<"\n Maaf, pilihan yang anda pilihan tidak tersedia!";
        }
    } while (pilihan != 9);

    return 0;
}
