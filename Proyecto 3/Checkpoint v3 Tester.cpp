#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Alumno {
    string nombre, matricula, grupo;   // grupo = nombre del grupo (acepta letras y numeros)
    float calif[3];
};

struct Maestro {
    string nombre, materia;
};

struct Grupo {
    string nombre, carrera;
};

// ---------- Utilidades ----------

// Pide un entero y repite hasta que se escriba un numero valido
int leerEntero(const string& msg) {
    int x;
    cout << msg;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor no valido. " << msg;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

float promedio(const Alumno& a) {
    return (a.calif[0] + a.calif[1] + a.calif[2]) / 3;
}

// Busca la carrera de un grupo por su nombre
string carreraDe(const vector<Grupo>& grupos, const string& nombreGrupo) {
    for (int i = 0; i < (int)grupos.size(); i++)
        if (grupos[i].nombre == nombreGrupo)
            return grupos[i].carrera;
    return "Sin carrera";
}

bool existeGrupo(const vector<Grupo>& grupos, const string& nombreGrupo) {
    for (int i = 0; i < (int)grupos.size(); i++)
        if (grupos[i].nombre == nombreGrupo)
            return true;
    return false;
}

// ---------- Alumnos ----------

void mostrar(Alumno a, const vector<Grupo>& grupos) {
    cout << "\n" << a.nombre << " | " << a.matricula
        << " | Grupo: " << a.grupo
        << " | Carrera: " << carreraDe(grupos, a.grupo)
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
    }
    catch (...) {
        return false;
    }

    if (!getline(s, a.grupo, '|')) return false;

    return true;
}

