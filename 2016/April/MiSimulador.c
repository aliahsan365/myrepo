#include "CacheSim.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	unsigned int v;
	unsigned int tag;
	}linea; 


linea cache[128];

unsigned int nhits; //TOTAL DE ACIERTOS.
unsigned int nmises; // TOTAL DE MISES.



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	nhits = 0;
    nmises = 0;
    int i;
    for (i = 0; i < 128; ++i) {
		cache[i].v = 0;
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte; 
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
    
    //CALCULO DESGLOZADO.
	 byte = (address << 27);
	 byte = (byte >> 27);
	 
	 bloque_m = (address>>5);
	 
	 linea_mc = (bloque_m%128); 
	 
	 tag = (address>>12);
	
	
	

	//LECTURA
    if(LE == 0) {
		esc_mp = 0;
	    
	    //NO HAY NADA EN LA LINEA
	    if (cache[linea_mc ].v == 0) {
			miss = 1;
			++nmises;
			lec_mp = 1;
			mida_lec_mp = 32;
			replacement = 0;
			cache[linea_mc].tag = tag;
		    cache[linea_mc ].v = 1;
			}
		
		//HAY ALGO EN LA LINEA	
		else {
			//hit 
			if (cache[linea_mc].tag == tag) {
				miss = 0;
				lec_mp = 0;
				replacement = 0;
				++nhits;
				}
			//miss 
			else {
				miss = 1;
				++nmises;
				lec_mp = 1;
				mida_lec_mp = 32;
				replacement = 1;
			    tag_out = cache[linea_mc].tag;
			    cache[linea_mc].tag = tag;
			    }
			}
		}
    
    
	//ESCRITURA
	else {
		esc_mp = 1;
		mida_esc_mp = 1;
		//LA LINEA ESTA VACIA
		if (cache[linea_mc ].v == 0) {
			miss = 1;
			lec_mp = 0;
			mida_lec_mp = 0;
			replacement = 0;
			++nmises;
			}
			
		//LA LINEA ESTA LLENA.	
		else {
			//hit 
			if (cache[linea_mc].tag == tag) {
				miss = 0;
				lec_mp = 0;
				mida_lec_mp = 0;
				replacement = 0;
				++nhits;
				}
			//miss 
			else {
				miss = 1;
				lec_mp = 0;
				mida_lec_mp = 0;
				replacement = 0;
			    ++nmises;
			   }
			}
		}






	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf("numero de aciertos es: %d\n",nhits);
  printf("numero de fallos es: %d\n",nmises);
  
}