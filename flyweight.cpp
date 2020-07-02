#include <iostream>
#include <string>
#include <unordered_map> 
using namespace std;
/**
 * Flyweight Design Pattern
 *
 * Deja encajar más objetos en la cantidad disponible
 * de memoria RAM compartiendo partes en común del estado
 * entre múltiples objetos, en lugar de tener la data de cada objeto
 *
 */

struct EstadoCompartido
{
    string marca_;
    string modelo_;
    string color_;

    EstadoCompartido(const string &brand, const string &model, const string &color)
        : marca_(brand), modelo_(model), color_(color)
    {
    }

    friend ostream &operator<<(ostream &os, const EstadoCompartido &ss)
    {
        return os << "[ " << ss.marca_ << " , " << ss.modelo_ << " , " << ss.color_ << " ]";
    }
};

struct EstadoUnico
{
    string propietario_;
    string placa_;

    EstadoUnico(const string &owner, const string &plates)
        : propietario_(owner), placa_(plates)
    {
    }

    friend ostream &operator<<(ostream &os, const EstadoUnico &us)
    {
        return os << "[ " << us.propietario_ << " , " << us.placa_ << " ]";
    }
};

/**
 * Flyweight guarda una porción común del estado (estado intrínseco) 
 * Flyweight acepta el resto del estado (estado extrinseco, único para cada objeto)
 * a través de métodos
 */
class Flyweight
{
private:
    EstadoCompartido *estado_compartido;

public:
    Flyweight(const EstadoCompartido *shared_state) : estado_compartido(new EstadoCompartido(*shared_state)){}
    Flyweight(const Flyweight &other) : estado_compartido(new EstadoCompartido(*other.estado_compartido)){}
    ~Flyweight()
    {
        delete estado_compartido;
    }
    EstadoCompartido *shared_state() const
    {
        return estado_compartido;
    }
    void Operation(const EstadoUnico &unique_state) const
    {
        cout << "Flyweight: Mostrando estados compartidos(" << *estado_compartido << ") y estados unicos (" << unique_state << ").\n";
    }
};
/**
 * The Flyweight Factory crea y maneja los flyweights
 */
class FlyweightFactory
{
private:
    unordered_map<string, Flyweight> flyweights_;
    string GetKey(const EstadoCompartido &ss) const
    {
        return ss.marca_ + "_" + ss.modelo_ + "_" + ss.color_;
    }

public:
    FlyweightFactory(initializer_list<EstadoCompartido> share_states)
    {
        for (const EstadoCompartido &ss : share_states)
        {
            this->flyweights_.insert(make_pair<string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
        }
    }
    Flyweight GetFlyweight(const EstadoCompartido &shared_state)
    {
        string key = this->GetKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            cout << "FlyweightFactory: No hay un flyweight existente, creando uno nuevo.\n";
            this->flyweights_.insert(make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            cout << "FlyweightFactory: Reusando flyweight existente.\n";
        }
        return this->flyweights_.at(key);
    }
    void Lista_de_Flyweights() const
    {
        size_t count = this->flyweights_.size();
        cout << "\nFlyweightFactory: Tengo " << count << " flyweights:\n";
        for (pair<string, Flyweight> pair : this->flyweights_)
        {
            cout << pair.first << "\n";
        }
    }
};


void CarroalaBasedeDtos( FlyweightFactory &ff, const string &plates, const string &owner, 
const string &brand, const string &model, const string &color)
{
    cout << "\nCliente: Agregando carro a la base de datos.\n";
    const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
    flyweight.Operation({plates, owner});
}


int main()
{
    FlyweightFactory *factory = new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"}, 
    {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
    factory->Lista_de_Flyweights();

    CarroalaBasedeDtos(*factory, "CL234IR", "James Doe", "BMW", "M5","red");

    CarroalaBasedeDtos(*factory, "CL234IR","James Doe", "BMW", "X1", "red");
    factory->Lista_de_Flyweights();
    delete factory;

    return 0;
}
