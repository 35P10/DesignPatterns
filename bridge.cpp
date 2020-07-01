#include <iostream>
using namespace std;

class Colores{
    public:
        virtual string Color() =0;
};
class colorAzul: public Colores{
    public:
    string Color(){
        return " color azul";
    }
}; 
class colorRojo: public Colores{
    public:
    string Color(){
        return " color rojo";
    }
};
class colorAmarillo: public Colores{
    public:
    string Color(){
        return " color amarillo";
    }
};

class Formas{
    public:
        virtual string Forma() =0;
};
class Cuadrado: public Formas{
    Colores *newColor;
    public:
        Cuadrado(Colores *objeto):newColor(objeto){}
        string Forma(){
            return "Cuadrado" + newColor->Color();
        }
};
class Circulo: public Formas{
    Colores *newColor;
    public:
        Circulo(Colores *objeto):newColor(objeto){}
        string Forma(){
            return "Circulo" + newColor->Color();
        }
};
class Triangulo: public Formas{
    Colores *newColor;
    public:
        Triangulo(Colores *objeto):newColor(objeto){}
        string Forma(){
            return "Triangulo" + newColor->Color();
        }
};

int main(){
    Colores* rojo = new colorRojo();
    Colores* azul = new colorAzul();
    Colores* amarillo = new colorAmarillo();

    Formas* circulo = new Circulo(rojo);
    Formas* cuadrado = new Cuadrado(azul);
    Formas* circulo1 = new Circulo(azul);
    Formas* cuadrado1 = new Cuadrado(rojo);
    Formas* triangulo = new Triangulo(amarillo);

    cout<<circulo->Forma()<<endl;
    cout<<circulo1->Forma()<<endl;
    cout<<cuadrado->Forma()<<endl;
    cout<<cuadrado1->Forma()<<endl;
    cout<<triangulo->Forma()<<endl;

    delete rojo;
    delete azul;
    delete amarillo;
    return 0;

}
