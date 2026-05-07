#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>   // Eigen <-> NumPy bridge
#include <Eigen/Dense>

namespace py = pybind11;

// ── The actual C++ function ──────────────────────────────────────────────────
//
//  Input : const ref to a dynamic double matrix  (MatrixXd)
//  Output: dynamic double array                  (ArrayXXd)
//          (returned by value – zero-copy into NumPy on the Python side)
//
//  Eigen::Ref<> is the key: it accepts a NumPy array passed from Python
//  *without* copying the data into a new Eigen object.

Eigen::ArrayXXd matrix_to_array(Eigen::Ref<const Eigen::MatrixXd> mat)
{
    // Example transform: element-wise square, returned as an Array
    return mat.array().square();
}

// ── Binding ──────────────────────────────────────────────────────────────────
PYBIND11_MODULE(eigenbind, m)
{
    m.doc() = "Eigen ↔ NumPy demo: matrix in (ref), array out";

    m.def(
        "matrix_to_array",
        &matrix_to_array,
        py::arg("mat"),                     // named argument for Python callers
        "Square every element. "
        "Input MatrixXd taken by const-ref (no copy); "
        "output ArrayXXd mapped to NumPy."
    );
}