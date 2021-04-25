#include "unit_tests.h"

using namespace std;

void TestMatrix()
{
	AssertEqual(Matrix(2).GetMatrix(), vector<vector<int>>(2, vector<int>(2,0)), "Constructor Matrix(int n)");
	AssertEqual(Matrix(1,2).GetMatrix(), vector<vector<int>>(1, vector<int>(2,0)), "Constructor Matrix(int n, int m)");

	{
		Matrix A(2);
		A.SetValue(0, 0, 1);
		vector<vector<int>> a(2, vector<int>(2, 0));
		a[0][0] = 1;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set value i=0, j=0, value=1");
		A.SetValue(0, 1, 2);
		A.SetValue(1, 0, 3);
		a[0][1] = 2;
		a[1][0] = 3;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set value i=0, j=1, value=2; set value i=1, j=0, value=3");

		Matrix B(2,3);
		B.SetValue(0, 0, 1);
		vector<vector<int>> b(2, vector<int>(3, 0));
		b[0][0] = 1;
		AssertEqual(B.GetMatrix(), b, "Rectangle matrix: set value i=0, j=0, value=1");
		B.SetValue(1, 2, 4);
		b[1][2] = 4;
		AssertEqual(B.GetMatrix(), b, "Rectangle matrix: set value i=1, j=2, value=4");
		B.SetValue(0, 1, 2);
		B.SetValue(1, 0, 3);
		b[0][1] = 2;
		b[1][0] = 3;
		AssertEqual(B.GetMatrix(), b, "Rectangle matrix: set value i=0, j=1, value=2; set value i=1, j=0, value=3");
	}

	{
		Matrix A(3);
		A.SetColumn(0, { 1,2,3 });
		vector<vector<int>> a(3, vector<int>(3, 0));
		a[0][0] = 1;
		a[1][0] = 2;
		a[2][0] = 3;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set first column {1,2,3} values");
		A.SetColumn(1, { 3,1,2 });
		a[0][1] = 3;
		a[1][1] = 1;
		a[2][1] = 2;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set second column {3,1,2} values");
		A.SetColumn(2, { 2,3,1 });
		a[0][2] = 2;
		a[1][2] = 3;
		a[2][2] = 1;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set last column {2,3,1} values");
	}

	{
		Matrix A(2,3);
		A.SetColumn(0, { 1,2 });
		vector<vector<int>> a(2, vector<int>(3, 0));
		a[0][0] = 1;
		a[1][0] = 2;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set first column {1,2} values");
		A.SetColumn(1, { 3,4 });
		a[0][1] = 3;
		a[1][1] = 4;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set second column {3,4} values");
		A.SetColumn(2, { 5,6 });
		a[0][2] = 5;
		a[1][2] = 6;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set last column {5,6} values");
	}

	{
		Matrix A(3);
		A.SetRow(0, { 1,2,3 });
		vector<vector<int>> a(3, vector<int>(3, 0));
		a[0][0] = 1;
		a[0][1] = 2;
		a[0][2] = 3;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set first row {1,2,3} values");
		A.SetRow(1, { 3,1,2 });
		a[1][0] = 3;
		a[1][1] = 1;
		a[1][2] = 2;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set second row {3,1,2} values");
		A.SetRow(2, { 2,3,1 });
		a[2][0] = 2;
		a[2][1] = 3;
		a[2][2] = 1;
		AssertEqual(A.GetMatrix(), a, "Square matrix: set last row {2,3,1} values");
	}

	{
		Matrix A(3, 2);
		A.SetRow(0, { 1,2 });
		vector<vector<int>> a(3, vector<int>(2, 0));
		a[0][0] = 1;
		a[0][1] = 2;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set first row {1,2} values");
		A.SetRow(1, { 3,4 });
		a[1][0] = 3;
		a[1][1] = 4;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set second row {3,4} values");
		A.SetRow(2, { 5,6 });
		a[2][0] = 5;
		a[2][1] = 6;
		AssertEqual(A.GetMatrix(), a, "Rectangle matrix: set last row {5,6} values");
	}

	{
		Matrix A(1);
		A.ChangeNumberOfColumns(10);
		A.ChangeNumberOfRows(5);
		AssertEqual(A.GetNumberOfColumns(), 10, "Change number of columns");
		AssertEqual(A.GetNumberOfRows(), 5, "Change number of rows");
		A.ChangeSize(7);
		AssertEqual(A.GetNumberOfColumns(), 7, "Change size (check number of columns)");
		AssertEqual(A.GetNumberOfRows(), 7, "Change size (check number of rows)");
	}

	{
		Matrix A({ {1,2,3,4,5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} });
		AssertEqual(A.GetValue(0, 0), 1, "Value on (0,0) position");
		AssertEqual(A.GetValue(0, 1), 2, "Value on (0,1) position");
		AssertEqual(A.GetValue(0, 2), 3, "Value on (0,2) position");
		AssertEqual(A.GetValue(0, 3), 4, "Value on (0,3) position");
		AssertEqual(A.GetValue(0, 4), 5, "Value on (0,4) position");
		AssertEqual(A.GetValue(1, 0), 6, "Value on (1,0) position");
		AssertEqual(A.GetValue(1, 1), 7, "Value on (1,1) position");
		AssertEqual(A.GetValue(1, 2), 8, "Value on (1,2) position");
		AssertEqual(A.GetValue(1, 3), 9, "Value on (1,3) position");
		AssertEqual(A.GetValue(1, 4), 10, "Value on (1,4) position");
		AssertEqual(A.GetValue(2, 0), 11, "Value on (2,0) position");
		AssertEqual(A.GetValue(2, 1), 12, "Value on (2,1) position");
		AssertEqual(A.GetValue(2, 2), 13, "Value on (2,2) position");
		AssertEqual(A.GetValue(2, 3), 14, "Value on (2,3) position");
		AssertEqual(A.GetValue(2, 4), 15, "Value on (2,4) position");
		AssertEqual(A.GetValue(3, 0), 16, "Value on (3,0) position");
		AssertEqual(A.GetValue(3, 1), 17, "Value on (3,1) position");
		AssertEqual(A.GetValue(3, 2), 18, "Value on (3,2) position");
		AssertEqual(A.GetValue(3, 3), 19, "Value on (3,3) position");
		AssertEqual(A.GetValue(3, 4), 20, "Value on (3,4) position");
		AssertEqual(A.GetValue(4, 0), 21, "Value on (4,0) position");
		AssertEqual(A.GetValue(4, 1), 22, "Value on (4,1) position");
		AssertEqual(A.GetValue(4, 2), 23, "Value on (4,2) position");
		AssertEqual(A.GetValue(4, 3), 24, "Value on (4,3) position");
		AssertEqual(A.GetValue(4, 4), 25, "Value on (4,4) position");
	}
}

