#include <iostream>
#include <vector>
using namespace std;

struct account{
    string user_id;
    string user;
    string passwrd;
};

//VER CUENTAS
void showAcc(const vector<account>& accounts){
    if(accounts.empty()){
        cout <<"No hay cuentas guardadas";
        return;
    }

    cout <<"\n--CUENTAS--\n";
    for (size_t i = 0; i < accounts.size(); i++){
        cout <<i + 1 << "-Nombre cuenta: " <<accounts[i].user_id
        <<"\nNombre usuario: " <<accounts[i].user
        <<"\nContrasena: " <<accounts[i].passwrd <<"\n";
    }
}

//AÑADIR CUENTA
void addAcc(vector<account>& accounts){
    account nueva;
    cout <<"Ingrese nombre de cuenta: ";
    cin >>nueva.user_id;
    cout <<"Ingrese nombre de usuario: ";
    cin >>nueva.user;
    cout <<"Ingrese contrasena: ";
    cin >>nueva.passwrd;

    accounts.push_back(nueva);
    cout <<"Cuenta agregada";
}

//ELIMINAR CUENTA
void delAcc(vector<account>& accounts){
    if(accounts.empty()){
        cout <<"No hay cuentas guardadas";
        return;
    }
    showAcc(accounts);

    int choose;
    cout <<"Ingrese el numero de cuenta a eliminar: ";
    cin >>choose;

    if(choose < 1 || choose >(int)accounts.size()){
        cout <<"Cuenta no existe\n";
        return;
    }
    accounts.erase(accounts.begin() + (choose - 1));
    cout <<"Cuenta eliminada.\n";

}

//PAUSA
void pause(){
    cout <<"\nPresiona ENTER para volver al menu.";
    cin.get();
}

int main(){

    int i =0;
    vector<account> accounts;
    do{
            
            int opt;

             cout <<"\n --ELIGE UNA OPCION--\n\n"
             <<"1- Ver cuentas" <<endl
             <<"2- Agregar cuenta" <<endl
             <<"3- Eliminar cuenta" <<endl
             <<"4- Salir" <<endl;
             cin >>opt;

             switch(opt){
                    case 1:
                        showAcc(accounts);
                        pause();
                        break;
        
                    case 2:
                        addAcc(accounts);
                        pause();
                        break;
        
                    case 3:
                        delAcc(accounts);
                        pause();
                        break;
                    case 4:
                        cout <<"Saliendo...\n";
                        break;
            }
 
            
    }while(true);
    return 0;
}