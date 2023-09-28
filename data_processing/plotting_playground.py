import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Read the CSV file into a DataFrame
df = pd.read_csv('build/simulated_state_history.csv')

# Extract x, y, and z positions from the DataFrame
x = df['Position_X']
y = df['Position_Y']
z = df['Position_Z']

# Create a 3D scatter plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z, c='b', marker='o', label='Position')

# Set labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.title('3D Position Plot')

plt.show()
