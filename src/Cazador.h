#ifndef CAZADOR_H
#define CAZADOR_H

class Agente;

class Cazador : public Agente
{
public:
  void atraparMonstruo(Monstruo * monstruo);
  bool estaMuerto();

private:
  int monstruosCazados;

};

#endif // CAZADOR_H
