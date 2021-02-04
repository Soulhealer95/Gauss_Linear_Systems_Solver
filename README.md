# Gauss_Linear_Systems_Solver
Headers for Matrix/Vector support and Implementation of Gauss Elimination using LU and Partial Pivot

# Usage
```
./GaussPP
Please enter the size of matrix to process:
3
Values of Vector b
Enter the Vector value for index V[0]:
3
Enter the Vector value for index V[1]:
6
Enter the Vector value for index V[2]:
10
Please enter Matrix Value for A[0][0]
1
Please enter Matrix Value for A[0][1]
2
Please enter Matrix Value for A[0][2]
2
Please enter Matrix Value for A[1][0]
4
Please enter Matrix Value for A[1][1]
4
Please enter Matrix Value for A[1][2]
2
Please enter Matrix Value for A[2][0]
4
Please enter Matrix Value for A[2][1]
6
Please enter Matrix Value for A[2][2]
4
Starting Values:
A:
[ 1.00  2.00  2.00 ]
[ 4.00  4.00  2.00 ]
[ 4.00  6.00  4.00 ]

b:
[ 3.00 ]
[ 6.00 ]
[ 10.00 ]

Swapping rows 0 and 1
After Row Swap:
A:
[ 4.00  4.00  2.00 ]
[ 1.00  2.00  2.00 ]
[ 4.00  6.00  4.00 ]

L:
[ 0.00  0.00  0.00 ]
[ 0.00  0.00  0.00 ]
[ 0.00  0.00  0.00 ]

b:
[ 6.00 ]
[ 3.00 ]
[ 10.00 ]

After Elimination at 1, A:
[ 4.00  4.00  2.00 ]
[ 0.00  1.00  2.00 ]
[ 0.00  6.00  4.00 ]

After Elimination at 1, A:
[ 4.00  4.00  2.00 ]
[ 0.00  1.00  2.00 ]
[ 0.00  2.00  4.00 ]

After Elimination, b:
[ 6.00 ]
[ 1.50 ]
[ 10.00 ]

After Elimination at 2, A:
[ 4.00  4.00  2.00 ]
[ 0.00  1.00  1.50 ]
[ 0.00  2.00  4.00 ]

After Elimination at 2, A:
[ 4.00  4.00  2.00 ]
[ 0.00  1.00  1.50 ]
[ 0.00  2.00  2.00 ]

After Elimination, b:
[ 6.00 ]
[ 1.50 ]
[ 4.00 ]

Swapping rows 1 and 2
After Row Swap:
A:
[ 4.00  4.00  2.00 ]
[ 0.00  2.00  2.00 ]
[ 0.00  1.00  1.50 ]

L:
[ 0.00  0.00  0.00 ]
[ 1.00  0.00  0.00 ]
[ 0.25  0.00  0.00 ]

b:
[ 6.00 ]
[ 4.00 ]
[ 1.50 ]

After Elimination at 2, A:
[ 4.00  4.00  2.00 ]
[ 0.00  2.00  2.00 ]
[ 0.00  0.00  0.50 ]

After Elimination, b:
[ 6.00 ]
[ 4.00 ]
[ -0.50 ]

Pre Result
A:
[ 4.00  4.00  2.00 ]
[ 0.00  2.00  2.00 ]
[ 0.00  0.00  0.50 ]

L:
[ 1.00  0.00  0.00 ]
[ 1.00  1.00  0.00 ]
[ 0.25  0.50  1.00 ]

b:
[ 6.00 ]
[ 4.00 ]
[ -0.50 ]

Upper_TLS(): After Elimination at 1, b:
[ 6.00 ]
[ 6.00 ]
[ -0.50 ]

Upper_TLS(): After Elimination at 0, b:
[ 8.00 ]
[ 6.00 ]
[ -0.50 ]

Upper_TLS(): After Elimination at 0, b:
[ -4.00 ]
[ 6.00 ]
[ -0.50 ]

Final Result:
A:
[ 4.00  4.00  2.00 ]
[ 0.00  2.00  2.00 ]
[ 0.00  0.00  0.50 ]

b:
[ -4.00 ]
[ 6.00 ]
[ -0.50 ]

x:
[ -1.00 ]
[ 3.00 ]
[ -1.00 ]
```
