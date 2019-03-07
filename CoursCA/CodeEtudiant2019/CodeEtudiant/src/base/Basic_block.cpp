#include <Basic_block.h>



void Basic_block::show_dependances(Instruction *i1, Instruction *i2){
   
   if(i1->is_dep_RAW1(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": RAW1"<<endl; 
   if(i1->is_dep_RAW2(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": RAW2"<<endl;
   
   if(i1->is_dep_WAR1(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": WAR1"<<endl;
  
   if(i1->is_dep_WAR2(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": WAR2"<<endl;
   
   if(i1->is_dep_WAW(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": WAW"<<endl;
   
   if(i1->is_dep_MEM(i2)) 
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": MEM"<<endl;
   
}

Basic_block::Basic_block():
  Use(vector<bool>(NB_REG, false)),
  Def(vector<bool>(NB_REG, false)),
  LiveIn(vector<bool>(NB_REG, false)),
  LiveOut(vector<bool>(NB_REG, false)), 
  DefLiveOut(vector<int>(NB_REG, -1)), 
  Domin(vector<bool>(NB_MAX_BB, true)){
   _head = nullptr;
   _end = nullptr;
   _branch = nullptr;
   _index = 0;
   _nb_instr = 0;
   _firstInst=nullptr;
   _lastInst=nullptr;
   dep_done = false;
   use_def_done = false;
}


Basic_block::~Basic_block(){}


void Basic_block::set_index(int i){
   _index = i;
}

int Basic_block::get_index(){
   return _index;
}

void Basic_block::set_head(Line *head){
   _head = head;
}

void Basic_block::set_end(Line *end){
   _end = end;
}

Line* Basic_block::get_head(){
   return _head;
}

Line* Basic_block::get_end(){
   return _end;
}




void Basic_block::set_successor(Basic_block *BB){
   _succ.push_back(BB);
}

Basic_block *Basic_block::get_successor(int index){
   int size=(int)_succ.size();
   if(index< size){
     int i = index;
     for (auto bbsucc: _succ){
       if (i == 0)
	 return bbsucc;
       else
	 i--;
     }
   }
   else cout<<"Error Basic_block::get_successor: index is bigger than the size of the list"<<endl; 	
   return _succ.back();
}

void Basic_block::set_predecessor(Basic_block *BB){
   _pred.push_back(BB);
}

Basic_block *Basic_block::get_predecessor(int index){

  int size=(int)_pred.size();
   if(index< size){
     int i = index;
     for (auto bbpred: _pred){
       if (i == 0)
	 return bbpred;
       else
	 i--;
     }
   }
   else cout<<"Error Basic_block::get_predecessor: index is bigger than the size of the list"<<endl; 	
   return _pred.back();
	
}

int Basic_block::get_nb_succ(){
   return _succ.size();
}

int Basic_block::get_nb_pred(){
   return _pred.size();
}

void Basic_block::set_branch(Line* br){
   _branch=br;
}

Line* Basic_block::get_branch(){
   return _branch;
}

void Basic_block::display(){
  cout<<"Begin BB"<< get_index() << endl;
   Line* element = _head;
   int i=0;
   if(element == _end)	
      cout << _head->get_content() <<endl;
  
   while(element != _end->get_next()){
      if(element->isInst()){
	 cout<<"i"<<i<<" ";
	 i++;
      }
      if(!element->isDirective())
	 cout <<element->get_content() <<endl;
      
      element = element->get_next();
   }
   cout<<"End BB"<< get_index() << endl;
}

string Basic_block::get_content(){
   string rt = "";
   Line* element = _head;
   
   while(element != _end->get_next()){
     if(element->isInst()){
	rt = rt + element->get_content() + "\\l" ;	 	
     }
     else if(element->isLabel())
       rt = rt + element->get_content() + "\\l" ;
      
      element = element->get_next();
   }
  
   return rt ;
}

int Basic_block::size(){
   Line* element = _head;
   int lenght=0;
   while(element != _end){
      lenght++;
      if(element->get_next()==_end)	
	 break;
      else 
	 element = element->get_next();
   }
   return lenght;
}	


void Basic_block::restitution(string const filename){	
   Line* element = _head;
   ofstream monflux(filename.c_str(), ios::app);
   if(monflux){
     monflux<<"Begin BB"<< get_index() << endl;
      if(element == _end)	
	monflux << _head->get_content() <<endl;
      while(element != _end)
      {
	 if(element->isInst()) 
	    monflux<<"\t";
	 if(!element->isDirective())
	    monflux << element->get_content()<<endl ;
		
	 if(element->get_next()==_end){
	    if(element->get_next()->isInst()) 
	       monflux<<"\t";
	    if(!element->isDirective())
	       monflux << element->get_next()->get_content()<<endl;
	    break;
	 }
	 else element = element->get_next();
      }
      monflux<<"End BB" << get_index() << "\n\n"<<endl;		
   }
   else {
      cout<<"Error cannot open the file"<<endl;
   }
   monflux.close();

}

bool Basic_block::is_labeled(){
   if (_head->isLabel()){
      return true;
   }
   else return false;
}

int Basic_block::get_nb_inst(){   
   if (_nb_instr == 0)
      link_instructions();
   return _nb_instr;
    
}

Instruction* Basic_block::get_instruction_at_index(int index){
   Instruction *inst;
   
   if(index >= get_nb_inst()){
      return nullptr;
   }   
   inst=get_first_instruction();
   for(int i=0; i<index; i++, inst=inst->get_next());
   
   return inst;
}

Line* Basic_block::get_first_line_instruction(){
   
   Line *current = _head;
   while(!current->isInst()){
      current=current->get_next();
      if(current==_end && !current->isInst())
	 return nullptr;
   }
   return current;
}

Instruction* Basic_block::get_first_instruction(){
  if(_firstInst==nullptr){
      _firstInst= getInst(this->get_first_line_instruction());
      this->link_instructions();
  }
   return _firstInst;
}

Instruction* Basic_block::get_last_instruction(){
   if(_lastInst==nullptr)
      this->link_instructions();
   return _lastInst;
}


/* link_instructions  numérote les instructions du bloc */
/* remplit le champ nb d'instructions du bloc (_nb_instr) */
/* remplit le champ derniere instruction du bloc (_lastInst) */
void Basic_block::link_instructions(){

   int index=0;
   Line *current, *next;
   current=get_first_line_instruction();
   next=current->get_next();

   Instruction *i1 = getInst(current);

   i1->set_index(index);
   index++;
   Instruction *i2;
   
//Calcul des successeurs
   while(current != _end){
   
      while(!next->isInst()){
	 next=next->get_next();
	 if(next==_end){
	    if(next->isInst())
	       break;
	    else{
	       _lastInst = i1;
	       _nb_instr = index;
	       return;
	    }
	 }
      }
      
      i2 = getInst(next);
      i2->set_index(index);
      index++;
      i1->set_link_succ_pred(i2);
      
      i1=i2;
      current=next;
      next=next->get_next();
   }
   _lastInst = i1;
   _nb_instr = index;
}

bool Basic_block::is_delayed_slot(Instruction *i){
   if (get_branch()== nullptr)
      return false;
   int j = (getInst(get_branch()))->get_index();
   return (j < i-> get_index());

}

/* set_link_succ_pred : ajoute succ comme successeur de this et ajoute this comme prédécesseur de succ
 */

void Basic_block::set_link_succ_pred(Basic_block* succ){
  _succ.push_back(succ);
  succ->set_predecessor(this);
}

/* add_dep_link ajoute la dépendance avec pred à la liste des dependances précédesseurs de succ */
/* ajoute la dependance avec succ à la liste des dépendances successeurs de pred */

/* dep est une structure de données contenant une instruction et  un type de dépendance */

void add_dep_link(Instruction *pred, Instruction* succ, t_Dep type){
   dep *d;
   d=(dep*)malloc(sizeof(dep));
   d->inst=succ;
   d->type=type;
   pred->add_succ_dep(d);
   
   d=(dep*)malloc(sizeof(dep));
   d->inst=pred;
   d->type=type;
   succ->add_pred_dep(d);
}


/* calcul des dépendances entre les instructions dans le bloc  */
/* une instruction a au plus 1 reg dest et 2 reg sources */
/* Attention le reg source peut être 2 fois le même */ 
/* Utiliser les méthodes is_dep_RAW1, is_dep_RAW2, is_dep_WAR1, is_dep_WAR2, is_dep_WAW, is_dep_MEM pour déterminer les dépendances */

/* ne pas oublier les dépendances de controle avec le branchement s'il y en a un */

/* utiliser la fonction add_dep_link ci-dessus qui ajoute à la liste des dépendances pred et succ une dependance entre 2 instructions */


void Basic_block::comput_pred_succ_dep(){
   
  link_instructions(); // essentiel pour avoir un lien entre les instructions
   if (dep_done) return;
  
   /* A REMPLIR */

 

   // FIN A REMPLIR

   // NE PAS ENLEVER : cette fonction ne doit être appelée qu'une seule fois
   dep_done = true;
   return;
}

void Basic_block::reset_pred_succ_dep(){

  Instruction *ic = get_first_instruction();
  while (ic){
    ic -> reset_pred_succ_dep();
    ic = ic -> get_next();
  }
  dep_done = false;
  return;
}

/* affiche les instructions successeurs des instructions du block */
/* permet de visualiser les successeurs et impliciement les prédécesseurs ! */ 
 
void Basic_block::show_succ_dep(){
  if (!dep_done) return;
  cout << "Affichage dependance des instructions du BB " << get_index() << endl;

  Instruction *ic = get_first_instruction();
  while (ic){
    ic -> print_succ_dep();
    ic = ic -> get_next();
  }
  return;
}




/* calcul le nb de cycles pour executer le BB, on suppose qu'une instruction peut sortir du pipeline à chaque cycle, il faut trouver les cycles de gel induit par les dépendances */

int Basic_block::nb_cycles(){
  
  comput_pred_succ_dep(); // besoin d'avoir les dépendances entre instruction

  /* tableau ci-dessous utile pour savoir pour chaque instruction quand elle sort pour en déduire les cycles qu'elle peut induire avec les instructions qui en dépendent, initialisation à -1  */
   vector<int> inst_cycle(get_nb_inst()); 
   for (int i=0; i< get_nb_inst(); i++ ){
     inst_cycle[i] = -1;
   }
   
   Instruction *ic=get_first_instruction();
   int exect = 0;  
   while(ic){   

     // A REMPLIR 
  


     
    
     //FIN A REMPLIR 
#ifdef DEBUG     
      cout << endl << "inst " << ic -> get_index() << " " << ic-> get_content () << " cycle "<<  inst_cycle[ic->get_index()] ;
#endif 
     ic = ic->get_next();
   }

#ifdef DEBUG  
    cout << endl;
#endif
   return exect;
   
  
}



/* 
calcule DEF et USE pour l'analyse de registre vivant 
à la fin on doit avoir
 USE[i] vaut 1 si $i est utilisé (lu) dans le bloc avant d'être potentiellement défini dans le bloc
 DEF[i] vaut 1 si $i est défini (écrit) dans le bloc 
ne pas oublier les conventions d'appel : les registres $4, $5, $6, $7 peuvent contenir des paramètres (du 1er au 4eme les autres sont sur la pile) avant un appel de fonctions, au retour d'une fonction $2 a été écrit car il contient la valeur de retour (sauf si on rend void). 
Un appel de fonction (call) écrit aussi l'adresse de retour dans $31 donc définit implicitement $31.

******************/

void Basic_block::compute_use_def(void){
  if (use_def_done) return;
 
  /* A REMPLIR */
 


  /* FIN A REMPLIR */
    return;
}


void Basic_block::show_use_def(void){
  cout << "****** BB " << get_index() << "************" << endl;
  cout << "USE : " ;
  for(int i=0; i<NB_REG; i++){
      if (Use[i])
      cout << "$"<< i << " "; 
  }
  cout << endl;
  cout << "DEF : " ;
  for(int i=0; i<NB_REG; i++){
      if (Def[i])
	cout << "$"<< i << " "; 
    }
  cout << endl;
  return;
}

/**** compute_def_liveout 
à la fin de la fonction on doit avoir
DefLiveOut[i] vaut l'index de l'instruction du bloc qui définit $i si $i vivant en sortie seulement
Si $i est défini plusieurs fois c'est l'instruction avec l'index le plus grand
*****/
void Basic_block::compute_def_liveout(){
  
 
  /* A REMPLIR */

 


  /* FIN A REMPLIR */

  return;
}


void Basic_block::show_def_liveout(){
  cout << "DEF LIVE OUT: " ;
  for(int i=0; i<NB_REG; i++){
    if (DefLiveOut[i] != -1)
      cout << "$"<< i << " definit par l'instruction i" << DefLiveOut[i] << endl; 
  }
  cout << endl;
  return;
}

/**** renomme les registres renommables : ceux qui sont définis et utilisés dans le bloc et dont la définition n'est pas vivante en sortie
Utilise comme registres disponibles ceux dont le numéro est dans la liste paramètre 
*****/

void Basic_block::reg_rename(list<int> *frees){
  compute_def_liveout();   // definition vivantes en sortie necessaires à connaitre
 
  /* A REMPLIR */



  /* FIN A REMPLIR */

 
}



/**** renomme les registres renommables : ceux qui sont définis et utilisés dans le bloc et dont la définition n'est pas vivante en sortie
Utilise comme registres disponibles ceux dont le numéro est dans la liste paramètre 
*****/
void Basic_block::reg_rename(){
 
  compute_def_liveout();
 
  list<int> free_regs;
 
   /* A REMPLIR */



  /* FIN A REMPLIR */

}


void Basic_block::apply_scheduling(list <Node_dfg*> *new_order){
   list <Node_dfg*>::iterator it=new_order->begin();
   Instruction *inst=(*it)->get_instruction();
   Line *n=_head, *prevn=nullptr;
   Line *end_next = _end->get_next();
   if(!n){
      cout<<"wrong bb : cannot apply"<<endl;
      return;
   }
   
   while(!n->isInst()){
     prevn=n;
     n=n->get_next();
     if(n==_end){
       cout<<"wrong bb : cannot apply"<<endl;
       return;
     }
   }
   
   //y'a des instructions, on sait pas si c'est le bon BB, mais on va supposer que oui
   inst->set_index(0);
   inst->set_prev(nullptr);
   _firstInst = inst;
   n = inst;
   
   if(prevn){
     prevn->set_next(n);
     n->set_prev(prevn);
   }
   else{
     set_head(n);
   }

   int i;
   it++;
   for(i=1; it!=new_order->end(); it++, i++){
     inst->set_link_succ_pred((*it)->get_instruction());   
     inst=(*it)->get_instruction();
     inst->set_index(i);
     prevn = n;
     n = inst;
     prevn->set_next(n);
     n->set_prev(prevn);
     }
   inst->set_next(nullptr);
   _lastInst = inst;
   set_end(n);
   n->set_next(end_next);

   if (_nb_instr > i){
     if (_nb_instr - i > 1)
       cout << "nb instructions differents de plus de 1, difference : " << _nb_instr - i << endl;
     _nb_instr = i;
   }
   return;
}

/* permet de tester des choses sur un bloc de base, par exemple la construction d'un DFG, à venir ... là ne fait rien qu'afficher le BB */
void Basic_block::test(){
   cout << "test du BB " << get_index() << endl;
   display();
  
   cout <<  "nb de predecesseurs : " << get_nb_pred() << endl ;
   int nbpred = (int) get_nb_pred();
   for (int i = 0; i < nbpred; i++){
      if (get_predecessor(i) != nullptr)
	 cout << " pred "<< i <<  " : BB" << get_predecessor(i)-> get_index() << endl;
   }
   cout << endl;
   int nbsucc = (int) get_nb_succ();
   cout << "nb de successeurs : " << get_nb_succ() << endl;
   
   for (int i = 0; i < nbsucc; i++){
     if (get_successor(i) != nullptr)
       cout << " succ " << i  << " : BB" <<  get_successor(i)-> get_index() << endl ;
   }
   cout << endl;
}
