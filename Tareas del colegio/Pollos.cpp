#include "bits/stdc++.h"
#define CC "CERO"
#define UU "UNO"
#define DD "DOS"
#define TT "TRES"
#define Cc "CUATRO"
#define cc "CINCO"
#define SS "SEIS"
#define Ss "SIETE"
#define OO "OCHO"
#define NN "NUEVE"
#define dd "DIEZ"
#define Dd "DIECI"
#define Oo "ONCE"
#define ddd "DOCE"
#define Tt "TRECE"
#define cC "CATORCE"
#define QQ "QUINCE"
#define VV "VEINTE"
#define Vv "VEINTI"
#define MM "MIL"
#define CCC "CIEN"
#define CCc "CIENTO"
#define QQQ "QUINIENTOS"
#define SSS "CIENTOS"
#define TTT "TREINTA"
#define CUA "CUARENTA"
#define CIN "CINCUENTA"
#define SES "SESENTA"
#define SET "SETENTA"
#define OCH "OCHENTA"
#define NOV "NOVENTA"
using namespace std;
int main(){
	cout<<"Sistema de compra\nPOLLOS COPACABANA\nComo te gusta a ti\n";
		string Usuario;
	while(1){
		cout<<"Ingrese el usuario. ";
		cin>>Usuario;
		if(Usuario == "123"){
			Usuario = "Gabriel";
			break;
		} else if(Usuario == "456"){
			Usuario = "Cruz";
			break;
		} else {
			cout<<"No se reconoció el usuario.\n";
		}
	}
	cout<<"Bienvenido(a) "<<Usuario<<"\n";
	system("pause");
	system("cls");
		map<string, long long> Productos;
		map<long long, string> Nombres_de_los_productos;
		Nombres_de_los_productos[1] = "Combo fiesta";
		Nombres_de_los_productos[2] = "Combo un sexto";
		Nombres_de_los_productos[3] = "Combo un quinto";
		Nombres_de_los_productos[4] = "Combo un cuarto";
		Nombres_de_los_productos[5] = "Combo un tercio";
		Nombres_de_los_productos[6] = "Combo un medio";
		Nombres_de_los_productos[7] = "Hamburguesa";
		Nombres_de_los_productos[8] = "Combo tres";
		Nombres_de_los_productos[9] = "Balde";
		Nombres_de_los_productos[10] = "222 pollos + peluche";
		Productos["Combo fiesta"] = 20;
		Productos["Combo un sexto"] = 3;
		Productos["Combo un quinto"] = 4;
		Productos["Combo un cuarto"] = 5;
		Productos["Combo un tercio"] = 7;
		Productos["Combo un medio"] = 10;
		Productos["Hamburguesa"] = 16;
		Productos["Combo tres"] = 60;
		Productos["Balde"] = 44;
		Productos["222 pollos + peluche"] = 222;
	while(1){
		system("cls");
		set< pair<long long, long long> > Factura;
		while(1){
			system("cls");
			cout<<"Elija una opción.\n";
			cout<<"1.  Combo fiesta           20 bolivianos\n";
			cout<<"2.  Combo un sexto         3 bolivianos\n";
			cout<<"3.  Combo un quinto        4 bolivianos\n";
			cout<<"4.  Combo un cuarto        5 bolivianos\n";
			cout<<"5.  Combo un tercio        7 bolivianos\n";
			cout<<"6.  Combo un medio         10 bolivianos\n";
			cout<<"7.  Hamburguesa            16 bolivianos\n";
			cout<<"8.  Combo tres             60 bolivianos\n";
			cout<<"9.  Balde                  44 bolivanos\n";
			cout<<"10. 222 pollos + peluche   222 bolivianos\n";
			long long Opci_n;
			cin>>Opci_n;
			if(Opci_n <= 10 and Opci_n >= 1){
                cout<<"Seleccionó "<<Nombres_de_los_productos[Opci_n]<<" por "<<Productos[Nombres_de_los_productos[Opci_n]]<<" boliviano(s)\n";
                cout<<"Ingrese la cantidad. ";
                long long Cantidad;
                cin>>Cantidad;
                if(Factura.lower_bound(make_pair(Opci_n, 0)) == Factura.end()){
                    Factura.insert(make_pair(Opci_n, Cantidad));
                } else if((*Factura.lower_bound(make_pair(Opci_n, 0))).first != Opci_n){
                    Cantidad += (*Factura.lower_bound(make_pair(Opci_n, 0))).second;
                    Factura.erase(Factura.lower_bound(make_pair(Opci_n, 0)));
                    Factura.insert(make_pair(Opci_n, Cantidad));
                }
			} else cout<<"Eso no es una opción. ";
			cout<<"¿Quiere algo más? (S/N) ";
			char Bien;
			cin>>Bien;
			if(Bien == 'N') break;
		}
		system("cls");
		cout<<"Datos de la factura.\nNIT o CI: ";
		string NIT, Apellido;
		cin>>NIT;
		cout<<"Nombre o razón social: ";
		cin>>Apellido;
		system("cls");
		cout<<"Resumen\n";
		cout<<"NIT o CI: "<<NIT<<"\n";
		cout<<"Nombre o razón social: "<<Apellido<<"\n";
		cout<<"Descripción          Cantidad     Precio\n";
		long long Precio_final = 0;
		for(auto E: Factura){
			cout<<Nombres_de_los_productos[E.first];
			for(int i = 0; i < (22 - Nombres_de_los_productos[E.first].size()); i++) cout<<" ";
			cout<<E.second;
			for(int i = 0; i < (11 - (int)log10(E.second) + 1); i++) cout<<" ";
			cout<<Productos[Nombres_de_los_productos[E.first]] * E.second<<"\n";
			Precio_final += Productos[Nombres_de_los_productos[E.first]] * E.second;
		}
		cout<<"Total:                             "<<Precio_final<<"\n";
		stringstream Conversor;
		Conversor<<Precio_final;
		string a;
		Conversor>>a;
		cout<<"SON: ";
		bool Acabar = 1;
		while(a.size() > 0 and Acabar){
			long long b;
			string c = a;
			stringstream d;
			d<<c;
			d>>b;
			switch(a.size()){
				case 1:
				switch(b){
					case 0:
					cout<<CC;
					break;
					case 1:
					cout<<UU;
					break;
					case 2:
					cout<<DD;
					break;
					case 3:
					cout<<TT;
					break;
					case 4:
					cout<<Cc;
					break;
					case 5:
					cout<<cc;
					break;
					case 6:
					cout<<SS;
					break;
					case 7:
					cout<<Ss;
					break;
					case 8:
					cout<<OO;
					break;
					case 9:
					cout<<NN;
					break;
				}
				break;
				case 2:
				switch(b){
					case 10:
					cout<<dd;
					Acabar = 0;
					break;
					case 11:
					cout<<Oo;
					Acabar = 0;
					break;
					case 12:
					cout<<ddd;
					Acabar = 0;
					break;
					case 13:
					Acabar = 0;
					cout<<Tt;
					break;
					case 14:
					Acabar = 0;
					cout<<cC;
					break;
					case 15:
					Acabar = 0;
					cout<<QQ;
					break;
					default:
					switch(a[0]){
						case '0':
						break;
						case '1':
						cout<<Dd;
						break;
						case '2':
						switch(a.back()){
							case '0':
							cout<<VV;
							Acabar = 0;
							break;
							default:
							cout<<Vv;
						}
						break;
						case '3':
						switch(a.back()){
							case '0':
							cout<<TTT;
							Acabar = 0;
							break;
							default:
							cout<<TTT<<" Y ";
						}
						case '4':
						switch(a.back()){
							case '0':
							cout<<CUA;
							Acabar = 0;
							break;
							default:
							cout<<CUA<<" Y ";
						}
						break;
						case '5':
						switch(a.back()){
							case '0':
							cout<<CIN;
							Acabar = 0;
							break;
							default:
							cout<<CIN<<" Y ";
						}
						break;
						case '6':
						switch(a.back()){
							case '0':
							cout<<SES;
							Acabar = 0;
							break;
							default:
							cout<<SES<<" Y ";
						}
						break;
						case '7':
						switch(a.back()){
							case '0':
							cout<<SET;
							Acabar = 0;
							break;
							default:
							cout<<SET<<" Y ";
						}
						break;
						case '8':
						switch(a.back()){
							case '0':
							cout<<OCH;
							Acabar = 0;
							break;
							default:
							cout<<OCH<<" Y ";
						}
						break;
						case '9':
						switch(a.back()){
							case '0':
							cout<<NOV;
							Acabar = 0;
							break;
							default:
							cout<<NOV<<" Y ";
						}
						break;
					}
				}
				break;
				case 3:
				if(a == "100"){
					cout<<CCC;
					Acabar = 0;
				} else {
					switch(a[0]){
						case '1':
						cout<<CCc;
						break;
						case '2':
						cout<<DD<<SSS;
						break;
						case '3':
						cout<<TT<<SSS;
						break;
						case '4':
						cout<<Cc<<SSS;
						break;
						case '5':
						cout<<QQQ;
						break;
						case '6':
						cout<<SS<<SSS;
						break;
						case '7':
						cout<<"SETE"<<SSS;
						break;
						case '8':
						cout<<OO<<SSS;
						break;
						case '9':
						cout<<"NOVE"<<SSS;
						break;
					}
				}
				if(a[1] == '0' and a[2] == '0') Acabar = 0;
				break;
				case 4:
					if(a[0] != '0'){
						switch(a[0]){
							case '2':
							cout<<DD;
							break;
							case '3':
							cout<<TT;
							break;
							case '4':
							cout<<Cc;
							break;
							case '5':
							cout<<cc;
							break;
							case '6':
							cout<<SS;
							break;
							case '7':
							cout<<Ss;
							break;
							case '8':
							cout<<OO;
							break;
							case '9':
							cout<<NN;
							break;
						}
						cout<<" "<<MM<<" ";
					}
				break;
				case 5:
				cout<<"DIEZ MIL";
				Acabar = 0;
			}
			string Nuevo = "";
			for(long long i = a.size() - 1; i > 0; i--){
				//cout<<Nuevo;
				Nuevo = a[i] + Nuevo;
			}
			//cout<<Nuevo<<" ";
			if(a.size() == 3) cout<<" ";
			a = Nuevo;
		}
		cout<<" BOLIVIANO(S)\n";
		cout<<"Gracias por su compra.\n";
		system("pause");
		system("cls");
	}
	return 0;
}