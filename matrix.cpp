#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>      // std::out_of_range

//Initializes a matrix of size N × N with all elements set to 0
Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N, 0)) {}

//Initializes a matrix with the given 2D vector of values
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(std::move(nums)) {}

//Get the size of the matrix (assuming it's square)
int Matrix::get_size() const {
    return data.size();
}

//Get the value at a specific row and column
int Matrix::get_value(std::size_t i, std::size_t j) const {
    try {
        return data[i][j];
    }catch (const std::out_of_range& e) {
        std::cerr << "Out of Range error: " << e.what() << '\n';
    }
}

//Set a value at a specific row and column
void Matrix::set_value(std::size_t i, std::size_t j, int value) {
    // Check the indices are within bounds before setting the value
    if (i < data.size() && j < data.size()) {
        data[i][j] = value;
    }
}

//Print the matrix with proper formatting
void Matrix::print_matrix() const {
    for (const auto &row : data) { // Iterate through each row
        for (int val : row) { // Iterate through each element in the row
            std::cout << std::setw(5) << val << " "; // Print the value with proper spacing
        }
        std::cout << std::endl;
    }
}

//Overloaded operator to add two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = data.size();
    Matrix result(N);

    // Iterate through each element and add corresponding values from both matrices
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

//Overloaded operator to multiply two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = data.size();
    Matrix result(N);

    // Matrix multiplication
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.data[i][j] = 0; // Initialize result cell to 0
            for (std::size_t k = 0; k < N; ++k) {
                result.data[i][j] += data[i][k] * rhs.data[k][j]; // Compute dot product
            }
        }
    }
    return result;
}

//Calculate the sum of the major diagonal elements
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < data.size(); ++i) {
        sum += data[i][i]; // Add the diagonal element at (i, i)
    }
    return sum;
}

//Calculate the sum of the minor diagonal elements
int Matrix::sum_diagonal_minor() const {
    std::size_t N = data.size();
    int sum = 0;
    for (std::size_t i = 0; i < N; ++i) {
        sum += data[i][N - 1 - i]; // Add the element at (i, N-1-i)
    }
    return sum;
}

//Swap 2 rows of the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    // Check indices are within bounds before swapping
    if (r1 < data.size() && r2 < data.size()) {
        std::swap(data[r1], data[r2]); // Swap the rows
    }
}

//Swap 2 columns of the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    // Check indices are within bounds before swapping
    if (c1 < data.size() && c2 < data.size()) {
        for (std::size_t i = 0; i < data.size(); ++i) {
            std::swap(data[i][c1], data[i][c2]); // Swap the cols
        }
    }
}

//Load two matrices from a file
bool load_matrices_from_file(const std::string &filename, Matrix &mat1, Matrix &mat2) {
    std::ifstream file(filename); // Open the input file
    if (!file) { // Check if file opened successfully
        std::cerr << "Error opening file: " << filename << std::endl;
        return false; // Return failure
    }

    std::size_t N; // Variable to store the size of matrices
    file >> N; // Read the matrix size from the file

    // Temp storage for matrix data
    std::vector<std::vector<int>> matrix1(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> matrix2(N, std::vector<int>(N, 0));

    // Read 1st matrix from file
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix1[i][j]; // Read each value
        }
    }

    // Read 2nd matrix from file
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix2[i][j]; // Read each value
        }
    }

    // Assign values to the 1st matrix
    mat1 = Matrix(matrix1);
    // Assign values to the 2nd matrix
    mat2 = Matrix(matrix2);

    return true;
}
