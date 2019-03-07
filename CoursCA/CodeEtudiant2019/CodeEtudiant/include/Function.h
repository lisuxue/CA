#ifndef _Function_H
#define _Function_H

/**	\file	Function.h
	\brief	Function class
	\author	Hajjem, Heydemann
*/


#include <Line.h>
#include <Basic_block.h>
#include <Loop.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Label.h>
#include <Enum_type.h>
#include <list>
#include <Cfg.h>
#include <fstream>


using namespace std;

/**	\class	Function
	\brief	class representing a Function in a program
*/

class Function{

public:
/**	\brief	Constructor of a function
*/
	Function();

/**	\brief	Destructor of a function
*/
	~Function();

/**	\brief	setter of the head of the function
*/
	void set_head(Line *);

/**	\brief	setter of the end of the function
*/
	void set_end(Line *);

/**	\brief	get the head of the function
*/
	Line* get_head();

/**	\brief	get the first BB of the function
*/

	Basic_block *get_firstBB();

/**	\brief	get the ending Line of the function
*/
	Line* get_end();

/**	\brief	display the function
*/
	void display();

/**	\brief	get number of Lines  of the function
*/
	int size();	

/**	\brief	restitute the function in a file
*/
	void restitution(string const);

/**	\brief creates a new BB with the given start line, end line and branch line and its index, add it to the BB list of this
*/
	void add_BB(Line *, Line*, Line*, int);
/**	\brief	Calculate the basics bolck of the function
*/
	void comput_basic_block();

/**	\brief	get the number of Basic block in the function
*/
	int nbr_BB();

/**	\brief	get the Basic Block at a position in the BB list
*/
	Basic_block *get_BB(int);
	

/**	\brief	comput labels of the function in list
*/

	void comput_label();

/**	\brief	get a specific label of the function
*/
	Label* get_label(int);

/**	\brief	get the size of the list label
*/
	int nbr_label();

/**	\brief	Get the basic block that starts with a given label (operand)
*/
	Basic_block *find_label_BB(OPLabel*);

/**	\brief	Computes the successors and predecessors of each basic block 
*/
	void comput_succ_pred_BB();


	/** \brief computes dominators for each basic block
	 */

	void compute_dom();

	/** \brief computes loops inside the function
	 */
	void compute_loops();


	/** \brief show the loops of the function
	 */
	void display_loops();

	/** \brief computes alive variables for each basic block
	 */
	void compute_live_var();


	/** \brief display alive variables for each basic block 
	 */
	void show_live_var();

	/**	\brief	method to perform some test, usefull for testing methods 
	on basic blocks */
	void test();

private:
	/** \brief true if basic blocks has been computed
	 */
	bool BB_computed;

	/** \brief true if dominators has been computed
	 */

	bool label_computed;

	/** \brief true if all basic block links have been computed
	 */

	bool BB_pred_succ;

	/** \brief true if dominators has been computed
	 */

	bool dom_computed;

	/** \brief first line of the Function */

	Line *_head;

	/** \brief last line of the Function */

	Line *_end;

	/** \brief list of basic blocks of the function
	 */


	list <Basic_block*> _myBB;


	/** \brief list of loops of the function
	 */

	list <Loop*> _myLoop;


	/** \brief list of labels of the function
	 */

	list <Label*> _list_lab;
};

#endif
