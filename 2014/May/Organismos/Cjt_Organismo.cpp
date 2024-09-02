/** @file Cjt_Organismo.cpp
    @brief Código de la clase Cjt_Organismo 
*/


#include "Cjt_Organismo.hpp"



    // CONSTRUCTORAS


Cjt_Organismo::Cjt_Organismo(int M) 
{
    this -> M = M; 
    norg = 0; 
    nvivos = 0; 
    v = vector<Organismo> (M); 
    mat = vector< vector<bool> > (M, vector<bool> (M)); 
}
    // cambiar el nombre de la funcion esta


    // MODIFICADORAS
int Cjt_Organismo::ronda_de_reproduccion(Ranking &R) {
    int tm = norg;
    int n_hijos = 0;
    vector<bool> emparejados(tm,false);
    int i = 0;
    bool fin = false;
    while (i < tm and not fin) {
        if (v[i].consultar_mida()!=0 and not emparejados[i]) {
            int j = i + 1;
            bool intento = false;
            while (j < tm and not intento) {
                if (not emparejados[j]){
                    if (not mat[i][j] and v[j].consultar_mida() != 0) {
                        intento = true;
                        mat[i][j] = true;;
                        emparejados[i] = true;
                        emparejados[j] = true;
                        Organismo hijo = v[i].reproduccion(v[j]);
                        if (hijo.consultar_mida() != 0) {
                            ++nvivos;
                            ++n_hijos;
                            ++norg;
                            if (norg == M) fin = true;
                            v[norg-1] = hijo;
                            R.actualizar_ranking(i+1,j+1,norg);
                        }
                    }
                    else if (mat[i][j] or v[j].consultar_mida() == 0) ++j;
                }
                else ++j;
            }
        }
        ++i;
    }
    return n_hijos;
}

void Cjt_Organismo::aplica_estiron_conjunto(int x) {
    if (esta(x) and (v[x-1].consultar_mida() != 0) and not v[x-1].consultar_cortada()) {
        v[x-1].aplica_estiron_organismo();
    }
}


void Cjt_Organismo::aplica_recorte_conjunto(int x) {
    if (esta(x)) {
        if ((v[x-1].consultar_mida() != 0)) {
            v[x-1].aplica_recorte_organismo();
            if (v[x-1].consultar_mida() == 0) --nvivos;
        }
    }
}

    // CONSULTORAS


int Cjt_Organismo::consultar_tamano_actual() const {
    return norg;
}

bool Cjt_Organismo::esta(int x) const {
    return (x-1) < consultar_tamano_actual();
}





int Cjt_Organismo::n_vivos() const {
    return nvivos;
}

    // LECTURA Y ESCRITURA


void Cjt_Organismo::escribir_organismos_nacidos_en_el_ultimo_emparejamiento(int hijos){
    for (int i = norg-hijos; i < norg ; ++i) {
        cout << i+1 << " : ";
        v[i].escribir_organismo();
        cout << endl;
    }
}




void Cjt_Organismo::leer_cjt_organismo(int N) {
    for (int i = 0; i < N; ++i) {
        v[i].leer_organismo();
        ++norg;
        ++nvivos;
    }
}



void Cjt_Organismo::escribir_organismo_del_conjunto(int x) {
    if (esta(x)) {
        cout << x  << " : ";
        v[x-1].escribir_organismo();
        cout << endl;
    }
}

