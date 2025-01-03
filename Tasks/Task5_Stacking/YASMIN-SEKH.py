def find_median_height():
    """
    Finds the median height of stacks after applying K instructions.
    Takes input from the user.
    """
    # Input: N (number of stacks) and K (number of instructions)
    N, K = map(int, input("Enter N (number of stacks) and K (number of instructions): ").split())

    # Initialize the difference array
    diff = [0] * (N + 2)  # Extra space for boundary handling

    # Input instructions and process updates
    print(f"Enter {K} instructions (A B):")
    for _ in range(K):
        A, B = map(int, input().split())
        diff[A] += 1
        diff[B + 1] -= 1

    # Compute heights using prefix sum
    heights = []
    current_height = 0
    for i in range(1, N + 1):
        current_height += diff[i]
        heights.append(current_height)

    # Find the median (N is odd, so median is at index N//2)
    median = sorted(heights)[N // 2]
    print(median)


# Run the function
if __name__ == "__main__":
    find_median_height()
