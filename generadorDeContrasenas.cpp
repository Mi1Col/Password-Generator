#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>

class GeneradorContrasena {
	public:
		std::string mayusculas = "QWERTYUIOPASDFGHJKLMNBVCXZ";
		std::string minusculas = "qwertyuiopasdfghjklmnbvcxz";
		std::string numeros = "1234567890";
		std::string caracteres_especiales = "!@#$%^&*()_-+=<>?";
		int longitud = 8;
		bool usarMayusculas = true;
		bool usarMinusculas = false;
		bool usarNumeros = true;
		bool usarCaracteres_especiales = true;
		bool guardar_contrasena = true;
		std::string asignar_nombre = "";

		std::string generarContrasena() {
			std::string caracteres_disponibles = "";

			if (usarMayusculas) caracteres_disponibles += mayusculas;
		
			if (usarMinusculas) caracteres_disponibles += minusculas;
			
			if (usarNumeros) caracteres_disponibles += numeros;
		
			if (usarCaracteres_especiales) caracteres_disponibles += caracteres_especiales;
		
			if (caracteres_disponibles.empty()) {
				return "ERROR: No se seleccionaron caracteres.";
			}

			std::string contrasena = "";

			for (int i = 0; i < longitud; i++){
				char caracteresAleatorios = caracteres_disponibles[rand() % caracteres_disponibles.length()];
				contrasena += caracteresAleatorios;
			
			}
		
			return contrasena;
		
		};

		void guardarContrasena(const std::string& contrasena) {
			std::ofstream archivo("/home/miguel/contrasenas.txt");
			if (guardar_contrasena && archivo.is_open()) {
				archivo << asignar_nombre << ": " << contrasena << std::endl;
				archivo.close();
			}
		
		};
};


int main(){
	srand(static_cast<unsigned>(time(0)));
	
	GeneradorContrasena generador;

	std::cout << "Introduzca la longitud (8 por defecto): ";
	std::cin >> generador.longitud;

	char opcion;
	std::cout << "¿Usar mayusculas? (s/n): ";
	std::cin >> opcion;
	generador.usarMayusculas = (opcion == 's' || opcion == 'S');	
	
	std::cout << "¿Usar minusculas? (s/n): ";
	std::cin >> opcion;
	generador.usarMinusculas = (opcion == 's' || opcion == 'S');

	std::cout << "¿Usar numeros? (s/n): ";
	std::cin >> opcion;
	generador.usarNumeros = (opcion == 's' || opcion == 'S');

	std::cout << "¿Usar caracteres especiales? (s/n): ";	
	std::cin >> opcion;
	generador.usarCaracteres_especiales = (opcion == 's' || opcion == 'S');	
	
	std::string contrasena = generador.generarContrasena();
	std::cout << "\nSu contraseña es: " << contrasena << std::endl;
	
	std::cout << "¿Desea guardar la contraseña? (s/n): ";
	std::cin >> opcion;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (opcion == 's' || opcion == 'S') {
        std::cout << "Introduzca un nombre para asociar con la contraseña: ";

	std::getline(std::cin, generador.asignar_nombre);
        generador.guardarContrasena(contrasena);
        std::cout << "Contraseña guardada con éxito." << std::endl;
    }
	return 0;
}
