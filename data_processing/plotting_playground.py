import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Read the CSV file into a DataFrame
df = pd.read_csv('build/simulated_state_history.csv')

# Extract x, y, and z positions from the DataFrame
x = df['Position_X']
y = df['Position_Y']
z = df['Position_Z']

ux = df['U_X']
uy = df['U_Y']
uz = df['U_Z']
t = df['Time']

# Create individual plots
plt.figure(figsize=(12, 6))  # Adjust the figure size as needed

# Plot for U_X
plt.subplot(131)  # 1 row, 3 columns, first subplot
plt.plot(t, ux)
plt.xlabel('Time')
plt.ylabel('U_X (m/s^2)')
plt.title('U_X vs. Time')

# Plot for U_Y
plt.subplot(132)  # 1 row, 3 columns, second subplot
plt.plot(t, uy)
plt.xlabel('Time')
plt.ylabel('U_Y (m/s^2)')
plt.title('U_Y vs. Time')

# Plot for U_Z
plt.subplot(133)  # 1 row, 3 columns, third subplot
plt.plot(t, uz)
plt.xlabel('Time')
plt.ylabel('U_Z (m/s^2)')
plt.title('U_Z vs. Time')

# Adjust layout and show the plots
plt.tight_layout()
plt.show()

# Create a 3D scatter plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z, c='b', marker='o', label='Chaser Satellite Position in Hill Frame')
#ax.scatter(x_des, y_des, z_des, c='r', marker='o', label='Desired Position')
# Set labels and title
ax.set_xlabel('X - radial distance (m)')
ax.set_ylabel('Y - along track distance (m)')
ax.set_zlabel('Z - along h direction (m)')
plt.title('Rendezvous from 12km radial offset')
ax.legend()

plt.show()


