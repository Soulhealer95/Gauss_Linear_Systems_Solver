# Gauss_Linear_Systems_Solver
Headers for Matrix/Vector support and Implementation of Gauss Elimination using LU and Partial Pivot

# Usage
```
 ./GaussPP
Please enter the size of matrix to process:
4
Values of Vector b
Enter the Vector value for index V[0]:
5
Enter the Vector value for index V[1]:
16
Enter the Vector value for index V[2]:
22
Enter the Vector value for index V[3]:
15
Please enter Matrix Value for A[0][0]
1
Please enter Matrix Value for A[0][1]
2
Please enter Matrix Value for A[0][2]
1
Please enter Matrix Value for A[0][3]
-1
Please enter Matrix Value for A[1][0]
3
Please enter Matrix Value for A[1][1]
2
Please enter Matrix Value for A[1][2]
4
Please enter Matrix Value for A[1][3]
4
Please enter Matrix Value for A[2][0]
4
Please enter Matrix Value for A[2][1]
4
Please enter Matrix Value for A[2][2]
3
Please enter Matrix Value for A[2][3]
4
Please enter Matrix Value for A[3][0]
2
Please enter Matrix Value for A[3][1]
0
Please enter Matrix Value for A[3][2]
1
Please enter Matrix Value for A[3][3]
5
Starting Values:
A:
[ 1.00  2.00  1.00  -1.00 ]
[ 3.00  2.00  4.00  4.00 ]
[ 4.00  4.00  3.00  4.00 ]
[ 2.00  0.00  1.00  5.00 ]

b:
[ 5.00 ]
[ 16.00 ]
[ 22.00 ]
[ 15.00 ]

Swapping rows 0 and 2
After Row Swap:
A:
[ 4.00  4.00  3.00  4.00 ]
[ 3.00  2.00  4.00  4.00 ]
[ 1.00  2.00  1.00  -1.00 ]
[ 2.00  0.00  1.00  5.00 ]

L:
[ 0.00  0.00  0.00  0.00 ]
[ 0.00  0.00  0.00  0.00 ]
[ 0.00  0.00  0.00  0.00 ]
[ 0.00  0.00  0.00  0.00 ]

b:
[ 22.00 ]
[ 16.00 ]
[ 5.00 ]
[ 15.00 ]

After Elimination at 1, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  4.00  4.00 ]
[ 0.00  2.00  1.00  -1.00 ]
[ 0.00  0.00  1.00  5.00 ]

After Elimination at 1, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  4.00  4.00 ]
[ 0.00  1.00  1.00  -1.00 ]
[ 0.00  0.00  1.00  5.00 ]

After Elimination at 1, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  4.00  4.00 ]
[ 0.00  1.00  1.00  -1.00 ]
[ 0.00  -2.00  1.00  5.00 ]

After Elimination, b:
[ 22.00 ]
[ -0.50 ]
[ 5.00 ]
[ 15.00 ]

After Elimination at 2, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  4.00 ]
[ 0.00  1.00  1.00  -1.00 ]
[ 0.00  -2.00  1.00  5.00 ]

After Elimination at 2, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  4.00 ]
[ 0.00  1.00  0.25  -1.00 ]
[ 0.00  -2.00  1.00  5.00 ]

After Elimination at 2, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  4.00 ]
[ 0.00  1.00  0.25  -1.00 ]
[ 0.00  -2.00  -0.50  5.00 ]

After Elimination, b:
[ 22.00 ]
[ -0.50 ]
[ -0.50 ]
[ 15.00 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  1.00 ]
[ 0.00  1.00  0.25  -1.00 ]
[ 0.00  -2.00  -0.50  5.00 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  1.00 ]
[ 0.00  1.00  0.25  -2.00 ]
[ 0.00  -2.00  -0.50  5.00 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -1.00  1.75  1.00 ]
[ 0.00  1.00  0.25  -2.00 ]
[ 0.00  -2.00  -0.50  3.00 ]

After Elimination, b:
[ 22.00 ]
[ -0.50 ]
[ -0.50 ]
[ 4.00 ]

Swapping rows 1 and 3
After Row Swap:
A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  1.00  0.25  -2.00 ]
[ 0.00  -1.00  1.75  1.00 ]

L:
[ 0.00  0.00  0.00  0.00 ]
[ 0.50  0.00  0.00  0.00 ]
[ 0.25  0.00  0.00  0.00 ]
[ 0.75  0.00  0.00  0.00 ]

b:
[ 22.00 ]
[ 4.00 ]
[ -0.50 ]
[ -0.50 ]

After Elimination at 2, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  0.00  -2.00 ]
[ 0.00  0.00  1.75  1.00 ]

After Elimination at 2, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  0.00  -2.00 ]
[ 0.00  0.00  2.00  1.00 ]

After Elimination, b:
[ 22.00 ]
[ 4.00 ]
[ 1.50 ]
[ -0.50 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  0.00  -0.50 ]
[ 0.00  0.00  2.00  1.00 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  0.00  -0.50 ]
[ 0.00  0.00  2.00  -0.50 ]

After Elimination, b:
[ 22.00 ]
[ 4.00 ]
[ 1.50 ]
[ -2.50 ]

Swapping rows 2 and 3
After Row Swap:
A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  2.00  -0.50 ]
[ 0.00  0.00  0.00  -0.50 ]

L:
[ 0.00  0.00  0.00  0.00 ]
[ 0.50  0.00  0.00  0.00 ]
[ 0.75  0.50  0.00  0.00 ]
[ 0.25  -0.50  0.00  0.00 ]

b:
[ 22.00 ]
[ 4.00 ]
[ -2.50 ]
[ 1.50 ]

After Elimination at 3, A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  2.00  -0.50 ]
[ 0.00  0.00  0.00  -0.50 ]

After Elimination, b:
[ 22.00 ]
[ 4.00 ]
[ -2.50 ]
[ 1.50 ]

Pre Result
A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  2.00  -0.50 ]
[ 0.00  0.00  0.00  -0.50 ]

L:
[ 1.00  0.00  0.00  0.00 ]
[ 0.50  1.00  0.00  0.00 ]
[ 0.75  0.50  1.00  0.00 ]
[ 0.25  -0.50  0.00  1.00 ]

b:
[ 22.00 ]
[ 4.00 ]
[ -2.50 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 2, b:
[ 22.00 ]
[ 4.00 ]
[ -4.00 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 1, b:
[ 22.00 ]
[ 13.00 ]
[ -4.00 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 0, b:
[ 34.00 ]
[ 13.00 ]
[ -4.00 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 1, b:
[ 34.00 ]
[ 12.00 ]
[ -4.00 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 0, b:
[ 40.00 ]
[ 12.00 ]
[ -4.00 ]
[ 1.50 ]

Upper_TLS(): After Elimination at 0, b:
[ 64.00 ]
[ 12.00 ]
[ -4.00 ]
[ 1.50 ]

Final Result:
A:
[ 4.00  4.00  3.00  4.00 ]
[ 0.00  -2.00  -0.50  3.00 ]
[ 0.00  0.00  2.00  -0.50 ]
[ 0.00  0.00  0.00  -0.50 ]

b:
[ 64.00 ]
[ 12.00 ]
[ -4.00 ]
[ 1.50 ]

x:
[ 16.00 ]
[ -6.00 ]
[ -2.00 ]
[ -3.00 ]
```
