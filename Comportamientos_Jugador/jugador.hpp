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

struct stateN1{
    ubicacion jugador;
    ubicacion sonambulo;

    bool operator==(const stateN1 &st) const{
        return (jugador.f == st.jugador.f && jugador.c == st.jugador.c &&
        sonambulo.f == st.sonambulo.f && sonambulo.c == st.sonambulo.c &&
        jugador.brujula == st.jugador.brujula && sonambulo.brujula == st.sonambulo.brujula);
    }

    bool operator<(const stateN1 &st) const
    {
        return (jugador.f < st.jugador.f ||
               (jugador.f == st.jugador.f && jugador.c < st.jugador.c) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula < st.jugador.brujula) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && sonambulo.f < st.sonambulo.f) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && sonambulo.f == st.sonambulo.f && sonambulo.c < st.sonambulo.c) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && sonambulo.f == st.sonambulo.f && sonambulo.c == st.sonambulo.c && sonambulo.brujula < st.sonambulo.brujula));
    }
};

struct nodeN1{
  stateN1 st;
  list<Action> secuencia;

  bool operator==(const nodeN1 &nd) const{
    return (st == nd.st);
  }

  bool operator<(const nodeN1 &nd) const
    {
        return (st < nd.st);
    }
};

struct stateN2{
    ubicacion jugador;
    ubicacion sonambulo;

    bool jugadorBikini;
    bool jugadorZapatillas;

    bool operator==(const stateN2 &st) const{
        return (jugador.f == st.jugador.f && jugador.c == st.jugador.c &&
        sonambulo.f == st.sonambulo.f && sonambulo.c == st.sonambulo.c &&
        jugador.brujula == st.jugador.brujula && sonambulo.brujula == st.sonambulo.brujula &&
        jugadorBikini == st.jugadorBikini && jugadorZapatillas == st.jugadorZapatillas);
    }

    bool operator<(const stateN2 &st) const
    {
        return (jugador.f < st.jugador.f ||
               (jugador.f == st.jugador.f && jugador.c < st.jugador.c) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula < st.jugador.brujula) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini < st.jugadorBikini) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini == st.jugadorBikini && jugadorZapatillas < st.jugadorZapatillas));
    }
};

struct nodeN2{
  stateN2 st;
  list<Action> secuencia;
  int coste;

  bool operator==(const nodeN2 &nd) const{
    return (st == nd.st);
  }

  bool operator<(const nodeN2 &nd) const
    {
        return (coste > nd.coste);
    }
};

struct stateN3{
    ubicacion jugador;
    ubicacion sonambulo;

    bool jugadorBikini;
    bool jugadorZapatillas;
    bool sonambuloBikini;
    bool sonambuloZapatillas;

    bool operator==(const stateN3 &st) const{
        return (jugador.f == st.jugador.f && jugador.c == st.jugador.c &&
        sonambulo.f == st.sonambulo.f && sonambulo.c == st.sonambulo.c &&
        jugador.brujula == st.jugador.brujula && sonambulo.brujula == st.sonambulo.brujula &&
        jugadorBikini == st.jugadorBikini && jugadorZapatillas == st.jugadorZapatillas &&
        sonambuloBikini == st.sonambuloBikini && sonambuloZapatillas == st.sonambuloZapatillas);
    }

    bool operator<(const stateN3 &st) const
    {
        return (jugador.f < st.jugador.f ||
               (jugador.f == st.jugador.f && jugador.c < st.jugador.c) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula < st.jugador.brujula) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini < st.jugadorBikini) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini == st.jugadorBikini && jugadorZapatillas < st.jugadorZapatillas) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini == st.jugadorBikini && jugadorZapatillas == st.jugadorZapatillas && sonambuloBikini < st.sonambuloBikini) ||
               (jugador.f == st.jugador.f && jugador.c == st.jugador.c && jugador.brujula == st.jugador.brujula && jugadorBikini == st.jugadorBikini && jugadorZapatillas == st.jugadorZapatillas && sonambuloBikini == st.sonambuloBikini && sonambuloZapatillas < st.sonambuloZapatillas));
    }
};

struct nodeN3{
  stateN3 st;
  list<Action> secuencia;
  int coste;
  int heuristica;
  int suma;

  bool operator==(const nodeN3 &nd) const{
    return (st == nd.st);
  }

  bool operator<(const nodeN3 &nd) const
    {
        return (suma > nd.suma);
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

      c_state_N1.jugador.c = 99;
      c_state_N1.jugador.f = 99;
      c_state_N1.jugador.brujula = norte;
      c_state_N1.sonambulo.c = 99;
      c_state_N1.sonambulo.f = 99;
      c_state_N1.sonambulo.brujula = norte;
      
      c_state_N2.jugador.c = 99;
      c_state_N2.jugador.f = 99;
      c_state_N2.jugador.brujula = norte;
      c_state_N2.sonambulo.c = 99;
      c_state_N2.sonambulo.f = 99;
      c_state_N2.sonambulo.brujula = norte;
      c_state_N2.jugadorBikini = false;
      c_state_N2.jugadorZapatillas = false;

      c_state_N3.jugador.c = 99;
      c_state_N3.jugador.f = 99;
      c_state_N3.jugador.brujula = norte;
      c_state_N3.sonambulo.c = 99;
      c_state_N3.sonambulo.f = 99;
      c_state_N3.sonambulo.brujula = norte;
      c_state_N3.jugadorBikini = false;
      c_state_N3.jugadorZapatillas = false;
      c_state_N3.sonambuloBikini = false;
      c_state_N3.sonambuloZapatillas = false;

    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

    void VisualizaPlan(const stateN0 &st, const list<Action> &plan);
    void VisualizaPlan_N1(const stateN1 &st, const list<Action> &plan);
    void VisualizaPlan_N2(const stateN2 &st, const list<Action> &plan);
    void VisualizaPlan_N3(const stateN3 &st, const list<Action> &plan);

  private:
    // Declarar Variables de Estado

    bool hayPlan;
    list<Action> plan;
    stateN0 c_state;
    stateN1 c_state_N1;
    stateN2 c_state_N2;
    stateN3 c_state_N3;
    
    ubicacion goal;

};

#endif
