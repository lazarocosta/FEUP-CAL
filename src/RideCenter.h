#ifndef SRC_RIDECENTER_H_
#define SRC_RIDECENTER_H_

#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "ReaderFiles.h"
#include "User.h"
#include "Interface.h"
#include "Adress.h"


class RideCenter{
	Graph<Node,Road> graph;
	vector<Relation> rels;
	vector<Node> nodes;
	vector<Road> roads;
public:
	RideCenter(ReaderFiles &r);
	void printGraph() const;
	vector<User> in_elipse(User U,Interface I);

	//VAI PARA PRIVATE MUDAR DEPOIS
	void centerGraph(Node T);
	vector<Vertex<Node,Road> *> getPath(const Node &Sourc,const Node &Dest, double &dist) ;
	//
	Node FindNode(unsigned long id);
	vector< Vertex<Node,Road> > BestPath(const Node &Sourc, const Node & Dest,const vector <Node> InterestPoints, unsigned int passenger_capacity);
	Adress* getAdress(Node N)const;


};



#endif
