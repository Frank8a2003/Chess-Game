#include "Peon.h"
#include <iostream>
using namespace std;


Peon::Peon(string etiqueta, int contador, string color, int x, int y,bool avanceDoble) : Pieza(etiqueta,contador,color,x,y){
  avanceDoble=false;
}

void Peon::setAvanceDoble( ){
  avanceDoble=true;
}
void Peon::setAvanceNormal(){
  avanceDoble=false;
}
bool Peon::getAvanceDoble(){
  return avanceDoble;
}
bool Peon::validarMovimiento(int x_New, int y_New,Pieza* Tablero[][8]){
  int paso = 1;
  if (getColor()=="blanco")//  si es blanco
    paso *= -1;

  if(x_New == getX() && y_New == getY()+paso){//Si el movimiento es para avanzar enfrente
    if(Tablero[y_New][x_New]==NULL){ 
      int acom=getContador();
      setContador(acom+1);
      return true;
      }
    }

    //Comer en diagonal
  if ((x_New == getX()+paso && y_New == getY()+paso && Tablero[y_New][x_New]-> getColor()!=getColor()) || (x_New == getX()-paso && y_New == getY()+paso && Tablero[y_New][x_New]-> getColor()!=getColor() ) ){
    int acom=getContador();
    setContador(acom+1);
    return true;
    }
  
  if(x_New == getX() && y_New == getY()+2*paso && getContador()==0) {//Si el movimiento es para avanzar enfrente 2 casillas
    if(Tablero[y_New][x_New]==NULL && Tablero[y_New-1][x_New]==NULL){
      int acom=getContador();
      setContador(acom+1);
      setAvanceDoble();
      return true;
    }
    }

  if(Peon* ptrCirculo=dynamic_cast<Peon*>(Tablero[getY()][getX()+1])){

  //Comida de paso
  
if(Peon* ptrPeon=dynamic_cast<Peon*>(Tablero[getY()][getX()+1])){
    if(ptrPeon->getAvanceDoble()){
      if(x_New == getX()+1 && y_New == getY()+paso){
        return true;
      }
    }
      }

if(Peon* ptrPeon=dynamic_cast<Peon*>(Tablero[getY()][getX()-1])){
    if(ptrPeon->getAvanceDoble()){
      if(x_New == getX()-1 && y_New == getY()+paso){
        return true;
      }
    }
      }

  return false;
  }
   