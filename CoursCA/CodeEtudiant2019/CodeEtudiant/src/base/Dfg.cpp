#include <Dfg.h>


Arc_t* new_arc(int del, t_Dep d, Node_dfg *n){
   Arc_t *arc = new Arc_t;
   arc->delai=del;
   arc->dep=d;
   arc->next=n;
   
   return arc;
}

int get_delay(t_Dep dep, Instruction *from, Instruction *to){
   switch(dep){
   case t_Dep::WAW:
      return WAW_DELAY;
   case t_Dep::WAR:
      return WAR_DELAY;
   case t_Dep::MEMDEP:
      return MEMDEP_DELAY;
   case t_Dep::CONTROL:
      return 0;
   case t_Dep::NONE:
      return 0;
   case t_Dep::RAW:
      int ret=t_delay[from->get_type()][to->get_type()];
      if(ret<1)
	 return 1;
      return ret;
   }
   
   return 0;
}


/* rend vrai si le noeud n est d�j� dans l, faux sinon */

bool contains(list<Node_dfg*>* l, Node_dfg* n){
   list<Node_dfg*>::iterator it;
   
   for(it=l->begin(); it!= l->end(); it++){
      if( (*it)==n ){
	 return true;
      }
   }
   return false;
}


Dfg::Dfg(Basic_block *bb){
   _bb=bb;
   Instruction *itmp;
   int icurr=0, inxt, nb_inst, del, need_new_arc;
   list<Arc_t*>::iterator ita;
  
   nb_inst=bb->get_nb_inst();
   bb->comput_pred_succ_dep();

   Node_dfg **nodeTab= new Node_dfg*[nb_inst];
   
   for(int i=0; i<nb_inst; i++)
      nodeTab[i]=nullptr;
   
   Arc_t *arc;
  
   itmp=bb->get_first_instruction();
   _nb_arc=0;

   while(itmp!=nullptr){
     // creation d'un noeud si non existant d�j�
      if(nodeTab[icurr]==nullptr){
	 nodeTab[icurr]=new Node_dfg(itmp);
      }
     
      //ajoute noeud � la liste des noeuds
      list_node_dfg.push_back(nodeTab[icurr]);
      
     
      //si pas de pr�d�cesseur, ajout � la racine
      if(itmp->get_nb_pred()==0){
	 _roots.push_back(nodeTab[icurr]);
      }

      list<dep*>::iterator itd;
      need_new_arc=1;

      //parcours des instructions qui dependent de l'instruction courante
      for(itd=itmp->succ_begin(); itd!=itmp->succ_end(); itd++){
	inxt=(*itd)->inst->get_index();
	del=get_delay((*itd)->type, itmp, (*itd)->inst);
#ifdef DEBUG2
	 cout << "inst " << itmp->to_string() << "->" << (*itd)->type<< "->" << (*itd)->inst->to_string();
	 cout << "delai " << del << endl;
#endif
	 need_new_arc=1;   
	 //creation noeud pour l'instruction dependante si non existant 
	 if(nodeTab[inxt]==nullptr){
	    nodeTab[inxt]=new Node_dfg((*itd)->inst);
	 }
	 else{
	   // � commenter si on  veut  toutes les d�pendances entre 2 instructions
	   //par d�faut on les met toutes ce qui ne change pas les calculs ensuite.
	   

	   //on cherche s'il existe d�j� un arc entre les 2 instructions
	   // si oui on regarde s'il faut mettre � jour le type de l'arc
	   // en consid�rant le d�lai comme crit�re de mise � jour 
	   // RAW prend le pas sur WAR et WAW et MEM 
	   // penser � mettre le d�lai le plus long
	   
	   /*for (ita= nodeTab[icurr]->arcs_begin(); ita!=nodeTab[icurr]->arcs_end(); ita++){
	      if( (*ita)->next->get_instruction()==(*itd)->inst){
		if(del>(*ita)->delai){
		  (*ita)->delai=del;
		  (*ita)->dep=(*itd)->type;
		  }
		  if((*itd)->type==RAW){// RAW == vrai d�pendance, elle prend le pas
		  (*ita)->delai=del; // sur toute autre d�pendance
		  (*ita)->dep=RAW;
		  } 
		  need_new_arc=0;
		  break;
		  }
		  }*/
	   ;
	 }
	 if (itmp -> is_branch() && (itmp -> get_index()  == (*itd)->inst->get_index() -1))
	   { need_new_arc = 0; // pas d'arc entre branchement et inst du delayed slot 
	     cout << "ERREUR Construction DFG : pas d'arc entre saut et delayed_slod" << endl;
	     exit(0);
	   }
	 if(
	    need_new_arc){
	   arc = new_arc(del, (*itd)->type, nodeTab[inxt]);
	   nodeTab[icurr]->add_successeur(arc);
	   nodeTab[inxt]->add_predecesseur(nodeTab[icurr]);
	   _nb_arc++;
	 }
	 
      }
      if(itmp->is_branch()){
	 _branch = nodeTab[icurr];

	 itmp=itmp->get_next();//on va sauter par dessus le delayed slot
	 icurr++;

         //dans notre cas le seul delayed slot potentiel 
	 //est la derni�re instr si l'avant derni�re est un saut

	 //si on ne l'a pas d�ja rencontr� (si dependance avec des instructions du bloc, donc si ce n'est pas un nop) on lui cr�� un noeud
	 if (nodeTab[icurr] == nullptr)
	   nodeTab[icurr]=new Node_dfg(itmp);
	 else { 
	   if (icurr > 1) {  
	   cout << "on ajoute un arc control " << endl;
	   arc = new_arc(0, t_Dep::CONTROL, nodeTab[icurr-1]);
	   nodeTab[icurr]->add_successeur(arc);
	   nodeTab[icurr-1]->add_predecesseur(nodeTab[icurr]);
	   if (contains(&_roots, _branch))
	     _roots.remove(_branch);
	   }}
	 //on l'ajoute � la liste  des delayed_slots
	 _delayed_slot.push_back(nodeTab[icurr]);
	 
      }

      itmp=itmp->get_next();
      icurr++;
   }
   
   _length=nb_inst;
   _read= new int[nb_inst];
   free(nodeTab);
}

