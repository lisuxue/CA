#include <Function.h>

Function::Function(){
  _head = nullptr;
  _end = nullptr;
  BB_computed = false;
  label_computed = false;
  BB_pred_succ = false;
  dom_computed = false;
  
}

Function::~Function(){}

void Function::set_head(Line *head){
  _head = head;
}

void Function::set_end(Line *end){
  _end = end;
}

Line* Function::get_head(){
  return _head;
}

Basic_block* Function::get_firstBB(){
   return _myBB.front();
}

Line* Function::get_end(){
  return _end;
}

void Function::display(){
  cout<<"Begin Function"<<endl;
  Line* element = _head;

  while(element != _end){
    cout << element->get_content() <<endl;		
    element = element->get_next();
  }

  if (element == _end)	
    cout << _head->get_content() <<endl;

  cout<<"End Function\n\n"<<endl;
	
}

int Function::size(){
  Line* element = _head;
  int lenght=0;
  while(element != _end)
    {
      lenght++;		
      if (element->get_next()==_end)
	break;
      else
	element = element->get_next();
    }
  return lenght;
}	


void Function::restitution(string const filename){
	
  Line* element = _head;
  ofstream monflux(filename.c_str(), ios::app);

  if(monflux){
    monflux<<"Begin"<<endl;
    if(element == _end)	
      monflux << _head->get_content() <<endl;
    while(element != _end)
      {
	if(element->isInst() || 
	   element->isDirective()) 
	  monflux<<"\t";
	
	monflux << element->get_content() ;
	
	if(element->get_content().compare("nop")) 
	  monflux<<endl;
		
	if(element->get_next()==_end){
	  if(element->get_next()->isInst() || 
	     element->get_next()->isDirective())
	    monflux<<"\t";
	  monflux << element->get_next()->get_content()<<endl;
	  break;
	}
	else element = element->get_next();

      }
    monflux<<"End\n\n"<<endl;
		
  }

  else {
    cout<<"Error cannot open the file"<<endl;
  }

  monflux.close();
}

void Function::comput_label(){
  if (label_computed) return; // on ne le fait qu'une fois
  Line* element = _head;

  if(element == _end && element->isLabel())	
    _list_lab.push_back(getLabel(element));
  while(element != _end)
    {

      if(element->isLabel())	
	_list_lab.push_back(getLabel(element));

      if(element->get_next()==_end){
	if(element->isLabel())	
	  _list_lab.push_back(getLabel(element));
	break;
      }
      else element = element->get_next();

    }
  label_computed = true;
}

int Function::nbr_label(){
  return _list_lab.size();

}

Label* Function::get_label(int index){

  int size=(int) _list_lab.size();
  if(index< size){
    int i = index; 
    for (auto label_fct: _list_lab) {
      if (i == 0)
	return label_fct;
      else
	i--;
    }
  }
  else cout<<"Error get_label : index is bigger than the size of the list, returns the last one (if any)"<<endl; 	
  return _list_lab.back();
}

Basic_block *Function::find_label_BB(OPLabel* label){
  for(auto bb : _myBB) {		
    if(bb ->is_labeled()){	 
      string str= bb ->get_head()->get_content();
      if (!str.compare(0, (str.size()-1),label->get_op())){
	return bb;
       }
    }
  }
  cout << "find_label_BB can't find a BB starting with " << label->to_string() << endl;
  return nullptr;
}


/* add_BB(debut, fin, br, index) crée un nouveau BB et 
 l'ajoute à la liste de BB de la fonction en le creant */
/* "debut" est l'entete, "fin" la derniere ligne du BB, "br" est une ligne contenant un saut ou vaut nullptr si le BB ne finit pas par un saut , "index" est le numéro du BB */ 

void Function::add_BB(Line *debut, Line* fin, Line *br, int index){
   Basic_block *b = new Basic_block();
   b->set_head(debut);
   b->set_end(fin);
   b->set_index(index);
   b->set_branch(br);
   _myBB.push_back(b);
}


// Calcule la liste des blocs de base : il faut délimiter les BB, en parcourant la liste des lignes (qui contiennent des directives, des labels ou des instructions) à partir de la premiere de la fonction, il faut s'arreter à chaque branchement (et prendre en compte le delayed slot qui appartient au meme BB, c'est l'instruction qui suit tout branchement) ou à chaque label (on estime que tout label est utilisé par un saut et donc correspond bien à une entête de BB).

