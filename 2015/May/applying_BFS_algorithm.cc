#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int i;
    int j;
};
// tresors 4

bool pos_valida (int m ,int n, int fi , int ci) {
    return fi >= 0 and ci >= 0 and fi <= (m-1) and ci <= (n-1); 
}

/*
void escriure_matriu(int m , int n ,vector<vector<int> > &mapa_distancias) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mapa_distancias[i][j] << " ";
            }
        cout << endl;
        }
    }
*/
int bfs_2(int m , int n, const vector< vector<char> > &mapa , int fi , int ci) {
    int dist_max = -1;
    int dist = 0;
    pos pi,paux; 
    pi.i = fi; 
    pi.j = ci;
    queue<pos> q;
    vector< vector<bool> > mapa_marcado(m, vector<bool> (n,false));
    vector< vector<int> > mapa_distancias(m,vector<int> (n,-1)); 
    mapa_marcado[fi][ci] = true;
    mapa_distancias[fi][ci] = 0;
    if (mapa[fi][ci] == 't') {dist_max = dist;}
    q.push(pi);
    while (not q.empty()) {
      pos aux = q.front(); q.pop();
      if (pos_valida(m,n,aux.i+1,aux.j)) {
        if (not mapa_marcado[aux.i+1][aux.j]) {
         if (mapa[aux.i+1][aux.j] == 't') {
          mapa_marcado[aux.i+1][aux.j] = true;
          mapa_distancias[aux.i+1][aux.j] = mapa_distancias[aux.i][aux.j] + 1;
          dist = mapa_distancias[aux.i+1][aux.j];
          paux.i = aux.i+1; paux.j = aux.j;
          q.push(paux);
          if (dist > dist_max) dist_max = dist;
      } 
      else {
          if (mapa[aux.i+1][aux.j] == 'X')  {
           mapa_marcado[aux.i+1][aux.j] = true;
       }
                        else   { // cuando es un punto
                            mapa_marcado[aux.i+1][aux.j] = true;
                            mapa_distancias[aux.i+1][aux.j] = mapa_distancias[aux.i][aux.j] + 1;
                            dist = mapa_distancias[aux.i+1][aux.j];
                            paux.i = aux.i+1; paux.j = aux.j;
                            q.push(paux);
                        }
                    }
                }
            }

            if (pos_valida(m,n,aux.i-1,aux.j)) {
                if (not mapa_marcado[aux.i-1][aux.j]) {
                 if (mapa[aux.i-1][aux.j] == 't') {
                  mapa_marcado[aux.i-1][aux.j] = true;
                  mapa_distancias[aux.i-1][aux.j] = mapa_distancias[aux.i][aux.j] + 1;
                  dist = mapa_distancias[aux.i-1][aux.j];
                  if (dist > dist_max) dist_max = dist;
                  paux.i = aux.i-1; paux.j = aux.j;
                  q.push(paux);
              } 
              else {
                  if (mapa[aux.i-1][aux.j] == 'X')  {
                   mapa_marcado[aux.i-1][aux.j] = true;
               }
                        else   { // cuando es un punto
                            mapa_marcado[aux.i-1][aux.j] = true;
                            mapa_distancias[aux.i-1][aux.j] = mapa_distancias[aux.i][aux.j] + 1;
                            dist = mapa_distancias[aux.i-1][aux.j];

                            paux.i = aux.i-1; paux.j = aux.j;
                            q.push(paux);
                        }
                    }
                }
            }
            if (pos_valida(m,n,aux.i,aux.j+1)) {
                if (not mapa_marcado[aux.i][aux.j+1]) {
                 if (mapa[aux.i][aux.j+1] == 't') {

                     mapa_marcado[aux.i][aux.j+1] = true;
                     mapa_distancias[aux.i][aux.j+1] = mapa_distancias[aux.i][aux.j] + 1;
                     dist = mapa_distancias[aux.i][aux.j+1];
                     if (dist > dist_max) dist_max = dist;
                     paux.i = aux.i; paux.j = aux.j+1;
                     q.push(paux);

                 } 
                 else {
                  if (mapa[aux.i][aux.j+1] == 'X')  {
                   mapa_marcado[aux.i][aux.j+1] = true;
               }
                        else   { // cuando es un punto
                            mapa_marcado[aux.i][aux.j+1] = true;
                            mapa_distancias[aux.i][aux.j+1] = mapa_distancias[aux.i][aux.j] + 1;
                            dist = mapa_distancias[aux.i][aux.j+1];
                            paux.i = aux.i; paux.j = aux.j+1;
                            q.push(paux);
                        }
                    }
                }
            }
            if (pos_valida(m,n,aux.i,aux.j-1)) {
                if (not mapa_marcado[aux.i][aux.j-1]) {
                 if (mapa[aux.i][aux.j-1] == 't') {
                  mapa_marcado[aux.i][aux.j-1] = true;
                  mapa_distancias[aux.i][aux.j-1] = mapa_distancias[aux.i][aux.j] + 1;
                  dist = mapa_distancias[aux.i][aux.j-1];
                  if (dist > dist_max) dist_max = dist;
                  paux.i = aux.i; paux.j = aux.j-1;
                  q.push(paux);
              } 
              else {
                  if (mapa[aux.i][aux.j-1] == 'X')  {
                   mapa_marcado[aux.i][aux.j-1] = true;
               }
                        else   { // cuando es un punto
                            mapa_marcado[aux.i][aux.j-1] = true;
                            mapa_distancias[aux.i][aux.j-1] = mapa_distancias[aux.i][aux.j] + 1;
                            dist = mapa_distancias[aux.i][aux.j-1];
                            paux.i = aux.i; paux.j = aux.j-1;
                            q.push(paux);
                        }
                    }
                }
            }
        }
        //escriure_matriu(m,n,mapa_distancias);
        return dist_max;
    }





    int main() {
     int m,n;
     cin >> m >> n;
     vector< vector<char> > mapa(m,vector<char>(n));
     for(int i = 0; i < m; ++i) {
      for(int  j = 0; j <n ; ++j) {
       cin >> mapa[i][j];
   }
}
int fi,ci;
cin >> fi >> ci;
int dist_max = bfs_2(m,n,mapa,fi-1,ci-1);
if (dist_max != -1 )cout <<  "distancia maxima: " << dist_max << endl;
else cout << "no es pot arribar a cap tresor" << endl;
}

