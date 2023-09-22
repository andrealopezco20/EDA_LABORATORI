import matplotlib.pyplot as plt
import pandas as pd

# Dimensiones a considerar
dimensions = [10, 50, 100, 500, 1000, 2000, 5000]

for dim in dimensions:
    # Cargar las distancias desde el archivo txt
    df = pd.read_csv(f'distancia_dimension_{dim}.txt', header=None, names=['Distance'])

    # Crear un histograma
    plt.figure(figsize=(8, 6))
    plt.hist(df['Distance'], bins=50, color='skyblue', edgecolor='black')
    plt.title(f'Histogram of Distances (Dimension {dim})')
    plt.xlabel('Distance')
    plt.ylabel('Frequency')
    plt.grid(True)
    
    # Guardar la figura como imagen
    plt.savefig(f'histogram_dim_{dim}.png')
    plt.show()
