import numpy as np
import pandas as pd
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve', 'Frank', 'Grace', 'Hannah'],  
    'Age': [24, 27, 22, 32, 29, 31, 26, 28],  
    'City': ['New York', 'Los Angeles', 'Chicago', 'Houston', 'Phoenix', 'Philadelphia', 'San Antonio', 'San Diego'], 
    'Score': [85.5, 90.0, 78.5, 88.0, 92.5, 80.0, 87.5, 91.0]
    }
df = pd.DataFrame(data)
filtered = df[(df['Age']> 20) & (df['Score']>90)]
print(filtered)







