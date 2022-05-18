#include <string>

class Persona{
	private:
	std::string nombre;
	int edad;
	public:
		Persona(std::string ,int m);		
		void imprimirDatos();		
		Persona *operator->();
};