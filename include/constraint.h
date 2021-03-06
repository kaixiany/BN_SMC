#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <boost/tokenizer.hpp>
#include <math.h>
#include <boost/math/distributions/chi_squared.hpp>

#include "data.h"


using namespace std;
class CONSTRAINT
{
public:
    CONSTRAINT();
    CONSTRAINT(double);
    virtual ~CONSTRAINT();
    int Get_correspondingNode()
    {
        return _correspondingNode;
    }
    void Set_correspondingNode(int val)
    {
        _correspondingNode = val;
    }
    double Get_cutoff()
    {
        return _cutoff;
    }
    void Set_cutoff(double val)
    {
        _cutoff = val;

    }
//    int Get_dependency()
//    {
//        return _dependency;
//    }
    vector< int >& Get_dependentNode()
    {
        return _dependentNode;
    }
    int Get_dependentNode(int id)
    {
        return _dependentNode[id];
    }
    void Set_dependentNode(vector< int >& val)
    {
        _dependentNode = val;
    }

    vector< double >& Get_testScore()
    {
        return _testScore;
    }
    double Get_testScore(int id)
    {
        return _testScore[id];
    }

     vector< double >& Get_orderedTestScore()
    {
        return _orderedTestScore;
    }
    double Get_orderedTestScore(int id)
    {
        return _orderedTestScore[id];
    }

    void Set_testScore(vector< double >& val)
    {
        _testScore = val;
    }

    //utility

    //void clear_rank(int);
    //@func clear_rank: used to set the corresponding testscore to 0, so the corresponding node will not be sampled again.
    //@param int: the node ID which we want to clear the test score.

    //void ClearRank(int,bool);
    // int: nodeId or the position.
    // bool: whether a search needed, true means directly clear the index, false means need a search

    void MIT(DATA&);
    //@func MIT: mutual information test for dependency
    //@param DATA: the data set
    //@param int*: the information file, contains information about how many categories of the nodes.
//    protected:
private:
    int _correspondingNode;// each node gets it unique constraint class.
    double _cutoff;// the cut off p-value to determine whether the node are dependent with the corresponding node.
    //int _dependency;// number of dependencies, which is determined by the MI test.
    vector <int> _dependentNode;// The id of the nodes tested to be dependent with this node with order of their ordered test score.
    vector< double > _testScore;// the p-value of the mutual information test.
    vector <double> _orderedTestScore; // the p-value of the dependent nodes ordered from smallest to largest.
    // the i-th(the corresponding Node id) entry is 0, which means the node will not be sampled.
    int _IndexSearch(int);
    void _InsertOrderedScore(int,double);

};

#endif // CONSTRAINT_H
