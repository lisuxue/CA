#include <Cfg.h>

Cfg::Cfg(Basic_block * BB, int size){
	_head = BB;
	_length = size;
	_read = new int[size];
	
}

Cfg::~Cfg(){}

Basic_block *Cfg::get_head(){
	return _head;
}



//Donner Null en parametre de la fonction lors de son appel
void Cfg::display(Basic_block *BB){

   //Si on entre dans la fonction pour la premi�re fois le bloc de base  sera la tete du cfg  
   if(BB == nullptr)	{
      BB = _head;
      for(int i=0; i<_length; i++)
	 _read[i]=0;		
   }
   
   //Si le bloc b'as pas encore �t� lu (pour eviter les boucle infini)
   if(!_read[BB->get_index()]){
      //On le marque comme lu
      _read[BB->get_index()]=1;
      cout<<"BB"<<BB->get_index()<<endl;
      int nb_pred=BB->get_nb_pred();
      cout <<"nb_pred "<<nb_pred<<endl;		
      if(nb_pred){
	 for(int i=0; i<nb_pred; i++){
	    cout<<" -> BB "<<BB->get_predecessor(i)->get_index()<<endl;
	 }		   
      }
      cout<<"nbr succ "<<BB->get_nb_succ()<<endl;
      //On affiche ses successeurs s'il en a
      if(BB->get_nb_succ()){
	 cout<<" -> BB"<<BB->get_successor(0)->get_index()<<endl;		
	 if(BB->get_nb_succ()==2){
	    cout<<" -> BB"<<BB->get_successor(1)->get_index()<<endl;  		
	 }
	 cout<<endl;	 
	 display(BB->get_successor(0));
	 if(BB->get_nb_succ()==2)	
	    display(BB->get_successor(1));
      }
   }			
}

//Donner Null pour le BB en parametre de la fonction lors de son appel
void Cfg::restitution(Basic_block *BB, string const filename){
  if (BB == nullptr)
    remove(filename.c_str());

  ofstream monflux(filename.c_str(), ios::app);
  int test=0, end=0;

  if(monflux){
    if(BB == nullptr)	{
      BB = _head;
      for(int i=0; i<_length; i++)	
	_read[i]=0;
      monflux<< "digraph G1 {"<<endl;	
      monflux << "node [shape = box];\n" ; 
    }
    
    if(!_read[BB->get_index()]){
      _read[BB->get_index()]=1;
      monflux << "BB" << BB->get_index() << " [label = \"" << "BB" << BB->get_index() << "\\n" << BB->get_content() << "\"] ;" << endl;
      //ecriture des successeurs dans le fichier
      if(BB->get_nb_succ() == 0){
	monflux<<"BB"<<BB->get_index()<<" -> EXIT " <<" [style = filled, label = \"\"];"<<endl;
	monflux.close();
      }
      else 
	{ 
	  if(BB->get_nb_succ() == 1){
	  monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor(0)->get_index()<<" [style = filled, label = \"\"];"<<endl;
	  }
	  if(BB->get_nb_succ()==2){
	    if (BB->get_successor(0)->get_index() == BB->get_index()+1){
	      monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor(0)->get_index()<<" [style = filled, label = \"F\"];"<<endl;
	      
	      monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor(1)->get_index()<<"[style = filled, label = \"T\"];"<<endl;				
	    }
	    else {
	      monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor(0)->get_index()<<" [style = filled, label = \"T\"];"<<endl;
	      
	      monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor(1)->get_index()<<"[style = filled, label = \"F\"];"<<endl;				
	    }

	  }
	  
	  monflux.close();
	  restitution(BB->get_successor(0), filename);
	  if(BB->get_nb_succ()==2)	
	    restitution(BB->get_successor(1), filename);
	}
    }
    		
    //lecture du fichier pour savoir s'il y a d�j� un parenthese de fin
    ifstream fichier(filename.c_str());
    if(fichier){      
      string ligne;     //Une variable pour stocker les lignes lues
      while(getline(fichier, ligne))    //Tant qu'on n'est pas a la fin, on lit
	{	
	  if (!ligne.compare("}"))	end=1;
	}
    }
    else
      {
	cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
      }	
    //si pas d�j� de parenthese la rajouter
    if(end==0){  
      if (monflux.is_open())
	monflux.close();
      monflux.open(filename.c_str(), ios::app);
      if (monflux) {
	for(int i=0; i<_length; i++)	
	  if(_read[i]==0) {
	    test=1;
	    // pour ajouter la parenth�se apr�s insertion de toutes les infos
	  }
	if(test==0)	
	  { 
	    monflux << "}"<< endl; 
	    cout << "test vaut 0 " << endl;
	  }
	
	monflux.close();
      }
      
    }
  }
  
}


