def max_travel_time(x, positions, times):
    return max(t + abs(x - pos) for t, pos in zip(times, positions))

def find_optimal_position(n, positions, times):
    left = min(positions)
    right = max(positions)
    
    # Binary search done with precision
    while right - left > 1e-7:  
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3
        
        if max_travel_time(mid1, positions, times) < max_travel_time(mid2, positions, times):
            right = mid2
        else:
            left = mid1
            
    return (left + right) / 2

# Input taken
n = int(input())
positions = list(map(int, input().split()))
times = list(map(int, input().split()))

# Finds and prints the optimal position
optimal_position = find_optimal_position(n, positions, times)
print(f"{optimal_position:.6f}")
