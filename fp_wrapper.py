import ctypes
import os

# Directory of this file
_here = os.path.abspath(os.path.dirname(__file__))

# Shared library path
_libpath = os.path.join(_here, "libfixed_point.so")

if not os.path.exists(_libpath):
    raise FileNotFoundError(f"Cannot find shared library: {_libpath}")

_lib = ctypes.CDLL(_libpath)

# Configure argument types
_lib.fixed_point_solve.argtypes = [
    ctypes.c_double,  # x1_0
    ctypes.c_double,  # x2_0
    ctypes.c_double,  # tol
    ctypes.c_int,     # max_iter
    ctypes.POINTER(ctypes.c_double),  # x1_out
    ctypes.POINTER(ctypes.c_double),  # x2_out
    ctypes.POINTER(ctypes.c_int),     # iters_out
    ctypes.c_double    # scale
]
_lib.fixed_point_solve.restype = ctypes.c_int


def solve_system(x1_0, x2_0, tol, max_iter, scale):
    """Python wrapper for fixed_point_solve."""

    x1_out = ctypes.c_double()
    x2_out = ctypes.c_double()
    iters_out = ctypes.c_int()

    rc = _lib.fixed_point_solve(
        float(x1_0), float(x2_0), float(tol), int(max_iter),
        ctypes.byref(x1_out), ctypes.byref(x2_out),
        ctypes.byref(iters_out), float(scale)
    )

    if rc == -1:
        raise ValueError("Invalid input to fixed_point_solve()")
    if rc == 1:
        print("Warning: solver did not converge within max_iter")

    return x1_out.value, x2_out.value, iters_out.value
