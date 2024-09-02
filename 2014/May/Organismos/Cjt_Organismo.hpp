
/** @file Cjt_Organismo.hpp
    @brief Especificació de la classe Cjt_Organismo
*/

#ifndef CJT_ORGANISMO_HPP
#define CJT_ORGANISMO_HPP


#include "Organismo.hpp"
#include "Ranking.hpp"
#include <vector>



class Cjt_Organismo{
private:
   
   int norg; 
   int M; 
   int nvivos; 
   vector<Organismo> v;
   vector< vector<bool> > mat;
   
public:
   
   // CONSTRUCTORA
   /** @brief Creadora.
 
      Se ejecuta automaticamente al declarar un Cjt_Organismo.
      \pre Cierto.
      \post El resultado es un Cjt_Organismo de medida M vacio sin ningun Organisme.
     */  
   Cjt_Organismo(int M);

   
   // MODIFICADORAS
   /** @brief Hacer una ronda de reproducción.
 
      \pre Que norg < M y existen al menos dos organismo vivos.
      \post Retorna el numero de Organismos nuevos que han nacido en esa ronda. Si la reproducción
       da luegar a nuevos Organismos estos se añaden al paràmetro implícito. Si durante la ronda
       se llega a norg esta no se acaba i es finaliza el Experimento.
    */ 
   
   int ronda_de_reproduccion(Ranking &R);
   
   /** @brief Estirar un conjunto de Organismos.
 
      \pre El organismo esta en el p.i , esta vivo , y no ha sido recortado con anterioridad
      \post Han crecido los organismos con dicho identificador, se han fisionado la celulas no fisionada (las hojas)
      / la medida del organismo ha augmentando y el id maximo se ha actualizado
    */ 
   
   
   void aplica_estiron_conjunto(int x); 
   
     /** @brief Recortar un conjunto de Organismos.
 
      \pre El organismo esta en el p.i y esta vivo. 
      \post Han decrecido los oraganismos con dicho identificador que estan en el p.i, la medida del organismo ha drecido
      y el id maximo del cada organismo ha sido actualizado 
    */ 
   
   void aplica_recorte_conjunto(int x);
   
   
   // CONSULTORAS
   /** @brief Consultora del numero de Organismo.
   \pre Cierto.
      \post Retorna el numero de Organisme que contiene Cjt_Organismo
    */ 
   
   int consultar_tamano_actual() const; 
     /** @brief Consultora de si el organismo pertenece al p.i  (esta incluido)
   \pre Cierto.
      \post El resultado es true si esta , sino no esta , es falso
    */ 
   

   bool esta(int x) const;    
   /** @brief Consultora del numero de Organismos vivos.
 
      \pre Cierto.
      \post Retorna el numero de Organismos vivos que hay en el Cjt_Organismo.
      */    
   
   
   int n_vivos() const;
   
   
   
   // LECTURA Y ESCRITURA
 /** @brief Operació de escritura de los Organismo nacidos en la ultima
           ronda de reproducció.
   \pre Cierto.
      \post Se han  escrito por el canal standard de salida, los atributos de los
           Organismos  nacidos en la ultima ronda.
        */
   
   void escribir_organismos_nacidos_en_el_ultimo_emparejamiento(int hijos);
 /** @brief Operación de entrada de un conjunto de Organismos
      \pre Cierto.
      \post Al p .i. se han  anadido N organismes vivos.
        */

   void leer_cjt_organismo(int N);

   /** @brief Operació d'escriptura d'un conjunt d' <em>Organisme</em>
      \pre El organismo con dicho organismo ha de estar en el p.i
 
          \post Se han  escrito por el canal standard de salida los atributos
           de los Organismos con los identificadores de la seqûencia.
        */
   void escribir_organismo_del_conjunto(int x); 

   
};
#endif
