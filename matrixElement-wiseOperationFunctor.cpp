#include <iostream>
#include <ostream>
#include <istream>
#include <cstddef>
#include <stdexcept>

class MatrixAdder;

class Matrix {
public:
	Matrix();
	Matrix(int row, int column);
	Matrix(const Matrix& src);
	Matrix(Matrix&& src) noexcept;
	~Matrix();

	const Matrix& operator=(const Matrix& rhs);
	const Matrix& operator= (Matrix&& rhs) noexcept;
public:
	int getRow() const;
	int getColumn() const;
	int** getArr() const;
	void Adder(const Matrix& rhs, MatrixAdder& op) const;
	
protected:
	void swap(Matrix& src) noexcept;
	
private:
	int** m_arr;
	int m_row;
	int m_column;
};

class MatrixAdder {
public:
	void operator()(const Matrix& lhs, const Matrix& rhs);
	Matrix getResult() const;
private:
	Matrix m_matrix;
}; 

void MatrixAdder::operator()(const Matrix& lhs, const Matrix& rhs) {
        int row1 = lhs.getRow();
        int row2 = rhs.getRow();
        if (row1 != row2) { throw std::invalid_argument("Matrix dimensions are not compatible for addition"); }
        int column2 = rhs.getColumn();
        int column1 = lhs.getColumn();
        if (column1 != column2) { throw std::invalid_argument("Matrix dimensions are not compatible for addition"); }
        int** arr1 =  lhs.getArr();
        int** arr2 =  rhs.getArr();
        m_matrix = Matrix(row1, column1);
        int** arr = m_matrix.getArr();
        for (std::size_t i{}; i < row1; ++i) {
        	for (std::size_t j{}; j < column1; ++j) {
                        arr[i][j] = arr1[i][j] + arr2[i][j];
                }
        }	
}

Matrix MatrixAdder::getResult() const {return m_matrix;}

Matrix::Matrix() :  m_arr{nullptr}, m_row{}, m_column{} {}

Matrix::Matrix(int row, int column) : m_row{row}, m_column{column} {
	m_arr = new int*[m_row];
	for (std::size_t i{}; i < m_row; ++i) {
		m_arr[i] = new int[m_column];
	}
}

Matrix::Matrix(const Matrix& src) : Matrix(src.m_row, src.m_column) {
	for (std::size_t i{}; i < m_row; ++i) {
		for (std::size_t j{}; j < m_column; ++j) {
			m_arr[i][j] = src.m_arr[i][j];
		}
	}
}

Matrix::Matrix(Matrix&& src) noexcept : Matrix() {
	swap(src);
}
const Matrix& Matrix::operator=(const Matrix& rhs) {
	Matrix tmp(rhs);
	swap(tmp);
	return *this;
}

const Matrix& Matrix::operator=(Matrix&& rhs) noexcept {
	Matrix tmp(std::move(rhs));
	swap(tmp);
	return *this;
}

void Matrix::swap(Matrix& src) noexcept {
	std::swap(m_row, src.m_row);
	std::swap(m_column, src.m_column);
	std::swap(m_arr, src.m_arr);
}

Matrix::~Matrix() {
	for (std::size_t i{}; i < m_row; ++i) {
		delete[] m_arr[i];
	}
	delete[] m_arr;
}

int Matrix::getRow() const { return m_row;}

int Matrix::getColumn() const { return m_column;}

int** Matrix::getArr() const { return m_arr;}

void Matrix::Adder(const Matrix& rhs, MatrixAdder& op) const {
	op(*this, rhs);
}

std::ostream& operator<<(std::ostream& cout, const Matrix& src) {
	int** arr =  src.getArr();
	int row = src.getRow();
	int column = src.getColumn();
	for (std::size_t i{}; i < row; ++i) {
		for (std::size_t j{}; j < column; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return cout;
}

std::istream& operator>>(std::istream& cin, Matrix& src) {
        int** arr =  src.getArr();
        int row = src.getRow();
        int column = src.getColumn();
        for (std::size_t i{}; i < row; ++i) {
                for (std::size_t j{}; j < column; ++j) {
                        cin >> arr[i][j];
                }
        }
	return cin;
}

int main() {
	try {
		Matrix m1(2, 2);
                Matrix m2(2, 2);

                std::cout << "Enter values for matrix m1:" << std::endl;
                std::cin >> m1;

                std::cout << "Enter values for matrix m2:" << std::endl;
                std::cin >> m2;

                MatrixAdder operation;
                m1.Adder(m2, operation);

                std::cout << "Result of matrix addition:" << std::endl;
                std::cout << operation.getResult() << std::endl;
        } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
                std::cerr << "Unexpected error: " << e.what() << std::endl;
        }

	return 0;
}