void TestAutoGenerateMatrix()
{
	{
		Matrix A = AutoGenerateMatrix(10);
		AssertEqual(A.GetNumberOfColumns(), 10, "Generated matrix with 10 columns");
		AssertEqual(A.GetNumberOfRows(), 10, "Generated matrix with 10 rows");
	}

	{
		Matrix A = AutoGenerateMatrix(5);
		AssertEqual(A.GetNumberOfColumns(), 5, "Generated matrix with 5 columns");
		AssertEqual(A.GetNumberOfRows(), 5, "Generated matrix with 5 rows");
	}

	{
		Matrix A = AutoGenerateMatrix(7,8);
		AssertEqual(A.GetNumberOfColumns(), 8, "Generated matrix with 8 columns");
		AssertEqual(A.GetNumberOfRows(), 7, "Generated matrix with 7 rows");
	}

	{
		Matrix A = AutoGenerateMatrix(2, 4);
		AssertEqual(A.GetNumberOfColumns(), 4, "Generated matrix with 4 columns");
		AssertEqual(A.GetNumberOfRows(), 2, "Generated matrix with 2 rows");
	}

	{
		Matrix A = AutoGenerateMatrix(3,2);
		AssertEqual(A.GetNumberOfColumns(), 2, "Generated matrix with 2 columns");
		AssertEqual(A.GetNumberOfRows(), 3, "Generated matrix with 3 rows");
	}

	{
		Matrix A = AutoGenerateMatrix(9, 6);
		AssertEqual(A.GetNumberOfColumns(), 6, "Generated matrix with 6 columns");
		AssertEqual(A.GetNumberOfRows(), 9, "Generated matrix with 9 rows");
	}
}

