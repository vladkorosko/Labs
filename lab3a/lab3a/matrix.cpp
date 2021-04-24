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

int Matrix::GetNumberOfRows() const
{
	return matrix.size();
}

int Matrix::GetNumberOfColumns() const
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