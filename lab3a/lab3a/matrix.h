#pragma once
#include <iostream>
#include <string>
#include <vector>

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

	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;

	int GetValue(int i, int j) const;
	std::vector<std::vector<int>> GetMatrix() const;
};