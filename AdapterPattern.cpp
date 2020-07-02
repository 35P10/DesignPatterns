#include <iostream>
using namespace std;


class clavijaSquare
{
 public:
     int area=0;
     clavijaSquare(int x){
        area = x;
        cout << "Es una clavija cuadrada\n" << endl;
    }
    int getX() {
        return area;
    }
};

class clavijaCircular
{
public:

    int radio;

    clavijaCircular(){
        cout << "Es una clavija circular\n" << endl;
    }
    void virtual setRadio(int x)
    {
        radio = x;
    }
    int virtual getRadio() {
     return radio;
    }
};

class Adapter : public clavijaCircular
{
public:
    clavijaSquare *T;
    Adapter(clavijaSquare *TT) {
            T = TT;
    }
    int getRadio() {
        return T->getX();
    }
};

class Enchufe
{
public:
    int radio;

    Enchufe(int x)
    {
        radio = x;
    }

    void conectar(clavijaCircular *S)
    {
        if(radio == S->getRadio())
        {
            cout<<"Conectado\n";
        }
        else if (radio > S->getRadio())
        {
            cout<<"Clavija muy pequeña para el enchufe\n";
        }
        else
        {
            cout<<"Clavija muy grande para el enchufe\n";
        }
    }
};


int main()
{
    clavijaSquare *ClavijoCuadrado = new clavijaSquare(6);
    clavijaCircular *ClavijoCircular = new clavijaCircular();
    clavijaCircular *adaptador = new Adapter(ClavijoCuadrado);

    adaptador->getRadio();
    ClavijoCircular->setRadio(5);
    Enchufe X(5);
    X.conectar(ClavijoCircular);
    X.conectar(adaptador);

}

