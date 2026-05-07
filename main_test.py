#import example
#
#print('*** Example 0: Basic function binding')
#help(example) # should show the docstring for the add function
#print('Should return 5: ', example.add(2, 3)) # should return 5
#print('Should give error: ', example.add(2.5, 3.5)) # should give error (expects ints)





import numpy as np
import eigenbind          # the compiled .so

print('\n*** Example 1: Eigen matrix to NumPy array conversion')

# Create a plain NumPy array – pybind11/eigen maps it directly (no copy)
mat = np.array([[1.0, 2.0, 3.0],
                [4.0, 5.0, 6.0]], dtype=np.float64)
#mat = np.array(np.random.rand(20000, 30000), dtype=np.float64)  # random values for more interesting output

result = eigenbind.matrix_to_array(mat)

print("Input  (matrix):\n", mat)
print("Output (array – element-wise square):\n", result)
print("NumPy dtype:", result.dtype)   # float64
