/** @file Cjt_Organismo.cpp
    @brief Código de la clase Cjt_Organismo 
*/


#include "Organismo.hpp"


// ESTO YA METERLO EN EL CODIGO OFICIAL , PK FUNKA BIEN

Organismo::Organismo() {
    cortada = false;
    id_maxim = 0;
    mida = 0;
}


bool Organismo::consultar_cortada() const {
    return cortada;
}



int Organismo::consultar_mida() const {
    return mida;
}





// MODIFICADORAS
// ESCRIBIR LA FUNCION DE  LA REPRODUCCION
void Organismo::aux_b(Arbre<Celula> &b,Arbre<Celula> &c, bool &act, int &id_max, int &m, int &pid) {
    Arbre<Celula> b1,b2,c1,c2;
    Celula raiz = b.arrel();
    b.fills(b1,b2);
    if (b1.es_buit() and b2.es_buit()) {
        if (raiz.activa) {
            act = true; 
            ++m;
            ++pid;
            raiz.id = pid;
            if (raiz.id > id_max) id_max = raiz.id;
            c.plantar(raiz,b1,b2);
        }
    }
    else {
        ++pid;
        raiz.id = pid;
        bool act1 = false;
        bool act2 = false;
        if (not b1.es_buit()) aux_b(b1,c1,act1,id_max,m,pid);
        if (not b2.es_buit()) aux_b(b2,c2,act2,id_max,m,pid);
        Arbre<Celula> d1,d2;
        if (not act1 and not act2) {
            if (raiz.activa) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true; 
                ++m;
                c.plantar(raiz,d1,d2); 
            }
            else --pid;
        }
        else {
            
            if (act1 and not act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true; 
                ++m; 
                c.plantar(raiz,c1,d1);
            }
            else if (not act1 and act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true; 
                ++m;
                c.plantar(raiz,d2,c2); 
            } 
            else if (act1 and act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true; 
                ++m;
                c.plantar(raiz,c1,c2);
            }
        }
    }
}

void Organismo::aux_a(Arbre<Celula> &a,Arbre<Celula> &c, bool &act, int &m, int &id_max) {
    Arbre<Celula> a1,a2,c1,c2;
    Celula raiz = a.arrel();
    a.fills(a1,a2);
    if (a1.es_buit() and a2.es_buit()) {
        if (raiz.activa) {
            if (raiz.id > id_max) id_max = raiz.id;
            act = true; 
            ++m;
            c.plantar(raiz,a1,a2);
        }
        else act = false;
    }
    else {
        bool act1 = false;
        bool act2 = false;
        if (not a1.es_buit()) aux_a(a1,c1,act1,m,id_max);
        if (not a2.es_buit()) aux_a(a2,c2,act2,m,id_max);
        Arbre<Celula> d1,d2;
        if (not act1 and not act2) {
            if (raiz.activa) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true;
                ++m;
                c.plantar(raiz,d1,d2); 
            }
        }
        else {
            if (act1 and not act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true; 
                ++m;
                c.plantar(raiz,c1,d1); 
            }
            else if (not act1 and act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true;
                ++m;
                c.plantar(raiz,d2,c2); 
            } 
            else if (act1 and act2) {
                if (raiz.id > id_max) id_max = raiz.id;
                act = true;
                ++m;
                c.plantar(raiz,c1,c2); 
            }
        }
    }
}

void Organismo::hacer_hijo(Arbre<Celula>& a, Arbre<Celula> &b, Arbre<Celula> &c,int &id_max, int &m, int &pid) {
    Arbre<Celula> c1,c2;
    bool act = false;
    if (a.es_buit() and b.es_buit());   
    else if (not a.es_buit() and not b.es_buit()){
        ++m;
        Celula raiz = a.arrel(); 
        Arbre<Celula> a1,a2;
        a.fills(a1,a2);
        if (raiz.id > id_max) id_max = raiz.id;
        Celula y = b.arrel();
        raiz.activa = (raiz.activa or y.activa);
        Arbre<Celula> b1,b2;
        b.fills(b1,b2);
        hacer_hijo(a1,b1,c1,id_max,m,pid);
        hacer_hijo(a2,b2,c2,id_max,m,pid);
        c.plantar(raiz,c1,c2);
    }
    else if (not a.es_buit() and b.es_buit()) {
        aux_a(a,c,act,m,id_max); 
    }
    else if (a.es_buit() and not b.es_buit()) {
        aux_b(b,c,act,id_max,m,pid);
    }
}



