def can_sort_array(n, x, arr):
    # Store original indices and their values
    indexed_arr = list(enumerate(arr))
    
    # Sort the array to find the desired order
    sorted_arr = sorted(arr)
    
    # Check if each index can reach its sorted position
    visited = [False] * n  # Track visited indices
    for i in range(n):
        if visited[i]:
            continue
        
        # Explore the component for this index
        component_indices = []
        stack = [i]
        while stack:
            current = stack.pop()
            if visited[current]:
                continue
            visited[current] = True
            component_indices.append(current)
            
            # Find indices that are part of the same component
            for j in range(n):
                if not visited[j] and abs(current - j) >= x:
                    stack.append(j)
        
        # Check if this component can be sorted correctly
        component_values = [arr[idx] for idx in component_indices]
        sorted_component_values = sorted(component_values)
        for idx, val in zip(sorted(component_indices), sorted_component_values):
            if sorted_arr[idx] != val:
                return "NO"
    
    return "YES"

# Input Reading (single line)
data = list(map(int, input().split()))
n = data[0]
x = data[1]
arr = data[2:]

# Solve and Output Result
print(can_sort_array(n, x, arr))
