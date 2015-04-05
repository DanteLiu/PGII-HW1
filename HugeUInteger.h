#ifndef HUGE_UINTEGER_H
#define HUGE_UINTEGER_H

#define MAX 1000 //< max length of huge integer
#include <vector>

using namespace std;

class HugeUInteger 
{
public:
  HugeUInteger (); //< default constructor
  HugeUInteger (HugeUInteger &in); //< copy constructor
  void random( unsigned int size ); //< randomly generate an integer
  void add(HugeUInteger &add); //< add a number 
  void subtract(HugeUInteger &sub); //< subtract a number 
                                    //< (Use ZERO to replace negative result)
  void print(); //< print out the huge unsigned integer
private:
///add something to stores this huge integer (dynamic array or std::vector or …)
///add some helper functions
	
	vector<int> integers;
	unsigned int _size;
	bool isbigger;
};

#endif