Dfg::~Dfg(){}


void Dfg::display(Node_dfg * node, bool first){
   
   
   list<Node_dfg*>::iterator it;
   it=_roots.begin();

   if(first)	
      for(int i=0; i<_length; i++)	
	 _read[i]=0;  	
   
   for (unsigned int j=0; j<_roots.size();j++ ){ 
      if(first) node = *it;	
			

      if(!_read[node->get_instruction()->get_index()]){
	 _read[node->get_instruction()->get_index()]=1;
	 cout<<"pour i"<<node->get_instruction()->get_index()<<endl;
	 cout<<"l'instruction "<<node->get_instruction()->get_content()<<endl;
			
	 //On affiche ses successeurs s'il en a
	 for(int i=0;i<node->get_nb_arcs();i++){
	    if (node->get_arc(i)){
	       cout<< " -> succ i"
		   << node->get_arc(i)->next->get_instruction()->get_index()
		   << " : "
		   << node->get_arc(i)->next->get_instruction()->get_content()
		   << endl;
	    }
	 }
	 for(int i=0;i<node->get_nb_arcs();i++){
	    if (node->get_arc(i))
	       display(node->get_arc(i)->next, false);
	 }
      }
      it++;

   }
}

#define DEP(x) ((x == t_Dep::NONE) ? "" : \
		((x == t_Dep::RAW) ? "RAW_" : \
		 ((x == t_Dep::WAR) ? "WAR" : \
		  ((x == t_Dep::WAW) ? "WAW" :				\
		   ((x == t_Dep::MEMDEP) ? "MEM" : "CONTROL")))))


