#include <iostream>
#include <string>
#include <Program.h>
#include <Basic_block.h>
#include <Function.h>


int main(int argc, char * argv[]){

	if (argc < 2) {
	  cout << "erreur : pas de fichier assembleur" << endl;
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

	// delimitation et construction des fonctions du fichier
	prog.comput_function();
	cout<<"nombre de fonctions : "<<prog.nbr_func()<<endl;

	list<int> frees;
	
	//traitement pour toutes les fonction 
	for(int i=0; i<  prog.nbr_func(); i++){

	  Function* functmp= prog.get_function(i);
		   
	  // delimitation des BB de la fonction
	  functmp->comput_basic_block();
	 
	  // determination des liens entre les BB
	  functmp->comput_succ_pred_BB();
	  
	  // production d'un fichier .dot pour le CFG de la fonction
	  
	  string name_f_cfg = "./tmp/" + name + "_cfg_func_" + std::to_string(i) +".dot";
	  Cfg *c = new Cfg(functmp->get_BB(0), functmp->nbr_BB());
	  c->restitution(nullptr, name_f_cfg);
	 
  
	   cout<<"========== Function "<<i<<"==========="<<endl;
	   cout<<"============================"<<endl;
	   
	   
	   // iteration sur tous les BB du CFG
	   for(int j = 0;  j< functmp->nbr_BB(); j++){
	     
	     Basic_block * bb= functmp -> get_BB(j);
	     cout<<"---------- BB "<<j<<" -----------"<<endl;
	     
	     //affichage du BB
	     bb->display();
	   
	     //calcul des liens de dépendances entre les instructions du BB
	     bb->comput_pred_succ_dep();
	     // montre les dépendances entre les instructions du BB
	     bb->show_succ_dep();

	     /**************** CALCUL NB CYCLES *********************/
	     //affichage du nb de cycle pour l'execution du BB
	     int nbcycles_base = bb->nb_cycles();
	     cout<<"---nb_cycles : "<< nbcycles_base <<" -----------"<<endl;
	     
	     // creation du DAG de dépendance associé au BB
	     Dfg* d = new Dfg(bb);
	     string name_f_dfg1 = "./tmp/" + name + "_func_" + std::to_string(i) + "_dfg_bb" + std::to_string(bb->get_index()) + ".dot";
	     d->restitute(nullptr, name_f_dfg1, true);
	     
	   }
	}
	
}
