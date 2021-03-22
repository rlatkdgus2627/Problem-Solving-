//--------------------------------------------------------------------
//	written by : 2020112036 김상현
//                                                          listarr.h
//
//  Class declaration for the array implementation of the List ADT
//	2021-03-19
//--------------------------------------------------------------------
// #pragma warning( disable : 4290 )

#include <stdexcept>
#include <iostream>

using namespace std;

const int defMaxListSize = 10;   // Default maximum list size

typedef char DataType;

class List
{
public:

	// Constructor
	List(int maxNumber = defMaxListSize);

	// Destructor
	~List();

	// List manipulation operations
	void insert(const DataType& newDataItem)    // Insert after cursor
		throw (logic_error);
	void remove()                                 // Remove data item
		throw (logic_error);
	void replace(const DataType& newDataItem)   // Replace data item
		throw (logic_error);
	void clear();                                 // Clear list

	// List status operations
	bool isEmpty() const;                    // List is empty
	bool isFull() const;                     // List is full

	// List iteration operations
	bool gotoBeginning()                     // Go to beginning
		throw (logic_error);
	bool gotoEnd()                           // Go to end
		throw (logic_error);
	bool gotoNext()                          // Go to next data item
		throw (logic_error);
	bool gotoPrior()                         // Go to prior data item
		throw (logic_error);
	DataType getCursor() const
		throw (logic_error);                // Return data item

	// Output the list structure -- used in testing/debugging
	void showStructure() const;
////////////////////////////////////////////////////////////////////////////
	//in-lab
	void moveToNth(int n)
		throw (logic_error);
	bool find(const DataType& searchDataItem)
		throw (logic_error);

private:
	// Data members
	int maxSize,
		size,             // Actual number of data item in the list
		cursor;           // Cursor array index
	DataType* dataItems;  // Array containing the list data item
};

