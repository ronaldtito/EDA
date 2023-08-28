import matplotlib.pyplot as plot

all_distances = []
##COLOCAR DIMENSION
dimension=int(input('Dimension:'))
name_file = 'dimension_'+str(dimension)
with open(name_file) as file:
    for line in file:
        all_distances.append(float(line))


plot.hist(x =all_distances, bins=120,edgecolor='black')
plot.title('Histograma de las distancias entre puntos con dimension '+str(dimension))
plot.xlabel('Distancias')
plot.ylabel('Frecuencias')
plot.show()