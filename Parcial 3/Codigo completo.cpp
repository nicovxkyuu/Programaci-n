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

void mostrar(Alumno a) {
    cout << "\n" << a.nombre << " | " << a.matricula
        << " | Grupo: " << a.grupo
        << " | Promedio: " << promedio(a) << endl;
}

void escribir(ofstream& f, Alumno a) {
    f << a.nombre << "|" << a.matricula << "|"
        << a.calif[0] << "|" << a.calif[1] << "|"
        << a.calif[2] << "|" << a.grupo << endl;
}

bool leer(string linea, Alumno& a) {
    stringstream s(linea);
    string dato;

    if (!getline(s, a.nombre, '|')) return false;
    if (!getline(s, a.matricula, '|')) return false;

    try {
        for (int i = 0; i < 3; i++) {
            if (!getline(s, dato, '|')) return false;
            a.calif[i] = stof(dato);
        }

        if (!getline(s, dato, '|')) return false;
        a.grupo = stoi(dato);
    }
    catch (...) {
        return false;
    }

    return true;
}

void capturar(Alumno& a) {
    cout << "Nombre: ";
    getline(cin, a.nombre);
    cout << "Matricula: ";
    getline(cin, a.matricula);

    for (int i = 0; i < 3; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> a.calif[i];
    }

    cout << "Grupo: ";
    cin >> a.grupo;
    cin.ignore(1000, '\n');
}

int main() {
    Alumno alumnos[100], nuevo, aux;
    int n, opcion;
    string linea;

    cout << "Cantidad de alumnos: ";
    cin >> n;
    cin.ignore(1000, '\n');

    if (n < 1 || n > 100) {
        cout << "Cantidad no valida.";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nAlumno " << i + 1 << endl;
        capturar(alumnos[i]);
    }

    do {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Guardar alumnos en texto";
        cout << "\n2. Leer alumnos";
        cout << "\n3. Agregar alumno";
        cout << "\n4. Guardar archivo binario";
        cout << "\n5. Comprobar errores";
        cout << "\n6. Generar reporte";
        cout << "\n7. Salir";
        cout << "\nOpcion: ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        switch (opcion) {

        case 1: {
            ofstream f("alumnos.txt");
            if (!f) {
                cout << "Error al crear archivo.";
                break;
            }
            for (int i = 0; i < n; i++)
                escribir(f, alumnos[i]);
            f.close();
            cout << "Alumnos guardados.";
            break;
        }

        case 2: {
            ifstream f("alumnos.txt");
            if (!f) {
                cout << "No se pudo abrir el archivo.";
                break;
            }
            n = 0;
            while (getline(f, linea) && n < 100) {
                if (leer(linea, alumnos[n]))
                    n++;
            }
            f.close();

            for (int i = 0; i < n; i++)
                mostrar(alumnos[i]);
            break;
        }

        case 3: {
            if (n >= 100) {
                cout << "Arreglo lleno.";
                break;
            }

            cout << "\nNuevo alumno:\n";
            capturar(nuevo);

            ofstream f("alumnos.txt", ios::app);
            if (!f) {
                cout << "No se pudo abrir el archivo.";
                break;
            }
            escribir(f, nuevo);
            f.close();

            alumnos[n] = nuevo;
            n++;
            cout << "Alumno agregado.";
            break;
        }

        case 4: {
            ofstream f("alumnos.dat", ios::binary);
            if (!f) {
                cout << "Error al crear archivo binario.";
                break;
            }

            f.write((char*)&n, sizeof(n));

            for (int i = 0; i < n; i++) {
                unsigned int tam = alumnos[i].nombre.size();
                f.write((char*)&tam, sizeof(tam));
                f.write(alumnos[i].nombre.c_str(), tam);

                tam = alumnos[i].matricula.size();
                f.write((char*)&tam, sizeof(tam));
                f.write(alumnos[i].matricula.c_str(), tam);

                f.write((char*)alumnos[i].calif, sizeof(alumnos[i].calif));
                f.write((char*)&alumnos[i].grupo, sizeof(alumnos[i].grupo));
            }
            f.close();

            ifstream t("alumnos.txt", ios::binary | ios::ate);
            ifstream b("alumnos.dat", ios::binary | ios::ate);

            if (t && b) {
                cout << "Texto: " << t.tellg() << " bytes";
                cout << "\nBinario: " << b.tellg() << " bytes";
            }
            else {
                cout << "No se pudieron comparar los archivos.";
            }
            break;
        }

        case 5: {
            ifstream f("archivo_inexistente.txt");
            if (!f)
                cout << "Error: el archivo no existe o no se puede abrir.";
            else {
                cout << "Archivo abierto correctamente.";
                f.close();
            }
            break;
        }

        case 6: {
            ifstream f("alumnos.txt");
            if (!f) {
                cout << "No se pudo leer alumnos.txt.";
                break;
            }

            Alumno datos[100];
            int cantidad = 0;

            while (getline(f, linea) && cantidad < 100) {
                if (leer(linea, datos[cantidad]))
                    cantidad++;
            }
            f.close();

            for (int i = 0; i < cantidad - 1; i++) {
                for (int j = 0; j < cantidad - i - 1; j++) {
                    if (promedio(datos[j]) < promedio(datos[j + 1])) {
                        aux = datos[j];
                        datos[j] = datos[j + 1];
                        datos[j + 1] = aux;
                    }
                }
            }

            ofstream r("reporte_alumnos.txt");
            if (!r) {
                cout << "No se pudo crear el reporte.";
                break;
            }

            for (int i = 0; i < cantidad; i++) {
                r << datos[i].nombre << " - "
                    << datos[i].matricula << " - Promedio: "
                    << promedio(datos[i]) << endl;
            }

            r.close();
            cout << "Reporte generado correctamente.";
            break;
        }

        case 7:
            cout << "Programa finalizado.";
            break;

        default:
            cout << "Opcion incorrecta.";
        }

    } while (opcion != 7);

    return 0;
}
