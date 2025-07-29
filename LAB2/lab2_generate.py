import random
import names
import os

# Define departments and salary range
NAMES = ['Alice','Lois','Peter','Mike','Ben','Joe','Phil','Luke']
DEPARTMENTS = ["HR", "IT", "Finance", "Marketing", "Engineering"]
SALARY_RANGE = (30000.0, 100000.0)  # Min and max salary
OUTPUT_DIR = "employee_data"  # Directory to store output files

# Create output directory if it doesn't exist
if not os.path.exists(OUTPUT_DIR):
    os.makedirs(OUTPUT_DIR)

def generate_employee_records(n, scenario):
    """
    Generate n employee records for the given scenario.
    Returns a list of tuples (id, name, department, salary).
    """
    records = []
    for i in range(n):
        emp_id = i + 1  # IDs start from 1
        name = random.choice(NAMES)
        department = random.choice(DEPARTMENTS)
        salary = round(random.uniform(SALARY_RANGE[0], SALARY_RANGE[1]), 2)
        records.append((emp_id, name, department, salary))

    # Sort or shuffle based on scenario
    if scenario == "best":
        # Already sorted by ID (ascending)
        pass
    elif scenario == "worst":
        # Reverse for descending order
        records = sorted(records, key=lambda x: x[0], reverse=True)
    elif scenario == "average":
        # Shuffle for random order
        random.shuffle(records)

    return records

def write_to_file(records, filename):
    """
    Write employee records to a .txt file in the format: ID,Name,Department,Salary
    """
    filepath = os.path.join(OUTPUT_DIR, filename)
    with open(filepath, 'w') as f:
        for record in records:
            f.write(f"{record[0]},{record[1]},{record[2]},{record[3]}\n")
    print(f"Generated file: {filepath}")

def main():
    # Input sizes
    sizes = [5000, 10000, 20000]
    scenarios = [
        ("best", "ascending_employees"),
        ("worst", "descending_employees"),
        ("average", "random_employees")
    ]

    # Generate files for each size and scenario
    for size in sizes:
        for scenario, prefix in scenarios:
            records = generate_employee_records(size, scenario)
            filename = f"{prefix}_{size}.txt"
            write_to_file(records, filename)

if __name__ == "__main__":
    main()
