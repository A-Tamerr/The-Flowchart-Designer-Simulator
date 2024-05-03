#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{

	SrcStat = Src;
	DstStat = Dst;
	ConnType = 0;
	Selected = false;
}




void Connector::setSrcStat(Statement* Src)
{
	SrcStat = Src;

}

Statement* Connector::getSrcStat()
{
	return SrcStat;
}

void Connector::setDstStat(Statement* Dst)
{
	DstStat = Dst;

}

Statement* Connector::getDstStat()
{
	return DstStat;
}

void Connector::setStartPoint(Point P)
{
	Start = P;
}

Point Connector::getStartPoint()
{
	return Start;
}

void Connector::setEndPoint(Point P)
{
	End = P;
}

Point Connector::getEndPoint()
{
	return End;
}


void Connector::Draw(Output* pOut) const
{
	///TODO: Call output to draw a connector here
	pOut->DrawConnector(Start, End, Selected);
}

void Connector::SetSelected(bool s)
{
	Selected = s;
}

bool Connector::IsSelected() const
{
	return Selected;
}



void Connector::setSrcID(int ID)
{
	SrcID = ID;
}

int Connector::getSrsID()
{
	return SrcID;
}

void Connector::setDstID(int ID)
{
	DstID = ID;
}


int Connector::getDstID()
{
	return DstID;
}
void Connector::setConnType(int C)
{
	ConnType = C;
}

int Connector::getConnType()
{
	return ConnType;
}
bool Connector::IsOnConnect(Point P)
{
	if (End.y > Start.y)
	{
		if (P.x == Start.x && P.y >= Start.y && P.y <= Start.y + 10)
			return true;
		if (P.x >= Start.x && P.x <= End.x && P.y == Start.y + 10)
			return true;
		if (P.x >= End.x && P.x <= Start.x && P.y == Start.y + 10)
			return true;
		if (P.x == End.x && P.y >= Start.y + 10 && P.y <= End.y)
			return true;
		if (P.x >= End.x && P.x <= End.x + 10 && P.y <= End.y && P.y >= End.y - 10)
			return true;
		if (P.x <= End.x && P.x >= End.x - 10 && P.y <= End.y && P.y >= End.y - 10)
			return true;

		return false;
	}
	else if (End.y < Start.y)
	{
		if (End.x > Start.x)
		{
			if (P.x == Start.x && P.y >= Start.y && P.y <= Start.y + 10)
				return true;
			if (P.x <= Start.x && P.x >= Start.x - 150 && P.y == Start.y + 10)
				return true;
			if (P.x == Start.x - 150 && P.y <= Start.y + 10 && P.y >= End.y)
				return true;
			if (P.x >= Start.x - 150 && P.x <= End.x && P.y == End.y)
				return true;
			if (P.x <= End.x && P.x >= End.x - 10 && P.y >= End.y && P.y <= End.y + 10)
				return true;
			if (P.x <= End.x && P.x >= End.x - 10 && P.y <= End.y && P.y >= End.y - 10)
				return true;

			return false;
		}
		else
		{
			if (P.x == Start.x && P.y >= Start.y && P.y <= Start.y + 10)
				return true;
			if (P.x >= Start.x && P.x <= Start.x + 150 && P.y == Start.y + 10)
				return true;
			if (P.x == Start.x + 150 && P.y <= Start.y + 10 && P.y >= End.y)
				return true;
			if (P.x <= Start.x + 150 && P.x >= End.x && P.y == End.y)
				return true;
			if (P.x >= End.x && P.x <= End.x + 10 && P.y >= End.y && P.y <= End.y + 10)
				return true;
			if (P.x >= End.x && P.x <= End.x + 10 && P.y <= End.y && P.y >= End.y - 10)
				return true;

			return false;
		}
	}
	else
	{
		if (End.x > Start.x)
		{
			if (P.x >= Start.x && P.x <= End.x && P.y == Start.y)
				return true;
			if (P.x <= End.x && P.x >= End.x - 10 && P.y >= End.y && P.y <= End.y + 10)
				return true;
			if (P.x <= End.x && P.x >= End.x - 10 && P.y <= End.y && P.y >= End.y - 10)
				return true;

			return false;
		}
		else
		{



			if (P.x <= Start.x && P.x >= End.x && P.y == Start.y)
				return true;
			if (P.x >= End.x && P.x <= End.x + 10 && P.y >= End.y && P.y <= End.y + 10)
				return true;
			if (P.x >= End.x && P.x <= End.x + 10 && P.y <= End.y && P.y >= End.y - 10)
				return true;

			return false;

		}
	}
}

void Connector::Save(ofstream& Outfile)
{
	Outfile << SrcID << "\t" << DstID << "\t" << ConnType << endl;
}

void Connector::Load(ifstream& Infile)
{
	Infile >> SrcID >> DstID >> ConnType;
}