//Pour g�n�rer le fichier .dot: dot -Tps graph.dot -o graph.ps
void Dfg::restitute(Node_dfg * node, string const filename, bool first){
   if(first)
      remove(filename.c_str());
   ofstream monflux(filename.c_str(), ios::app);
   list<Node_dfg*>::iterator it;
 
   if(first && _length){
     
      for(int i=0; i<_length; i++)
	 _read[i]=0;
      
      it = _delayed_slot.begin();
      
    
      
      monflux << "digraph G1 {" << endl;
      monflux << "node [shape = ellipse];\n" ; 
     
      for(unsigned int i=0; i < _delayed_slot.size(); i++){
	monflux << "i" << (*it)->get_instruction()->get_index()  <<  
	  " [label = \" delayed slot : " << (*it)->get_instruction()->get_content() << "\"] ;" << endl; 
	_read[(*it)->get_instruction()->get_index()]=1;
	monflux<<"i"<<(*it)->get_instruction()->get_index() - 1;
	monflux<<" ->  i" << (*it)->get_instruction()->get_index() <<" [style = bold, dir= none, fontcolor = blue, color = blue, label= \"delayed_slot\"];"<<endl;;
	it++;
	if (_branch)
	  restitute(_branch,filename.c_str(),false);
      }
      
      
   }	
   it=_roots.begin();
   for (unsigned int j=0; j<_roots.size();j++ ){ 		

      if(first) node = *it;
		
      if(monflux){			
	 //monflux.open(filename.c_str(), ios::app);
	 if(!_read[node->get_instruction()->get_index()]){
	    _read[node->get_instruction()->get_index()]=1;
	
	    monflux << "i" << node->get_instruction()->get_index() <<  " [label = \"" << node->get_instruction()->get_content() << "\"] ;" << endl; 
	    //On affiche ses successeurs s'il en a
	    for(int i=0; i<node->get_nb_arcs(); i++){
	       if (node->get_arc(i)){
	   
		  monflux<<"i"<<node->get_instruction()->get_index();
		  monflux<<" ->  i" << node->get_arc(i)->next->get_instruction()->get_index();

		  // monflux<<"i"<<node->get_instruction()->get_index()<<"_"<<node->get_weight();
		  // monflux<<" ->  i" << node->get_arc(i)->next->get_instruction()->get_index();
		  // monflux<<"_"<<node->get_arc(i)->next->get_weight();
		  if (node->get_arc(i)->dep == t_Dep::RAW)
		    monflux<<" [color = red, fontcolor = red, label= \""<< DEP(node->get_arc(i)->dep) << node->get_arc(i)->delai<<"\"];"<<endl;
		  else if (node->get_arc(i)->dep == t_Dep::MEMDEP)
		    monflux<<" [color = green, fontcolor = green, label= \""<< DEP(node->get_arc(i)->dep) << node->get_arc(i)->delai<<"\"];"<<endl;
		  else
		    monflux<<" [label= \""<< DEP(node->get_arc(i)->dep) <<"\"];"<<endl;
	       }
	    }
	    monflux.close();
	
	    for(int i=0;i<node->get_nb_arcs();i++){
	       if (node->get_arc(i))
		  restitute(node->get_arc(i)->next,filename.c_str(),false);	
	    }
	 }
      }
      if((j+1) < _roots.size())	monflux.open(filename.c_str(), ios::app);
      it++;
   }

   if (first && _length){
      monflux.open(filename.c_str(), ios::app);
      monflux<<"}"<<endl;
      monflux.close();
   }
   return;
 
}

bool Dfg::read_test(){
  for(int i=0; i<_length; i++)	if(_read[i]==0)	return true;
  return false;
}



