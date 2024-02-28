//MEILYN JULEISY GARCIA LIMA
//9959-23-17838
#include <iostream>
#include <ctime>
#include <cstdlib>

// Definición de constantes
const int NUM_INDUSTRIAS = 3;
const int NUM_EMPRESAS = 5;
const int NUM_ANIOS = 4;
const double MONTO_MAXIMO = 1000000.00;

// Función para generar un número aleatorio dentro de un rango
double generarMontoAleatorio() {
    return (rand() % (int(MONTO_MAXIMO) + 1));
}

int main() {
    srand(time(0)); // Inicialización del generador de números aleatorios

    // Matrices para almacenar los montos de ventas
    double ventas[NUM_INDUSTRIAS][NUM_EMPRESAS][NUM_ANIOS];

    // Inicialización de las ventas aleatorias
    for (int i = 0; i < NUM_INDUSTRIAS; ++i) {
        for (int j = 0; j < NUM_EMPRESAS; ++j) {
            for (int k = 0; k < NUM_ANIOS; ++k) {
                ventas[i][j][k] = generarMontoAleatorio();
            }
        }
    }

    // Variables para almacenar los resultados
    double ventasMaximas[NUM_INDUSTRIAS] = {0};
    double ventasMinimas[NUM_INDUSTRIAS] = {MONTO_MAXIMO};
    double sumasIndustria[NUM_INDUSTRIAS] = {0};
    double promediosIndustria[NUM_INDUSTRIAS];

    // Cálculo de máximos, mínimos y sumas
    for (int i = 0; i < NUM_INDUSTRIAS; ++i) {
        for (int j = 0; j < NUM_EMPRESAS; ++j) {
            for (int k = 0; k < NUM_ANIOS; ++k) {
                double ventaActual = ventas[i][j][k];
                if (ventaActual > ventasMaximas[i]) {
                    ventasMaximas[i] = ventaActual;
                }
                if (ventaActual < ventasMinimas[i]) {
                    ventasMinimas[i] = ventaActual;
                }
                sumasIndustria[i] += ventaActual;
            }
        }
        promediosIndustria[i] = sumasIndustria[i] / (NUM_EMPRESAS * NUM_ANIOS);
    }

    // Mostrar resultados
    std::cout << "Resultados:\n";
    for (int i = 0; i < NUM_INDUSTRIAS; ++i) {
        std::cout << "Industria " << (i + 1) << ":\n";
        std::cout << "  Venta máxima: " << ventasMaximas[i] << "\n";
        std::cout << "  Venta mínima: " << ventasMinimas[i] << "\n";
        std::cout << "  Promedio de ventas: " << promediosIndustria[i] << "\n";
    }

    // Determinar la mejor industria
    int mejorIndustria = 0;
    double mejorPromedio = promediosIndustria[0];
    for (int i = 1; i < NUM_INDUSTRIAS; ++i) {
        if (promediosIndustria[i] > mejorPromedio) {
            mejorIndustria = i;
            mejorPromedio = promediosIndustria[i];
        }
    }
    std::cout << "La mejor industria es la " << (mejorIndustria + 1) << " con un promedio de ventas de " << mejorPromedio << "\n";

    return 0;
}
