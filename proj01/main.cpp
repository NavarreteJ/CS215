#include "stringArr.hpp"
#include <iostream>
using namespace std;

void TestEmptyArray(StringArr a) {
   cout << "**** TESTING EMPTY ARRAY ****\n";
   cout << "Printing: should print nothing\n";
   a.print(); 
   cout << "Printing sorted version: should print nothing\n";
   a.printSorted(); 
   cout << "Printing shortest and longest strings: should print nothing\n";
   cout << "Shortest: " << a.shortest() << endl;
   cout << "Longest: " << a.longest() << endl;
   string mySequence[MAXSIZE];
   int seqLength = a.longestAscending(mySequence);
   cout << "Length of longest ascending sequence (should be 0): " << seqLength << endl;

   for (int i = 0; i < seqLength; i++) {
     cout << mySequence[i] << endl;
   }
   seqLength = a.longestDescending(mySequence);
   cout << "Length of longest descending (should be 0): " << seqLength << endl;
   for (int i = 0; i < seqLength; i++) {
     cout << mySequence[i] << endl;
   }

}

int main () {
    StringArr arr1;
    StringArr arr2("strings.txt");

    TestEmptyArray(arr1);
    TestEmptyArray(arr2);
    // more test code goes here 

    return 0;
}