// Pour créer un bloc il est conseiller d'utiliser la fonction addBB ci-dessus qui crée un BB et l'ajoute à la liste des BB de la fonction 
void Function::comput_basic_block(){
  
  bool verbose = false;  // passer à false pour moins d'affichage 
  if (verbose){
    cout << "comput BB" <<endl;
    cout<<" head:"<< _head->get_content()<<endl;
    cout<<" tail:"<< _end->get_content()<<endl;
  }
  if (BB_computed) return; // NE PAS TOUCHER, évite de recalculer si déjà fait

  // A REMPLIR 
  Line* entete = nullptr;
  int index = 0;
  Line* current = _head;

	while ( current  != _end->get_next() ) {
		if (current->isLabel()) {
			if (entete != nullptr){
				add_BB(entete,current->get_prev(),nullptr,index++);
			}
			entete = current;
		}else{
			if (current->isInst()){
				if (entete == nullptr) {
					entete = current;
				}
				if (((Instruction*) current)->is_branch()){
					current = current->get_next();
					add_BB(entete,current,current->get_prev(),index++);
					entete = nullptr;
				}
			}
		}
		current = current->get_next();
	}
	if (entete != nullptr){
		add_BB(entete,current->get_prev(),nullptr,index++);
	}
	
  
  // FIN A REMPLIR 
  
  
  if (verbose)
    cout<<"end comput Basic Block"<<endl;
  
  
  // calcul effectué, ne pas toucher ci-dessous
  BB_computed = true;
  return;
}

int Function::nbr_BB(){
   return _myBB.size();
}



Basic_block *Function::get_BB(int index){
   int size=(int)_myBB.size();
 
   if (index < size){
     int i = index;
     for (auto bb: _myBB){
       if (i == 0)
	 return bb;
       else i--;
     }
   }
   return nullptr;
}


/* comput_pred_succ calcule les successeurs (et prédécesseur) des BB */
/* et itérer sur tous les BB d'une fonction */
/* il faut determiner si un BB a un ou deux successeurs : dépend de la présence d'un saut présent ou non à la fin */
/* pas de saut ou saut incontionnel ou appel de fonction : 1 successeur (lequel ?)*/
/* branchement conditionnel : 2 successeurs */ 
/* le bloc de sortie de fonction  n'a pas de successeurs - celui qui se termine par jr R31 */
/* les sauts indirects n'ont pas de successeur */
/* lorsque l'on a un successeur on l'ajoute au BB, et on ajoute BB comme prédecesseur du successeur */

void Function::comput_succ_pred_BB(){
  
  if (BB_pred_succ) return; // on ne le fait qu'une fois 
  
  if (!BB_computed) 
    comput_basic_block();
  if (!label_computed) 
    comput_label();
 
 
  //int size = (int) _myBB.size();
   
  for (auto bb: _myBB){ // parcours tous les BB de _myBB
    //Instruction *instr;
    Basic_block *succ=nullptr;
    OPLabel* lab = nullptr;
    	
    // A REMPLIR 
    Instruction* branch = (Instruction*)(bb->get_branch());
    if (branch == nullptr){
    	succ = get_BB(bb->get_index()+1);
    	if (succ)
    		bb->set_link_succ_pred(succ);	
    }else{
		if (branch->is_call()){
			succ = get_BB(bb->get_index()+1);
			if (succ)
				bb->set_link_succ_pred(succ);
		}else{
			if(branch->is_cond_branch()){
				succ = get_BB(bb->get_index()+1);
				if (succ)
		 	  	  bb->set_link_succ_pred(succ);
		 	    lab = branch->get_op_label();
				bb->set_link_succ_pred(find_label_BB(lab));
			}else{
				if(branch->is_indirect_branch()){
				}else{
					lab = branch->get_op_label();
					bb->set_link_succ_pred(find_label_BB(lab));
				}}}}
  }
    // fin à remplir 
    
  // ne pas toucher ci-dessous
  BB_pred_succ = true; // calcul effectué
  return;
}