void Dfg::comput_critical_path(){
   list<Node_dfg*>::iterator it;
   list<Node_dfg*>::iterator itp;
   list<Node_dfg*> leafs, grp1, grp2, *next_grp, *current_grp, *swap;
   Instruction *inst;

   // chercher les feuilles du DAG
   for(it=list_node_dfg.begin(); it!=list_node_dfg.end(); it++){
      if((*it)->get_nb_arcs()==0){ //0 successeurs
	 leafs.push_back(*it);
      }
   }   
   // on ajoute le delayed_slot (si non nop c'est important)
   for (it=_delayed_slot.begin(); it!=_delayed_slot.end(); it++)
     {
     	 leafs.push_back(*it);
     }
   

   next_grp=&grp1;
   //traitement des feuilles en premier
   for(it=leafs.begin(); it!=leafs.end(); it++){
     inst=(*it)->get_instruction();
      
     if(inst->is_branch())
       (*it)->set_weight(2);//poids du branch + du delayed slot
     else
       (*it)->set_weight(inst->get_latency());
     
     // on ajoute tout les successeurs des feuilles dans le prochain groupe � traiter
     for(itp=(*it)->pred_begin(); itp!=(*it)->pred_end(); itp++){
       if(!contains(next_grp, *itp) ){
	 next_grp->push_back(*itp);
       }
     }
   }
   
   current_grp=next_grp;
   next_grp=&grp2;
   while(current_grp->size()>0){
      
      for(it=current_grp->begin(); it!=current_grp->end(); it++){
	int w = (*it)->compute_weight();
	 if( w==0 ){
	    // on a pas pu valuer le noeuds ce tour ci, il faudra recommencer au prochain tour
	       next_grp->push_back(*it);
	 }
	 else{
	   //le noeud a �t� valu�, au prochain tour on �tudie tout ses pr�decesseurs
	   if (w == 1)
	    for(itp=(*it)->pred_begin(); itp!=(*it)->pred_end(); itp++){
	      next_grp->push_back(*itp);
	    }
	 }
      }
      current_grp->clear();
      swap=current_grp;
      current_grp=next_grp;
      next_grp=swap;
   }
  
#ifdef DEBUG2
   it=list_node_dfg.begin();
   for(unsigned int k = 0; k < list_node_dfg.size(); k++, it++){
      Node_dfg* node = *it;
      cout << "node inst " << node -> get_instruction() -> get_index();
      cout << " poids=" << node->get_weight() << " nb succ=" << node->get_nb_arcs() << endl;
   }
#endif
}

/* rend la valeur du chemin critique */
int Dfg::get_critical_path(){
   list <Node_dfg*>::iterator it= _roots.begin();
   list <Node_dfg*>::iterator it2;
   int max=0;
   
   if((*it)->get_weight()==0){
      comput_critical_path();
   }
#ifdef DEGUB2

   cout << "Poids chemin critique calcul�, dans get_critical_path " << endl;
   for(it2=list_node_dfg.begin(); it2!=list_node_dfg.end(); it2++){
     cout << "i" << (*it2)->get_instruction()->get_index() << " poids" << (*it2)->get_weight() << endl;
   }
#endif    
   for(; it!=_roots.end(); it++){
      if((*it)->get_weight()>max){
	 max=(*it)->get_weight();
      }
   }
   return max;
}


Node_dfg* heaviest_in_critical_path(list<Node_dfg*>* ready){
   list <Node_dfg*>::iterator it;
   int max=0, w, more_than_one_max=0;
   Node_dfg* heaviest=nullptr;
   
   for(it=ready->begin(); it!=ready->end(); it++){
      w=(*it)->get_weight();
      if(w==max){
	 more_than_one_max++;
      }
      else if(w>max){
	 max=w;
	 heaviest=*it;
	 more_than_one_max=0;
      }
   }
   if(!more_than_one_max)
      return heaviest;
   else
      return nullptr;
}

void heaviest_nodes_critical_path(list<Node_dfg*>* ready, list<Node_dfg*>* res){
   list <Node_dfg*>::iterator it;
   
   int max=0, w, more_than_one_max=0;
   Node_dfg* heaviest=nullptr;
   
   for(it=ready->begin(); it!=ready->end(); it++){
      w=(*it)->get_weight();
      if(w==max){
	 more_than_one_max++;
      }
      else if(w>max){
	 max=w;
	 heaviest=*it;
	 more_than_one_max=0;
      }
   }
   if(!more_than_one_max){
     res->push_back(heaviest);
   }
   else
     for(it=ready->begin(); it!=ready->end(); it++){
       w=(*it)->get_weight();
       if(w == max){
	 res->push_back(*it);
       }
     }  
 
      return;
}

