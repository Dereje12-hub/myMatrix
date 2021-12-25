/*mymatrix.h*/

// 
// << DEREJE GUDETA>>
// U. of Illinois, Chicago
// CS 251: Spring 2020
// Project #02
//

//
// mymatrix
//
// The mymatrix class provides a matrix (2D array) abstraction.
// The size can grow dynamically in both directions (rows and 
// cols).  Also, rows can be "jagged" --- i.e. rows can have 
// different column sizes, and thus the matrix is not necessarily 
// rectangular.  All elements are initialized to the default value
// for the given type T.  Example:
//
//   mymatrix<int>  M;  // 4x4 matrix, initialized to 0
//   
//   M(0, 0) = 123;
//   M(1, 1) = 456;
//   M(2, 2) = 789;
//   M(3, 3) = -99;
//
//   M.growcols(1, 8);  // increase # of cols in row 1 to 8
//
//   for (int r = 0; r < M.numrows(); ++r)
//   {
//      for (int c = 0; c < M.numcols(r); ++c)
//         cout << M(r, c) << " ";
//      cout << endl;
//   }
//
// Output:
//   123 0 0 0
//   0 456 0 0 0 0 0 0
//   0 0 789 0
//   0 0 0 -99
//

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

template<typename T>
class mymatrix
{
private:
  struct ROW
  {
    T*  Cols;     // dynamic array of column elements
    int NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // dynamic array of ROWs
  int  NumRows;  // total # of rows (0..NumRows-1)
 
  
 
  
public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 matrix.  All 
  // elements are initialized to the default value of T.
  //
  
  mymatrix()
  {
    Rows = new ROW[4];  // an array with 4 ROW structs:
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[4];  // an array with 4 elements of type T:
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{};  // default value for type T:
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a matrix with R rows, 
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  mymatrix(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::constructor: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::constructor: # of cols");

   
	Rows = new ROW[R];  // an array with R ROW structs:
    NumRows = R;

    // initialize each row to have C columns
    // 
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[C];  // an array with C elements of type T:
      Rows[r].NumCols = C;

      // initialize the elements to their default value:
      // 
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{};  // default value for type T:
      }
    }//end outer loop
	
  }


  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a matrix that contains a 
  // copy of an existing matrix.  Example: this occurs when passing 
  // mymatrix as a parameter by value
  //
  //   void somefunction(mymatrix<int> M2)  <--- M2 is a copy:
  //   { ... }
  //
  mymatrix(const mymatrix<T>& other)
  {
  
	this->Rows = new ROW[other.NumRows];// an array with other ROW structs:
    this->NumRows = other.NumRows;
   

    // initialize each row to have 4 columns
    // 
    for (int r = 0; r < NumRows; ++r)
    {
      this->Rows[r].Cols = new T[other.Rows[r].NumCols];  // an array with 4 elements of type T:
      this->Rows[r].NumCols = other.Rows[r].NumCols;

      //loop used to copy 
      for (int c = 0; c < other.Rows[r].NumCols; ++c)
      {
        this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
      }
    }//end outer loop

	
  }//end copy constructor


  //
  // numrows
  //
  // Returns the # of rows in the matrix.  The indices for these rows
  // are 0..numrows-1.
  //
  int numrows() const
  {
    
	return this->NumRows; 
  }
  

  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  Note that the # of columns can be different 
  // row-by-row since "jagged" rows are supported --- matrices are not
  // necessarily rectangular.
  //
  int numcols(int r) const
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::numcols: row");

