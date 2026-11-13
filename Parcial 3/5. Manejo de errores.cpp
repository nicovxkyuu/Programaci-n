#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("archivo_inexistente.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo.";
        cout << "\nVerifica que exista.";
    }
    else {
        cout << "Archivo abierto correctamente.";
        archivo.close();
    }

    return 0;
}