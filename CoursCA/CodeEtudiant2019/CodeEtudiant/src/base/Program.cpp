#include <Program.h>
#include <asm_mipsyac.h>

extern	void programparse(string) ; 
extern	Program prog ;

Program::Program(){
   _head = nullptr;
   _length = 0;
}


//constructeur de copie
Program::Program(Program const&  otherprogram){
   //On initialise la liste.
   _head = nullptr;
   _length = 0;
   // On copie la liste.
   Line * tmp = otherprogram._head;
   while (tmp != nullptr){
      add_line(tmp);
      tmp = tmp->get_next();
   }
}

//constructeur qui vas permettre de parser un fichier
Program::Program (string const file){
   _head = nullptr ;
   _length = 0 ;
   programparse(file) ;
  
   Line * tmp = prog._head;
   while (tmp != nullptr){
      add_line(tmp);
      tmp = tmp->get_next();
   }
}

Program::~Program(){
   _head = nullptr;
   _length = 0;
}



void Program::add_line(Line * newline){
   if(!_head){
      _head= newline;
      _end=newline;
   }
   else{
     newline->set_prev(_end);
     if (_end !=nullptr)  
       _end->set_next(newline);
      _end=newline;
   }
   _length++;
}


void Program::del_line(int index){
   Line * to_delete = nullptr;
   Line * prec;
	
   if (index >= 0 && index < _length){
      if (index == 0){
	 if (_length > 0){
	    // On efface le maillon.
	    to_delete = _head;
	    _head = _head->get_next();	
	    _head->set_prev(nullptr);
	 }
      }
      else {	// On se place sur le pr√©c√©dent.
	 prec = _head;
	 for (int i = 0; i < index-1; ++i){
	    prec = prec->get_next();
	 }

	 // On retire le maillon.
	 to_delete = prec->get_next();
	 
	 prec->set_next( to_delete->get_next() );
	 to_delete->get_next()->set_prev(prec);   
      }
      delete to_delete;
      --_length;
   }
   return;
}

int Program::add_line_at(Line *newline, int position)
{
   if (position <= 0){
     

      newline->set_next(_head); // newline pointe sur le premier.
      _head->set_prev(newline);
      _head = newline;         // newline est maintenant premier.
      ++_length;
      return 1;
   }

   else if (position >= _length)
      add_line(newline);

   else
   {
      
      Line * prec = _head;
     
      // On se place sur le precedent.
      for (int i = 0; i < position - 1; ++i){
	 prec = prec->get_next();
      }

      // On ajuste les pointeurs.
      newline->set_next(prec->get_next());
      prec->set_next(newline);
      ++_length;
      return 1;
   }
   return 1;
}


void Program::display()
{
   Line* element = _head;
   while(element != nullptr){
      cout << element->get_content() <<endl;
		
      if(element->get_next()==nullptr)	
	 break;
      else 
	 element = element->get_next();
   }
   if (is_empty())	
      cout<<"The program is empty"<<endl;
   cout << endl;
   return;
}

void Program::flush(){

   while(!is_empty()){
      del_line(0);		
   }
   return;
}


void Program::exchange_line(int line1, int line2){
   Line * lg1,*lg2;
	
   lg1=find_line(line1);
   lg2=find_line(line2);

   del_line(line1);
   add_line_at(lg2,line1);
   del_line(line2);
   add_line_at(lg1,line2);
   return;
}

Line* Program::find_line(int index){
   int j;
   Line *e = _head;
   for (j=0; j< _length ;j++) {
      if(j==index) {
	 return e;
      }
      e = e->get_next();
   }
   return nullptr;
}


int Program::size(){
   return _length;
}

bool Program::is_empty(){
   if(!_head)	
      return true;
   return false;
}

void Program::in_file(string const filename){
   Line* element = _head;
   ofstream monflux(filename.c_str());
  
   if(monflux){
      while(element != nullptr)
      {
	if(element->type_line()== t_Line::Instr || 
	   element->type_line()== t_Line::Directive) 
	    monflux<<"\t";
	 monflux << element-> get_content();
	
	 if(element->get_next()==nullptr)	
	    break;
	 else {
	    if(element->get_content().compare("nop")) 
	       monflux<<endl;
	    element = element->get_next();
	 }			
      } 
   }
   else {
      cout<<"Error cannot open the file"<<endl;
   }
  
   monflux.close();	
}

/* Delimite les fonctions du programme et crÈe la liste des fonctions 
*/
void Program::comput_function(){
   Function *func;
   Line *element_debut=nullptr;
   Line* current = _head;
   
   Directive *d=nullptr;
   string direct;

   while(current != nullptr){   
      if(current->isDirective()){
	 d = getDirective(current);
	 direct=d->get_content();
	 if(direct.size() !=0){
	    if( direct.compare(0, 4, ".ent")==0){
	       element_debut=current;
	    }
	    if( direct.compare(0, 4, ".end")==0){
	       func = new Function();
	       func->set_head(element_debut);
	       func->set_end(current);
	       element_debut=nullptr;
	       //func -> display();
	       _myfunc.push_back(func);
	    }
	 }
      }

      if(current->get_next()==nullptr)	
	 break;
      else 
	 current = current->get_next();
   }
   if (is_empty())	
      cout<<"The program is empty"<<endl;
}

int Program::nbr_func(){
   return _myfunc.size();
}

Function*  Program::get_function(int index){
  /* list<Function*>::iterator it;
   it=_myfunc.begin();
   int size=(int)_myfunc.size();
  
   if (index < size){
      for (int i = 0; i<index; i++) 
	 it++;
      return *it;	
   }
   return nullptr;	*/

  if (index >= (int)_myfunc.size()){
    cerr <<"Error Program::get_function: index is bigger than the size of the function list"<<endl; 
    return nullptr;
  }
	  
  int i = index;
  for (auto fct: _myfunc){
    if (i == 0)
      return fct;
    i--;
	}
  return nullptr;
}



/* Pour chaque fonction du programme, donc de la liste _myfunc, il faut crÈer un CFG et l'ajouter ‡ la liste _myCFG ;
   La crÈation d'un CFG se fait avec un appel au constructeur, par exemple : 
   Cfg * cfg = new Cfg(bb0, n);
   crÈe un CFG dont le BB d'entrÈe est bb0 et contenant n BBs.
   Vous pouvez vous inspirer de la fonction ci-dessus pour itÈrer sur la liste des fonctions _myfunc. 
   N'oubliez pas de calculer les blocs de base des fonctions et les succ/pred des BB sinon le CFG n'aura qu'un bloc, le premier (meme si on dit qu'il en a n en paramËtre)
*/

void  Program::comput_CFG(){
   
  
   return;
}




Cfg*  Program::get_CFG(int index)
{
   list<Cfg*>::iterator it;
   it=_myCFG.begin();
   if (index< (int)_myCFG.size()){
      for (int i = 0; i<index;i++) 
	 it++;
      return *it;	
   }
   return _myCFG.back();	
}
