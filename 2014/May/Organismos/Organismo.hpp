
/** @file Organismo.hpp
    @brief Especificació de la classe Organismo
*/

#ifndef ORGANISMO_HPP
#define ORGANISMO_HPP




#include "Arbre.hpp"
#include "utils.PRO2"


class Organismo {
private:
  struct Celula{
    int id;
    bool activa;
  };
  Arbre<Celula> a;
  bool cortada;
  int mida;
  int id_maxim;
  static void escribir_morfologia(Arbre<Celula> &a);
  static void leer_morfologia(Arbre<Celula> &a,int marca,int &t, int &id_max);
  static void recorte(Arbre<Celula> &a,int &m, int &id_max); 
  static void estiron(Arbre<Celula> &a, int &m, int &id_max);
  static void compatibles(Arbre<Celula>& a, Arbre<Celula> &b, int &m);
  static void hacer_hijo(Arbre<Celula>& a, Arbre<Celula> &b, Arbre<Celula> &c,int &id_max, int &m, int &pid);
  static void aux_a(Arbre<Celula> &a,Arbre<Celula> &c, bool &act, int &m, int &id_max);
  static void aux_b(Arbre<Celula> &b,Arbre<Celula> &c, bool &act, int &id_max, int &m, int &pid);
public:

  
  // CONSTRUCTORAS
  /** @brief Creadora por defecto.
   * Se ejecuta automaticamente al declarar un organismo
   * \pre Cierto.
   * \post El resultado es un organismo "vacio" con id_maximo a 0 y no recortado
   */
  
  Organismo();

  // CONSULTORAS

    /** @brief Consultora de si un organismo ha estato recortado 
    \pre Cierto. 
    \post El resultato es cierto si el p.i. ha estato recortado anteriormente y falso en caso contrario. 
    */
  bool consultar_cortada() const; 
  
  /** @brief Consultora de la mida de un Organismo. 
  \pre Cierto. 
  \post El resultato es el numero de celules del p.i. 
  */ 
  
  int consultar_mida() const;
  
  
  
  
    //MDDIFICADORAS
  

    /** @brief Reproducción de dos organismos.
          \pre P.i. y Org son vivos y no se han emparejado anteriormente.
          \post El resultato és el hijo nacido de la reproducción del parametro
                implícito y Org. Si no ha estado possible la reproducción el resultato
                es un Organisme vacio.
        */



  Organismo reproduccion(Organismo &Org);

    /** @brief Estira/Crece un Organismo.
      \pre P.i. esta vivo i no ha estato recortado.
      \post El p.i. queda crecido/estirado. Su medida  queda augmentada.
    */
  
  void aplica_estiron_organismo(); 
  
  /** @brief Recorta un Organismo.
      \pre El parametro ímplicito esta vivo.
      \post El parametro implícito queda recortado. El paràmetre implícito ya no se puede estirar nunca más.
    */
  
  void aplica_recorte_organismo(); 
  


  
  
  // LECTURA ESCRITURA

     /** @brief Operación de lectura.
 
      \pre En el canal standard de entrada se encuentran los valores del los atributos de un Organismo
      \post El p.i. queda inicializado con los  valores introducidos.
    */
  void leer_organismo();
   /** @brief Operación de escritura.
 
      \pre Cierto.
      \post Se han escrito los atributos del p.i. en el canal
      standard de salida.
    */
  
  void escribir_organismo();

  
  
};
#endif
