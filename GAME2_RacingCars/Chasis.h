#pragma once
#include <iostream>
#include <conio.h>
#define COL 80
#define FIL 30

using namespace std;
using namespace System;

class Chasis
{
private:
	int x;
	int y;

public:
	Chasis(int x, int y);
	~Chasis();

	void borrar();
	void mostrar();
	bool desplazar(); //para el ganador, true es para que los autos avancen y false para detenerse si un auto llega antes
};

Chasis::Chasis(int x, int y)
{
	this->x = x;
	this->y = y;
}

Chasis::~Chasis()
{
}

void Chasis::borrar()
{
	//ubicarme en una psoicion determinada
	Console::SetCursorPosition(x, y);
	//borrar 4 espacios
	cout << "    ";
}

void Chasis::mostrar()
{
	//ubicarme en una psoicion determinada
	Console::SetCursorPosition(x, y);
	//imprime los caracteres
	cout << char(219) << char(219) << char(219) << char(219);
}

bool Chasis::desplazar()
{
	//es 4, pq de ese tamaño es el carro y que este no exceda la ultima columna
	if (x + 4 < COL)
	{
		borrar();
		x = x + 1; //mover a la derecha
		mostrar();

		return true; //se desplazó correctamente
	}
	else
		return false; //llego a la meta
}