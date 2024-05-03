#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Statements/Statement.h"
class Input;
class Output;

// The Maestro
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCount = 200 };						// Max no of statements/connectors in a single flowchart

private:
	Point P;
		
	int StatCount;									// number of statements
	int StatID;										// stat ID
	int ConnCount;									// number of connectors
	int VarCount;									// number of variables

	Statement* StatList[MaxCount];					// list of all statements (pointers array)
	Connector* ConnList[MaxCount];					// list of all connectors (pointers array)
	Variable* VarList[MaxCount];					// list of all variables (pointers array)
	
	Statement* pSelectedStat;						// a pointer to the last selected stat
	Connector* pSelectedConn;						// a pointer to the last selected conn
	
	Statement* pCopied;								// ptr to copied item
	Statement* pCut;								// ptr to cut item

	int CopyType;
	bool editedDesign;								//boolean tells if the design is edited or not
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	string SaveArr[10000];
	int GL, plus;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Actions Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction();
	void ExecuteAction(ActionType);				    //Creates an action and executes it

	// -- Statements/Connector Management Functions
	int GetStatCount();							    //returns the number of statements in the statements list
	int GetConnCount();							    //returns the number of connectors in the connectors list
	int GetVarCount();							    //returns the number of variables in the variables list


	void AddStatement(Statement* pStat);		    //Adds a new Statement to the Flowchart
	Statement* GetStatement(Point P) const;		    //search for a statement where point P belongs
	void DeleteStat(Statement* Stat);			    //delete a statement from the statements list

	void SetConnector(Connector* pConn);		    //Adds a new Connector to the Flowchart
	Connector* GetConnector(Point P) const;		    //search for a Connector where point P belongs
	void EditConnectors(Statement* Stat);		    //edit the input connectors to a statement
	void DeleteConn(Connector* Conn);			    //delete a connector from the connectors list

	Variable* AddVariable(Variable* V);
	Variable* GetVariable(int j) const;
	void deleteVariable(Variable* V);
	void InitializeVar();

	Statement* GetSelectedStatement() const;	    //Returns the selected Statement
	void SetSelectedStatement(Statement* pStat);    //Set the Statement selected by the user

	Connector* GetSelectedSConnector() const;	    //Returns the selected Connector
	void SetSelectedConnector(Connector* pConn);    //Set the Connector selected by the user

	Statement* GetStatList(int j);				    //gets a statement from the statements list
	Connector* GetConnList(int j);				    //gets a connector from the connectorslist



	void SetCopied(Statement* P);				    //set the statement copied or cut by the user
	Statement* GetCopied();						    //get the copied or cut statement
	 //added by sama

	Statement* GetCut() const;
	void SetCut(Statement* pStat);

	void SetCopyType(int x);					    //set the copy type < 1 for copy > <2 for cut>
	int GetCopyType();							    //get the copy type

	void UnSelect();							    //unselect any selected object
	Point getPoint();							    //get the point where the user clicked

	bool onBars(Point P);						    //check if the clicked point is on any of tool bars or not
	bool onObject(Point P);						    //check if the clicked point is on any drawn object or not
	void onExit();

	void setEditedDesign(bool E);
	bool getEditedDesign();
	void UndoRedo(int n = 0);
	void LoadModify();							    //modify variables & connectors with statements after the load operation

	void SwitchToSim();	//switch to simulation mode

	// -- Interface Functions
	Input* GetInput() const;					    // ptr to input
	Output* GetOutput() const;				        // ptr to output
	void UpdateInterface() const;				    // updates the drawing UI

	Connector** GetConnList();
	Statement** GetStatList();


	void LoadChart(ifstream& Infile);

};

#endif