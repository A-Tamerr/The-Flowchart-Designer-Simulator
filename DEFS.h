#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	ADD_START,   //Add start statement
	ADD_END,     //Add End  statement
	ADD_VALUE_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_SINGLE_OPERATOR_ASSIGN, //Add single operator assignment statement
	ADD_READ_STAT,   //add read statement
	ADD_WRITE_STAT,   //add write statement
	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)
	EDIT_CONNECTOR,  //Edit connector
	ADD_CONNECTOR, //Add a connector between two statements

	EDIT_STAT,	//Edit a statement
	NEW,	//clear and open a new 
	SELECT,		//Select a statement, a connector

	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)

	COMMENT,  //comment on a statement
	COPY,     // copy a figure
	CUT,      // cut a figure
	PASTE,    // paste a figure

	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	EXIT,		//Exit the application
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to simulatiom mode
	SIM_TOOL,	//A click on an empty place in the simulation tool bar
	RUN,         // run the design
	STEP,         // step by step running
	INTERACTIVE_RUN, // run interactive run
	GENERATE,     // generate flowchart to c++ code
	UNDO,
	REDO,
	ZOOMIN,
	ZOOMOUT

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


#ifndef NULL
#define NULL 0
#endif
#endif
