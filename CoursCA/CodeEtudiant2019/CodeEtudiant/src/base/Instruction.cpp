#include <Instruction.h>
#include <Enum_type.h>
#include <stdlib.h> //pour atoi

 Instruction* getInst(Line* l){
	   if (l->isInst())
	     return (dynamic_cast< Instruction * > (l));
	   else return nullptr;
	}


/* retourne le délai induit par une dépendance RAW i1 -> i2 avec i1 de type t1 et i2 de type t2 */

int delai(t_Inst t1, t_Inst t2){
  return t_delay[t1][t2];
}


static int getNbDiffNull(Operand *Op1, Operand *Op2, Operand *Op3){
   int i=0;
   if(Op1!=nullptr)
      i++;
   if(Op2!=nullptr)
      i++;
   if(Op3!=nullptr)
      i++;
   return i;
}

Instruction::Instruction(string instr, t_Operator oper, t_Inst type, 
			 Operand *Op1, Operand *Op2, Operand *Op3){
   
   _line= instr;
   _op= oper;
    _type=op_profile[_op].type;
   _type= type;
   _op1= Op1;
   _op2= Op2;
   _op3= Op3;
   _index = 0;
   _next=nullptr;
   _prev=nullptr;
   _next_inst=nullptr;
   _prev_inst=nullptr;
   _nbOp=getNbDiffNull(Op1,Op2,Op3);
}

Instruction::Instruction(t_Operator oper, Operand *Op1, Operand *Op2, Operand *Op3){
   _op= oper;
    _type=op_profile[_op].type;
   _op1= Op1;
   _op2= Op2;
   _op3= Op3;
   _index = 0;
   _next=nullptr;
   _prev=nullptr;
   _next_inst=nullptr;
   _prev_inst=nullptr;
   _nbOp=getNbDiffNull(Op1,Op2,Op3);
}

Instruction::Instruction(t_Operator oper, Operand *Op1, Operand *Op2){
   _op= oper;
    _type=op_profile[_op].type;
   _op1= Op1;
   _op2= Op2;
   _op3= nullptr;
   _index = 0;
   _next=nullptr;
   _prev=nullptr;
 _next_inst=nullptr;
   _prev_inst=nullptr;
   _nbOp=getNbDiffNull(Op1, Op2, nullptr);
}

Instruction::Instruction(t_Operator oper, Operand *Op1){
   _op= oper;
   _op1= Op1;
   _op2= nullptr;
   _op3= nullptr;
   _index = 0;
   _next=nullptr;
   _prev=nullptr;
   _next_inst=nullptr;
   _prev_inst=nullptr;
    _type=op_profile[_op].type;
   if(Op1!=nullptr)
      _nbOp=1;
   else 
      _nbOp=0;

}

Instruction::Instruction(t_Operator oper){
   _op= oper;
    _type=op_profile[_op].type;
   _op1= nullptr;
   _op2= nullptr;
   _op3= nullptr;
   _nbOp=0;
   _index = 0;
   _next=nullptr;
   _prev=nullptr;
   _next_inst=nullptr;
   _prev_inst=nullptr;
}

Instruction::~Instruction(){}

Operand* Instruction::get_op1(){
   return _op1;
}

void Instruction::set_op1(Operand * o){
   if (_op1 == nullptr)
      _nbOp++;
   _op1=o;
}

Operand* Instruction::get_op2(){
   return _op2;
}

void Instruction::set_op2(Operand * o){
   if (_op2 == nullptr)
      _nbOp++;
   _op2=o;
}

Operand* Instruction::get_op3(){
   return _op3;
}

void Instruction::set_op3(Operand * o){
   if (_op3 == nullptr)
      _nbOp++;
   _op3 =o;
}

int Instruction::get_nbOp(){
   return _nbOp;
}

t_Operator Instruction::get_opcode(){
   return _op;
}

void Instruction::set_opcode(t_Operator newop){
   _op = newop;
}

string Instruction::string_opcode(){
   return op_profile[_op].nom;
}


