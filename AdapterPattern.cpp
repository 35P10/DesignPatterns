#include <iostream>
using namespace std;


class Perro
{
 public:
     Perro(){
        cout << "El perro" << endl;
    }
    void Comer() {
        cout << "El perro come" << endl;
    }
    void Ladrar() {
        cout << "Guau!" << endl;
    }
};

class perroDePeluche
{
public:
    perroDePeluche(){
        cout << "Es un perro de peluche" << endl;
    }
    void virtual Sonar() {
    cout << "Guau! pero en peluche" << endl;
    }
};

class Adapter : public perroDePeluche
{
public:
    Perro *T;
    Adapter(Perro *TT) {
            T = TT;
    }
    void Sonar() {
        T->Ladrar();
    }
};

int main()
{
    Perro *myPerro = new Perro;
    perroDePeluche *myPerroDePeluche = new perroDePeluche();
    perroDePeluche *myPerroDePeluche2 = new Adapter(myPerro);

    myPerro->Ladrar();

    myPerroDePeluche->Sonar();

    myPerroDePeluche2->Sonar();

}