void TestCanAdd()
{
	{
		Matrix A(5);
		Assert(CanAdd(A, A), "We can add the same square matrixes");
		Matrix B(2, 3);
		Assert(CanAdd(B, B), "We can add the same rectangle matrixes");
	}

	{
		Matrix A(7);
		Matrix B(7);
		Assert(CanAdd(A, B), "We can add square matrixes with the same size (in direct order)");
		Assert(CanAdd(B, A), "We can add square matrixes with the same size (in reverse order)");
	}

	{
		Matrix A(3,9);
		Matrix B(3,9);
		Assert(CanAdd(A, B), "We can add rectangle matrixes with the same size (in direct order)");
		Assert(CanAdd(B, A), "We can add rectangle matrixes with the same size (in reverse order)");
	}

	{
		Matrix A(7);
		Matrix B(9);
		Assert(!CanAdd(A, B), "We can't add square matrixes with different sizes (in direct order)");
		Assert(!CanAdd(B, A), "We can't add square matrixes with different sizes (in reverse order)");
	}

	{
		Matrix A(3, 9);
		Matrix B(3, 10);
		Assert(!CanAdd(A, B), "We can`t add rectangle matrixes with different number of columns (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add rectangle matrixes with different number of columns (in reverse order)");
	}

	{
		Matrix A(4, 9);
		Matrix B(3, 9);
		Assert(!CanAdd(A, B), "We can`t add rectangle matrixes with different number of rows (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add rectangle matrixes with different number of rows (in reverse order)");
	}

	{
		Matrix A(4, 9);
		Matrix B(3, 10);
		Assert(!CanAdd(A, B), "We can`t add rectangle matrixes with different number of columns and rows (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add rectangle matrixes with different number of columns and rows (in reverse order)");
	}

	{
		Matrix A(3);
		Matrix B(3, 10);
		Assert(!CanAdd(A, B), "We can`t add square and rectangle matrixes with same number of rows (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add square and rectangle matrixes with same number of rows (in reverse order)");
	}

	{
		Matrix A(10);
		Matrix B(3, 10);
		Assert(!CanAdd(A, B), "We can`t add square and rectangle matrixes with same number of columns (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add square and rectangle matrixes with same number of columns (in reverse order)");
	}

	{
		Matrix A(5);
		Matrix B(3, 10);
		Assert(!CanAdd(A, B), "We can`t add square and rectangle matrixes with different number of columns and rows  (in direct order)");
		Assert(!CanAdd(B, A), "We can`t add square and rectangle matrixes with different number of columns and rows  (in reverse order)");
	}
}