t_Format Instruction::get_format(){
   return op_profile[_op].format;
}

//static
std::map<t_Format,string> Instruction::form={
  {t_Format::J, "J"}, 
  {t_Format::I, "I"}, 
  {t_Format::R, "R"}, 
  {t_Format::O, "O"}, 
  {t_Format::B,"B"}};

string Instruction::string_form(){
   return form[get_format()];
}

t_Inst  Instruction::get_type(){
  
   return _type;

}

string Instruction::to_string(){
   return get_content();

}

void Instruction::display(){
  cout << get_content() << endl;
  return;
}

t_Line Instruction::type_line(){
  return t_Line::Instr;
}

string Instruction::get_content(){

   string rt ;

   rt= string_opcode()+ " ";

   if (get_type()==t_Inst::MEM){
      if (_op1!=nullptr){
	 rt = rt + _op1->get_op();
	 if (_op2!=nullptr){
	   if(_op2->get_op_type()!= t_OpType::Reg)
	       rt = rt+ "," + _op2->get_op();
	    else	
	       rt = rt+ ",(" + _op2->get_op()+")";
	 }
			
	 if(_op3!=nullptr && _op2==nullptr){
	    rt =rt+",("+ _op3->get_op()+")";	
	 }
	 else if(_op3!=nullptr && _op2!=nullptr){
	    rt =rt+"("+ _op3->get_op()+")";	
	 }		
      }
   }
   else{
      if (_op1!=nullptr){
	 rt = rt+ _op1->get_op();
	 if (_op2!=nullptr){
	    rt = rt+ "," + _op2->get_op();
	    if(_op3!=nullptr){
	       rt =rt+","+ _op3->get_op();
	    }
	 }
      }
   }	
   return rt;
}

void Instruction::set_content(string line){
   _line =line;

}



std::map<t_Inst,string> Instruction::typ = {
  {t_Inst::ALU,"ALU"}, 
  {t_Inst::MEM,"MEM"}, 
  {t_Inst::ALU,"BR"}, 
  {t_Inst::OTHER,"OTHER"},
  {t_Inst::BAD,"BAD"}}
  ;

string Instruction::string_type(){
   return typ[get_type()];
}


// ------------------ RAW ----------------------

bool Instruction::is_dep_RAW1(Instruction *i2){
   return (this->get_reg_dst() != nullptr && 
	   i2->get_reg_src1() != nullptr && 
	   !(this->get_reg_dst()->get_op().compare(i2->get_reg_src1()-> get_op())));
}

bool Instruction::is_dep_RAW2(Instruction *i2){
   return (this->get_reg_dst() != nullptr && 
	   i2->get_reg_src2() != nullptr && 
	   !(this->get_reg_dst()-> get_op().compare(i2->get_reg_src2()-> get_op())));  
}
//this write, i2 read
bool Instruction::is_dep_RAW(Instruction *i2){
   return this->is_dep_RAW1(i2) || this->is_dep_RAW2(i2) ;
}

// ------------------ WAR ----------------------

bool Instruction::is_dep_WAR1(Instruction *i2){
  return (i2->get_reg_dst() != nullptr && 
	  this->get_reg_src1() != nullptr && 
	  !(i2->get_reg_dst()-> get_op().compare(this->get_reg_src1()-> get_op())));
}

bool Instruction::is_dep_WAR2(Instruction *i2){
  return  (i2->get_reg_dst() != nullptr &&
	   this->get_reg_src2() != nullptr && 
	   !(i2->get_reg_dst()-> get_op().compare(this->get_reg_src2()-> get_op())));
}

//this read, i2 write
bool Instruction::is_dep_WAR(Instruction *i2){
   return this->is_dep_WAR1(i2) || this->is_dep_WAR2(i2);
}

bool Instruction::is_dep_WAW(Instruction *i2){
  return (i2->get_reg_dst() != nullptr && get_reg_dst()!= nullptr &&  
	  !(i2->get_reg_dst()->get_op().compare(this->get_reg_dst()->get_op())));
}

// ------------------ MEM ----------------------

