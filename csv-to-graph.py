import pandas as pd
import matplotlib.pyplot as plt
import io

df = pd.read_csv('results.csv')
df_iterative = df.copy()
df_small = df[df['InputSize'] <= 45]


plt.figure(figsize=(10, 6))
plt.plot(df_iterative['InputSize'], df_iterative['IterativeTime_us'], 
         label='Iterative $O(n)$', marker='o', color='blue')

plt.title('Performance: Iterative Only')
plt.xlabel('Input Size (N)')
plt.ylabel('Time (microseconds)')
plt.xscale('log')
plt.grid(True, which="both", ls="-", alpha=0.5)
plt.legend()
plt.tight_layout()
plt.savefig('1_iterative_only.png')
plt.show()


plt.figure(figsize=(10, 6))
plt.plot(df_small['InputSize'], df_small['RecursiveTime_us'], 
         label='Recursive $O(2^n)$', marker='x', color='red')

plt.title('Performance: Recursive Only')
plt.xlabel('Input Size (N)')
plt.ylabel('Time (microseconds)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('2_recursive_only.png')
plt.show()


plt.figure(figsize=(10, 6))

plt.plot(df_small['InputSize'], df_small['IterativeTime_us'], 
         label='Iterative $O(n)$', marker='o', color='blue')

plt.plot(df_small['InputSize'], df_small['RecursiveTime_us'], 
         label='Recursive $O(2^n)$', marker='x', color='red')

plt.title('Performance Comparison: Iterative vs Recursive')
plt.xlabel('Input Size (N)')
plt.ylabel('Time (microseconds)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('3_combined_comparison.png')
plt.show()