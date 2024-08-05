#include "Player.hh"
using namespace std;


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AliOli_v3


struct PLAYER_NAME : public Player {


  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  
  /**
   * Attributes for your player can be defined here.
   */
  

  /**
   * Play method.
   *
   * This method will be invoked once per each round.
   * You have to read the board here to place your actions
   * for this round.
   *
   */

  virtual void play () {
   Pos p = goku(me()).pos; 
   GType g = goku(me()).type; 
   pair<Dir,int> dir_int; 
   int forza = goku(me()).strength;
   if (forza < max_strength()*0.2) {
     dir_int = calcular_ruta(p,Bean);
     move(dir_int.first);
   }
   else if (g == Normal) {
     pair<Dir,int> dir_int_dos;
     dir_int_dos = calcular_ruta(p,Ball);
     dir_int = calcular_ruta(p,Kinton);
     if (dir_int_dos.second < dir_int.second) {
       move(dir_int_dos.first);
     }
     else {
       move(dir_int.first);
     } 
   }
   else if (g == On_Kinton) {
     pair<Dir,int> dir_int_dos;
     dir_int_dos = calcular_ruta(p,Bean);
     dir_int = calcular_ruta(p,Ball);
     if (dir_int_dos.second < dir_int.second) {
       move(dir_int_dos.first);
     }
     else {
       move(dir_int.first);
     }
   }
   else if (g == With_Ball) {
     pair<Dir,int> dir_int_dos;
     dir_int_dos = calcular_ruta(p,Kinton); 
     dir_int = calcular_ruta(p,Capsule);
     if (dir_int_dos.second < dir_int.second) {
       move(dir_int_dos.first);
     }
     else {
       move(dir_int.first);
     }
   }
   else if (g == On_Kinton_With_Ball){
     dir_int = calcular_ruta(p, Capsule);
     move(dir_int.first);
   }
 }

 
 
 pair<Dir,int>  calcular_ruta(Pos p, CType c) {
  pair<Dir,int> dir_int;
  Dir d;
  Pos D;
  Dir direcciones[4] = {Left, Right, Bottom, Top}; 
  queue<Pos> q;
  vector< vector<bool> > mapa_marcado(rows(),vector<bool>(cols(),false));
  vector< vector<int> >  mapa_distancias(rows(),vector<int>(cols(),-2));
  mapa_distancias[p.i][p.j] = 0;
  mapa_marcado[p.i][p.j] = true;
  q.push(p); 
  bool trobat = false;
  while (not q.empty() and not trobat) {
   Pos auxp = q.front(); q.pop();
   for (int k = 0; k < 4 and not trobat; ++k) { 
     if (pos_ok(auxp,direcciones[k])) {  
       Pos aux2 = dest(auxp,direcciones[k]); 
       if (can_move(auxp,direcciones[k]) and not mapa_marcado[aux2.i][aux2.j]) {
         Cell c1 = cell(aux2);
         trobat = (c1.type == c);
         mapa_marcado[aux2.i][aux2.j] = true;
         q.push(aux2); 
         mapa_distancias[aux2.i][aux2.j] = mapa_distancias[auxp.i][auxp.j]+1;; 
         if (trobat) {
           D = aux2;
           dir_int.second = mapa_distancias[D.i][D.j];
         }
       }
     }
   }
 }
 if (trobat) {
   dir_int.first = busca_dirreccion(p,D,mapa_distancias);
   return dir_int;
 }
 else {
   dir_int.first = None;
   dir_int.second = -10;
   return dir_int;
   
 }
}


Dir busca_dirreccion(Pos G, Pos D, vector< vector<int> > &mat) {
  if (G == D) return None;
  Dir direcciones[4] = {Left, Right, Bottom, Top}; 
  Dir dp;
  Pos aux = D;
  bool trobat = false;
  while (not trobat) {
   int min = 5000;
   Pos aux3;
   for (int k = 0; k < 4 and not trobat; ++k) {
     Pos aux2 = dest(aux,direcciones[k]);
     if (pos_ok(aux2)) {
       if (mat[aux2.i][aux2.j] != -2) {
         if (mat[aux2.i][aux2.j] < min)  {
           min = mat[aux2.i][aux2.j];
           aux3 = aux2; 
         }
       }
     }
   } 
   if (min == 0) {
    trobat = true;
    if (aux == dest(aux3,Left)) {
      dp = Left;
    }
    else if (aux == dest(aux3,Right)) {
      dp = Right;
    }   
    else if (aux == dest(aux3,Top)) {
      dp = Top;
    }
    else {
      dp = Bottom;
    }
  }
  else {
    aux = aux3;
  }
}
return dp;
}


bool can_move (Pos p, Dir d) {
  CType t = cell(dest(p, d)).type;
  if (t == Rock) return false;
    //int id = cell(dest(p, d)).id;
    //if (id != -1 and goku(me()).strength < goku(id).strength) return false;
  return true;
}





};



/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);

