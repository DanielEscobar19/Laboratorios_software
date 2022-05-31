// Métodos plantilla en c++

template < typename T, class F >
vector< vector< T > > carga_valida_datos(ifstream& archivo, F t) throw (invalid_argument, out_of_range)
{
    vector< vector< T > > valores;
    vector< T > linea_valores;
    string linea;
    while (getline(archivo,linea)) {
        linea_valores.clear();
        stringstream ss(linea);
        string numero_S;
        T numero_T;
        while (getline(ss, numero_S, ',')) {
			try {
				numero_T = t(numero_S);
			}
			catch (exception e) {
				throw e;
			}
            linea_valores.push_back(numero_T);
        }
        valores.push_back(linea_valores);
    }
    return valores;
}