#include <iostream>
#include <sstream>
#include <Program.h>
#include <Basic_block.h>
#include <Function.h>


/*  Programme à appeler avec le nom d'un fichier assembleur en argument  */

/*  -Affichage du nombre de lignes du programme, de son contenu
   - Découpage en fonctions et affichage du nombre de fonction
    -Pour chaque fonction,  affichage de son contenu, détermination des blocs de base et affichage des BB déterminés 

*/

int main(int argc, char * argv[]){

   if (argc < 2) {
      cout << "erreur : pas de fichier assembleur en entree" << endl;
   }

 
   Program prog(argv[1]);
  
   cout<<"Le programme a "<<prog.size()<<" lignes\n"<<endl;
  
   cout<<"\n Calcul des fonctions des block de base et restitution\n"<<endl;
   prog.comput_function();
   
   cout<<"nombre de fonctions : "<<prog.nbr_func()<<endl;

   
   for (int i=0; i<prog.nbr_func(); i++){
      
     // recupération de la ieme fonction du programme
       Function* functmp = prog.get_function(i);

      if(functmp == nullptr){
	cout<<"fonction" << i << " est nullptr"<<endl;
	break;
      }
      // commenter pour ne pas voir le code de la fonction dans le terminal
      
      cout << "FONCTION " << i << endl;
      functmp -> display();
      
      //determine les BB de la fonction
      functmp->comput_basic_block();
      
      // commenter ci-dessous pour ne pas voir le découpage en BB
      cout << "Affichage des blocs de base " << endl; 
      for(int j=0; j<functmp->nbr_BB(); j++){
	 functmp->get_BB(j)->display();
      }
    
   }
  
   return 0;
}
