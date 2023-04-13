#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct stateN0{
    ubicacion jugador;
    ubicacion sonambulo;

    bool operator==(const stateN0 &st) const{
        return (jugador.f == st.jugador.f && jugador.c == st.jugador.c &&
        sonambulo.f == st.sonambulo.f && sonambulo.c == st.sonambulo.c &&
        jugador.brujula == st.jugador.brujula && sonambulo.brujula == st.sonambulo.brujula);
    }

    bool operator<(const stateN0 &st) const
    {
        return (jugador.f < st.jugador.f ||
               (jugador.f == st.jugador.f && jugador.c < st.jugador.c) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula < st.jugador.brujula));
    }
};

struct nodeN0{
  stateN0 st;
  list<Action> secuencia;

  bool operator==(const nodeN0 &nd) const{
    return (st == nd.st);
  }

  bool operator<(const nodeN0 &nd) const
    {
        return (st < nd.st);
    }
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      hayPlan = false;

      goal.c = 99;
      goal.f = 99;
      c_state.jugador.c = 99;
      c_state.jugador.f = 99;
      c_state.jugador.brujula = norte;
      c_state.sonambulo.c = 99;
      c_state.sonambulo.f = 99;
      c_state.sonambulo.brujula = norte;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

    void VisualizaPlan(const stateN0 &st, const list<Action> &plan);


  private:
    // Declarar Variables de Estado

    bool hayPlan;
    list<Action> plan;
    stateN0 c_state;
    ubicacion goal;

};

#endif
