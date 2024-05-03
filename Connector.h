#ifndef CONNECTOR_H
#define CONNECTOR_H

#include<fstream>
#include "GUI/Output.h"
#include "GUI/UI_Info.h"
class Statement;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement* SrcStat;	//The source statement of the connector
	Statement* DstStat;	//The destination statement of the connector
	int SrcID;			//the ID of source statement
	int DstID;			// the ID of destination statement
	int ConnType;		//the connection type -- it's always equal 0 except Condition statement = 1
	bool Selected;
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
public:
	Connector(Statement* Src, Statement* Dst);

	void SetSelected(bool s);
	bool IsSelected() const;

	void		setSrcStat(Statement* Src);
	Statement* getSrcStat();
	void		setDstStat(Statement* Dst);
	Statement* getDstStat();

	void setSrcID(int ID);
	int getSrsID();
	void setDstID(int ID);
	int getDstID();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void setConnType(int C);
	int getConnType();

	void Draw(Output* pOut) const;

	bool IsOnConnect(Point P);
	void Save(ofstream& Outfile);
	void Load(ifstream& Infile);
};

#endif