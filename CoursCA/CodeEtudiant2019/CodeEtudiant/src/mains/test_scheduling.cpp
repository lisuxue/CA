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
	  // association des labels avec le bloc qui le suit
	  functmp->comput_label();
	  // determination des liens entre les BB
	  functmp->comput_succ_pred_BB();
	  
	  // production d'un fichier .dot pour le CFG de la fonction
	  
	  string name_f_cfg = "./tmp/" + name + "_cfg_func_" + std::to_string(i) +".dot";
	  Cfg *c = new Cfg(functmp->get_BB(0), functmp->nbr_BB());
	  c->restitution(nullptr, name_f_cfg);
	 
  
	   cout<<"========== Function "<<i<<"==========="<<endl;
	   cout<<"============================"<<endl;
	   
	   // calcul des registres vivants en entrée et sortie des BB
	   functmp ->compute_live_var();
	   
	   // iteration sur tous les BB du CFG
	   for(int j = 0;  j< functmp->nbr_BB(); j++){
	     
	     Basic_block * bb= functmp -> get_BB(j);
	     cout<<"---------- BB "<<j<<" -----------"<<endl;
	     
	     //affichage du BB
	     bb->display();
	     // création des liens entre les instructions du BB 
	     bb->link_instructions();

	     //calcul des liens de dépendances entre les instructions du BB
	     bb->comput_pred_succ_dep();

	     /**************** CALCUL NB CYCLES *********************/
	     //affichage du nb de cycle pour l'execution du BB
	     int nbcycles_base = bb->nb_cycles();
	     cout<<"---nb_cycles : "<< nbcycles_base <<" -----------"<<endl;
	     
	     if (nbcycles_base == bb->get_nb_inst() && 
		 (!bb->get_branch() || (bb->get_branch() && !(bb->get_instruction_at_index(bb->get_nb_inst()-1)->is_nop())))){
	       cout << "nb de cycles == nb d'instructions et pas de delayed slot/nop dans le delayed slot" << endl;
	       continue;
	     }
	     
	     // creation du DAG de dépendance associé au BB
	     Dfg* d = new Dfg(bb);
	     string name_f_dfg1 = "./tmp/" + name + "_func_" + std::to_string(i) + "_dfg_bb" + std::to_string(bb->get_index()) + ".dot";
	     d->restitute(nullptr, name_f_dfg1, true);
	     
	     
	     /*********** CALCUL CHEMIN CRITIQUE  ***********/ 
	     
	     cout<<"comput critical path"<<endl;
	     d->comput_critical_path();
	     cout<<"critical path "<<d->get_critical_path()<<endl;
	     
	     /************** REORDONNANCEMENT *****************/ 
	     
	     // calcul d'un nouvel ordonnancement	     
	     d->scheduling(false);
	       
	     cout<<"----  new scheduling: -----"<<endl;
	     d->display_sheduled_instr();
	     
	     // Application du  nouvel ordonnancement (changement réel dans le BB)
	     d->apply_scheduling();
	     cout<<"---- BB with new scheduling: -----"<<endl;
	     bb->display();
	     
	     
	     // recalcul du nb de cycle après scheduling 
	     int nbcycles_sched = bb->nb_cycles();
	     cout<<"----------nb_cycles apres scheduling : "<< nbcycles_sched<<"  -----------"<<endl;
	    	      
	     cout << " gain sched : " << nbcycles_base - nbcycles_sched ;
	    
	   }
	}
	return 0;
}
