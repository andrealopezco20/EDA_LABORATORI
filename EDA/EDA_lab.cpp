#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

// Función para calcular la distancia euclidiana entre dos puntos
double euclideanDistance(const std::vector<double>& point1, const std::vector<double>& point2) {
	double sum = 0.0;
	for (size_t i = 0; i < point1.size(); ++i) {
		double diff = point1[i] - point2[i];
		sum += diff * diff;
	}
	return std::sqrt(sum);
}

int main() {
	// Dimensiones a considerar
	std::vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};
	
	for (int dim : dimensions) {
		// Generar 100 puntos aleatorios de dimensión 'dim' entre 0 y 1
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> distribution(0.0, 1.0);
		
		std::vector<std::vector<double>> points(100, std::vector<double>(dim));
		
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < dim; ++j) {
				points[i][j] = distribution(gen);
			}
		}
		
		// Calcular distancias entre todos los pares de puntos
		std::vector<double> distances;
		
		for (size_t i = 0; i < points.size(); ++i) {
			for (size_t j = i + 1; j < points.size(); ++j) {
				double distance = euclideanDistance(points[i], points[j]);
				distances.push_back(distance);
			}
		}
		
		// Generar un archivo CSV con las distancias
		std::ofstream outFile("distancia_dimension_" + std::to_string(dim) + ".txt");
		for (double distance : distances) {
			outFile << distance << "\n";
		}
		outFile.close();
	}
	
	return 0;
}


