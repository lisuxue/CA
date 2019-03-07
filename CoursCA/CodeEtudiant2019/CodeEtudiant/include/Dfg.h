#ifndef _Dfg_H
#define _Dfg_H

/**	\file	Dfg.h
	\brief	Dfg class
*/


#include <Node_dfg.h>
#include <Instruction.h>
#include <Enum_type.h>
#include <fstream>
#include <list>

class Basic_block;
class Node_dfg;

/**	\class	Dfg
	\brief	class representing a Dfg of a Basic block, a data flow graph
	that is to be used to calculate the critical path and schedule code
*/


class Dfg{

public:


	/**	\brief	Constructor of Dfg given a basic block
*/
	Dfg(Basic_block *);

	/**	\brief	Destructor of Dfg
*/
	~Dfg();

	/**	\brief	Build the Dfg, 
		when you call this method you have to affect the fisrt parameter to nullptr and the 
		second to true
*/
	void build_dfg(Node_dfg*,bool);

	/**	\brief	Display the Dfg, 
		when you call this method you have to affect the fisrt parameter to nullptr and the 
		second to true
*/
	void display(Node_dfg * ,bool);

	/**	\brief	restitute the Dfg, 
		when you call this method you have to affect the fisrt parameter to nullptr and the 
		third to true
*/
	void restitute(Node_dfg * ,string const, bool );

	/**	\brief	tests if all node have been read
*/
	bool read_test();

	/**	\brief	comput the node weight needed for critical path computation of the Dfg
*/
	void comput_critical_path();


	/**	\brief	comput the number of descendant of each node in the Dfg
*/

	void compute_nb_descendant();

	/**	\brief	compute the order the instructions in the basic block according to an algorithm list, verbose mode as parameter
*/
	void scheduling(bool);

/**	\brief	\brief change the schedule of the basic block with the computed one
*/

	void apply_scheduling();

/**	\brief	returns the highest weigth of nodes
*/
	int get_critical_path();

/**	\brief	\brief display the computed schedule of the basic block
*/

	void display_sheduled_instr();


/**	\brief	returns an instruction to fill the delayed slot (if any)
*/
	Node_dfg * get_inst_for_delayed_slot();

	bool is_ready2(Node_dfg* node, list<Node_dfg*>* scheduled, Node_dfg* delayed_inst);
private:
	Basic_block *_bb;
	list <Node_dfg*> list_node_dfg;
	list <Node_dfg*> _roots;
	list <Node_dfg*> _delayed_slot;
	Node_dfg* _branch;
	
	list <Node_dfg*> _inst_ready;
	list <Node_dfg*> new_order;

	int _nb_arc;
	int _length;
	int *_read; 
	
};

#endif

