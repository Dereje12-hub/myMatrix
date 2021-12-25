



#include <cmath>
#include "mymatrix.h"




bool case_test1()
{
	mymatrix<int> M;   //crrates 4x4 matrix
	

  int R = 4;
  //int C = 4;

  if (M.numrows() == R)
		return true;
	else 
		return false;
	
}



bool case_test2()
{
	mymatrix<int>  M(8, 10);

  int R = 8;
  int C = 10;
	
	if (M.size() == R*C)
		return true;
	else 
		return false;
	
}




bool case_test3()
{
	mymatrix<int> M;   //crrates 4x4 matrix
	M.grow(4, 7);   // grow row 
	
	if (M.size() == 20)
		return true;
	else 
		return false;
	
}



bool case_test4()
{
	mymatrix<int> M;   //crrates 4x4 matrix
	M.grow(5, 7);   // grow row 
	
	if (M.size() == 20)
		return true;
	else 
		return false;
	
	return true;
	
}



bool case_test5()
{
	mymatrix<int> M;   //crrates 4x4 matrix
	int R = 4;
	int C = 4;
	
	if (M.size() == 20)
		return true;
	else 
		return false;
	
	for (int r = 0; r < R; ++r){
    for (int c = 0; c < C; ++c)
      if (M(r, c) != 0)
		  return false;
	}
return true;
}



bool case_test6()
{
	mymatrix<int> M;   //crrates 4x4 matrix
	

  int R = 4;
  int C = 4;

  if (M.numrows() != R)
	  return false;

  for (int r = 0; r < R; ++r)
  {
	  if(M.numcols(r) != C)
		return false;
	  }

  if(M.size() != (R*C))
	  return false;

  
  // all elements should be 0:
  
  for (int r = 0; r < R; ++r){
    for (int c = 0; c < C; ++c)
      if (M(r, c) != 0)
		  return false;
	
	}
		
	return true;
	
}




bool case_test7()
{
	mymatrix<int>  M(11, 5);

  int R = 11;
  int C = 5;

  if (M.numrows() != R)
	  return false;

  for (int r = 0; r < R; ++r)
  {
	  if(M.numcols(r) != C)
		return false;
	  }

  if(M.size() != (R*C))
	  return false;

  //
  // all elements should be 0:
  //
  for (int r = 0; r < R; ++r){
    for (int c = 0; c < C; ++c)
      if (M(r, c) != 0)
		  return false;
	
	}
		
	return true;
	
}




bool case_test8()
{
 mymatrix<int>  M;

  int R = 4;
  int C = 4;

  if(M.numrows() != R)
	  return false;

  for (int r = 0; r < R; ++r){
    if(M.numcols(r) != C)
		return false;
  }
  if (M.size() != (R * C))
	  return false;

  //
  // all elements should be 0:
  //
  for (int r = 0; r < R; ++r){
    for (int c = 0; c < C; ++c){
      if (M(r, c) != 0)
		  return false;
	}
  }

  //
  //  update the values:  1, 2, 3, ...
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      M(r, c) = -5 * ((r * C) + c + 1);

  //
  //  values were stored properly:
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != (-5*((r * C) + c + 1)))
        return true;
  //
  // repeat with .at()...
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      M.at(r,c) = -9 * ((r * C) + c + 1);

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M.at(r,c) != (-9*((r * C) + c + 1)))
		return false;

	return true;
}






bool case_test9()
{
mymatrix<int>  M(7, 9);

  int R = 7;
  int C = 9;

  if (M.numrows() != R)
	  return false;

  for (int r = 0; r < R; ++r)
    if(M.numcols(r) != C)
		return false;

  if (M.size() != (R * C))
	  return false;

  //
  // all elements should be 0:
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != 0)
		  return false;

 

  //
  // let's grow a couple columns to be different sizes, make sure
  // it works:
  //
  M.growcols(0, 20);
  M.growcols(4, 15);

  if(M.numrows() != 7)
	  return false;
  if(M.numcols(0) != 20)
	  return false;
  if(M.numcols(1) != 9)
	  return false;
  if(M.numcols(2) != 9)
	  return false;
  if(M.numcols(3) != 9)
	  return false;
  if(M.numcols(4) != 15)
	  return false;
  if(M.numcols(5) != 9)
	  return false;
  if(M.numcols(6) != 9)
	  return false;
  if(M.size() != 80)
	 return false; 

  // the original RxC matrix should still be 5, 10, 15, ...
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != ((5 * r * C) + c + 1))
            return false;
 

  //
  // now grow another column:
  //
  M.growcols(6, 25);

  if(M.numcols(6) != 25)
	  return false;
	  
  if(M.size() != 96)
	  return false;

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != ((5 * r * C) + c + 1));

  for (int c = C; c < 25; ++c)
    if(M(6, c) != 0)
		return false;

  //
  // now let's store some values in those new columns, 
  // and make sure they are actually stored:
  //
  M.at(0, 19) = 1234;
  M.at(4, 14) = 5678;
  M.at(6, 24) = 9101112;

  if(M(0, 19) != 1234)
	  return false;
  if(M(4, 14) != 5678)
	  return false;
  if(M(6, 24) != 9101112)
	  return false;

	return true;
}




