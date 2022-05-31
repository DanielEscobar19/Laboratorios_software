# Métodos plantilla en c++


## EFE: lee un archivo csv con numeros separados por coma y retorna una lista 
## de listas de numeros de tipo tn.
def lee_numeros_csv(archivo,tn):
	lista = []
	read_csv = csv.reader(archivo, delimiter=',')
	for row in read_csv:
		sublista = []
		for n in row:
			try:
				if (tn == Tipos_numeros.int):
					sublista.append(int(n))
				else: 
					sublista.append(float(n))
			except ValueError as error_de_valor:
				print("Error de tipo de valor: {0}".format(error_de_valor))
		lista.append(sublista)
	return lista