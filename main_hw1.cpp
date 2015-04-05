#include <iostream>
using namespace std;
#include "HugeUInteger.h" //< CORRECT this file name

int main() //< Do NOT modified this functiuon
{
  unsigned int seed;
  cout << "Enter seed: ";
  cin >> seed;
  srand( seed );

  unsigned int length1, length2, length3;
  cout << "Enter the lengths of three huge integers: ";
  cin >> length1 >> length2 >> length3;
  
  HugeUInteger n1, n2, n3;
  n1.random( length1 );
  cout << "N1: "; n1.print(); cout << endl;
  n2.random( length2 );
  cout << "N2: "; n2.print(); cout << endl;
  n3.random( length3 );
  cout << "N3: "; n3.print(); cout << endl;

  cout << "N1 + N3 = "; n1.add(n3);
  n1.print(); cout << endl;

  cout << "N2 - N3 = "; n2.subtract(n3);
  n2.print(); cout << endl;

  
  system("pause");
  return 0;
}