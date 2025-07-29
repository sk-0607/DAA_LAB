import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data
df = pd.read_csv("sort_times.csv")

# Unique values
cases = ["ascending", "descending", "random"]
algorithms = df['algorithm'].unique()dddcxvdcxdcxvzdcxfvzdcsxgbfv
colors = {"selection": "red", "insertion": "orange", "quick": "green", "merge": "blue"}

# Plot for each case
for case in cases:
    plt.figure(figsize=(8, 5))
    for algo in algorithms:
        subset = df[(df["case"] == case) & (df["algorithm"] == algo)]
        plt.plot(subset["input_size"], subset["time"], label=algo, marker='o', color=colors[algo])
    
    plt.title(f"Sorting Performance - {case.capitalize()} Case")
    plt.xlabel("Input Size")
    plt.ylabel("Time (seconds)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"plot_{case}.png")
    plt.show()

# Plot all cases together
plt.figure(figsize=(10, 6))
for case in cases:
    for algo in algorithms:
        subset = df[(df["case"] == case) & (df["algorithm"] == algo)]
        plt.plot(subset["input_size"], subset["time"], label=f"{algo} ({case})", marker='o')

plt.title("Sorting Performance - All Cases")
plt.xlabel("Input Size")
plt.ylabel("Time (seconds)")
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
plt.grid(True)
plt.tight_layout()
plt.savefig("plot_all_cases.png")
plt.show()