bool Instruction::is_mem(){
   return _type==t_Inst::MEM;
}

bool Instruction::is_mem_load(){
  return ( _type==t_Inst::MEM && 
	    ( _op==t_Operator::lb || 
	      _op==t_Operator::lbu || 
	      _op==t_Operator::lh || 
	      _op==t_Operator::lhu  || 
	      _op==t_Operator::lw || 
	      _op==t_Operator::lwl || 
	      _op==t_Operator::lwr  || 
	      _op==t_Operator::ll || 
	      _op==t_Operator::pref));
}

bool Instruction::is_mem_store(){
  return (_type==t_Inst::MEM && (_op==	t_Operator::sw ||_op == t_Operator::sb || _op== t_Operator::sh));
}

bool Instruction::is_dep_MEM(Instruction *i2){
   
  if(!( this->get_type()==t_Inst::MEM 
	 && i2->get_type()==t_Inst::MEM))
      return false;
   
   Instruction *loader= nullptr, *storer=nullptr, *storer2=nullptr;

   if (is_mem_load() && i2->is_mem_store()){
      loader=this;
      storer=i2;
   }
   else if (i2->is_mem_load() && is_mem_store()){
      loader=i2;
      storer=this;
   }
   else if ((i2->is_mem_store() && is_mem_store())){
      storer=this;
      storer2=i2;
   }
   else{
      //2 loads -> WAW possible, mais pas de conflit mem !
      return false;
   }
   
   if (storer2 == nullptr
      && loader->get_reg_src1()-> get_op().compare(storer->get_reg_src2()-> get_op()))
	 return true;
   
   if (storer2 != nullptr
      && storer->get_reg_src2()-> get_op().compare(storer2->get_reg_src2()-> get_op()))
      	 return true;

   //this.op3 == i2.op3
   string str=this->get_op2()->get_op();
   int imm=atoi( str.c_str() );
   str=i2 ->get_op2()->get_op();
   int imm_i2=atoi( str.c_str() );
   
   if (imm-imm_i2>=4
       || imm_i2-imm>=4)
      return false;
       
   return true;
}


t_Dep Instruction::is_dependant(Instruction *i2){

   if(is_dep_RAW(i2)) 
     return t_Dep::RAW;
   if(is_dep_WAR(i2)) 
      return t_Dep::WAR;
   if(is_dep_WAW(i2)) 
      return t_Dep::WAW;
   if(is_dep_MEM(i2)) 
      return t_Dep::MEMDEP;
   return t_Dep::NONE;

}


OPRegister* Instruction::get_reg_dst(){
   OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
   
   if( op1!=nullptr && op1->get_type() == Dst && _op1->get_op().compare("$0"))
      return op1;

   return nullptr;
}

OPRegister* Instruction::get_reg_src1(){
   OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
   OPRegister *op2 = dynamic_cast< OPRegister * > (_op2);
   OPRegister *op3 = dynamic_cast< OPRegister * > (_op3);

   if(op1!=nullptr) 
      if(op1->get_type() == Src)
	 return op1;
   if(op2!=nullptr) 
      if(op2->get_type() == Src)
	 return op2;
   if(op3!=nullptr) 
      if(op3->get_type() == Src)
	 return op3;
   return nullptr;
}

OPRegister* Instruction::get_reg_src2(){
   OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
   OPRegister *op3 = dynamic_cast< OPRegister * > (_op3);
   OPRegister *op2 = dynamic_cast< OPRegister * > (_op2);

   if (op1 && op1->get_type() == Dst){ 
      if(op2 && op2->get_type() == Src)
	 if (op3  && op3->get_type() == Src)
	    return op3;
      return nullptr;
   }
   if (op1 && op1->get_type() == Src){ 
      if( op2 && op2->get_type() == Src)
	 return op2;
      else
	 if (op3  && op3->get_type() == Src)
	    return op3;
      return nullptr;
   }
   return nullptr;
}