Node_dfg* first_without_freeze(list<Node_dfg*>* ready, int curTime){
   list <Node_dfg*>::iterator it;
   for(it=ready->begin(); it!=ready->end(); it++){
      if((*it)->get_tready()<=curTime)
	 return *it;
   }
   return nullptr;
}

 void nodes_without_freeze(list<Node_dfg*>* ready, int curTime, list<Node_dfg*>* res){
   list <Node_dfg*>::iterator it;
   for(it=ready->begin(); it!=ready->end(); it++){
      if((*it)->get_tready()<=curTime)
	res->push_back(*it);
   }
   return;
}


 void  nodes_limiting_freeze(list<Node_dfg*>* ready, int curTime, list<Node_dfg*>* res) {

 list <Node_dfg*>::iterator it;
 int min_ready = 0;

   for(it=ready->begin(); it!=ready->end(); it++){
     if (min_ready ==0) min_ready = (*it)->get_tready();
     if ((*it)->get_tready() < min_ready)
       min_ready = (*it)->get_tready();
     
   }

   for(it=ready->begin(); it!=ready->end(); it++){
     if((*it)->get_tready()==min_ready)
       res->push_back(*it);
   }
 
   return;
 }


Node_dfg* highest_latency(list<Node_dfg*>* ready){
   list <Node_dfg*>::iterator it;
   Node_dfg* n=nullptr;
   int max=0, lat, more_than_one_max=0;

   for(it=ready->begin(); it!=ready->end(); it++){
      lat=(*it)->get_instruction()->get_latency();
      if(lat==max){
	 more_than_one_max++;
      }
      else if(lat>max){
	 max=lat;
	 n=*it;
	 more_than_one_max=0;
      }
   }
   
   if(!more_than_one_max)
      return n;
   else
      return nullptr;
}

 void  highest_latency_nodes(list<Node_dfg*>* ready, list<Node_dfg*>* res){
   list <Node_dfg*>::iterator it;
   Node_dfg* n=nullptr;
   int max=0, lat, more_than_one_max=0;

   for(it=ready->begin(); it!=ready->end(); it++){
      lat=(*it)->get_instruction()->get_latency();
      if(lat==max){
	 more_than_one_max++;
      }
      else if(lat>max){
	 max=lat;
	 n=*it;
	 more_than_one_max=0;
      }
   }
   
   if(!more_than_one_max)
     res->push_back(n);
   else
     for(it=ready->begin(); it!=ready->end(); it++){
       lat=(*it)->get_instruction()->get_latency();
       if(lat==max){
	 res->push_back(*it);
       }
     }
   return;
}



Node_dfg* more_succ(list<Node_dfg*>* ready){  
  Node_dfg* n = nullptr;
  int max=0, succ, more_than_one_max=0;

  for(auto nr : *ready){
    succ = nr -> get_nb_arcs();
    if(succ==max){
      more_than_one_max++;
    }
    else if(succ>max){
      max=succ;
      n = nr;
      more_than_one_max=0;
    }
  }
  
  if(!more_than_one_max)
    return n;
  else
    return nullptr;
}


void more_succ_nodes(list<Node_dfg*>* ready,list<Node_dfg*>* res){
  
  Node_dfg* n = nullptr;
  int max=0, succ, more_than_one_max=0;
  
  for(auto nr : *ready){
    succ = nr -> get_nb_arcs();
    if(succ==max){
      more_than_one_max++;
    }
    else if(succ>max){
      max=succ;
      n = nr;
      more_than_one_max=0;
    }
  }
  
  if(!more_than_one_max)
    res->push_back(n);
  else
    for(auto nr: *ready){
      succ = nr->get_nb_arcs();
      if(succ==max){
	res->push_back(nr);
      }
    }
     
   return;
 }


