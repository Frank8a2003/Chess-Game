#include "Rey.h"
Rey::Rey(string etiqueta, int contador, string color, int x, int y) : Pieza(etiqueta,contador,color,x,y){
}

bool Rey::validarMovimiento(int x_New, int y_New,Pieza* Tablero[][8]){
  vector<int> posicionX;
  vector<int> posicionY;
  
//Mover Derecha
  if (getX()+1<=7){
    //Arriba Derecha
    if(getY()+1<=7 && !esta_En_Jaque(getX()+1, getY()+1,Tablero) && Tablero[getY()+1][getX()+1]==NULL || Tablero[getY()+1][getX()+1]->getColor()!=getColor()){
      posicionX.push_back(getX()+1);
      posicionY.push_back(getY()+1);
    }
    //Derecha Centro
    if( !esta_En_Jaque(getX()+1, getY(),Tablero) && Tablero[getY()+1][getX()]==NULL || Tablero[getY()+1][getX()]->getColor()!=getColor()){
      posicionX.push_back(getX()+1);
      posicionY.push_back(getY());
    }  

    //Derecha Abajo
    if(getY()-1>=0 && !esta_En_Jaque(getX()+1, getY()-1,Tablero) && Tablero[getY()+1][getX()-1]==NULL || Tablero[getY()+1][getX()-1]->getColor()!=getColor()){
      posicionX.push_back(getX()+1);
      posicionY.push_back(getY()-1);
    }
  }

  //Mover Izquierda
  if (getX()-1>=0){
    //Arriba Izquierda
    if(getY()+1<=7 && !esta_En_Jaque(getX()-1, getY()+1,Tablero) && Tablero[getY()+1][getX()+1]==NULL || Tablero[getY()-1][getX()+1]->getColor()!=getColor()){
      posicionX.push_back(getX()-1);
      posicionY.push_back(getY()+1);
    }
    //Izquierda Centro
    if( !esta_En_Jaque(getX()-1, getY(),Tablero) && Tablero[getY()-1][getX()]==NULL || Tablero[getY()-1][getX()]->getColor()!=getColor()){
      posicionX.push_back(getX()-1);
      posicionY.push_back(getY());
    }  

    //Abajo Izquierda
    if(getY()-1>=0 && !esta_En_Jaque(getX()-1, getY()-1,Tablero) && Tablero[getY()-1][getX()-1]==NULL || Tablero[getY()-1][getX()-1]->getColor()!=getColor()){
      posicionX.push_back(getX()-1);
      posicionY.push_back(getY()-1);
    }
  }

  //Mover Arriba-Abajo
  if(getY()-1>=0 && !esta_En_Jaque(getX(), getY()-1,Tablero) && Tablero[getY()][getX()-1]==NULL || Tablero[getY()][getX()-1]->getColor()!=getColor()){
      posicionX.push_back(getX());
      posicionY.push_back(getY()-1);
    }
  if(getY()+1<=7 && !esta_En_Jaque(getX(), getY()+1,Tablero) && Tablero[getY()][getX()+1]==NULL || Tablero[getY()][getX()+1]->getColor()!=getColor()){
      posicionX.push_back(getX());
      posicionY.push_back(getY()+1);
    }

  for (int j=0; j<posicionX.size(); j++){
        if(posicionX[j]==x_New && posicionY[j]==y_New){
          
          return true;
        }
    }
  
  return false;  
}

bool Rey::esta_En_Jaque(int _x, int _y,Pieza* Tablero[][8] ){
  //Revisar Jaque en fila o columna
  int a=getX();
  int b=getY();
  while(a>0){
    if(Tablero[a-1][b]==NULL){
      a--;
    }
    else{
      if(Tablero[a-1][b]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a-1][b]->getEtiqueta()=="Torre"|| Tablero[a-1][b]->getEtiqueta()=="Reina"){
          return true;
        }
        break;
      }
    }
    
  }  
  a=getX();
  while(a<7){
    if(Tablero[a+1][b]==NULL){
      a++;
    }
    else{
      if(Tablero[a+1][b]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a+1][b]->getEtiqueta()=="Torre"|| Tablero[a+1][b]->getEtiqueta()=="Reina"){
          return true;
        }
        break;
      }
    }
    
  }


  a=getX();
  while(b>0){
    if(Tablero[a][b-1]==NULL){
      b--;
    }
    else{
      if(Tablero[a][b-1]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a][b-1]->getEtiqueta()=="Torre"|| Tablero[a][b-1]->getEtiqueta()=="Reina"){
          return true;
        }
        break;
      }
    }
    
  }  
  b=getY();
  while(b<7){
    if(Tablero[a][b+1]==NULL){
      b++;
    }
    else{
      if(Tablero[a][b+1]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a][b+1]->getEtiqueta()=="Torre"|| Tablero[a][b+1]->getEtiqueta()=="Reina"){
          return true;
        }
        break;
      }
    }
    
  }
  
