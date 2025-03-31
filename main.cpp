#include "matrix.hpp"
#include <iostream>

// Program execution starts here
int main() {
    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;

    Matrix mat1(0), mat2(0);

    // (1) Get into and print matrix
    if (!load_matrices_from_file(filename, mat1, mat2)) {
        return 1;
    }
    std::cout << "\n(1/7) Printing Matrix info from file:";
    std::cout << "\nMatrix 1:\n";
    mat1.print_matrix();
    std::cout << "\nMatrix 2:\n";
    mat2.print_matrix();

    // (2) Matrix Addition
    Matrix sumMatrix = mat1 + mat2;
    std::cout << "\n(2/7) Sum of Matrices:\n";
    sumMatrix.print_matrix();

    // (3) Matrix Multiplication
    Matrix prodMatrix = mat1 * mat2;
    std::cout << "\n(3/7) Product of Matrices:\n";
    prodMatrix.print_matrix();

    // (4) Sum of Diagonal Elements
    std::cout << "\n(4/7) Sum of Major Diagonal (Matrix 1): " << mat1.sum_diagonal_major() << std::endl;
    std::cout << "(4/7) Sum of Minor Diagonal (Matrix 1): " << mat1.sum_diagonal_minor() << std::endl;
    std::cout << "\n(4/7) Sum of Major Diagonal (Matrix 2): " << mat2.sum_diagonal_major() << std::endl;
    std::cout << "(4/7) Sum of Minor Diagonal (Matrix 2): " << mat2.sum_diagonal_minor() << std::endl;

    // (5) Swapping Rows (mat 1)
    std::size_t r1, r2;
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> r1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> r2;
    if ( (r1 < 0 || r1 >= mat1.get_size()) || (r2 < 0 || r2 >= mat1.get_size()) ) {
        std::cout << "\ninvalid row index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat1.swap_rows(r1, r2);
        std::cout << "(5/7) Matrix 1 after swapping rows:\n";
        mat1.print_matrix();
    }
    // Swapping Rows (mat 2)
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> r1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> r2;
    if ( (r1 < 0 || r1 >= mat2.get_size()) || (r2 < 0 || r2 >= mat2.get_size()) ) {
        std::cout << "\ninvalid row index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat2.swap_rows(r1, r2);
        std::cout << "(5/7) Matrix 2 after swapping rows:\n";
        mat2.print_matrix();
    }

    // (6) Swapping Columns (mat 1)
    std::size_t c1, c2;
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c2;
    if ( (c1 < 0 || c1 >= mat1.get_size()) || (c2 < 0 || c2 >= mat1.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat1.swap_cols(c1, c2);
        std::cout << "(6/7) Matrix 1 after swapping cols:\n";
        mat1.print_matrix();
    }
    // Swapping Columns (mat 2)
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c2;
    if ( (c1 < 0 || c1 >= mat2.get_size()) || (c2 < 0 || c2 >= mat2.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat2.swap_cols(c1, c2);
        std::cout << "(6/7) Matrix 2 after swapping cols:\n";
        mat2.print_matrix();
    }

    // (7) Updating a Single Value (mat 1)
    std::size_t row, col;
    int newVal;
    std::cout << "\nEnter row index for new value update for (Matrix 1): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 1): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 1): ";
    std::cin >> newVal;
    if ( (row< 0 || row >= mat1.get_size()) || (col < 0 || col >= mat1.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat1.set_value(row, col, newVal);
        std::cout << "(7/7) Matrix 1 after updating value:\n";
        mat1.print_matrix();
    }
    // Updating a Single Value (mat 2)
    std::cout << "\nEnter row index for new value update for (Matrix 2): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 2): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 2): ";
    std::cin >> newVal;
    if ( (row< 0 || row >= mat2.get_size()) || (col < 0 || col >= mat2.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        mat2.set_value(row, col, newVal);
        std::cout << "(7/7) Matrix 2 after updating value:\n";
        mat2.print_matrix();
    }

    return 0;
}

