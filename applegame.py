import random


def generate_grid(rows, cols, min_val, max_val):
    return [[random.randint(min_val, max_val) for _ in range(cols)] for _ in range(rows)]


grid = generate_grid(17, 10, 1, 9)

print(grid)


def find_rectangles(grid, target_sum=10):
    rows = len(grid)
    cols = len(grid[0])
    valid_rectangles = []

    for height in range(1, rows + 1):
        for width in range(1, cols + 1):
            for row in range(rows - height + 1):
                for col in range(cols - width + 1):
                    if rectangle_sum(grid, row, col, height, width) == target_sum:
                        valid_rectangles.append((row, col, height, width))

    return valid_rectangles


def rectangle_sum(grid, top_row, left_col, height, width):
    return sum(grid[r][c] for r in range(top_row, top_row + height) for c in range(left_col, left_col + width))


# Example usage with a sample grid
rectangles = find_rectangles(grid)
print(f"Found rectangles: {rectangles}")


def is_overlapping(rect1, rect2):
    # Check if two rectangles overlap
    r1y1, r1x1, r1h, r1w = rect1
    r1y2, r1x2 = r1y1 + r1h, r1x1 + r1w
    r2y1, r2x1, r2h, r2w = rect2
    r2y2, r2x2 = r2y1 + r2h, r2x1 + r2w

    return not (r1x2 <= r2x1 or r1x1 >= r2x2 or r1y2 <= r2y1 or r1y1 >= r2y2)


def optimize_apples(rectangles):
    # Sort by area (number of apples)
    rectangles = sorted(rectangles, key=lambda x: x[2]*x[3], reverse=True)
    chosen_rectangles = []

    for rect in rectangles:
        if not any(is_overlapping(rect, chosen) for chosen in chosen_rectangles):
            chosen_rectangles.append(rect)

    return chosen_rectangles


# Example usage
chosen_rectangles = optimize_apples(rectangles)
print(f"Chosen rectangles: {chosen_rectangles}")


def solve_grid(grid):
    rectangles = find_rectangles(grid)
    chosen_rectangles = optimize_apples(rectangles)
    # Each rect is a list of coordinates
    score = sum(len(rect) for rect in chosen_rectangles)
    return score, chosen_rectangles


score, steps = solve_grid(grid)
print(f"Score: {score}, Steps: {steps}")
