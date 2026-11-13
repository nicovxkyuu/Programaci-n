#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Alumno {
    string nombre, matricula;
    float calif[3];
    int grupo;
};

float promedio(Alumno a) {
    return (a.calif[0] + a.calif[1] + a.calif[2]) / 3;
}

int main() {
    Alumno a[100], aux;
    string linea, dato;
    int n = 0;

    ifstream archivo("alumnos.txt");

    if (!archivo) {
        cout << "No se pudo abrir el archivo.";
        return 0;
    }

    while (getline(archivo, linea) && n < 100) {
        stringstream s(linea);

        if (!getline(s, a[n].nombre, '|')) continue;
        if (!getline(s, a[n].matricula, '|')) continue;

        try {
            for (int j = 0; j < 3; j++) {
                if (!getline(s, dato, '|')) throw 1;
                a[n].calif[j] = stof(dato);
            }

            if (!getline(s, dato, '|')) throw 1;
            a[n].grupo = stoi(dato);
        }
        catch (...) {
            continue;
        }

        n++;
    }

    archivo.close();

    // Ordenar de mayor a menor
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (promedio(a[j]) < promedio(a[j + 1])) {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }

    ofstream reporte("reporte_alumnos.txt");

    if (!reporte) {
        cout << "Error al crear reporte.";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        reporte << a[i].nombre
            << " - Promedio: "
            << promedio(a[i]) << endl;
    }

    reporte.close();

    cout << "Reporte generado correctamente.";

    return 0;
}