void TestCanMultiplicate()
{
	{
		Matrix A(5);
		Assert(CanMultiplicate(A, A), "We can multiplicate the same square matrixes");
		Matrix B(2, 3);
		Assert(!CanMultiplicate(B, B), "We can't add the same rectangle matrixes");
	}

	{
		Matrix A(7);
		Matrix B(7);
		Assert(CanMultiplicate(A, B), "We can multiplicate square matrixes with the same size (in direct order)");
		Assert(CanMultiplicate(B, A), "We can multiplicate square matrixes with the same size (in reverse order)");
	}

	{
		Matrix A(3, 9);
		Matrix B(3, 9);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate rectangle matrixes with the same size (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate rectangle matrixes with the same size (in reverse order)");
	}

	{
		Matrix A(7);
		Matrix B(9);
		Assert(!CanMultiplicate(A, B), "We can't multiplicate square matrixes with different sizes (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can't multiplicate square matrixes with different sizes (in reverse order)");
	}

	{
		Matrix A(3, 9);
		Matrix B(3, 10);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate rectangle matrixes with different number of columns (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate rectangle matrixes with different number of columns (in reverse order)");
	}

	{
		Matrix A(4, 9);
		Matrix B(3, 9);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate rectangle matrixes with different number of rows (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate rectangle matrixes with different number of rows (in reverse order)");
	}

	{
		Matrix A(4, 9);
		Matrix B(3, 10);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate rectangle matrixes with different number of columns and rows (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate rectangle matrixes with different number of columns and rows (in reverse order)");
	}

	{
		Matrix A(3);
		Matrix B(3, 10);
		Assert(CanMultiplicate(A, B), "We can multiplicate square and rectangle matrixes with same number of rows (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate square and rectangle matrixes with same number of rows (in reverse order)");
	}

	{
		Matrix A(10);
		Matrix B(3, 10);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate square and rectangle matrixes with same number of columns (in direct order)");
		Assert(CanMultiplicate(B, A), "We can multiplicate square and rectangle matrixes with same number of columns (in reverse order)");
	}

	{
		Matrix A(5);
		Matrix B(3, 10);
		Assert(!CanMultiplicate(A, B), "We can`t multiplicate square and rectangle matrixes with different number of columns and rows  (in direct order)");
		Assert(!CanMultiplicate(B, A), "We can`t multiplicate square and rectangle matrixes with different number of columns and rows  (in reverse order)");
	}

	{
		Matrix A(3, 5);
		Matrix B(5, 3);
		Assert(CanMultiplicate(A, B), "We can multiplicate rectangle matrixes when number of rows of the fisrt matrix equals number of columns of the second 1");
		Assert(CanMultiplicate(B, A), "We can multiplicate rectangle matrixes when number of rows of the fisrt matrix equals number of columns of the second 2");
	}
}

void TestParallelMultiplication()
{
	{
		Matrix A = AutoGenerateMatrix(1);
		AssertEqual(MultiplyParallel(A, A).GetMatrix(), (A * A).GetMatrix(), "Check A * A, where A - random square matrix with size 1");
	}

	{
		Matrix A = AutoGenerateMatrix(2);
		AssertEqual(MultiplyParallel(A, A).GetMatrix(), (A * A).GetMatrix(), "Check A * A, where A - random square matrix with size 2");
	}

	{
		Matrix A = AutoGenerateMatrix(3);
		AssertEqual(MultiplyParallel(A, A).GetMatrix(), (A * A).GetMatrix(), "Check A * A, where A - random square matrix with size 3");
	}

	{
		Matrix A = AutoGenerateMatrix(3);
		Matrix B = AutoGenerateMatrix(3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A,B - random square matrix with size 3 (1)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A,B - random square matrix with size 3 (1)");
	}

	{
		Matrix A = AutoGenerateMatrix(3);
		Matrix B = AutoGenerateMatrix(3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A,B - random square matrix with size 3 (2)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A,B - random square matrix with size 3 (2)");
	}

	{
		Matrix A = AutoGenerateMatrix(3);
		Matrix B = AutoGenerateMatrix(3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A,B - random square matrix with size 3 (3)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A,B - random square matrix with size 3 (3)");
	}

	{
		Matrix A = AutoGenerateMatrix(3);
		Matrix B = AutoGenerateMatrix(3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A,B - random square matrix with size 3 (4)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A,B - random square matrix with size 3 (4)");
	}

	{
		Matrix A = AutoGenerateMatrix(2,4);
		Matrix B = AutoGenerateMatrix(4,2);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x2 (1)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A - random rectangle matrix with size 2x4; B - 4x2 (1)");
	}
	
	{
		Matrix A = AutoGenerateMatrix(2,4);
		Matrix B = AutoGenerateMatrix(4,2);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x2 (2)");
		AssertEqual(MultiplyParallel(B, A).GetMatrix(), (B * A).GetMatrix(), "Check B * A, where A - random rectangle matrix with size 2x4; B - 4x2 (2)");
	}

	{
		Matrix A = AutoGenerateMatrix(2, 4);
		Matrix B = AutoGenerateMatrix(4, 3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x3 (1)");
	}

	{
		Matrix A = AutoGenerateMatrix(2, 4);
		Matrix B = AutoGenerateMatrix(4, 3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x3 (2)");
	}

	{
		Matrix A = AutoGenerateMatrix(2, 4);
		Matrix B = AutoGenerateMatrix(4, 3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x3 (3)");
	}

	{
		Matrix A = AutoGenerateMatrix(2, 4);
		Matrix B = AutoGenerateMatrix(4, 3);
		AssertEqual(MultiplyParallel(A, B).GetMatrix(), (A * B).GetMatrix(), "Check A * B, where A - random rectangle matrix with size 2x4; B - 4x3 (4)");
	}
}

void TestAll()
{
	TestRunner tr;
	tr.RunTest(TestMatrix, "TestMatrix");
	tr.RunTest(TestAutoGenerateMatrix, "TestAutoGenerateMatrix");
	tr.RunTest(TestCanAdd, "TestCanAdd");
	tr.RunTest(TestCanMultiplicate, "TestCanMultiplicate");
	tr.RunTest(TestParallelMultiplication, "TestParallelMultiplication");
}