OPLabel* Instruction::get_op_label(){
   OPLabel *op1 = dynamic_cast< OPLabel * > (_op1);
   OPLabel *op3 = dynamic_cast< OPLabel * > (_op3);
   OPLabel *op2 = dynamic_cast< OPLabel * > (_op2);

   if (op1)
     return op1;
   if (op2)
     return op2;
   if (op3)
     return op3;
    
   return nullptr;
}

void Instruction::set_next(Instruction *inst){	
   _next_inst=inst;
}

Instruction *Instruction::get_next(){
   return _next_inst;
}

void Instruction::set_prev(Instruction *inst){
   _prev_inst=inst;
}

void Instruction::set_link_succ_pred(Instruction *succ){
   _next_inst=succ;
   succ->set_prev(this);
}

Instruction *Instruction::get_prev(){
   return _prev_inst;	
}

void Instruction::add_pred_dep(dep *d){
   _pred_dep.push_back(d);
}

void Instruction::add_succ_dep(dep *d){
   _succ_dep.push_back(d);
}

list<dep*>::iterator Instruction::succ_begin(){
   return _succ_dep.begin();
}
list<dep*>::iterator Instruction::succ_end(){
   return _succ_dep.end();
}


list<dep*>::iterator Instruction::pred_begin(){
   return _pred_dep.begin();
}
list<dep*>::iterator Instruction::pred_end(){
   return _pred_dep.end();
}


dep* Instruction::get_pred_dep(int index){	
	if (index >= (int)_pred_dep.size()){
	  cerr <<"Error: index is bigger than the size of the list"<<endl; 
	  return nullptr;
	}
	  
	int i = index;
	for (auto dep: _pred_dep){
	  if (i == 0)
	    return dep;
	  i--;

	}
	return nullptr;

}
dep* Instruction::get_succ_dep(int index){
  	if (index >= (int)_succ_dep.size()){
	  cerr <<"Error: index is bigger than the size of the list"<<endl; 
	  return nullptr;
	}	  
	int i = index;
	for (auto dep: _succ_dep){
	  if (i == 0)
	    return dep;
	  i--;
	}
	return nullptr;
}


int Instruction::get_nb_succ(){
   return _succ_dep.size();
}

int Instruction::get_nb_pred(){
   return _pred_dep.size();
}

int Instruction::get_index(){
   return _index;
}

void Instruction::set_index(int id){
   _index = id;
}

bool Instruction::is_branch(){
  return _type == (t_Inst::BR);
}

bool Instruction::is_nop(){
  OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
   
  if(op1 && 
     op1->get_type() == Dst && 
     (_op1->get_op().compare("$0")==0))
      return true;

  return (get_content().compare(0,3,"nop")==0);
}

bool Instruction::is_call(){
  return _op == t_Operator::jal;
}
bool Instruction::is_cond_branch(){
   return (get_content().compare(0,1,"b")==0);
}
bool Instruction::is_indirect_branch(){
   return ( get_opcode() == t_Operator::jr ||  get_opcode() == t_Operator::jalr);
}

int Instruction::get_latency(){
  // 1 pour tout le monde
    return 1;
}

string str_t_dep(t_Dep td){
  std::map<t_Dep, string> dep_str_map = 
    { {t_Dep::NONE,"None"}, 
      {t_Dep::RAW, "RAW"}, 
      {t_Dep::WAR, "WAR"}, 
      {t_Dep::WAW, "WAW"}, 
      {t_Dep::MEMDEP, "MEMDEP"}, 
      {t_Dep::CONTROL,"CONTROL"}};
   
   return dep_str_map[td];
}

void Instruction::print_succ_dep(){
  for (auto dep: _succ_dep){
    cout<< "i"<< _index <<" -> i"<< dep->inst->get_index()<<" : "<<str_t_dep(dep->type)<<endl;
  }
}


void Instruction::reset_pred_succ_dep(){ 
    for (auto dep: _succ_dep){
       free(dep);
    }
    _succ_dep.clear();
 
    for (auto dep: _pred_dep){
      free(dep);
    }
   _pred_dep.clear();
   return;
}
