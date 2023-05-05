#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

list<Action> AvanzaASaltosDeCaballo(){
	list<Action> secuencia;
	secuencia.push_back(actFORWARD);
	secuencia.push_back(actFORWARD);
	secuencia.push_back(actTURN_R);
    secuencia.push_back(actFORWARD);
	return secuencia;
}

/** Devuelve si una ubicación en el mapa es transitable para el agente */
bool CasillaTransitable(const ubicacion &x, const vector<vector<unsigned char>> &mapa)
{
	return (mapa[x.f][x.c] != 'P' and mapa[x.f][x.c] != 'M');
}

/** Devuelve la ubicación siguiente según el avance del agente*/
ubicacion NextCasilla(const ubicacion &pos)
{
	ubicacion next = pos;
	switch (pos.brujula)
	{
	case norte:
		next.f = pos.f - 1;
		break;
	case noreste:
		next.f = pos.f - 1;
		next.c = pos.c + 1;
		break;
	case este:
		next.c = pos.c + 1;
		break;
	case sureste:
		next.f = pos.f + 1;
		next.c = pos.c + 1;
		break;
	case sur:
		next.f = pos.f + 1;
		break;
	case suroeste:
		next.f = pos.f + 1;
		next.c = pos.c - 1;
		break;
	case oeste:
		next.c = pos.c - 1;
		break;
	case noroeste:
		next.f = pos.f - 1;
		next.c = pos.c - 1;
		break;
	default:
		break;
	}

	return next;
}

bool verSonambuloN1(const stateN1 &estado){
	bool loVe = false;

	switch(estado.jugador.brujula){
		case norte:
			if ((estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) ||
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c))
				loVe = true;
		case noreste:
			if ((estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c + 1 == estado.sonambulo.c) || 
			(estado.jugador.f  == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) ||
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c))
				loVe = true;
		break;
		case este:	
			if ((estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) ||
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c))
				loVe = true;
		break;
		case sureste:
			if ((estado.jugador.f == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) ||
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c))
				loVe = true;
		break;
		case sur:
			if ((estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +3 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c +1 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) ||
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c))
				loVe = true;
		break;
		case suroeste:
			if ((estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f  == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c  == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) ||
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c))
				loVe = true;
		break;
		case oeste:
			if ((estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f +3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f +2 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f +1 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) ||
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c))
				loVe = true;
		break;
		case noroeste:
			if ((estado.jugador.f == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c) || 
			(estado.jugador.f == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -1 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -2 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -3 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -2 == estado.sonambulo.c) || 
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c -1 == estado.sonambulo.c) ||
			(estado.jugador.f -3 == estado.sonambulo.f && estado.jugador.c == estado.sonambulo.c))
				loVe = true;
		break;
	}
	return loVe;
}

/** Encuentra si el elmento item está en lista */
bool Find(const stateN0 &item, const list<nodeN0> &lista)
{
  auto it = lista.begin();
  while (it != lista.end() and !((*it).st == item))
    it++;

  return (!(it == lista.end()));
}

int CalculaCoste(const stateN2 &st, const Action &accion, const vector<vector<unsigned char>> &mapa){
	int coste = 0;
	char tipo_casilla = mapa[st.jugador.f][st.jugador.c];
	switch(tipo_casilla){
		case 'A':
			if(accion == actFORWARD){
				if(st.jugadorBikini){
					coste = 10;
				}
				else{
					coste = 100;
				}
			} else if (accion == actTURN_L || accion == actTURN_R){
				if(st.jugadorBikini){
					coste = 5;
				}
				else{
					coste = 25;
				}
			}
		break;
		case 'B':
			if(accion == actFORWARD){
				if(st.jugadorZapatillas){
					coste = 15;
				}
				else{
					coste = 50;
				}
			} else if (accion == actTURN_L || accion == actTURN_R){
				if(st.jugadorZapatillas){
					coste = 1;
				}
				else{
					coste = 5;
				}
			}
		break;
		case 'T':
			coste = 2;
		break;
		default:
			coste = 1;
		break;
	}
	return coste;
}
/** Devuelve el estado que se genera si el agente puede avanzar.
 * Si no puede avanzar, se devuelve como salida el mismo estado de entrada.
 */
