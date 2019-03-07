#include <Loop.h>

Loop::Loop(Basic_block *bb1, Basic_block *bb2):header_bb(bb1), latch_bb(bb2){}

Loop::~Loop(){}

void Loop::set_header(Basic_block *bb){
  header_bb = bb;
  return;
}
void Loop::set_latch(Basic_block *bb){
  latch_bb = bb;
  return;
}

Basic_block* Loop::get_header(){
  return header_bb;
}
Basic_block* Loop::get_latch(){
  return latch_bb;
}
void Loop::display(){
  if (!header_bb || !latch_bb) {
    cerr << "Loop:display : can't display a loop without header or latch";
    exit(0);
  }
  cout << "Loop between BB" << header_bb->get_index() << " and BB" << latch_bb->get_index() << ": ";
    for (auto bb: _myBB){
	cout << "BB" << bb->get_index() << " ";
    }
  cout << endl;
  return;
}
int Loop::nbr_BB(){
  
  return _myBB.size();
}


void Loop::compute_in_loop_BB(){
  
  list <Basic_block*> working_list;
  vector<bool> read(NB_MAX_BB, false);
  working_list.push_back(latch_bb);

  while (!working_list.empty()){
    Basic_block * bb = working_list.front();
    working_list.pop_front();
    if (!read[bb-> get_index()]) {
      read[bb->get_index()] = true;
      _myBB.push_back(bb);
      for (int i = 0; i < bb-> get_nb_pred(); i++){
	if (bb->get_predecessor(i) != header_bb)
	  working_list.push_back(bb->get_predecessor(i));
      }
    }
  }
  _myBB.push_front(header_bb);
  return;
}
