#include <iostream>
#include <usuario.h>
#include<menuG.h>
using namespace std;

int main()
{
    //variables de user y contraseņan
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    usuario ingreso(user,contrasena);


     string id, nombre, puesto,departamento,sueldo,status;
        menuG catalogos(id, nombre, puesto,departamento,sueldo,status);

    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contraseņa se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        int opcion;

        do
        {
        	system("cls");

    cout <<"\t\t\t********************************************"<<endl;
    cout <<"\t\t\t        BIENVENIDO AL MENU PRINCIPAL      |"<<endl;
    cout <<"\t\t\t Nombre: Victor Omar Gomez Carrascosa|"<<endl;
    cout <<"\t\t\t Carne: 9959-23-10733                      |"<<endl;
    cout <<"\t\t\t********************************************"<<endl;
	cout<<"\t\t\t 1. Ingreso Al Menu de usuarios"<<endl;
	cout<<"\t\t\t 2. Ingreso Al Menu de Catalogos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;
    switch(opcion){

    case 1:
        ingreso.MenuUser();//ingresa al menu de usuarios
        break;

    case 2:
        catalogos.menuPrincipal();//ingresa al menu de usuarios
        break;
    case 3:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 2);

    }
    return 0;
}