Node_dfg* more_descendants(list<Node_dfg*>* ready){
   list <Node_dfg*>::iterator it;
   Node_dfg* n=nullptr;
   int max=0, desc, more_than_one_max=0;

   for(it=ready->begin(); it!=ready->end(); it++){
      desc=(*it)->get_nb_descendant();
      if(desc==max){
	 more_than_one_max++;
      }
      else if(desc>max){
	 max=desc;
	 n=*it;
	 more_than_one_max=0;
      }
   }
   
   if(!more_than_one_max)
      return n;
   else
      return nullptr;
}

 void  more_descendants_nodes(list<Node_dfg*>* ready,list<Node_dfg*>* res){
   list <Node_dfg*>::iterator it;
   Node_dfg* n=nullptr;
   int max=0, desc, more_than_one_max=0;

   for(it=ready->begin(); it!=ready->end(); it++){
      desc=(*it)->get_nb_descendant();
      if(desc==max){
	 more_than_one_max++;
      }
      else if(desc>max){
	 max=desc;
	 n=*it;
	 more_than_one_max=0;
      }
   }
   
   if(!more_than_one_max)
     res->push_back(n);
   else
     for(it=ready->begin(); it!=ready->end(); it++){
       desc=(*it)->get_nb_descendant();
       if(desc==max){
	 res->push_back(*it);
       }}

      return;
}

Node_dfg* lowest_index(list<Node_dfg*>* ready){
   list <Node_dfg*>::iterator it=ready->begin();
   Node_dfg* n=*it;
   int min=n->get_instruction()->get_index(), tmp;

   for(; it!=ready->end(); it++){
      tmp=(*it)->get_instruction()->get_index();
      if(min>tmp){
	 min=tmp;
	 n=*it;
      }
   }
   
   return n;
}



bool is_ready(Node_dfg* node, list<Node_dfg*>* scheduled){
   list<Node_dfg*>::iterator it;
   for(it=node->pred_begin(); it!=node->pred_end(); it++){
      if(!contains(scheduled, *it))
	 return false;
   }
   return true;
}

// ajouter � la classe pour  que l'on puisse verifier qu'un saut n'est pas pret avant les autres instructions 
// mais c'est moche, faudrait plutot recalculer proprement les dependances de controle....

bool Dfg::is_ready2(Node_dfg* node, list<Node_dfg*>* scheduled, Node_dfg* delayed_inst){
   list<Node_dfg*>::iterator it;
   if (node == delayed_inst || contains(&_delayed_slot,node)) return false;
   if (node != _branch){
     for(it=node->pred_begin(); it!=node->pred_end(); it++){
       if(! (contains(scheduled, *it) || (*it == delayed_inst && is_ready(*it, scheduled)))) 
	 return false;
     }
     return true;
   }
   // node == branch
#ifdef DEBUG3
   cout << "is branch ready ? " << node->get_instruction()->get_content() << endl;

#endif 
   for(it=node->pred_begin(); it!=node->pred_end(); it++){
     if( !(contains(scheduled, *it) || ((*it == delayed_inst || contains(&_delayed_slot, *it)) && is_ready(*it, scheduled))) ) {
#ifdef DEBUG3
        cout << "false pred non sched" << endl;
#endif
	return false;
     }
   }
   for (it = list_node_dfg.begin(); it != list_node_dfg.end(); it++){
     if(*it != delayed_inst  && *it != _branch && !(contains(scheduled, *it))){
#ifdef DEBUG3
       cout << "false noeuds non sched" << endl;
#endif
       return false;
     }
   }
#ifdef DEBUG3
   cout << "true" << endl;
#endif
   return true;
}

void print_linstr(list<Node_dfg*>* l){
   list<Node_dfg*>::iterator it;
   for(it=l->begin(); it!=l->end(); it++){
     cout<<"i"<<(*it)->get_instruction()->get_index()<<"  : " <<  (*it)->get_instruction()->to_string() << " ;" ;
   }
   cout << endl;
   return;
}

