/** @file Ranking.hpp
    @brief Especificació de la classe Ranking
*/

#ifndef RANKING_HPP
#define RANKING_HPP


#include "utils.PRO2"
#include <list>




class Ranking{
private:
    struct parejahijo {
        int pareja;
        int hijo;
    };
    
    struct padre{
        int idpadre;
        list<parejahijo> m;
    };
    
    list<padre> l;
public:
    
    // CONSTRUCTORA correcto
    /** @brief Constructora por defecto.
   * \pre Cierto.
   * \post El resultado es un ranking vacio y de tamaño N.
   */
    
    
    Ranking(int N);

    
    // MODIFICADORAS de momento si
    /** @brief Añade una nueva reproduccion exitosa.
   * \pre Cierto.
   * \post Se añade al ranking los id del hijo y del compañero del organismo que ha
   * completado la reproduccion
   */
    
    void actualizar_ranking(int papa,int mama, int nino); 
    
    
    /** @brief Operacion de escritura.
   * \pre Cierto.
   * \post Se escribe el contenido del p.i por el canal estandard de salida
   */
    
    // LECTURA Y ESCRITURA
    void escribir_ranking();
    
    

    
};
#endif