stateN0 apply(const Action &a, const stateN0 &st, const vector<vector<unsigned char>> &mapa)
{
  stateN0 st_result = st;
  ubicacion sig_ubicacion;
  switch (a){
  case actFORWARD: // si casilla delante es transitable y no está ocupada por el sonámbulo
    sig_ubicacion = NextCasilla(st.jugador);
    if (CasillaTransitable(sig_ubicacion, mapa) and !(sig_ubicacion == st.sonambulo)){
      st_result.jugador = sig_ubicacion;
    }
    break;
  case actTURN_L:
    st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
    break;

  case actTURN_R:
    st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
    break;
  }
  return st_result;
}

stateN1 apply_N1(const Action &a, const stateN1 &st, const vector<vector<unsigned char>> &mapa)
{
  stateN1 st_result = st;
  ubicacion sig_ubicacion;
  switch (a){
  	case actFORWARD: // si casilla delante es transitable y no está ocupada por el sonámbulo
    	sig_ubicacion = NextCasilla(st.jugador);
    	if (CasillaTransitable(sig_ubicacion, mapa) and !(sig_ubicacion == st.sonambulo)){
      		st_result.jugador = sig_ubicacion;
    	}
    break;
  	case actTURN_L:
    	st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
    break;

  	case actTURN_R:
    	st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
    break;

	case actSON_FORWARD:
		sig_ubicacion = NextCasilla(st.sonambulo);
    	if (CasillaTransitable(sig_ubicacion, mapa) and !(sig_ubicacion == st.jugador)){
      		st_result.sonambulo = sig_ubicacion;
    	}
	break;

	case actSON_TURN_SL:
		st_result.sonambulo.brujula = static_cast<Orientacion>((st_result.sonambulo.brujula + 7) % 8);
	break;

	case actSON_TURN_SR:
		st_result.sonambulo.brujula = static_cast<Orientacion>((st_result.sonambulo.brujula + 1) % 8);
	break;
  }
  return st_result;
}

stateN2 apply_N2(const Action &a, const stateN2 &st, const vector<vector<unsigned char>> &mapa)
{
  stateN2 st_result = st;
  ubicacion sig_ubicacion;
  switch (a){
  case actFORWARD: // si casilla delante es transitable y no está ocupada por el sonámbulo
    sig_ubicacion = NextCasilla(st.jugador);
    if (CasillaTransitable(sig_ubicacion, mapa) and !(sig_ubicacion == st.sonambulo)){
      st_result.jugador = sig_ubicacion;
    }
	st_result.coste += CalculaCoste(st_result, actFORWARD, mapa);
    break;
  case actTURN_L:
    st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
	st_result.coste += CalculaCoste(st_result, actTURN_L, mapa);
    break;

  case actTURN_R:
    st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
	st_result.coste += CalculaCoste(st_result, actTURN_R, mapa);
    break;
  }
  return st_result;
}

/** Implementación búsqueda en anchura nivel 0 */
list<Action> AnchuraSoloJugador_N0(const stateN0 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa)
{
  nodeN0 current_node; 
  current_node.st = inicio;
  list<nodeN0> frontier;
  set<nodeN0> explored;
  list<Action> plan;
  bool SolutionFound = (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c);
  frontier.push_back(current_node);

  while (!frontier.empty() and !SolutionFound) {
    frontier.pop_front();
    explored.insert(current_node);

    // Generar hijo actFORWARD
    nodeN0 child_forward = current_node;
	
	//child_forward.secuencia = current_node.secuencia;
	child_forward.st = apply(actFORWARD, current_node.st, mapa);
    if (child_forward.st.jugador.f == final.f and child_forward.st.jugador.c == final.c){
      current_node = child_forward;
	  current_node.secuencia.push_back(actFORWARD);
      SolutionFound = true;
    }
    else if (explored.find(child_forward) == explored.end()){
		child_forward.secuencia.push_back(actFORWARD);
		frontier.push_back(child_forward);
    }

    if (!SolutionFound) {
      // Generar hijo actTURN_L
	  nodeN0 child_turnl = current_node;
      child_turnl.st = apply(actTURN_L, current_node.st, mapa);
      if (explored.find(child_turnl) == explored.end()){
		child_turnl.secuencia.push_back(actTURN_L);
        frontier.push_back(child_turnl);
      }
      // Generar hijo actTURN_R
	  nodeN0 child_turnr = current_node;
      child_turnr.st = apply(actTURN_R, current_node.st, mapa);
      if (explored.find(child_turnr) == explored.end()){
		child_turnr.secuencia.push_back(actTURN_R);
        frontier.push_back(child_turnr);
      }
    }

    if (!SolutionFound && !frontier.empty()){
      current_node = frontier.front();
	  while(!frontier.empty() && explored.find(current_node) != explored.end()){
		frontier.pop_front();
		current_node = frontier.front();
	  }
    }
  }

  if(SolutionFound){
	plan = current_node.secuencia;
  }

  return plan;
}