void Dfg::compute_nb_descendant(){
   list<Node_dfg*>::iterator it;
   
   int nb_instr=_bb->get_nb_inst(), nb;
   for(it=list_node_dfg.begin(); it!=list_node_dfg.end(); it++){
      nb=(*it)->compute_nb_descendant(nb_instr, nullptr);
      (*it)->set_nb_descendant(nb);
   }
}




// si branchement : chercher les dependances de control avec pr�d�cesseur => instruction potentielle pour le delayed slot 

Node_dfg* Dfg::get_inst_for_delayed_slot(){

  if (!_bb->get_branch())
    return nullptr;

  Instruction * itmp = getInst(_bb->get_branch());

  if (! (_delayed_slot.front()) -> get_instruction() -> is_nop()) return nullptr;
  
  int max = 0;
 
  Node_dfg * selected_node = nullptr;

  cout << "on cherche une instruction pour le delayed slot" << endl; 

  // on itere sur les predecesseur du saut pour trouver inst avec dep de controle 
  for (auto itd =itmp->pred_begin(); itd!=itmp->pred_end(); itd++){
    if ((*itd)->type == t_Dep::CONTROL){ // si dep de controle pas d'autres dep avec le branchement possible (ou BUG)
      for (auto node_tmp: list_node_dfg) {
	if (node_tmp -> get_instruction() == (*itd)->inst && node_tmp -> get_weight() > max) {
	  max = node_tmp -> get_weight();
	  selected_node = node_tmp;
	}
      }
    }
  }
  if (selected_node){
    cout << "trouve instruction " << selected_node -> get_instruction()->get_content() << endl;
    //  selected_node->remove_dep_control();
    // enlever dep control entre delayed slot et branch (2 sens) ;
    // afficher delayed slot dans le .dot ; 
    // critical path avec delayed slot  
  }
  else cout << "pas trouve d'instruction" << endl;
  
  if (contains(&_roots,selected_node)){
    _roots.remove(selected_node);
    if (_roots.empty())
      _roots.push_back(_branch);
  }
  return selected_node;
 
}


