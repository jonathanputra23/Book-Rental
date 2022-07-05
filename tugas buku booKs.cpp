#include<iostream>
#include<limits>//menetukan batasan batasan
#include<cmath>
#include<conio.h>
using namespace std;

//Nanny bookrental
//Pilihan 1 untuk menambah buku untuk rental maksial 10 buku
//Pilihan 2 untuk menampilkan seluruh buku yang dirental


int bookNumber = 0;

class Book{
	private:
		string title;
		int price, quantity;
		
	public:
		void asktitle(){
			cout<<"Input the book title[5...20]";
			getline(cin, title);//memasukkan data string termasuk spasi
			if(title.length()<5 || title.length()>20){//jika panjang title kurang dari 5 atau lebih dari 20		
				cin.clear();
				asktitle();//memanggil kembali fungsi
			}
		}
		
		void askprice(){
			cout<<"Input the book price[Rp.5000...Rp.10000]";
			cin>>price;
			if (price<5000 || price>10000)
			{
				cin.clear();
				askprice();
			}
		}
		
		void askquantity()
		{
			cout<<"Input the quantity of the book[1-20]";
			cin>>quantity;
			if(quantity<1||quantity>20){
				cin.clear();
				askquantity();
			}
		}
		void addbook(){
			this->asktitle();
			this->askprice();
			this->askquantity();
			bookNumber++; //menambah jumlah buku
		}
		string gettitle(){ //accessor/getter title
			return title;
		}
		int getprice(){ //accessor price
			return price;
		}
		int getquantity(){
			return quantity;
		}
		
};
int choice;
Book *book = new Book[10];//pointer untuk memasukkan ke array, dibatasi jumlah maks 10
void hold(),welcome(),askchoice();

main(){
	system("cls");
	welcome();
}

void hold(){ 
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //function untuk enter otomatis
}

void welcome(){	//function untuk menampilkan welcome screen
	cout<<"Welcome to Nanny's bookrental"<<endl;
	cout<<"============================="<<endl;
	cout<<"1. Add a book"<<endl;
	cout<<"2. View all rented book"<<endl;
	cout<<"3. Exit and Delete all rent book"<<endl;
	askchoice();
}


void askchoice(){
	cout<<"Choice = ";
	cin>>choice;
	if (!cin){
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//cin akan enter secara otomatis
		askchoice();
	}
	else{
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		switch(choice){
			case 1:
				if(bookNumber<10){
					system("cls");//clear screen, menghapus tampilan layar
					book[bookNumber].addbook();
					main();//kembali ke integer main
					
				}
				else
				{
					cout<<"Maximum limit reached! Cannot add more books!!"<<endl;
					askchoice();
				}
				break;//setiap case harus di break
			
			case 2:
				if(bookNumber==0){
					system("cls");
					cout<<"List Ordered book"<<endl;
					cout<<"================="<<endl;
					cout<<"There is no rented book here"<<endl;
					cout<<"================="<<endl;
					cout<<"Total Price Rp.0"<<endl;
				}
				else{
					int longest = 0,totalprice=0;
					cout<<"List Ordered book"<<endl;
					cout<<"================="<<endl;
					//membuat bagan
					for(int i=0;i<bookNumber;i++){
						if(book[i].gettitle().length()/7>longest) //jiak title buku diatas longest
						longest = book[i].gettitle().length()/7; //longest menyesuaikan dengan title buku
					}
				cout<<"================="<<endl;
				cout<<"|No. \t|Title"; //\t digunakan untuk membuat tab
				for (int i=0;i<longest;i++){
					cout<<"\t";
				}
				cout<<"|Qty \t|Price \t|Subtotal\t"<<endl;
				cout<<"================="<<endl;
				for (int i=0; i<bookNumber;i++){
					cout<<"|"<<i+1<<"\t"<<book[i].gettitle();
					for (int x=0; x<abs(longest=book[i].gettitle().length()/7);x++){ //abs=absolut
						cout<<"\t";
					}
				cout<<"|"<<book[i].getquantity()<<"\t"<<book[i].getprice()<<"\t"<<book[i].getquantity()*book[i].getprice()<<"\t\t|"<<endl;
				totalprice +=book[i].getquantity()*book[i].getprice(); //total harga adalah total dari seluruh kuantitas x harga dari setiap buku
				}
				cout<<"================="<<endl;
				cout<<"Total Price Rp :"<<totalprice<<endl;
			}
			hold();
			main();
			break;
			
			case 3:
				cout<<"All of the books has been deleted, Thank you"<<endl; 
				delete [] book; //fungsi mendelete seluruh buku
				exit(0);
				break;
				
			default:
				cout<<"Please enter a valid number!"<<endl;
				cout<<"Choose only 1-3"<<endl;
				askchoice();
				break;
		}
	}
}


