#pragma once
#include <iostream>
#include <conio.h>
#include "LLanta.h"
#include "Chasis.h"

using namespace std;
using namespace System;

class Carro
{
private:
	Chasis* c;
	Llanta* llanta1, * llanta2, * llanta3, * llanta4;
	int color; //1->rojo, 2->azul, 3->verde
	int velocidad; //1->rapido, 2->medio, 3->lento
	int contador_tiempo;

public:
	Carro(int x_chasis, int y_chasis, int color, int velocidad);
	~Carro();
	void mostrar();
	bool desplazar(); //pregunta al chasis si se desplazó y responde con true y false
};

Carro::Carro(int x_chasis, int y_chasis, int color, int velocidad)
{
	this->color = color;
	this->velocidad = velocidad;
	contador_tiempo = 0;

	//se crea el chasis
	c = new Chasis(x_chasis, y_chasis);

	//se crean las llantas
	llanta1 = new Llanta(x_chasis, y_chasis - 1);
	llanta2 = new Llanta(x_chasis + 2, y_chasis - 1);
	llanta3 = new Llanta(x_chasis, y_chasis + 1);
	llanta4 = new Llanta(x_chasis + 2, y_chasis + 1);
}

Carro::~Carro()
{
}

void Carro::mostrar() //color 1)rojo, 2)azul, 3)verde
{
	if (color == 1)
		Console::ForegroundColor = ConsoleColor::Red;
	else if (color == 2)
		Console::ForegroundColor = ConsoleColor::Blue;
	else
		Console::ForegroundColor = ConsoleColor::Green;

	c->mostrar();
	llanta1->mostrar();
	llanta2->mostrar();
	llanta3->mostrar();
	llanta4->mostrar();
}

bool Carro::desplazar()
{
	bool se_desplazo = true;
	contador_tiempo++;

	if (contador_tiempo == velocidad)
	{
		if (color == 1)
			Console::ForegroundColor = ConsoleColor::Red;
		else if (color == 2)
			Console::ForegroundColor = ConsoleColor::Blue;
		else
			Console::ForegroundColor = ConsoleColor::Green;

		se_desplazo = c->desplazar();

		if (!se_desplazo) //si no se desplazó
		{
			Console::SetCursorPosition(0, 1);
			cout << ">> LLego a la meta!"; //imprime msj
		}
		else //si siguen desplazandose
		{
			//seguir desplazando
			llanta1->desplazar();
			llanta2->desplazar();
			llanta3->desplazar();
			llanta4->desplazar();

			contador_tiempo = 0;
		}
	}

	return se_desplazo;
}