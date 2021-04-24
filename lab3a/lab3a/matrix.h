#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>
#include <thread>

class Matrix
{
private:
	std::vector<std::vector<int>> matrix;

public:
	Matrix(int n);
	Matrix(int n, int m);
	Matrix(const std::vector<std::vector<int>>& new_matrix);

	void SetValue(int i, int j, int value);
	void SetRow(int row_num, const std::vector<int>& row);
	void SetColumn(int col_num, const std::vector<int>& row);

	void ChangeNumberOfRows(int num_rows);
	void ChangeNumberOfColumns(int num_cols);	
	void ChangeSize(int new_size);

	size_t GetNumberOfRows() const;
	size_t GetNumberOfColumns() const;

	int GetValue(int i, int j) const;
	std::vector<std::vector<int>> GetMatrix() const;
};

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

/*
std::vector<int> ParseString(int n, const std::string s)
{
	std::istringstream in(s);

}*/

Matrix AutoGenerate(int n);
Matrix AutoGenerate(int n, int m);

bool CanAdd(const Matrix& rhs, const Matrix& lhs);
bool CanMultiplicate(const Matrix& rhs, const Matrix& lhs);

Matrix MultiplyParallel(const Matrix& rhs, const Matrix& lhs);

Matrix operator+(const Matrix& rhs, const Matrix& lhs);
Matrix operator*(const Matrix& rhs, const Matrix& lhs);