void capturar(Alumno& a, const vector<Grupo>& grupos) {
    cout << "Nombre: ";
    getline(cin, a.nombre);
    cout << "Matricula: ";
    getline(cin, a.matricula);

    for (int i = 0; i < 3; i++) {
        cout << "Calificacion " << i + 1 << " (0 a 10): ";
        while (!(cin >> a.calif[i]) || a.calif[i] < 0 || a.calif[i] > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresa una calificacion de 0 a 10. Calificacion "
                << i + 1 << ": ";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nGrupos disponibles:\n";
    for (int i = 0; i < (int)grupos.size(); i++)
        cout << " - " << grupos[i].nombre << " (" << grupos[i].carrera << ")\n";

    cout << "Grupo: ";
    getline(cin, a.grupo);
    while (!existeGrupo(grupos, a.grupo)) {
        cout << "Selecciona un grupo existente: ";
        getline(cin, a.grupo);
    }
}

// ---------- Grupos y maestros ----------

void capturarGrupos(vector<Grupo>& grupos) {
    int cantidad = leerEntero("\nCuantos grupos deseas registrar? ");

    if (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que cero.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Grupo nuevo;
        cout << "\n--- Grupo " << grupos.size() + 1 << " ---\n";
        cout << "Nombre del grupo: ";
        getline(cin, nuevo.nombre);
        cout << "Carrera asociada: ";
        getline(cin, nuevo.carrera);
        grupos.push_back(nuevo);
        cout << "Grupo registrado correctamente.\n";
    }
}

void capturarMaestros(vector<Maestro>& maestros) {
    int cantidad = leerEntero("\nCuantos maestros deseas registrar? ");

    if (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que cero.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Maestro nuevo;
        cout << "\n--- Maestro " << maestros.size() + 1 << " ---\n";
        cout << "Nombre del maestro: ";
        getline(cin, nuevo.nombre);
        cout << "Materia que imparte: ";
        getline(cin, nuevo.materia);
        maestros.push_back(nuevo);
        cout << "Maestro registrado correctamente.\n";
    }
}

void mostrarMaestros(const vector<Maestro>& maestros) {
    if (maestros.empty()) {
        cout << "\nNo hay maestros registrados.";
        return;
    }

    cout << "\n--- LISTA DE MAESTROS Y MATERIAS ---\n";
    for (int i = 0; i < (int)maestros.size(); i++) {
        cout << "\nMaestro " << i + 1;
        cout << "\nNombre: " << maestros[i].nombre;
        cout << "\nMateria: " << maestros[i].materia << "\n";
    }
}

// ---------- Reportes en pantalla ----------

void mostrarPromedios(const vector<Alumno>& alumnos, const vector<Grupo>& grupos) {
    int n = (int)alumnos.size();
    cout << "\n--- PROMEDIO DE CADA ALUMNO ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNombre: " << alumnos[i].nombre;
        cout << "\nMatricula: " << alumnos[i].matricula;
        cout << "\nGrupo: " << alumnos[i].grupo;
        cout << "\nCarrera: " << carreraDe(grupos, alumnos[i].grupo);
        cout << "\nPromedio: " << promedio(alumnos[i]) << "\n";
    }
}

void mejorPorGrupo(const vector<Alumno>& alumnos, const vector<Grupo>& grupos) {
    int n = (int)alumnos.size();
    cout << "\n--- MEJOR PROMEDIO POR GRUPO ---\n";

    for (int i = 0; i < (int)grupos.size(); i++) {
        int mejor = -1;

        for (int j = 0; j < n; j++) {
            if (alumnos[j].grupo == grupos[i].nombre) {
                if (mejor == -1 || promedio(alumnos[j]) > promedio(alumnos[mejor]))
                    mejor = j;
            }
        }

        cout << "\nGrupo: " << grupos[i].nombre;
        if (mejor == -1)
            cout << "\nNo hay alumnos en este grupo.\n";
        else {
            cout << "\nMejor alumno: " << alumnos[mejor].nombre;
            cout << "\nPromedio: " << promedio(alumnos[mejor]) << "\n";
        }
    }
}

void alumnosPorCarrera(const vector<Alumno>& alumnos, const vector<Grupo>& grupos) {
    int n = (int)alumnos.size();
    cout << "\n--- ALUMNOS POR CARRERA ---\n";

    for (int i = 0; i < (int)grupos.size(); i++) {
        bool repetida = false;
        for (int j = 0; j < i; j++) {
            if (grupos[i].carrera == grupos[j].carrera) {
                repetida = true;
                break;
            }
        }
        if (repetida) continue;

        int cantidad = 0;
        for (int j = 0; j < n; j++)
            if (carreraDe(grupos, alumnos[j].grupo) == grupos[i].carrera)
                cantidad++;

        cout << "\nCarrera: " << grupos[i].carrera;
        cout << "\nCantidad de alumnos: " << cantidad << "\n";
    }
}

// ---------- Datos al azar ----------

// Si no hay grupos o maestros los crea, y agrega 'cantidad' alumnos al azar
void agregarAlAzar(vector<Alumno>& alumnos, vector<Grupo>& grupos,
    vector<Maestro>& maestros, int cantidad) {
    const string nombres[] = { "Ana", "Luis", "Maria", "Carlos", "Sofia", "Diego",
                               "Valeria", "Jorge", "Fernanda", "Pablo", "Camila", "Andres" };
    const string apellidos[] = { "Garcia", "Lopez", "Martinez", "Hernandez", "Gonzalez",
                                 "Perez", "Sanchez", "Ramirez", "Torres", "Flores" };
    const string nombresGrupo[] = { "1A", "1B", "2A", "3B" };
    const string carreras[] = { "Sistemas", "Mecatronica", "Industrial", "Administracion" };
    const string materias[] = { "Matematicas", "Programacion", "Fisica", "Ingles" };

    if (grupos.empty()) {
        for (int i = 0; i < 4; i++) {
            Grupo g;
            g.nombre = nombresGrupo[i];
            g.carrera = carreras[rand() % 4];
            grupos.push_back(g);
        }
    }

    if (maestros.empty()) {
        for (int i = 0; i < 4; i++) {
            Maestro m;
            m.nombre = "Prof. " + nombres[rand() % 12] + " " + apellidos[rand() % 10];
            m.materia = materias[i];
            maestros.push_back(m);
        }
    }

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        a.nombre = nombres[rand() % 12] + " " + apellidos[rand() % 10]
            + " " + apellidos[rand() % 10];
        a.matricula = to_string(1000000 + (((long long)rand() << 15) | rand()) % 9000000);
        for (int j = 0; j < 3; j++)
            a.calif[j] = (rand() % 101) / 10.0f;   // de 0.0 a 10.0
        a.grupo = grupos[rand() % grupos.size()].nombre;
        alumnos.push_back(a);
    }
}