bool case_test10()
{
mymatrix<int>  M(15, 7);

  int R = 15;
  int C = 7;

  if(M.numrows() != R);

  for (int r = 0; r < R; ++r)
    if(M.numcols(r) != C)
		return false;

  if(M.size() != (R * C))
	  return false;

  //
  // all elements should be 0:
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != 0)
		return false;

  //
  // now let's update the values:
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      M(r, c) = (r * C) + (2*c);

  //
  // now confirm the values were stored properly:
  //
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != ((r * C) + (2 * c)))
		  return false;

  //
  // let's grow the matrix:
  //
  M.grow(19, 12);

  int newR = 19;
  int newC = 12;

  if(M.numrows() != newR)
	  return false;

  for (int r = 0; r < newR; ++r)
    if(M.numcols(r) != newC)
		return false;
  
  if(M.size() != (newR*newC))
	  return false;

  // the original matrix should still have original values:
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != ((r * C) + (2 * c)))
		  return false;

  // the new values should be 0:
  for (int r = R; r < newR; ++r)
    for (int c = C; c < newC; ++c)
      if(M(r, c) != 0)
		  return false;

  //
  // now let's store some values in these new rows and cols:
  //
  for (int r = R; r < newR; ++r)
    for (int c = C; c < newC; ++c)
      M(r, c) = (9 * r * C) + c + 1;

  // the original matrix should still be there:
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if(M(r, c) != ((r * C) + (2 * c)))
		  return false;

  // the new elements have the new values:
  for (int r = R; r < newR; ++r)
    for (int c = C; c < newC; ++c)
      if(M(r, c) != ((9 * r * C) + c + 1))
		  return false;
return true;
}


bool case_test11()
{
  mymatrix<int>  M;  // 4x4
  mymatrix<int>  M2;

  for (int r = 0; r < 4; ++r)
    for (int c = 0; c < 4; ++c)
      M(r, c) = (r * 40) + (10 * (c + 1));

  M2 = M * (-12);

  if(M2.numrows() != 4)
	  return false;
  if(M2.numcols(0) != 4)
	  return false;
  if(M2.numcols(1) != 4)
	  return false;
  if(M2.numcols(2) != 4)
	  return false;
  if(M2.numcols(3) != 4)
	  return false;
  if(M2.size() != 16)
	  return false;

  for (int r = 0; r < 4; ++r)
    for (int c = 0; c < 4; ++c)
      if(M2(r, c) == (-12 * ((r * 40) + (10 * (c + 1)))));

	
	return true;
}



bool case_test12()
{
  mymatrix<double>  M;  // 4x4
  mymatrix<double>  M2;
  for (int r = 0; r < 4; ++r)
    for (int c = 0; c < 4; ++c)
      M(r, c) = (r * 40) + (10 * (c + 1));

  M2 = M * (0.5);

  if(M2.numrows() != 4)
	  return false;
  if(M2.numcols(0) != 4)
	  return false;
  if(M2.numcols(1) != 4)
	  return false;
  if(M2.numcols(2) != 4)
	  return false;
  if(M2.numcols(3) != 4)
	  return false;
  if(M2.size() != 16)
	  return false;

  for (int r = 0; r < 4; ++r)
    for (int c = 0; c < 4; ++c)
      if(M2(r, c) == (0.5 * ((r * 40) + (10 * (c + 1)))));

	
	return true;
}

  bool case_test13()
{
  mymatrix<int> M1(2, 3);
  mymatrix<int> M2(3, 3);

  M1(0, 0) = 1;
  M1(0, 1) = 3;
  M1(0, 2) = 5;
  M1(1, 0) = 2;
  M1(1, 1) = 4;
  M1(1, 2) = 6;

  M2(0, 0) = 1;
  M2(0, 1) = 2;
  M2(0, 2) = 3;
  M2(1, 0) = 4;
  M2(1, 1) = 5;
  M2(1, 2) = 6;
  M2(2, 0) = 7;
  M2(2, 1) = 8;
  M2(2, 2) = 9;

  mymatrix<int> M3;

  M3 = M1 * M2;

  if(M3.numrows() != 2)
	  return false;
  if(M3.numcols(0) != 3)
	  return false;
  if(M3.numcols(1) != 3)
	  return false;
  if(M3.size() != 6)
	  return false;

  if(M3(0, 0) != 48)
	  return false;
  if(M3(0, 1) != 57)
	  return false;
  if(M3(0, 2) != 66)
	  return false;
  if(M3(1, 0) != 60)
	  return false;
  if(M3(1, 1) != 72)
	  return false;
  if(M3(1, 2) != 84)
	  return false;
	  
	return true;
}