//Validar Ataque Diagonal
  b=getY();
  while(a<7 && b<7){
    if(Tablero[a+1][b+1]==NULL){
      b++;
      a++;
    }
    else{
      if (Tablero[a+1][b+1]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a+1][b+1]->getEtiqueta()=="Alfil"|| Tablero[a+1][b+1]->getEtiqueta()=="Reina"){
          return true;
        }
        else if(getColor()=="Negras" && a==getX() && b==getY() && Tablero[a+1][b+1]->getTipo()=="Peon"){
          return true;
        }
        break;
      } 
    }
  } 
  
  a=getX();
  b=getY();
  while(a>0 && b<7){
    if(Tablero[a-1][b+1]==NULL){
      b++;
      a--;
    }
    else{
      if (Tablero[a-1][b+1]->getColor()==getColor()){
        break;
      }
      else{
        if(Tablero[a-1][b+1]->getTipo()=="Alfil"|| Tablero[a-1][b+1]->getTipo()=="Reina"){
          return true;
        }
        else if(getTipo()=="Negras" && a==getX() && b==getY() && Tablero[a-1][b+1]->getTipo()=="Peon"){
          return true;
        }
        break;
      } 
    }
  }
  
  a=getX();
  b=getY();
  while(a>0 && b>0){
    if(Tablero[a-1][b-1]==NULL){
      b--;
      a--;
    }
    else{
      if (Tablero[a-1][b-1]->color==getColor()){
        break;
      }
      else{
        if(Tablero[a-1][b-1]->getTipo()=="Alfil"|| Tablero[a-1][b-1]->getTipo()=="Reina"){
          return true;
        }
        else if(getTipo()=="Blancas" && a==getX() && b==getY() && Tablero[a-1][b-1]->getTipo()=="Peon"){
          return true;
        }
        break;
      } 
    }
  } 

  a=getX();
  b=getY();
  while(a<7 && b>0){
    if(Tablero[a+1][b-1]==NULL){
      b--;
      a++;
    }
    else{
      if (Tablero[a+1][b-1]->color==getColor()){
        break;
      }
      else{
        if(Tablero[a+1][b-1]->getTipo()=="Alfil"|| Tablero[a+1][b-1]->getTipo()=="Reina"){
          return true;
        }
        else if(getTipo()=="Blancas" && a==getX() && b==getY() && Tablero[a+1][b-1]->getTipo()=="Peon"){
          return true;
        }
        break;
      } 
    }
  }
  
//Validar Ataque Caballo
  
  return false;
}

bool Rey::validarEnroque(string tipo,Pieza* Tablero[][8]){
  //Enroque Corto Rey Blanco
  if(getColor()=="Blanco"){
  if(tipo=="Corto"){
    if(Tablero[0][7]->getContador()==0 && Tablero[0][7]->getEtiqueta()=="Torre"){
      if(Tablero[0][6] == NULL && Tablero[0][6] == NULL){
        if(!esta_En_Jaque(4, 0,Tablero) && !esta_En_Jaque(5, 0,Tablero) && !esta_En_Jaque(6, 0,Tablero)){
          return true;
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
    else{
      return false;
      
    }
  }
  //Enroque Largo Rey Blanco
  if(tipo=="Largo"){
    if(Tablero[0][0]->getContador()==0 && Tablero[0][0]->getEtiqueta()=="Torre"){
      if(Tablero[0][3] == NULL && Tablero[0][2] == NULL && Tablero[0][1] == NULL){
        if(!esta_En_Jaque(4, 0,Tablero) && !esta_En_Jaque(3, 0,Tablero) && !esta_En_Jaque(2, 0,Tablero)){
          return true;
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
    else{
      return false;
      
    }
  }
    }
else{
  //Enroque Corto Rey Negro
  if(tipo=="Corto"){
    if(Tablero[7][7]->getContador()==0 && Tablero[7][7]->getEtiqueta()=="Torre"){
      if(Tablero[7][6] == NULL && Tablero[7][5] == NULL){
        if(!esta_En_Jaque(4, 7,Tablero) && !esta_En_Jaque(5, 7,Tablero) && !esta_En_Jaque(6, 7,Tablero)){
          return true;
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
    else{
      return false;
      
    }
  }
  //Enroque Largo Rey Negro
  if(tipo=="Largo"){
    if(Tablero[7][0]->getContador()==0 && Tablero[7][0]->getEtiqueta()=="Torre"){
      if(Tablero[7][3] == NULL && Tablero[7][2] == NULL && Tablero[7][1] == NULL){
        if(!esta_En_Jaque(4,7,Tablero) && !esta_En_Jaque(3, 7,Tablero) && !esta_En_Jaque(2, 7,Tablero)){
          return true;
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
    else{
      return false;
      
    }
  }
  }
}