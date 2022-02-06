#include <iostream>

using namespace::std;


struct Lista{
    int id;
    string duenio;
    string raza;  
    float peso;
    int edad;
};
Lista solicitarLista(void){
    Lista p;
    cout << "Id: ";
    cin >> p.id;cin.ignore();
    cout << "Nombre del duenio: ";
    getline(cin, p.duenio);
    cout << "Raza de la mascota: ";
    getline(cin, p.raza);
    cout << "Peso de la mascota: ";
    cin >> p.peso;cin.ignore();
    cout << "Edad de la mascota: ";
    cin >> p.edad;cin.ignore();
    return p;
}

void mostrarLista(Lista p){
    cout << "Id: " << p.id<<endl;
    cout << "Nombre del duenio: " << p.duenio<<endl;
    cout << "Raza de la mascota: " << p.raza<< endl;
    cout << "Peso de la mascota: " << p.peso<<endl;
    cout << "Edad de la mascota: " << p.edad<<endl;
}

typedef Lista T;
const T noValido = {-1,"","",-1,-1};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaCircular{
    private:
        nodo *pInicio;
    public:
        ListaCircular();
        ~ListaCircular();
        void insInicio(T);
        void mostrarListaDirectoIter(T);
        void mostrarListaById(T,int);
        void deleteItem(int);
        bool empty(void);
        bool mostrarId(int);
};

ListaCircular::ListaCircular(void){
    pInicio = NULL;
}

ListaCircular::~ListaCircular(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaCircular::insInicio(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

bool ListaCircular::mostrarId(int idref){
       if(!pInicio) // Lista vacía.
        return false;
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).id != idref) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            return false;
        else
            return true;
    } 
}

void ListaCircular::mostrarListaDirectoIter(T datoB){
    int idref;
    nodo *saltarin = pInicio;
    Lista p;
    while(saltarin != NULL){
        if(saltarin && (saltarin->dato).id != idref);
        mostrarLista(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
        }
    }

  void ListaCircular::mostrarListaById(T datoB, int idref){
    nodo *saltarin = pInicio;
    Lista p;
    while(saltarin != NULL){
    	if((saltarin->dato).id==idref){
    		mostrarLista(saltarin->dato);//cout << saltarin->dato << endl;
    		break;
		}else{
			saltarin = saltarin->sig;
		}
        
    }
}  

void ListaCircular::deleteItem(int idref){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay usuarios." << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).id != idref) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El usuario no está en la lista" << endl;
        else{ // Si saltarín no se salió (está sobre el dato a eliminar):
              // el nodo puede estar al principio, puede estar al final,
              // puede estar entre dos nodos, puede ser el único nodo.
            if(!saltarin->ant && saltarin->sig){ // Al principio (y hay más nodos).
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Mascota eliminada exitosamente!" << endl;
        }
    }
}
bool ListaCircular::empty(void){
    return pInicio == NULL;
}

int menu(){
    int opcion = 0;
    cout<<"VETERINARIA RODRIGUEZ :)"<<endl;
    cout << endl << "1) Agregar mascota." << endl;
    cout << "2) Mostrar mascotas por id." << endl;
    cout << "3) Eliminar mascotas por id"<<endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    cout<<endl;
    return opcion;
}

int main(void){
    ListaCircular objListaCircular;
    Lista p;
    bool continuar = true;
    int idref;
do{
        switch(menu()){
            case 1: //Agregar Inicio
                p=solicitarLista();
                objListaCircular.insInicio(p);
                cout <<"mascota almacenada exitosamente!" << endl<<endl;
                break;
            case 2: 
                if(objListaCircular.empty())
                    cout << "No hay mascotas por mostrar :(" << endl;
                else{
                    cout<<"id: ";
                    cin>>idref;
                    if(objListaCircular.mostrarId(idref)==true){
                     objListaCircular.mostrarListaById(p,idref);
                    }
                else 
                cout<<"No se encontro mascota por el id ingresado :("<<endl;
                }
                break;
            case 3: //Eliminar Inicio
                  if(objListaCircular.empty())
                    cout << "No hay mascotas por eliminar" << endl;
                else{
                    cout<<"id: ";
                    cin>>idref;
                    if(objListaCircular.mostrarId(idref))
                    objListaCircular.deleteItem(idref);
                    else
                    cout<<"Id no encontrado para eliminar mascota :("<<endl;
                }
                break;
            case 4: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    return 0;
}