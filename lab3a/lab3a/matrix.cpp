#include "matrix.h"

using namespace std;

Matrix::Matrix(int n) : matrix(vector<vector<int>>(n, vector<int>(n, 0))) {};

Matrix::Matrix(int n, int m) :matrix(vector<vector<int>>(n, vector<int>(m, 0))) {};

Matrix::Matrix(const vector<vector<int>>& new_matrix) : matrix(new_matrix) {};

void Matrix::SetValue(int i, int j, int value)
{
	matrix[i][j] = value;
}

void Matrix::SetRow(int row_num, const vector<int>& row)
{
	matrix[row_num] = row;
}

void Matrix::SetColumn(int col_num, const vector<int>& col)
{
	for (size_t i = 0; i < matrix.size(); i++)
		matrix[i][col_num] = col[i];
}

void Matrix::ChangeNumberOfRows(int num_rows)
{
	matrix.resize(num_rows);
}

void Matrix::ChangeNumberOfColumns(int num_cols)
{
	for (size_t i = 0; i < matrix.size(); i++)
		matrix[i].resize(num_cols);
}

void Matrix::ChangeSize(int new_size)
{
	ChangeNumberOfColumns(new_size);
	ChangeNumberOfRows(new_size);
}

size_t Matrix::GetNumberOfRows() const
{
	return matrix.size();
}

size_t Matrix::GetNumberOfColumns() const
{
	if (matrix.size())
		return matrix[0].size();
	return 0;
}

int Matrix::GetValue(int i, int j) const
{
	return matrix[i][j];
}

vector<vector<int>> Matrix::GetMatrix() const
{
	return matrix;
}

Matrix AutoGenerateMatrix(int n)
{
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = rand()%10;
	return Matrix(result);
}

Matrix AutoGenerateMatrix(int n, int m)
{
	vector<vector<int>> result(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i][j] = rand() % 10;
	return Matrix(result);
}

bool CanAdd(const Matrix& rhs, const Matrix& lhs)
{
	return rhs.GetNumberOfColumns() == lhs.GetNumberOfColumns() && rhs.GetNumberOfRows() == lhs.GetNumberOfRows();
}

bool CanMultiplicate(const Matrix& rhs, const Matrix& lhs)
{
	return rhs.GetNumberOfColumns() == lhs.GetNumberOfRows();
}

Matrix operator+(const Matrix& rhs, const Matrix& lhs)
{
	if (CanAdd(rhs, lhs))
	{
		size_t num_cols = rhs.GetNumberOfColumns();
		size_t num_rows = rhs.GetNumberOfRows();
		vector<vector<int>> res(num_rows, vector<int>(num_cols, 0));
		for (size_t i = 0; i < num_rows; i++)
			for (size_t j = 0; j < num_cols; j++)
				res[i][j] = (rhs.GetValue(i, j) + lhs.GetValue(i, j))%10;
		return Matrix(res);
	}
	throw logic_error("Can`t add two matrix with different sizes");
}

Matrix operator*(const Matrix& rhs, const Matrix& lhs)
{
	if (CanMultiplicate(rhs, lhs))
	{
		size_t num_cols = lhs.GetNumberOfColumns();
		size_t num_rows = rhs.GetNumberOfRows();
		vector<vector<int>> res(num_rows, vector<int>(num_cols, 0));
		for(size_t i = 0; i < num_rows; i++)
			for (size_t j = 0; j < num_cols; j++)
			{
				int temp = 0;
				for (size_t k = 0; k < lhs.GetNumberOfRows(); k++)
					temp += rhs.GetValue(i, k) * lhs.GetValue(k, j);
				res[i][j] = temp;
			}
		return Matrix(res);
	}
	throw logic_error("Can`t multiply two matrix with different sizes");
}

void PartMultiplication(const Matrix& rhs, const Matrix& lhs, size_t start, size_t finish, Matrix* res)
{
	if (CanMultiplicate(rhs, lhs))
	{
		for (size_t i = start; i < std::min(finish, rhs.GetNumberOfRows()); i++)
			for (size_t j = 0; j < lhs.GetNumberOfColumns(); j++)
			{
				int temp = 0;
				for (size_t k = 0; k < lhs.GetNumberOfRows(); k++)
					temp += rhs.GetValue(i, k) * lhs.GetValue(k, j);
				res->SetValue(i,j,temp);
			}
	}
	else
		throw logic_error("Can`t multiply two matrix with different sizes");
}

Matrix MultiplyParallel(const Matrix& rhs, const Matrix& lhs)
{
	size_t num_cols = lhs.GetNumberOfColumns();
	size_t num_rows = rhs.GetNumberOfRows();
	Matrix* res = new Matrix(vector<vector<int>>(num_rows, vector<int>(num_cols, 0)));

	std::size_t num_threads = std::thread::hardware_concurrency();
	std::vector<std::thread> threads(num_threads);
	std::size_t thread_size = (num_rows / num_threads) + 1;
	std::size_t start = 0;
	for (std::size_t i = 0; i < num_threads; i++)
	{
		threads[i] = std::thread(PartMultiplication, rhs, lhs, start, start + thread_size, res);
		start += thread_size;
	}

	for (std::size_t i = 0; i < num_threads; i++) {
		threads[i].join();
	}

	return *res;
}