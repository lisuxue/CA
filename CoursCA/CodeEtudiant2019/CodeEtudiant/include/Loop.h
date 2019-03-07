#ifndef _Loop_H
#define _Loop_H

/**	\file	Loop.h
	\brief	Function class
	\author	Heydemann
*/


#include <Line.h>
#include <Basic_block.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Label.h>
#include <Enum_type.h>
#include <list>
#include <Cfg.h>
#include <fstream>



using namespace std;

/**	\class	Loop
	\brief	class representing a Loop in a function
*/

class Loop{

public:
/**	\brief	Constructor of a loop
*/
  Loop(Basic_block*, Basic_block*);

/**	\brief	Destructor of a loop
*/
  ~Loop();

/**	\brief	setter of the header of the loop
*/
  void set_header(Basic_block *);

/**	\brief	setter of the latch of the loop
*/
  void set_latch(Basic_block *);

/**	\brief	get the head of the loop
*/
  Basic_block* get_header();

/**	\brief	get the latch of the loop
*/
  Basic_block* get_latch();

/**	\brief	display the loop
*/
  void display();


/**	\brief	get the number of Basic block in the loop
*/
  int nbr_BB();


/**	\brief	compute the set of BB composing the loop 
*/
  void compute_in_loop_BB();



private:
	/** \brief basic block header of the loop 
	 */ 
	Basic_block *header_bb;

	/** \brief BB where the back edge is from  
	 */ 
	Basic_block *latch_bb;

	/** \brief list of basic blocks of the loop 
	 */

	list <Basic_block*> _myBB;

};

#endif