/** Implementación búsqueda en anchura nivel 1 */
list<Action> AnchuraSoloSonambulo_N1(const stateN1 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa)
{
  nodeN1 current_node; 
  current_node.st = inicio;
  list<nodeN1> frontier;
  set<nodeN1> explored;
  list<Action> plan;
  bool SolutionFound = (current_node.st.sonambulo.f == final.f and current_node.st.sonambulo.c == final.c);
  frontier.push_back(current_node);

  while (!frontier.empty() and !SolutionFound) {
    frontier.pop_front();
    explored.insert(current_node);

	if(verSonambuloN1(current_node.st)){	//Mover Sonámbulo teóricamente -> Debemos evaluar todos los nodos
		// Generar hijo actSONFORWARD
    	nodeN1 child_sonforward = current_node;
	
		//child_forward.secuencia = current_node.secuencia;
		child_sonforward.st = apply_N1(actSON_FORWARD, current_node.st, mapa);
    	if (child_sonforward.st.sonambulo.f == final.f and child_sonforward.st.sonambulo.c == final.c){
      		current_node = child_sonforward;
	  		current_node.secuencia.push_back(actSON_FORWARD);
     		SolutionFound = true;
    	}
    	else if (explored.find(child_sonforward) == explored.end()){
			child_sonforward.secuencia.push_back(actSON_FORWARD);
			frontier.push_back(child_sonforward);
    	}

    	if (!SolutionFound) { //
      		// Generar hijo actTURN_SL
	  		nodeN1 child_sonturnl = current_node;
     		child_sonturnl.st = apply_N1(actSON_TURN_SL, current_node.st, mapa);
      		if (explored.find(child_sonturnl) == explored.end()){
				child_sonturnl.secuencia.push_back(actSON_TURN_SL);
        		frontier.push_back(child_sonturnl);
      		}
     	 	// Generar hijo actTURN_SR
	  		nodeN1 child_sonturnr = current_node;
      		child_sonturnr.st = apply_N1(actSON_TURN_SR, current_node.st, mapa);
     		if (explored.find(child_sonturnr) == explored.end()){
				child_sonturnr.secuencia.push_back(actSON_TURN_SR);
        		frontier.push_back(child_sonturnr);
      		}
			// Generar hijo actFORWARD -> Jugador
			nodeN1 child_forward = current_node;
			child_forward.st = apply_N1(actFORWARD, current_node.st, mapa);
			if (explored.find(child_forward) == explored.end()){
				child_forward.secuencia.push_back(actFORWARD);
				frontier.push_back(child_forward);
    		} 
			// Generar hijo actTURN_L -> Jugador
	 		nodeN1 child_turnl = current_node;
      		child_turnl.st = apply_N1(actTURN_L, current_node.st, mapa);
      		if (explored.find(child_turnl) == explored.end()){
				child_turnl.secuencia.push_back(actTURN_L);
        		frontier.push_back(child_turnl);
      		}	
      		// Generar hijo actTURN_R -> Jugador
	  		nodeN1 child_turnr = current_node;
     		child_turnr.st = apply_N1(actTURN_R, current_node.st, mapa);
      		if (explored.find(child_turnr) == explored.end()){
				child_turnr.secuencia.push_back(actTURN_R);
        		frontier.push_back(child_turnr);
      		}
    	}
	} else{	// Mover Jugador
		// Generar hijo actFORWARD
		nodeN1 child_forward = current_node;
		child_forward.st = apply_N1(actFORWARD, current_node.st, mapa);
		if (explored.find(child_forward) == explored.end()){
			child_forward.secuencia.push_back(actFORWARD);
			frontier.push_back(child_forward);
    	}
		// Generar hijo actTURN_L
	 	nodeN1 child_turnl = current_node;
      	child_turnl.st = apply_N1(actTURN_L, current_node.st, mapa);
      	if (explored.find(child_turnl) == explored.end()){
			child_turnl.secuencia.push_back(actTURN_L);
        	frontier.push_back(child_turnl);
      	}	
      	// Generar hijo actTURN_R
	  	nodeN1 child_turnr = current_node;
     	child_turnr.st = apply_N1(actTURN_R, current_node.st, mapa);
      	if (explored.find(child_turnr) == explored.end()){
			child_turnr.secuencia.push_back(actTURN_R);
        	frontier.push_back(child_turnr);
      	}
	}

    if (!SolutionFound && !frontier.empty()){
      current_node = frontier.front();
	  while(!frontier.empty() && explored.find(current_node) != explored.end()){
		frontier.pop_front();
		current_node = frontier.front();
	  }
    }
  }

  if(SolutionFound){
	plan = current_node.secuencia;
  }

  return plan;
}

