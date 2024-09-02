/** @file Ranking.cpp
    @brief Código de la clase Ranking 
*/

// ultima version

#include "Ranking.hpp"



Ranking::Ranking(int N) { 
    int i = 1; 
    list<padre>::iterator it = l.end();
    while (i <= N) { 
        padre p; 
        p.idpadre = i;
        l.insert(it,p); 
        ++i; 
    } 
}

void Ranking::actualizar_ranking(int papa,int mama, int nino) {
    list<padre>::iterator it = l.end();
    padre p;
    p.idpadre = nino;
    l.insert(it,p);
    it = l.begin();
    padre modificado;
    bool acaba = false;
    while (it != l.end() and not acaba){
        padre pa = *it;
        if (pa.idpadre == papa) {
            list<parejahijo>::iterator it2 = pa.m.end();
            parejahijo ph;
            ph.pareja = mama;
            ph.hijo = nino;
            pa.m.insert(it2,ph);
            modificado = pa;
            acaba = true;
        }
        else ++it;
    }
    acaba = false;
    it = l.erase(it);
    it = l.begin();
    while (it != l.end() and not acaba) {
        padre pa2 = *it;
        if (pa2.m.size() < modificado.m.size()) {
            l.insert(it,modificado);
            acaba = true;
        }
        else if (pa2.m.size() == modificado.m.size()) {
            if (pa2.idpadre > modificado.idpadre) {
                l.insert(it,modificado);
                acaba = true;
            }
        }   
        ++it;
    }
    int auxpapa = mama;
    int auxmama = papa;
    it = l.begin();
    acaba = false;
    while (it != l.end() and not acaba){
        padre pa = *it;
        if (pa.idpadre == auxpapa) {
            list<parejahijo>::iterator it2 = pa.m.end();
            parejahijo ph;
            ph.pareja = auxmama;
            ph.hijo = nino;
            pa.m.insert(it2,ph);
            modificado = pa;
            acaba = true;
        }
        else ++it;
    }
    acaba = false;
    it = l.erase(it); 
    it = l.begin();
    while (it != l.end() and not acaba) {
        padre pa2 = *it;
        if (pa2.m.size() < modificado.m.size()) {
            l.insert(it,modificado);
            acaba = true;
        }
        else if (pa2.m.size() == modificado.m.size()) {
            if (pa2.idpadre > modificado.idpadre) {
                l.insert(it,modificado);
                acaba = true;
            }
        }   
        ++it;
    }
}




void Ranking::escribir_ranking() {
    list<padre>::const_iterator it = l.begin();
    while (it != l.end()) {
        padre papa = *it; 
        cout << papa.idpadre << " : ";
        list<parejahijo>::const_iterator it2 = papa.m.begin();
        while (it2 != papa.m.end()) {
           parejahijo pj = *it2;
           cout << pj.pareja << " " << pj.hijo;
           cout << " ";
           ++it2;
       }
       ++it;
       cout << endl;
   }
   cout << endl;
}


