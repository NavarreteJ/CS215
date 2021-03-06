/* Implementation of the StringArr class defined in StringArr.hpp */
#include <fstream>
#include <iostream>
#include "stringArr.hpp"
using namespace std;

/* StringArr's default constructor
 * Should initialize its private member variables appropriately
 */
StringArr::StringArr() {
    length = 0;
}

/* Alternate constructor: when passed a filename,
 * you should use its contents to populate the StringArr object
 */
StringArr::StringArr(string filename) {
    ifstream inFile(filename);
    string s;
    length = 0;
    while (inFile >> s) {
      arr[length] = s;
      length++;
    }
    inFile.close();
}

/* Populate your string array by reading the named file
 * Overwrite array contents if they already exist
 * Return true if you were able to read the file, false otherwise
 */
bool StringArr::readFromFile(string filename) {
    length = 0;
    ifstream inFile(filename);
    // Just a check to see if file was unable to be read
    if (inFile.fail() == true) {
      return false;
    }
    string s;
    while (inFile >> s) {
      arr[length] = s;
      length++;
    }
    inFile.close();
    return true;
}

/* Print all strings in the array, one per line,
 * in the original order you read from the file
 */
void StringArr::print() {
  for (int i = 0; i < length; i++) {
      cout << arr[i] << endl;
  }
}

/* Return the shortest string in the array
 * Break ties however you want
 * For an empty array, return the empty string ("")
 */

string StringArr::shortest() {
  if (length == 0) {
    return "";
  }
  
  int shortest = 0; // index of shortest value
  for (int i = 0; i < length; i++) {
    // Comparing value at loop index to current shortest index
    if (arr[i].length() < arr[shortest].length()) {
      shortest = i;
    }
  }
  return arr[shortest];
}

// Returns the longest string in the array
string StringArr::longest() {
  int longest = 0;
  for (int i = 0; i < length; i++) {
    // Comparing calue at loop index to current longest index
    if (arr[i].length() > arr[longest].length()) {
      longest = i;
    }
  }
  return arr[longest];
}

/* Print all strings in the array, one per line, in
 * alphabetically sorted order (using > and < operators).
 * DON'T CHANGE THE ORIGINAL ARRAY!!
 */
void StringArr::printSorted() {
  string temparray[length];
  int counter = 0;
  // Giving temparray the values in arr
  while (counter < length) {
    temparray[counter] = arr[counter];
    counter++;
  }
  
  // Sorting array
  for (int i = 0; i < length; i++) {
    int j = i;
    while (j > 0 and temparray[j] < temparray[j-1]) {
      // Swapping Values on Index based on alphabet
      string s = temparray[j];
      temparray[j] = temparray[j-1];
      temparray[j-1] = s;
      j--;
    }
  }
  
  // Printing sorted array
  for (int g = 0; g < length; g++) {
    cout << temparray[g] << endl;
  }
}

/* Populate the seq[] array with the longest ascending sequence of consecutive
 * strings in the file. For example, if the strings are:
 * alpha beta zeta eta theta mu
 * You would populate the array with [alpha, beta, theta]
 * You can break ties however you like
 * You can assume that seq[] has enough space for the longest sequence
 * Return the length of the sequence (3 in this case)
 */
int StringArr::longestAscending(string seq[]) {
  // Loop handles cases where arr length is 0
  if(length == 0)
    return 0;
  int currentsequence = 0;
  int longestsequence = 0;
  int longestsequenceindex;
  
  for (int i = 0; i < length - 1; i++) {
    currentsequence++;
    
    // When no longer consecutivily ascending
    if(arr[i] >= arr[i+1]) {
	if (currentsequence > longestsequence) {
	  longestsequence = currentsequence;
	  longestsequenceindex = i - longestsequence + 1;
      }
      currentsequence = 0;
    }
  }
  // Add to currentsequence because currentsequence starts at zero and checks for sequences that end due to array length
  currentsequence++;
  if (currentsequence > longestsequence) {
    longestsequence = currentsequence;
    longestsequenceindex = length - longestsequence;
  }
  
  //  Setting seq[] to the longest sequence, if there are multiple of the same length, it will set it to the first sequence
  for (int j = 0; j < longestsequence; j++) {
      seq[j] = arr[longestsequenceindex + j];
  }
  
  return longestsequence;
}

/* Populate the seq[] array with the longest ascending sequence of consecutive
 * strings in the file. For example, if the strings are:
 * alpha beta zeta eta theta mu
 * You would populate the array with either [zeta, eta] or [theta, mu]
 * You can break ties however you like
 * You can assume that seq[] has enough space for the longest sequence
 * Return the length of the sequence (2 in this case)
 */
int StringArr::longestDescending(string seq[]) {
  if(length == 0)
    return 0;
  
  int currentsequence = 0;
  int longestsequence = 0;
  int longestsequenceindex;

  for (int i = 0; i < length - 1; i++) {
    currentsequence++;
    // Loops till no longer consecutive
    if(arr[i] <= arr[i+1]) {
        if (currentsequence > longestsequence) {
	  longestsequence = currentsequence;
	  longestsequenceindex = i - longestsequence + 1;
      }
      currentsequence = 0;
    }
  }
  // Check for sequences that end due to length of array
  currentsequence++;
  if (currentsequence > longestsequence) {
    longestsequence = currentsequence;
    longestsequenceindex = length - longestsequence;
  }
  // Setting seq[] to the longest sequence in arr, if there are multiple of the same length, it will set it to the first sequence
  for (int j = 0; j < longestsequence; j++) {
      seq[j] = arr[longestsequenceindex + j];
  }

  return longestsequence;
}
