#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class Llanta
{
private:
	int x;
	int y;

public:
	Llanta(int x, int y);
	~Llanta();

	void borrar();
	void mostrar();
	void desplazar(); //no es bool, porque el Chasis llega antes a la meta
};

Llanta::Llanta(int x, int y)
{
	this->x = x;
	this->y = y;
}

Llanta::~Llanta()
{
}

void Llanta::borrar()
{
	//ubicarme en una psoicion determinada
	Console::SetCursorPosition(x, y);
	//borrar 1 espacios
	cout << " ";
}

void Llanta::mostrar()
{
	//ubicarme en una psoicion determinada
	Console::SetCursorPosition(x, y);
	//imprime los caracteres
	cout << char(219);
}

void Llanta::desplazar()
{
	borrar();
	x = x + 1; //mover a la derecha
	mostrar();
}