void  Dfg::scheduling(bool verbose){
   list <Node_dfg*>::iterator it;
   list <Arc_t*>::iterator ita;

   comput_critical_path();
   compute_nb_descendant();
   int curTime=1;


   cout  << "Scheduling " << endl;
   Node_dfg * delayed_slot_inst = get_inst_for_delayed_slot();
 
   Node_dfg *scheduled, *succ;
   list <Node_dfg*> res, res2;
   
   _inst_ready.clear();
   
   for(it=_roots.begin(); it!=_roots.end(); it++){
     if (*it == delayed_slot_inst) {
       for (auto itaa=(*it)->arcs_begin(); 
	    itaa!= (*it)->arcs_end();
	    itaa++){
	 auto succ2 =(*itaa)->next;
	 is_ready2(succ2, &new_order,delayed_slot_inst);
	 succ2->set_tready(curTime+(*itaa)->delai);
	 _inst_ready.push_back(succ2);
       }
       continue;
     }
      _inst_ready.push_back(*it);
     (*it)->set_tready(1);
   }
   
   if(verbose)
      cout<<"Scheduling"<<endl;
  
   while(_inst_ready.size()>0 && _inst_ready.size() < 100){
     res.clear();
     res2.clear();
    
     if(verbose){
	cout<<curTime<<" : "<<endl;
	cout<<"ready : ";
	 print_linstr(&_inst_ready);
	 cout<<endl;
      }

      if(_inst_ready.size()==1){
	 if(verbose)
	    cout<<"only one : ";
	 scheduled=_inst_ready.front();
      }
      else {
	nodes_without_freeze(&_inst_ready, curTime, &res);
	if (res.size()==0)  { // tous provoquant des cycles de gel
	  // trouver les noeuds avec le min de gel 
         nodes_limiting_freeze(&_inst_ready, curTime, &res);
	}
	
	if (res.size()==1){
	  scheduled = res.front();
	  if(verbose)
	    cout<<"first without freeze :";
	}

	if (res.size()> 1){
	  res2.clear();
	  heaviest_nodes_critical_path(&res,&res2); // on garde ceux avec le plus fort poids
	  if (res2.size() == 0) cout << " aucun plus fort sur heaviest " << endl;
	  if (res2.size() == 1){
	    scheduled= res2.front();
	    if(verbose)
	      cout<<"heaviest :";
	  }
	  else {
	    res.clear();
	    highest_latency_nodes(&res2, &res);  // on garde ceux avec la plus grande latence
	  if (res.size() == 0) cout << " aucun plus fort avec latence " << endl;

	    if(res.size() == 1){
	      scheduled = res.front();
	      if(verbose)
		cout<<"highest latency :";
	    }
	    else {
	      res2.clear();
	      more_succ_nodes(&res, &res2); // on garde ceux avec le plus de successeurs
	      if (res2.size() == 0) cout << " aucun plus fort avec latence " << endl;


	      if(res2.size() == 1){
		scheduled = res2.front();
		if(verbose)
		  cout<<"more succ :";
	      }
	      else {
		res.clear();
		more_descendants_nodes(&res2, &res); // on garde ceux avec le plus de descendants
		if (res.size() == 1){
		  scheduled = res.front();
		  if(verbose)
		    cout<<"more descendants :";
		}
		else{
		  scheduled=lowest_index(&res);
		  if(verbose)
		    cout<<"lowest_index :";
		} // plus d'un avec le max de descendants
	      }// plus d'un avec le plus de successeurs
	    } // plus d'un avec la latence max
	  } // plus d'un avec poids max sur chemin critique
	} // plus d'un qui ne freeze pas
      } // plus d'un qui est pr�t
      

      _inst_ready.remove(scheduled);
   
     
      if(verbose)
	 cout<<"i"<<scheduled->get_instruction()->get_index()<<endl;
      new_order.push_back(scheduled);
      
      for (ita=scheduled->arcs_begin(); 
	   ita!=scheduled->arcs_end();
	   ita++){
	succ=(*ita)->next;
	
	if (is_ready2(succ, &new_order, delayed_slot_inst)){
	  succ->set_tready(curTime+(*ita)->delai);
#ifdef DEBUG3
	  // cout << "ajout dans les ready : " << succ->get_instruction()->get_content() << endl;
#endif
	  _inst_ready.push_back(succ);
	}
	else
	  if ((succ == delayed_slot_inst || contains(&_delayed_slot, succ)) && is_ready(succ, &new_order)) {
	    for (auto itaa=succ->arcs_begin(); 
		 itaa!=succ->arcs_end();
		 itaa++){
	      auto succ2 =(*itaa)->next;
	      is_ready2(succ2, &new_order,delayed_slot_inst);
	      succ2->set_tready(curTime+(*itaa)->delai);
#ifdef DEBUG3
	      // cout << "ajout dans les ready : " << succ2->get_instruction()->get_content() << endl;
#endif
	      _inst_ready.push_back(succ2);
	    }
	  }
      }
      
      curTime++;
   }
   //donc dans notre cas, le nop post jump
   if(_delayed_slot.size()!=0){
     if (delayed_slot_inst)
       new_order.push_back(delayed_slot_inst);
     else
       new_order.push_back(_delayed_slot.front());
   }
   if (verbose)
     display_sheduled_instr();
   return;
}

void Dfg::apply_scheduling(){
   _bb->apply_scheduling(&new_order);
}


void Dfg::display_sheduled_instr(){
   list <Node_dfg*>::iterator it;
   Instruction *inst;
   for(it=new_order.begin(); it!=new_order.end(); it++){
      inst=(*it)->get_instruction();
      cout<<"i"<<inst->get_index()<<": "<<inst->get_content()<<endl;
   }
}