    return Rows[r].NumCols;

  }//end uncoils


  //
  // growcols
  //
  // Grows the # of columns in row r to at least C.  If row r contains 
  // fewer than C columns, then columns are added; the existing elements
  // are retained and new locations are initialized to the default value 
  // for T.  If row r has C or more columns, then all existing columns
  // are retained -- we never reduce the # of columns.
  //
  // Jagged rows are supported, i.e. different rows may have different
  // column capacities -- matrices are not necessarily rectangular.
  //
  void growcols(int r, int C)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::growcols: row");
    if (C < 1)
      throw invalid_argument("mymatrix::growcols: columns");

    
    // conditional statement used to return if C is less or equal 
    // to the number of rows 
    //
    
	if (C <= Rows[r].NumCols)
		return;
	
	
	
	//Okay grow row to have C rows
	//
	
	T* newRow = new T[C];
	
	//loop to copy over the elements from previous row:
	//
	
	for(int i = 0; i < Rows[r].NumCols; ++i)
	{   
		  newRow[i] = Rows[r].Cols[i];  
	}
	
	//loop used to set the default value for the grow elements
	//
	for (int i = Rows[r].NumCols; i < C; ++i)
	{
	    newRow[i] = T{};
	}
	
	//now delete the old row and install the new one 
	//
	
	delete[] Rows[r].Cols;
	Rows[r].Cols = newRow;
	Rows[r].NumCols = C;
	  
 
  }//end of growcols


  //
  // grow
  //
  // Grows the size of the matrix so that it contains at least R rows,
  // and every row contains at least C columns.
  // 
  // If the matrix contains fewer than R rows, then rows are added
  // to the matrix; each new row will have C columns initialized to 
  // the default value of T.  If R <= numrows(), then all existing
  // rows are retained -- we never reduce the # of rows.
  //
  // If any row contains fewer than C columns, then columns are added
  // to increase the # of columns to C; existing values are retained
  // and additional columns are initialized to the default value of T.
  // If C <= numcols(r) for any row r, then all existing columns are
  // retained -- we never reduce the # of columns.
  // 
  void grow(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::grow: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::grow: # of cols");

   
	
	//return if NumRows > R
	//
	if (NumRows > R )
		return;
	
	 
	 //growing matrix contains fewer than R rows
	 //increase the the number of rows to R with default vlaue 0
	 //
	 if (NumRows <= R ) 
	 {
		
	     mymatrix<T> Temp(R,C); //default Matrix
	
	 	
		//copy existing elements to new array
		//
		for (int r = 0; r < NumRows; ++r) {
 		     
 			for (int c = 0; c < Rows[r].NumCols; ++c)
 				{
				
				//condition used to compare and call growcols to grow the row
				// 
				if (Temp.Rows[r].NumCols < Rows[r].NumCols){
				    
					   Temp.growcols(r,Rows[r].NumCols);
					}
					
				    Temp.Rows[r].Cols[c] = T{};//set default 0
		            Temp.Rows[r].Cols[c] = Rows[r].Cols[c];//copy each elements 
		        
	        }
		}//outer for loop

	
	   *this = Temp; //set each Temp row to this	
	
	 } //end outer if condinion

	
} //end grow function



  //
  // size
  //
  // Returns the total # of elements in the matrix.
  //
  int size() const
  {
   
    int Size = 0; //initialize variable size
    
      for (int r = 0; r < this->NumRows; ++r)
		 Size += Rows[r].NumCols;
		 
   return Size;
   
  }


  //
  // at
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M.at(r, c) = ...
  //    cout << M.at(r, c) << endl;
  //
  T& at(int r, int c)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::at: row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::at: col");

	
    return Rows[r].Cols[c];
	
	
  } //end of at


  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M(r, c) = ...
  //    cout << M(r, c) << endl;
  //
  T& operator()(int r, int c)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::(): row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::(): col");


	return this->Rows[r].Cols[c];
  }

  //
  // scalar multiplication
  //
  // Multiplies every element of this matrix by the given scalar value,
  // producing a new matrix that is returned.  "This" matrix is not
  // changed.
  //
  // Example:  M2 = M1 * 2;
  //
  mymatrix<T> operator*(T scalar)
  {
     mymatrix<T> result;

  
	result.Rows = new ROW[this->NumRows];// set a new array with other ROW structs:
    result.NumRows = this->NumRows; 

      //for loop that iterate through matrix and multiply the scalar in to the 
      //new matrix called result
      // 
     for (size_t r = 0; r < this->NumRows; r++)
	 {
		result.Rows[r].NumCols = this->Rows[r].NumCols;
		result.Rows[r].Cols = new T[this->Rows[r].NumCols];
		
		for (size_t c = 0; c < this->Rows[r].NumCols; c++)
	      result.Rows[r].Cols[c] = this->Rows[r].Cols[c] * scalar;
	 
	 }//end outer loop
	 


    return result;
  }//end scalar multiplication function
  


  //
  // matrix multiplication
  //
  // Performs matrix multiplication M1 * M2, where M1 is "this" matrix and
  // M2 is the "other" matrix.  This produces a new matrix, which is returned.
  // "This" matrix is not changed, and neither is the "other" matrix.
  //
  // Example:  M3 = M1 * M2;
  //
  // NOTE: M1 and M2 must be rectangular, if not an exception is thrown.  In
  // addition, the sizes of M1 and M2 must be compatible in the following sense:
  // M1 must be of size RxN and M2 must be of size NxC.  In this case, matrix
  // multiplication can be performed, and the resulting matrix is of size RxC.
  //
  mymatrix<T> operator*(const mymatrix<T>& other)
  {
    mymatrix<T> result;

    //
    // both matrices must be rectangular for this to work:
    //

	
    for(size_t r = 0; r < this->NumRows; r++){
	
    // if this matrix is not rectangular
    // 
       if(this->Rows[0].NumCols != this->Rows[r].NumCols)
         throw runtime_error("mymatrix::*: this not rectangular");
        	
	}
	

	for(size_t r = 0; r < other.NumRows; r++){
	
    // if other matrix is not rectangular
    // 
       if (other.Rows[0].NumCols != other.Rows[r].NumCols)
          throw runtime_error("mymatrix::*: other not rectangular");

     }  

	 
    //
    // Okay, both matrices are rectangular.  Can we multiply?  Only
    // if M1 is R1xN and M2 is NxC2.  This yields a result that is
    // R1xC2.
    // 
    // Example: 3x4 * 4x2 => 3x2
    //



    //
    // TODO
    //
    // if (this matrix's # of columns != other matrix's # of rows)
      if( this->Rows[0].NumCols != other.NumRows )
         throw runtime_error("mymatrix::*: size mismatch");

    //
    // Okay, we can multiply:
    //

    //
    // TODO
    //
    
     // set Matrix size with the NumRows similar with the first matrix X other number of rows 
     // 
	 mymatrix<T> Temp(this->NumRows, other.Rows[0].NumCols); 
	
	
	for (size_t r = 0; r < this->NumRows; r++){  //loop to iterate uptown NumRows 
	    
		for (size_t i = 0; i < other.Rows[0].NumCols; i++){  //loop on other NumCols
		
				for (size_t j = 0; j < other.NumRows; j++){  //loop to iterate upto other.NumRows
        
                      //multiply the desired matrixes save and add it in the same position
                      //
					   Temp.Rows[r].Cols[i] +=  this->Rows[r].Cols[j] * other.Rows[j].Cols[i];
                                  
				}//end inner for lop	
			
			}//end middle for loop
 
		}//end outer for loop
	
	*this = Temp;
    result = Temp;

    return result;
  }//end matrix multiplication


  //
  // _output
  //
  // Outputs the contents of the matrix; for debugging purposes.
  //
  void _output()
  {
    for (int r = 0; r < this->NumRows; ++r)
    {
      for (int c = 0; c < this->Rows[r].NumCols; ++c)
      {
        cout << this->Rows[r].Cols[c] << " ";
      }
      cout << endl;
    }
  }//end of _output function

};