void Function::compute_dom(){
 
  
  if (dom_computed) return; // on ne le fait qu'une fois

  if (!BB_pred_succ)
    comput_succ_pred_BB();   // on a besoin d'avoir calculé les blocs prédécesseurs et successeurs avant de calculer les dominants
  
 
   // on peut récupérer les BB de la fonction avec la méthode get_BB(num du BB) pour tous les numéros de BB entre 0 et nbBB-1.

  list<Basic_block*> workinglist; // liste de travail  
  bool change = true;  // pour itérer tant que pas de point fixe
 
  /* A REMPLIR */
  for(int i = 0;i< nbr_BB();i++){ // la racine n'a pas de dominant
  	get_BB(0)-> Domin[i] = false;
  }
  workinglist.push_back(get_BB(0));

  do {
  	change = false;
  	Basic_block* n = workinglist.front();
  	workinglist.pop_front();
  	if (n != get_BB(0)){ // la racine n'a pas de predecesseur
	  	vector<bool> t (nbr_BB(),true); //T:=N
	  	for(int i = 0;i<(n->get_nb_pred());i++){
	  		for(int j = 0;j<nbr_BB();j++){
	  			if (n->get_predecessor(i)->Domin[j] == true && t[j]==true) {}
	  			else {
	  				t[j]=false;
	  			}  				
	  		}
	  	}
	  	t[n->get_index()]=true;
	  	for(int i = 0;i<(nbr_BB());i++){
	  		if (t[i]!=n->Domin[i]) {
	  			n->Domin = t;
	  			change = true;
	  			break;
	  		}
	  	}
  	}else{
  		n->Domin[0] = true;
  		change = true;
  	}
  	if (change){
  		for(int i=0; i<(n->get_nb_succ());i++){
  			workinglist.push_back(n->get_successor(i));
  		}
  	}
  
  } while (!workinglist.empty());
 

  // affichage du resultat
  
  for (auto bb : _myBB){ // parcours des bb dans la liste des BB    
    cout << "Dominants pour BB" << bb -> get_index() << " : "; 
    for (int i = 0; i< nbr_BB(); i++){ // affichage des bloc dominants parmi les nbr_BB() bb de la fonction
      if (bb->Domin[i]) cout << " BB" << i  ;
    }
    cout << endl;
  }
  dom_computed = true;
  return;
}




void Function::compute_loops(){
  if (!BB_computed) 
    comput_basic_block();
  if (!BB_pred_succ) 
    comput_succ_pred_BB();
  if (!dom_computed)
    compute_dom();

	for (auto bb : _myBB){
		for (int j=0;j<bb->get_nb_succ();j++){
			if (bb->Domin[bb->get_successor(j)->get_index()] == true) {
  			 Loop *l = new Loop(bb->get_successor(j),bb);
				 l->compute_in_loop_BB();
				_myLoop.push_back(l);;
			}
		}
	}

  /* A REMPLIR */
  return;
}

void Function::display_loops(){
  cout << "Displaying the " << _myLoop.size() << " loops of the function" << endl;
  for(auto loop: _myLoop){
    loop->display();
  }

}

void Function::compute_live_var(){
 
  list<Basic_block*> workinglist;
  //bool change = true;
 
   

  /* A REMPLIR avec algo vu en cours et en TD*/
 /* algorithme itératif qui part des blocs sans successeur, ne pas oublier que lorsque l'on sort d'une fonction le registre $2 contient le résultat (il est donc vivant), le registre pointeur de pile ($29) est aussi vivant ! */


 

 // fin à REMPLIR
}

void Function::show_live_var(void){
  // Affichage du resultat
 
  for (auto bb: _myBB){
    cout << "********* bb " << bb->get_index() << "***********" << endl;
    cout << "LIVE_OUT : " ;
    for(int i = 0; i < NB_REG; i++){
      if (bb->LiveOut[i]){
	cout << "$"<< i << " "; 
      }
    }
    cout << endl;
    cout << "LIVE_IN :  " ;
    for(int i = 0 ; i < NB_REG ; i++){
      if (bb->LiveIn[i]){
	cout << "$"<< i << " "; 
      }}
    cout << endl;
  }
  return;
 }
     



/* en implementant la fonction test de la classe BB, permet de tester des choses sur tous les blocs de base d'une fonction par exemple l'affichage de tous les BB d'une fonction ou l'affichage des succ/pred des BBs comme c'est le cas -- voir la classe Basic_block et la méthode test */

void Function::test(){
  for(auto bb: _myBB){
    bb->test();
  }
   return;
}