int main() {
	
	mymatrix<int> M;
	
	int passed = 0;
	int failed = 0;
	
	
	
 	M(0, 0) = 10;
    M(1, 1) = 20;
    M(2, 2) = 30;
    M(3, 3) = -40;
	
	M.growcols(0,10);
	M.growcols(2,18);
	M.grow(5,5);
	cout << endl;
	cout << endl;
	
	
	cout << " M5 print " << endl;
	mymatrix<int> M5(M);   //crrates 4x4 matrix
	
	M5 = M * 2;
	
	M5._output();
	
//Test1
//

	

    mymatrix<int> M1;   //crrates 4x4 matrix
    
	cout << endl;
	cout << endl;
	if (case_test1())
	{
		
		cout << "\nSize_test1 passed"<< endl;
		passed++;
	}
	else{
		cout<< "size_test1 failed"<<endl;
		failed++;
	}
	cout << endl;
	M1._output();
	cout << endl;
	
	
	
	

// //Test 2 
//   mymatrix<int>  M2(8, 10);

 
// 	if (size_test2())
// 	{
// 		cout << "\nSize_test2 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test2 failed"<<endl;
// 		failed++;
// 	}
	
//     cout << endl;
// 	M2._output();


// 	cout << endl;
// 	cout << endl;
// 	cout << endl;
	
	

	
// //Test 3
//   int R = 4;
//   int C = 4;
// mymatrix<int> M3(R,C);   //crrates 4x4 matrix
	
  	
	
// if (size_test3())
// 	{
// 		cout << "\nSize_test3 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test3 failed"<<endl;
// 		failed++;
// 	}
// 	cout << endl;
// 	M3._output();
// 	cout << endl;
// 	cout << endl;
// 	cout << endl;
	
	
// //Test 4
// mymatrix<int>  M4(11, 5);

// if (size_test4())
// 	{
// 		cout << "\nSize_test4 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test4 failed"<<endl;
// 		failed++;
// 	}
// 	cout << endl;
// 	M4._output();
// 	cout << endl;
// 	cout << endl;
// 	cout << endl;
	
	
	
// // 	//Test 5
//  mymatrix<int>  M5(4, 4);
// //   int R = 4;
// //   int C = 4;
	
// if (size_test5())
// 	{
// 		cout << "\nSize_test5 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test5 failed"<<endl;
// 		failed++;
// 	}
// 	cout << endl;
// 	M5._output();
// 	cout << endl;
// 	cout << endl;
// 	cout << endl;
	
	
	

	
	
// //Test 10
//  mymatrix<int>  M10(4, 4);
// //   int R = 4;
// //   int C = 4;
	
// if (size_test10())
// 	{
// 		cout << "\nSize_test10 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test10 failed"<<endl;
// 		failed++;
// 	}
// 	cout << endl;
// 	M10._output();
// 	cout << endl;
// 	cout << endl;
// 	cout << endl;
	
	
// //Test 13
//  mymatrix<int>  M15(4, 4);
// //   int R = 4;
// //   int C = 4;
	
// if (size_test15())
// 	{
// 		cout << "\nSize_test13 passed"<< endl;
// 		passed++;
// 	}
// 	else{
// 		cout<< "size_test13 failed"<<endl;
// 		failed++;
// 	}
// 	cout << endl;
// 	M15._output();
// 	cout << endl;
// 	cout << endl;
// 	cout << endl;

	
	

	
	

	cout << " Code passed == " << passed << endl;
	cout << " Code failed == " << failed << endl;
	
	
	
	//M._output();
	//
	//
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
    cout << "The number of size = " << M.size() << endl;
	cout << "The number of rows are == "<<M.numrows() << endl;
	cout << "The number of colms of numcols(0) are == "<<M.numcols(0) << endl;
	cout << "The number of colms of numcols(1) are == "<<M.numcols(1) << endl;
	cout << "The number of colms of numcols(2) are == "<<M.numcols(2) << endl;
	cout << "The number of colms of numcols(3) are == "<<M.numcols(3) << endl;
	cout << "The number of colms of numrows() are == "<<M.numrows() << endl;
	
	
	cout << " m.at(r,c)  = " << M.at(2,2) << endl;
	
	
}




