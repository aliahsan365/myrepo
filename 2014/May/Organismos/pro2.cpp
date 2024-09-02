#include "Cjt_Organismo.hpp"
#include "Ranking.hpp"

int main() {
	int N = readint();  
	int M = readint();  
	Cjt_Organismo cjt(M);
    cjt.leer_cjt_organismo(N); 
	Ranking R(N);
	int hijos;
	int opc = readint();
	while (opc != -6 and cjt.n_vivos() != 0 and cjt.consultar_tamano_actual() < M) {
		//ESTIRAR/CRECER
		if (opc == -1) {
			int L = readint();
			for (int i = 0; i < L; ++i) {
				int x = readint();
				cjt.aplica_estiron_conjunto(x);
				}
			}
		//RECORTAR
		else if (opc == -2) {
			int L = readint();
			for (int i = 0; i < L; ++i) {
				int x = readint();
				cjt.aplica_recorte_conjunto(x);
				}
			}
		//RONDA DE REPRODUCCION
		else if (opc == -3) {
			cout << "RONDA DE EMPAREJAMIENTOS" << endl;
			hijos = cjt.ronda_de_reproduccion(R);
			cout << "Nuevos organismos : " << hijos << endl << endl;
			}
		// ESCRIBIR RANKING
		else if (opc == -4) {
			cout << "RANKING" << endl;
			R.escribir_ranking();
			}
		// ESCRIBIR ORGANISMOS
		else if (opc == -5) {
			cout << "ORGANISMOS" << endl;
			int L = readint();
			for (int i = 0; i < L; ++i) {
				int x = readint();
				cjt.escribir_organismo_del_conjunto(x);
				}
			cout << endl;
			}
		opc = readint();
		}
	cout << "FIN" << endl << endl;
	cout << "Organismos en total : " << cjt.consultar_tamano_actual() << endl;
	cout << "Organismos vivos : " << cjt.n_vivos() << endl << endl;
	if (cjt.consultar_tamano_actual() == M) {
        cout << "ORGANISMOS" << endl;
		cjt.escribir_organismos_nacidos_en_el_ultimo_emparejamiento(hijos);
        cout << endl;
        cout << "RANKING" << endl;
        R.escribir_ranking();
       }
    }
