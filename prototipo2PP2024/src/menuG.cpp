#include "menuG.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

menuG::menuG(string id, string nombre, string puesto, string departamento,string sueldo,string status)
{
    this->id = id;
    this->nombre = nombre;
    this->puesto = puesto;
    this->departamento = departamento;
     this->sueldo = sueldo;
     this -> status= status;
}

string menuG::setId( string id)
{
    this-> id=id;
}
string menuG::getId()
{
    return this -> id;
}

string menuG::setNombre(string nombre)
{
    this->nombre=nombre;
}

string menuG::getNombre()
{
    return this->nombre;
}

string menuG::setPuesto(string puesto)
{
    this->puesto=puesto;
}

string menuG::getPuesto()
{
    return this->puesto;
}

string menuG::setDepartamento(string departamento)
{
    this->departamento=departamento;
}

string menuG::getDepartamento()
{
    return this->departamento;
}

void menuG::menuPrincipal()
{
        bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|       MENU DE CATALOGOS         |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD CATALOGOS"<<endl;
	cout<<"\t\t\t 2. INFORMES"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        submenu();
		break;
	case 2:

		desplegar();
		system("pause");
        system ("cls");
		break;
	case 3:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(opcion!= 3);
}

void menuG::submenu()
{
int opcion;
    char x;
    bool repetir=true;
    system("cls");
   do
   {

     cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |       BIENVENIDO AL MENU De EMPLEADOS     |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Nuevos Empleados"<<endl;
	cout<<"\t\t\t 2. Modificar Empleados"<<endl;
	cout<<"\t\t\t 3. Borrar Empleados"<<endl;
	cout<<"\t\t\t 4. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";

    cin>>opcion;

    switch(opcion)

   //--------------------------------------------------------------------------------------------------
    {

    case 1:
        do
            {  insertar(); //metodo para ingresar usuarios
                cout<<"\n\t\t\t Agregar otra persona (S/N)"<<endl;
                cin>>x;//Recibe algo del usuario
            } while(x=='s'|| x=='S');// si el char que recive el usuario es S o s repetir el ciclo
            system("cls");
        break;
 //--------------------------------------------------------------------------------------------------

    case 2:
        modificar();
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 3:
         borrar();
         system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 4:
        break;
 //-------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 4);

}
void menuG::desplegar()
{
   system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Tabla de Registrados-------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("catalogos.txt",ios::in);
//condicion si el archivo no se puede abrir
if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay informaci�n..."; // muestra un mensaje de error
		fileDesplegar.close(); // cierra el archivo
    }
else
    {
        fileDesplegar >> id>> nombre>>puesto>>departamento>>sueldo>>status;//lee el primer registro del archivo
        //condicion de seguir leyendo registrso hasta llegar al final del registro
        while(!fileDesplegar.eof())
        {
         total++;//contado de usuarios
         cout<<"\t\t\t ID "<<id<<endl; // muestra el nombre del usuario
         cout<<"\t\t\t NOMBRE: "<<nombre<<endl;
         cout<<"\t\t\t PUESTO: "<<puesto<<endl;
        cout<<"\t\t\t DEPARTAMENTO: "<<departamento<<endl;
         cout<<"\t\t\t SUELDO: "<<sueldo<<endl;
          cout<<"\t\t\t STATUS: "<<status<<endl<<endl<<endl;

        fileDesplegar >> id>> nombre>>puesto>>departamento>>sueldo>>status;//leera el siguiente registro del archivo
        }

        if(total==0)//si no llegara a encontrar ningun registro en el archivo
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}

void menuG::insertar()
{
    system("cls");
    string id,nombre,puesto,departamento,sueldo,status;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar producto--------------------------------------------"<<endl;
   cout<<"\t\t\t INGRESE EL ID "<<endl; // muestra el nombre del usuario
         cin>>id;
         cout<<"\t\t\t INGRESE EL NOMBRE: "<<endl;
         cin>>nombre;
         cout<<"\t\t\t INGRESE EL  PUESTO: "<<endl;
        cin>>puesto;
        cout<<"\t\t\t INGRESE EL DEPARTAMENTO: "<<endl;
         cin>>departamento;
         cout<<"\t\t\tINGRESE EL  SUELDO: "<<endl;
          cin>>sueldo;
          cout<<"\t\t\tINGRESE EL  STATUS: "<<endl<<endl<<endl;
            cin>>status;
    // Abre el archivo "" en modo de apendizaje y escritura
    fstream fileIngresar;
    fileIngresar.open("catalogos.txt",ios::app| ios:: out);

    // Escribe en el archivo los datos del usuario ingresados por el usuario
    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< puesto<<std::left <<std::setw(15)<< departamento<<std::left <<std::setw(15)<<sueldo<<std::left <<std::setw(15)<<status<<"\n";

    //cierre del archivo
    fileIngresar.close();
    //mensaje de exito

    cout << "\t\t\t\nregistrado exitosamente."<<endl;


}

void menuG::modificar()
{

	system("cls");
    fstream fileOri, fileModif;  // Se crean dos objetos de archivo para leer y escribir en archivos de texto
    string productoModificar;  // Se define una cadena para almacenar el nombre del usuario a modificar

    int contador=0;  // Se define una variable para contar si se encuentra el usuario en el archivo
    cout<<"\n-------------------------Modificacion de cosas-------------------------"<<endl;  // Muestra un mensaje en pantalla
    fileOri.open("catalogos.txt",ios::in);  // Abre el archivo de texto en modo lectura

    if(!fileOri)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";  // Muestra un mensaje en pantalla
        fileOri.close();  // Cierra el archivo
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre del producto que quiere modificar: ";  // Muestra un mensaje en pantalla para ingresar el usuario a modificar
        cin>>productoModificar;  // Lee el nombre del usuario a modificar
        fileModif.open("record2.txt",ios::app | ios::out);  // Abre otro archivo de texto en modo escritura y agrega el contenido al final del archivo
        fileOri >>  id>> nombre>>puesto>>departamento>>sueldo>>status;  // Lee el primer usuario y contrase�a del archivo

        while(!fileOri.eof())  // Mientras no se llegue al final del archivo
        {
            if(productoModificar!=nombre)  // Si el usuario no es el que se quiere modificar
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< puesto<<std::left <<std::setw(15)<< departamento<<std::left <<std::setw(15)<<sueldo<<std::left <<std::setw(15)<<status<<"\n";


                }

            else  // Si se encuentra el usuario a modificar
                {
               cout<<"\t\t\t INGRESE EL ID "<<endl; // muestra el nombre del usuario
         cin>>id;
         cout<<"\t\t\t INGRESE EL NUEVO NOMBRE: "<<endl;
         cin>>nombre;
         cout<<"\t\t\t INGRESE EL NUEVO PUESTO: "<<endl;
        cin>>puesto;
        cout<<"\t\t\t INGRESE EL NUEVO DEPARTAMENTO: "<<endl;
         cin>>departamento;
         cout<<"\t\t\tINGRESE EL  NUEVO SUELDO: "<<endl;
          cin>>sueldo;
          cout<<"\t\t\tINGRESE EL  NUEVO STATUS: "<<endl<<endl<<endl;
            cin>>status;

                fileModif<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< puesto<<std::left <<std::setw(15)<< departamento<<std::left <<std::setw(15)<<sueldo<<std::left <<std::setw(15)<<status<<"\n";
                contador++;  // Incrementa el contador de usuarios modificados
                cout << "\t\t\t\nUsuario Modificado exitosamente.";
                }

                    fileOri >> id>> nombre>>puesto>>departamento>>sueldo>>status; // Lee el siguiente usuario y contrase�a del archivo
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("catalogos.txt");  // Elimina el archivo original
        rename("record2.txt","catalogos.txt");  // Renombra el archivo temporal con el nombre del archivo original
         cout << "\t\t\t\nUsuario no encontrado.";
          // Muestra un mensaje en pantalla
    }
}

void menuG::borrar()
{
   	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string partcipante;

	// Declarar una variable para indicar si se encontr� al usuario a borrar
	int encontrados= 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------empleado a borrar a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("catalogos.txt", ios::in);

	// Verificar si el archivo se pudo abrir
	if (!file)
	{
		cout << "\n\t\t\tNo hay informacion...";

		// Cerrar el archivo
		file.close();
	}
	else
	{
		// Pedir al usuario que ingrese el nombre del usuario a borrar
		cout << "\n Ingrese el nombre del empleado que quiere borrar: ";
		cin >> partcipante;

		// Abrir el archivo "Record.txt
		file1.open("record2.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contrase�a del archivo "Usuario y contrase�as.txt"
		file >> id>> nombre>>puesto>>departamento>>sueldo>>status;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario le�do es diferente al nombre del usuario a borrar
			if (partcipante != nombre)
			{
				// Escribir el nombre de usuario y contrase�a en el archivo "Record.txt"
                file1<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< puesto<<std::left <<std::setw(15)<< departamento<<std::left <<std::setw(15)<<sueldo<<std::left <<std::setw(15)<<status<<"\n";;  // Escribe en el archivo temporal el usuario y contrase�a sin modificar
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				encontrados++;

				// Mostrar un mensaje indicando que se borr� al usuario exitosamente
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

			// Leer el siguiente nombre de usuario y contrase�a del archivo "Usuarios1.txt"
		file >> id>> nombre>>puesto>>departamento>>sueldo>>status;

		}

		// Verificar si no se encontr� al usuario a borrar
		if (encontrados == 0)
		{
			cout << "\n\t\t\t Nombre del Usuario no encontrado...";
		}

		// Cerrar los archivos
		file1.close();
		file.close();

		// Borrar el archivo "Usuarios1.txt"
		remove("catalogos.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("record2.txt", "catalogos.txt");
	}
}


