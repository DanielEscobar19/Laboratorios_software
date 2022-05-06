#ifndef JUEGO_H
#define JUEGO_H


class Juego
{
private:
  void crearWumpus(void cantidad);
  void crearCadejo(int cantidad);
  void crearManada(list<Monstruo *> monstruos);
public:
  void run();

private:
  vector<Monstruo *> monstruos;
  Cazador * jugador;
  int cantidadMonstruos;

};

#endif // JUEGO_H