/** Implementación búsqueda en anchura nivel 1 */
list<Action> DijkstraSoloJugador_N2(const stateN2 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa)
{
	nodeN2 current_node; 
	current_node.st = inicio;
	priority_queue<nodeN2> frontier;
	set<nodeN2> explored;
	list<Action> plan;

	bool SolutionFound = (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c);
	frontier.push(current_node);

	while(!frontier.empty() and !SolutionFound){
		frontier.pop();
		explored.insert(current_node);

		if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'K'){
			current_node.st.jugadorBikini = true;
			if(current_node.st.jugadorZapatillas){
				current_node.st.jugadorZapatillas = false;
			}
		} else if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'D'){
			current_node.st.jugadorZapatillas = true;
			if(current_node.st.jugadorBikini){
				current_node.st.jugadorBikini = false;
			}
		}

		// Generar hijo actFORWARD
		nodeN2 child_forward = current_node;
		child_forward.st = apply_N2(actFORWARD, current_node.st, mapa);
		if (child_forward.st.jugador.f == final.f and child_forward.st.jugador.c == final.c){
			current_node = child_forward;
			current_node.secuencia.push_back(actFORWARD);
			SolutionFound = true;
		}
		else if (explored.find(child_forward) == explored.end()){
			child_forward.secuencia.push_back(actFORWARD);
			frontier.push(child_forward);
		}

		if(!SolutionFound){
			// Generar hijo actTURN_L
	  		nodeN2 child_turnl = current_node;
      		child_turnl.st = apply_N2(actTURN_L, current_node.st, mapa);
      		if (explored.find(child_turnl) == explored.end()){
				child_turnl.secuencia.push_back(actTURN_L);
       			frontier.push(child_turnl);
      		}
      		// Generar hijo actTURN_R
	  		nodeN2 child_turnr = current_node;
      		child_turnr.st = apply_N2(actTURN_R, current_node.st, mapa);
      		if (explored.find(child_turnr) == explored.end()){
				child_turnr.secuencia.push_back(actTURN_R);
        		frontier.push(child_turnr);
      		}
		}

		if (!SolutionFound && !frontier.empty()){
      		current_node = frontier.top();
	  		while(!frontier.empty() && explored.find(current_node) != explored.end()){
				frontier.pop();
				current_node = frontier.top();
	  		}
   		}	
	}

	if(SolutionFound){
		plan = current_node.secuencia;
	}

	return plan;
}

/** pone a cero todos los elementos de una matriz */
void AnularMatriz(vector<vector<unsigned char>> &matriz)
{
  for (int i = 0; i < matriz.size(); i++)
    for (int j = 0; j < matriz[0].size(); j++)
      matriz[i][j] = 0;
}

// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores){
 	Action accion = actIDLE;

	if(sensores.nivel != 4){
		
		// Incluir aquí el comportamiento del agente jugador
 		if (!hayPlan){
 			// Invocar al método de búsqueda
  			cout << "Calculando plan..." << endl;
  		
  			goal.f = sensores.destinoF;
  			goal.c = sensores.destinoC;

			switch(sensores.nivel){
				case 0:
					c_state.jugador.f = sensores.posF;
  					c_state.jugador.c = sensores.posC;
  					c_state.jugador.brujula = sensores.sentido;
 					c_state.sonambulo.f = sensores.SONposF;
 					c_state.sonambulo.c = sensores.SONposC;
  					c_state.sonambulo.brujula = sensores.SONsentido;
					// Solución para el Nivel 0
					plan = AnchuraSoloJugador_N0(c_state, goal, mapaResultado);
					if(plan.size() > 0){
						VisualizaPlan(c_state,plan);
  						hayPlan = true;
					}
				break;
				case 1:
					c_state_N1.jugador.f = sensores.posF;
      				c_state_N1.jugador.c = sensores.posC;
     				c_state_N1.jugador.brujula = sensores.sentido;
					c_state_N1.sonambulo.f = sensores.SONposF;
      				c_state_N1.sonambulo.c = sensores.SONposC;
      				c_state_N1.sonambulo.brujula = sensores.SONsentido;
					// Solución para el nivel 1
					plan = AnchuraSoloSonambulo_N1(c_state_N1, goal, mapaResultado);
					if(plan.size() > 0){
						VisualizaPlan_N1(c_state_N1,plan);
  						hayPlan = true;
					}
				break;
				case 2:
					c_state_N2.jugador.f = sensores.posF;
      				c_state_N2.jugador.c = sensores.posC;
     				c_state_N2.jugador.brujula = sensores.sentido;
					c_state_N2.sonambulo.f = sensores.SONposF;
      				c_state_N2.sonambulo.c = sensores.SONposC;
      				c_state_N2.sonambulo.brujula = sensores.SONsentido;
					c_state_N2.jugadorBikini = false;
					c_state_N2.jugadorZapatillas = false;
					c_state_N2.coste = 0;
					// Solución para el nivel 2
					plan = 	DijkstraSoloJugador_N2(c_state_N2, goal, mapaResultado);
					if(plan.size() > 0){
						VisualizaPlan_N2(c_state_N2,plan);
  						hayPlan = true;
					}
				break;
				case 3:
					// Solución para el nivel 3

				break;
			}
 		}

 		if (hayPlan and plan.size()>0){
  			cout << "Ejecutando siguietne acción del plan" << endl;
 			accion = plan.front();
  			plan.pop_front();
 		}

 		if (plan.size()== 0){
  			cout << "Se completó el plan" << endl;
  			hayPlan = false;
 		}
	}
 	else{
		// Solución para el Nivel 4
	}

 	return accion;
}

/** Permite pintar sobre el mapa del simulador el plan partiendo desde el estado st */
void ComportamientoJugador::VisualizaPlan(const stateN0 &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
  stateN0 cst = st;

  auto it = plan.begin();
  while (it != plan.end()){
    switch (*it){
      case actFORWARD:
        cst.jugador = NextCasilla(cst.jugador);
	  mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
	  break;
	case actTURN_R:
        cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
	  break;
	case actTURN_L:
	  cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
	  break;
	case actSON_FORWARD:
	  cst.sonambulo = NextCasilla(cst.sonambulo);
	  mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
	  break;
	case actSON_TURN_SR:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
	  break;
	case actSON_TURN_SL:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
	  break;
    }
    it++;
  }
}

void ComportamientoJugador::VisualizaPlan_N1(const stateN1 &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
  stateN1 cst = st;

  auto it = plan.begin();
  while (it != plan.end()){
    switch (*it){
      case actFORWARD:
        cst.jugador = NextCasilla(cst.jugador);
	  mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
	  break;
	case actTURN_R:
        cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
	  break;
	case actTURN_L:
	  cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
	  break;
	case actSON_FORWARD:
	  cst.sonambulo = NextCasilla(cst.sonambulo);
	  mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
	  break;
	case actSON_TURN_SR:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
	  break;
	case actSON_TURN_SL:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
	  break;
    }
    it++;
  }
}

void ComportamientoJugador::VisualizaPlan_N2(const stateN2 &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
  stateN2 cst = st;

  auto it = plan.begin();
  while (it != plan.end()){
    switch (*it){
      case actFORWARD:
        cst.jugador = NextCasilla(cst.jugador);
	  mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
	  break;
	case actTURN_R:
        cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
	  break;
	case actTURN_L:
	  cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
	  break;
	case actSON_FORWARD:
	  cst.sonambulo = NextCasilla(cst.sonambulo);
	  mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
	  break;
	case actSON_TURN_SR:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
	  break;
	case actSON_TURN_SL:
	  cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
	  break;
    }
    it++;
  }
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
