#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class menuG
{
    public:
        menuG(string id, string nombre, string puesto, string departamento,string sueldo,string status);

       string setId(string id);
        string getId();

        string setNombre(string nombre);
        string getNombre();

        string setPuesto(string puesto);
        string getPuesto();

        string setDepartamento(string departamento);
        string getDepartamento();

                string setSueldo(string sueldo);
        string getSueldo();

                string setStatus(string status);
        string getStatus();
//metodos

     void menuPrincipal();
     void submenu();
     void insertar();
     	void desplegar();
		void modificar();
		void buscar();
		void borrar();

    protected:

    private:
    string id,nombre,puesto,departamento,sueldo,status;
};