void Organismo::compatibles(Arbre<Celula>& a, Arbre<Celula> &b, int &m) {
    if (not a.es_buit() and not b.es_buit()){
        ++m;
        Arbre<Celula> a1,a2;
        a.fills(a1,a2);
        Arbre<Celula> b1,b2;
        b.fills(b1,b2);
        compatibles(a1,b1,m);
        compatibles(a2,b2,m);
    }         
}


Organismo Organismo::reproduccion(Organismo &O) {
    Organismo fill;
    Arbre<Celula> ca,cb;
    ca = a;
    cb = O.a;
    compatibles(ca,cb,fill.mida);
    bool com = int(((mida+O.mida)/4)) <= fill.mida;
    fill.mida = 0;
    if (com) {
        ca = a;
        cb = O.a;
        int pid = id_maxim; // id maxim del padre
        fill.id_maxim = 0;
        hacer_hijo(ca,cb,fill.a,fill.id_maxim,fill.mida,pid);
    }
    return fill;
}


void Organismo::estiron(Arbre<Celula> &a,int &m, int &id_max) {
    Celula cel = a.arrel();
    Arbre<Celula> a1,a2;
    a.fills(a1,a2);
    if (a1.es_buit() and a2.es_buit()) {
        m = m + 2;
        Arbre<Celula> b1,b2;
        Celula cel1,cel2;
        cel1.activa = cel.activa;
        cel2.activa = cel.activa;
        id_max = id_max + 1;
        cel1.id = id_max; 
        id_max = id_max + 1;
        cel2.id = id_max;
        b1.plantar(cel1,a1,a2);
        b2.plantar(cel2,a1,a2);
        a.plantar(cel,b1,b2);
    }
    else {
        if (not a1.es_buit()) estiron(a1,m,id_max);
        if (not a2.es_buit()) estiron(a2,m,id_max);
        a.plantar(cel,a1,a2);
    }
}




void Organismo::aplica_estiron_organismo() {
    estiron(a,mida,id_maxim); 
}



void Organismo::recorte(Arbre<Celula> &a,int &m, int &id_max) {
    Celula cel = a.arrel();
    Arbre<Celula> a1;
    Arbre<Celula> a2;
    a.fills(a1,a2);
    if (a1.es_buit() and a2.es_buit()) m = m - 1;
    else {
        if (not a1.es_buit()) {
            if (id_max < cel.id) id_max = cel.id;
            recorte(a1,m,id_max);
        }
        
        if (not a2.es_buit()) {
            if (id_max < cel.id) id_max = cel.id;
            recorte(a2,m,id_max);
        }
        a.plantar(cel,a1,a2);
    }
}



void Organismo::aplica_recorte_organismo() {
    id_maxim = 0;
    recorte(a,mida,id_maxim);
    cortada = true;
}


void Organismo::escribir_morfologia(Arbre<Celula> &a) {
    if (not a.es_buit()) {
        Arbre<Celula> a1;
        Arbre<Celula> a2;
        Celula x = a.arrel();
        a.fills(a1,a2);
        escribir_morfologia(a1);
        cout << x.id << " ";
        if (x.activa == true) cout << "1 ";
        else cout << "-1 ";
        escribir_morfologia(a2);
        a.plantar(x,a1,a2);
    }
    else cout << "0 ";
}

void Organismo::escribir_organismo() {
    escribir_morfologia(a);
}


void Organismo::leer_morfologia(Arbre<Celula> &a,int marca, int &m, int &id_max) { 
    Arbre<Celula> a1;
    Arbre<Celula> a2;
    Celula x;
    x.id = readint();
    if (x.id > id_max) id_max = x.id;
    if (x.id != marca) { 
        m = m + 1;
        x.activa = readbool();
        leer_morfologia(a1, marca,m,id_max);
        leer_morfologia(a2, marca,m,id_max);
        a.plantar(x,a1,a2);
    }
}

void Organismo::leer_organismo() { 
    leer_morfologia(a,0,mida,id_maxim);
}







