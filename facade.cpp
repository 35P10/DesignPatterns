#include <iostream>
using namespace std;

class Alarma{
public:
	void AlarmaOn(){
		cout << "La alarma esta encendida, la casa esta segura"<<endl;
	}
	void AlarmaOff(){
		cout << "La alarma esta apagada, puedes entrar a la casa"<<endl;
	}
};
class Musica{
public:
	void MusicaOn()	{
		cout << "La musica esta encendida"<<endl;
	}
	void MusicaOff(){
		cout << "La musica esta apagada"<<endl;
	}
};
class Tv{
public:
	void TvOn()	{
		cout << "La television esta prendida"<<endl;
	}
	void TvOff() {
		cout << "La television esta apagada"<<endl;
	}
};

class HouseFacade{
	Alarma alarma;
	Musica musica;
	Tv tv;
public:
	HouseFacade(){}
	void SalirCasa(){
		cout<<"Saldra de casa:"<<endl;
		alarma.AlarmaOn();
		musica.MusicaOff();
		tv.TvOff();
	}
	void VolverCasa(){
		cout<<"Llego a casa:"<<endl;
		alarma.AlarmaOff();
		musica.MusicaOn();
		tv.TvOn();
	}
};

int main(){
	HouseFacade casa;
	casa.SalirCasa();
	cout<<endl;
	casa.VolverCasa();
}
