#include <iostream>
#include <string>
#include <Program.h>
#include <Basic_block.h>
#include <Function.h>


/*  Programme à appeler avec le nom d'un fichier assembleur en argument  */

/*   -Affichage du nombre de lignes du programme, de son contenu
   - Découpage en fonctions et affichage du nombre de fonction
    -Pour chaque fonction,  affichage de son contenu, détermination des blocs de base et affichage des BB déterminés, détermination des successeurs et prédécesseurs des BB, construction et restitution en fichier .dot du CFG de la fonction permettant de visualiser les liens 

*/

int main(int argc, char * argv[]){

   if (argc < 2) {
      cout << "erreur : pas de fichier assembleur en entree" << endl;
   }

 	  
   // récupère le nom du fichier dans le chemin entrée et sans extension
   std::string argv1(argv[1]);	
   size_t debut = argv1.find_last_of("/");
   if (debut == std::string::npos)
     debut = 0;
   
   size_t fin = argv1.find_last_of(".");
   if (fin == std::string::npos)
     fin = argv1.size();
   
   string name = argv1.substr(debut + 1, fin - (debut + 1));
   


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
      // decommenter pour voir le code de la fonction dans le terminal
      // cout << "FONCTION " << i << endl;
      //  functmp -> display();
      
      //determine les BB de la fonction
      functmp->comput_basic_block();
      
      // commenter ci-dessous pour ne pas voir le découpage en BB
      cout << "Affichage des blocs de base " << endl; 
      for(int j=0; j<functmp->nbr_BB(); j++){
	functmp->get_BB(j)->display();
      }
     
      // calcul les liens entre BB 
      functmp->comput_succ_pred_BB();

      // appelle la fonction test (voir Function.cpp)
      // affichage des BB et des predecesseurs/successeurs
     
       functmp->test();

     
      // crée un nouveau CFG pour la fonction
       // permet de le visualiser avec dot ou dotty, cf. plus bas
       Cfg *graph = new Cfg(functmp->get_BB(0),
			  functmp->nbr_BB());
	
		
      cout<<"------------Function "<< (i+1) <<"/"<<prog.nbr_func()<<" DISPLAY----------\n" <<endl;
    
      // pour afficher le CFG mais l'affichage ci-dessus donne les infos aussi
      // graph->display(nullptr);

      // construit un fichier .dot pour le cfg numero i dans ./tmp/
      string name_f_cfg = "./tmp/" + name + "_cfg_func_" + std::to_string(i) +".dot";
      graph->restitution(nullptr,name_f_cfg);
   }
  
   return 0;
}
