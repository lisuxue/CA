#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>
#include <Cfg.h>

/* 
parsing d'un fichier assembleur 
affichage du programme
calcul des fonction, affichage du nombre de fonction
*/

int main(int argc, char ** argv){
  if (argc < 2){
    cerr << "pas de fichier assembleur en paramètre, pb !" << endl;
    return -1;
  }

  Program p2(argv[1]) ;

  p2.display() ;

  p2.comput_function();
  cout << "dans le fichier " << argv[1]  << " nb functions : " << p2.nbr_func() << endl;

  for (int i = 0; i < p2.nbr_func() ; i++){
    cout << " ----------------- FONCTION "<< i<< " --------------------" << endl;
     p2.get_function(i)->display();
  }
    
  return 0;
}
