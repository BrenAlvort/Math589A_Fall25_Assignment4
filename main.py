import fp_wrapper as fp

def main():
    x0 = 0.5
    y0 = 0.5
    tol = 1e-6
    max_iter = 1000

    for k in range(10, 100, 10):
        scale = 1.0 / k
        sol1, sol2, iters = fp.solve_system(x0, y0, tol, max_iter, scale)
        print(f"scale = {scale:.3f} → iterations = {iters}")

if __name__ == "__main__":
    main()
