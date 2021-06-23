//===========================
/* Nama		 : Imam Yogaswara;
*  NIM 		 : 1120031020
*/
//============================

#include <iostream>
#define MAX_STACK 10

using namespace std;
struct Stack {
	int top;
	string array_data[MAX_STACK];
} tumpuk;

void init(){
	tumpuk.top = -1;
}

int isEmpty(){
	if(tumpuk.top == -1){
		return 1;
	} else {
		return 0;
	}
}

int isFull(){
	if(tumpuk.top == MAX_STACK - 1){
		return 1;
	} else {
		return 0;
	}
}

void push(){
	if (isFull()){
		cout << "\nData Penuh!\n"<<endl;
	} else {
		tumpuk.top++;
		cout << "\nMasukan Data = ";
		cin >> tumpuk.array_data[tumpuk.top];
		cout << "Data " << tumpuk.array_data[tumpuk.top] << " masuk ke stack " << endl;
	}
}

void pop(){
	if(isEmpty()){
		cout << "\nData Kosong!\n"<<endl;
	} else {
		cout << "\nData yang terambil : "<<tumpuk.array_data[tumpuk.top]<<endl;
		tumpuk.top--;	
	}
}

void cetak() {
	if (isEmpty()){
		cout << "Data Kosong!";
	} else {
		cout << "\n======== List Data ========" << endl;
			for (int i = tumpuk.top; i >= 0; i--) {
					cout << "[ " << tumpuk.array_data[i] << " ]" << endl;
			}
		cout << "\n===========================" << endl;
	}
}

int main() {
    int pil;
	init();
    do {
        cout<<" \n"<<endl;
        cout<<" ============================"<<endl;
        cout<<"    PROGRAM STACK            "<<endl;
        cout<<" ============================"<<endl;
        cout<<" 1: TAMBAH ELEMEN            "<<endl;
        cout<<" 2: HAPUS ELEMEN             "<<endl;
        cout<<" 3: CETAK                    "<<endl;
        cout<<" 4: KELUAR                   "<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if(cin.fail()){
        	cout << "\nMasukan pilihan yang benar!\n" << endl;
        	return 0;
		}
		else if (pil == 1) {
            push();
        } else if (pil == 2){
        	pop();
		} else if (pil == 3){
			cetak();
		}
		else if (pil != 4) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 4);

    return 0;
}