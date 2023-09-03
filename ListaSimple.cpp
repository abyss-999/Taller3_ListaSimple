#include <iostream>
#include <conio.h>
using namespace std;
struct Elmto 
{
    int num;
    Elmto *siguiente;
    
};

Elmto *pi,*pa,*pf;

typedef struct Elmto *Tlista;
/////////////////////////////////////////////////
void insertar_dato(int dato){
    if (pi == NULL){
        pi = new (Elmto);
        pi->num = dato;
        pf=pi;
    }else{
        pa = new(Elmto);
        pf ->siguiente = pa;
        pa ->num = dato;
        pf = pa;
    }
    pf ->siguiente = NULL;
}
/////////////////////////////////////////////////
void BuscarElemento(Elmto* lista, int valor){
    Tlista q = lista;
    int i = 0, band = 0;

    while (q!=NULL)
    {
    if (q->num==valor)
    {
        cout<<endl<<"Encontrado en la posicion: "<<i<<endl;
        band=1;
}
    q=q->siguiente;
    i++;
}
    if(band==0)
    cout<<"\n\n Numero no encontrado"<<endl;
}
/////////////////////////////////////////////////
void EliminarDato(Elmto *&lista, int valor){

    if (lista!=NULL)
    {
        Elmto *aux_borrar;
        Elmto *anterior = NULL;

        aux_borrar = lista;

        while ((aux_borrar!=NULL)&&(aux_borrar->num != valor))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar==NULL){
        cout<<"\n\nNumero no encontrado"<<endl;
        }else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
        }else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
    
    
}
/////////////////////////////////////////////////
int ActualizarLista(int valor, int valor_actualizar){
    pa = pi;
    while (pa !=NULL)
    {
        if (pa->num == valor)
        {
            pa->num = valor_actualizar;
            return 1;
        }
        pa = pa->siguiente;
    }
    return 0;
}

/////////////////////////////////////////////////
void mostrar_lista(){
    int i = 0, band=0;
    pa = pi;
    cout <<endl<<endl<< "elementos de la lista "<<endl<<endl;
    while (pa != NULL){
        cout<<"elemento "<<i<< ":"<< pa->num << endl<<endl;
        band=1;
        pa = pa -> siguiente;
        i++;
    }
    
}

int main() {
    int dato, valor_actualizar; 
    char respuesta;
    /////////////////////////////////////////////////////////////////////////
    do
    {
        cout<<endl<<"*******************************************";
        cout<<endl<<"Ingrese un dato: ";cin>>dato;
        insertar_dato(dato);
        cout<<endl<<"Seguir ingresando datos? (s/n)";
        respuesta = getch();

    } while (respuesta == 's');
    mostrar_lista();
    /////////////////////////////////////////////////////////////////////////
    do
    {
        cout<<endl<<"*******************************************";
        cout<<endl<<"deseas buscar elementos? (s/n): ";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres buscar: ";
            cin >> dato;
            BuscarElemento(pi, dato);
        }
    } while (respuesta == 's');
    /////////////////////////////////////////////////////////////////////////
    do {
        cout<<endl<<"*******************************************";
        cout << endl << "Desea actualizar elementos? (s/n)";
        respuesta = getch();
        
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres actualizar: ";
            cin >> dato;

            cout << "\nvalor a modificar: ";
            cin >> valor_actualizar;

            if (ActualizarLista(dato, valor_actualizar) == 1) {
                cout << "El valor se actualizo";
                mostrar_lista();
            } else {
                cout << "El valor no se encontro en la lista";
            }
        }
    } while (respuesta == 's');

    /////////////////////////////////////////////////////////////////////////
    do
    {
        cout<<endl<<"*******************************************";
        cout << endl << "Desea eliminar elementos? (s/n)";
        respuesta = getch();
        
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres eliminar: ";
            cin >> dato;
            EliminarDato(pi, dato);
            mostrar_lista();
        }
    } while (respuesta == 's');
    return 0;

}