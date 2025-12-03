import fp_wrapper as fp

def main():
    for k in range(10, 100, 10):
        scale = 1.0 / k
        x1, x2, iters = fp.solve_system(0.5, 0.5, 1e-6, 1000, scale)
        print(f"scale={scale:0.3f} → iterations={iters}")

if __name__ == "__main__":
    main()

