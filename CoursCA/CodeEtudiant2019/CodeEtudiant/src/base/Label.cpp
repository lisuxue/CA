#include <Label.h>

Label::Label( string lab){
	_line= lab;
	_next=nullptr;
	_prev=nullptr;
}

Label::~Label(){
}

string Label::to_string(){
	return _line;

}


t_Line Label::type_line(){
  return t_Line::Label;
}

string Label::get_content(){

	return _line + ":";

}

void Label::set_content(string line){
	_line =line;
}


t_Inst  Label::get_type(){
  return t_Inst::OTHER;
}

  Label* getLabel(Line *l){
	   if (l->isLabel())
	     return (dynamic_cast< Label * > (l));
	   else return nullptr;
	}