// ---------- Programa principal ----------

int main() {
    vector<Alumno> alumnos;   // crece solo, sin limite fijo
    Alumno nuevo;
    vector<Grupo> grupos;
    vector<Maestro> maestros;
    int opcion;
    string linea;

    srand((unsigned)time(0));

    cout << "=== Captura inicial ===";
    cout << "\n1. Capturar datos manualmente";
    cout << "\n2. Generar datos al azar";
    int modo = leerEntero("\nOpcion: ");

    if (modo == 2) {
        int cantidad = leerEntero("Cuantos alumnos generar? ");
        if (cantidad < 1) {
            cout << "Cantidad no valida.";
            return 0;
        }
        agregarAlAzar(alumnos, grupos, maestros, cantidad);
        cout << "Datos generados al azar.";
    }
    else {
        // Los grupos se registran primero, porque cada alumno pertenece a uno
        cout << "\n=== Registro de grupos y carreras ===";
        while (grupos.empty())
            capturarGrupos(grupos);

        int cantidad = leerEntero("\nCantidad de alumnos: ");

        if (cantidad < 1) {
            cout << "Cantidad no valida.";
            return 0;
        }

        for (int i = 0; i < cantidad; i++) {
            cout << "\nAlumno " << i + 1 << endl;
            Alumno a;
            capturar(a, grupos);
            alumnos.push_back(a);
        }
    }

    do {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Guardar alumnos, grupos y maestros en texto";
        cout << "\n2. Leer alumnos, grupos y maestros";
        cout << "\n3. Agregar alumno";
        cout << "\n4. Guardar archivo binario";
        cout << "\n5. Comprobar errores";
        cout << "\n6. Generar reporte (archivo)";
        cout << "\n7. Capturar grupos y carreras";
        cout << "\n8. Capturar maestros";
        cout << "\n9. Mostrar maestros y materias";
        cout << "\n10. Mostrar reportes en pantalla";
        cout << "\n11. Generar alumnos al azar";
        cout << "\n12. Salir";
        opcion = leerEntero("\nOpcion: ");

        switch (opcion) {

        case 1: {
            ofstream f("alumnos.txt");
            ofstream g("grupos.txt");
            ofstream m("maestros.txt");
            if (!f || !g || !m) {
                cout << "Error al crear archivo.";
                break;
            }
            for (int i = 0; i < (int)alumnos.size(); i++)
                escribir(f, alumnos[i]);
            for (int i = 0; i < (int)grupos.size(); i++)
                g << grupos[i].nombre << "|" << grupos[i].carrera << endl;
            for (int i = 0; i < (int)maestros.size(); i++)
                m << maestros[i].nombre << "|" << maestros[i].materia << endl;
            cout << "Alumnos, grupos y maestros guardados.";
            break;
        }

        case 2: {
            ifstream f("alumnos.txt");
            if (!f) {
                cout << "No se pudo abrir el archivo.";
                break;
            }
            alumnos.clear();
            while (getline(f, linea)) {
                Alumno a;
                if (leer(linea, a))
                    alumnos.push_back(a);
            }
            f.close();

            // Grupos (solo se reemplazan si el archivo trae datos)
            ifstream g("grupos.txt");
            if (g) {
                vector<Grupo> leidos;
                while (getline(g, linea)) {
                    stringstream s(linea);
                    Grupo x;
                    if (getline(s, x.nombre, '|') && getline(s, x.carrera, '|'))
                        leidos.push_back(x);
                }
                if (!leidos.empty())
                    grupos = leidos;
            }

            // Maestros
            ifstream m("maestros.txt");
            if (m) {
                vector<Maestro> leidos;
                while (getline(m, linea)) {
                    stringstream s(linea);
                    Maestro x;
                    if (getline(s, x.nombre, '|') && getline(s, x.materia, '|'))
                        leidos.push_back(x);
                }
                maestros = leidos;
            }

            for (int i = 0; i < (int)alumnos.size(); i++)
                mostrar(alumnos[i], grupos);
            break;
        }

        case 3: {
            if (grupos.empty()) {
                cout << "Primero debes registrar al menos un grupo.";
                break;
            }

            cout << "\nNuevo alumno:\n";
            capturar(nuevo, grupos);

            ofstream f("alumnos.txt", ios::app);
            if (!f) {
                cout << "No se pudo abrir el archivo.";
                break;
            }
            escribir(f, nuevo);
            f.close();

            alumnos.push_back(nuevo);
            cout << "Alumno agregado.";
            break;
        }

        case 4: {
            ofstream f("alumnos.dat", ios::binary);
            if (!f) {
                cout << "Error al crear archivo binario.";
                break;
            }

            int total = (int)alumnos.size();
            f.write((char*)&total, sizeof(total));

            for (int i = 0; i < total; i++) {
                unsigned int tam = alumnos[i].nombre.size();
                f.write((char*)&tam, sizeof(tam));
                f.write(alumnos[i].nombre.c_str(), tam);

                tam = alumnos[i].matricula.size();
                f.write((char*)&tam, sizeof(tam));
                f.write(alumnos[i].matricula.c_str(), tam);

                f.write((char*)alumnos[i].calif, sizeof(alumnos[i].calif));

                tam = alumnos[i].grupo.size();
                f.write((char*)&tam, sizeof(tam));
                f.write(alumnos[i].grupo.c_str(), tam);
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
            string nombreArchivo;
            cout << "Nombre del archivo a comprobar (ej. alumnos.txt): ";
            getline(cin, nombreArchivo);

            ifstream f(nombreArchivo);
            if (!f)
                cout << "Error: el archivo \"" << nombreArchivo
                << "\" no existe o no se puede abrir.";
            else {
                cout << "El archivo \"" << nombreArchivo
                    << "\" se abrio correctamente.";
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

            vector<Alumno> datos;

            while (getline(f, linea)) {
                Alumno a;
                if (leer(linea, a))
                    datos.push_back(a);
            }
            f.close();
            int cantidad = (int)datos.size();

            // ordenar de mayor a menor promedio
            sort(datos.begin(), datos.end(),
                [](const Alumno& x, const Alumno& y) {
                    return promedio(x) > promedio(y);
                });

            ofstream r("reporte_alumnos.txt");
            if (!r) {
                cout << "No se pudo crear el reporte.";
                break;
            }

            for (int i = 0; i < cantidad; i++) {
                r << datos[i].nombre << " - "
                    << datos[i].matricula << " - Grupo: "
                    << datos[i].grupo << " - Promedio: "
                    << promedio(datos[i]) << endl;
            }

            r.close();
            cout << "Reporte generado correctamente.";
            break;
        }

        case 7:
            capturarGrupos(grupos);
            break;

        case 8:
            capturarMaestros(maestros);
            break;

        case 9:
            mostrarMaestros(maestros);
            break;

        case 10:
            if (alumnos.empty()) {
                cout << "\nNo hay alumnos registrados.";
                break;
            }
            cout << "\n========== REPORTES ==========";
            mostrarPromedios(alumnos, grupos);
            mejorPorGrupo(alumnos, grupos);
            alumnosPorCarrera(alumnos, grupos);
            break;

        case 11: {
            int cantidad = leerEntero("Cuantos alumnos generar? ");
            if (cantidad < 1) {
                cout << "Cantidad no valida.";
                break;
            }
            agregarAlAzar(alumnos, grupos, maestros, cantidad);
            cout << cantidad << " alumnos generados. Total: " << alumnos.size();
            break;
        }

        case 12:
            cout << "Programa finalizado.";
            break;

        default:
            cout << "Opcion incorrecta.";
        }

    } while (opcion != 12);

    return 0;
}