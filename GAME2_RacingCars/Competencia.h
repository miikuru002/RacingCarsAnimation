#pragma once
#include <iostream>
#include <conio.h>
#include "Carro.h"
#include "Carro.h"

using namespace std;
using namespace System;

class Competencia
{
private:
	Carro** arregloCar; //arreglo de carros

public:
	Competencia();
	~Competencia();
	void iniciarCarrera();
};

Competencia::Competencia()
{
	char tecla;

	//inicializar la ventana
	Console::Title = "Carrera de autos";
	Console::WindowWidth = COL; // Columnas de la ventana
	Console::WindowHeight = FIL; // Filas de la ventana
	Console::CursorVisible = false; // Ocultar el cursor

	//inicializar los carros
	arregloCar = new Carro * [3]; //3 carros
	arregloCar[0] = new Carro(0, 6, 1, 3); //rojo lento
	arregloCar[0]->mostrar();
	arregloCar[1] = new Carro(0, 12, 2, 1); //azul rapido
	arregloCar[1]->mostrar();
	arregloCar[2] = new Carro(0, 18, 3, 2); //verde medio
	arregloCar[2]->mostrar();

	Console::SetCursorPosition(0, 0);
	Console::ForegroundColor = ConsoleColor::White;

	cout << "Presione G para iniciar la carrera";

	while (true)
	{
		if (_kbhit())
		{
			tecla = _getch();

			if (tecla == 'G' || tecla == 'g') //inciar la carrera con g o G
				break;
		}
	}

}

Competencia::~Competencia()
{
	delete[] arregloCar;
}

void Competencia::iniciarCarrera()
{
	while (true)
	{
		//si no se desplaza el auto1 o el auto2 o el auto3
		if (!arregloCar[0]->desplazar() || !arregloCar[1]->desplazar() || !arregloCar[2]->desplazar())
			break; //terminar programa
		_sleep(100);
	}

	_getch();
}