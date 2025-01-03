def can_sort_array_with_logic():
    n, x = map(int, input("Enter n and x: ").split())
    a = list(map(int, input("Enter the array elements: ").split()))
    a_sort = sorted(a)
    f = True
    for i in range(n - x, x):
        if 0 <= i < n and a_sort[i] != a[i]:
            f = False
            break
    print("YES" if f else "NO")

if __name__ == "__main__":
    print("Test Case 1:")
    can_sort_array_with_logic()  
    
    print("\nTest Case 2:")
    can_sort_array_with_logic()  