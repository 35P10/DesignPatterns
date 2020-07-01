#include <iostream>
using namespace std;

//La interfaz de componentes base define operaciones que pueden ser alteradas por los decoradores.
class Enemigo {//
 public:
  virtual ~Enemigo() {}
  virtual string Operation() const = 0;
};


//EnemigoSimple proporciona implementaciones predeterminadas de las operaciones. Puede haber varias variaciones de estas clases.
class EnemigoSimple : public Enemigo {
 public:
  	string Operation() const override {
    return "Enemigo Corriente";
  }
};


/**
La clase base Decorator sigue la misma interfaz que los otros componentes.
El propósito principal de esta clase es definir la interfaz de envoltura para todos los decoradores de concreto. 
La implementación predeterminada del código de ajuste podría incluir un campo para almacenar un componente empaquetado y los medios para inicializarlo.
 */
class Decorator : public Enemigo { //public class interface Objeto
protected:
	Enemigo* enemy_;

public:
  	Decorator(Enemigo* componente) : enemy_(componente) {
  		//...
  	}
  	
	//El decorador delega todo el trabajo al componente envuelto.
  	string Operation() const override {
    return this->enemy_->Operation();
  	}
};


//Los decoradores de concreto llaman al objeto envuelto y alteran su resultado de alguna manera.
/**
Los decoradores pueden llamar a la implementación principal de la operación, 
en lugar de llamar al objeto envuelto directamente. 
Este enfoque simplifica la extensión de las clases de decorador.
*/

class cascoArmor : public Decorator {
 public:
  	cascoArmor(Enemigo* componente) : Decorator(componente) {
  	}
  	
	std::string Operation() const override {
		return "cascoArmor(" + Decorator::Operation() + ")";
  	}
};
 
//Los decoradores pueden ejecutar su comportamiento antes o después de la llamada a un objeto envuelto.
class capaArmor : public Decorator {
public:
	capaArmor(Enemigo* componente) : Decorator(componente) {
		//...
  	}

	string Operation() const override {
    	return "capaArmor(" + Decorator::Operation() + ")";
	}
};


/**
Los decoradores pueden llamar a la implementación principal de la operación, 
en lugar de llamar al objeto envuelto directamente. 
Este enfoque simplifica la extensión de las clases de decorador.	
*/
class armaduraArmor : public Decorator {
 public:
  	armaduraArmor(Enemigo* componente) : Decorator(componente) {
  	}
  	
	std::string Operation() const override {
		return "armaduraArmor(" + Decorator::Operation() + ")";
  	}
};




/**
El código de usuario funciona con todos los objetos que usan la interfaz Enemigo. 
De esta manera, puede mantenerse independiente de las clases concretas de componentes con los que trabaja.
 */
void UserCode(Enemigo* componente) {
	cout << "RESULTADO: " << componente->Operation();
}

int main() {
	Enemigo* simple = new EnemigoSimple;
	cout << "Usuario: Tengo un componente simple :\n";
	UserCode(simple);
	cout << "\n\n";
	
	Enemigo* simple1 = new EnemigoSimple;
	Enemigo* soloCasco = new cascoArmor(simple1);
	cout<<"Usuario: Solo tengo un decorado simple: \n";
	UserCode(soloCasco);
	cout<<"\n\n";
	
	Enemigo* casco = new cascoArmor(simple);
	Enemigo* capa = new capaArmor(casco);
	Enemigo* armadura = new armaduraArmor(capa);
	cout << "Usuario: Ahora tengo un componente decorado:\n";
	UserCode(armadura);
	cout << "\n";
	
	delete simple1;
	delete soloCasco;
	delete simple;
	delete casco;
	delete capa;
	delete armadura;

  return 0;
}
