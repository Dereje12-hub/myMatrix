# myMatrix
mymatrix

The mymatrix class provides a matrix (2D array) abstraction.
The size can grow dynamically in both directions (rows and 
cols).  Also, rows can be "jagged" --- i.e. rows can have 
different column sizes, and thus the matrix is not necessarily 
rectangular.  All elements are initialized to the default value
for the given type T.  Example:

  mymatrix<int>  M;  // 4x4 matrix, initialized to 0
  
  M(0, 0) = 123;
  M(1, 1) = 456;
  M(2, 2) = 789;
  M(3, 3) = -99;

  M.growcols(1, 8);  // increase # of cols in row 1 to 8

  for (int r = 0; r < M.numrows(); ++r)
  {
     for (int c = 0; c < M.numcols(r); ++c)
        cout << M(r, c) << " ";
     cout << endl;
  }

Output:
  123 0 0 0
  0 456 0 0 0 0 0 0
  0 0 789 0
  0 0 0 -99
