#include <iostream>
#include <conio.h>
#include "Carro.h"
#include "Chasis.h"
#include "Llanta.h"
#include "Competencia.h"

using namespace std;
using namespace System;

int main()
{
	Competencia* c = new Competencia();
	c->iniciarCarrera();
	
	return 0;
}

