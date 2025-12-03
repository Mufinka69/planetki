import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


names = ["Słońce", "Merkury", "Wenus", "Ziemia", "Mars"]

data = pd.read_csv("dane.csv")

n = (len(data.columns) - 1) // 6

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

colors = plt.cm.jet(np.linspace(0, 1, n))

for i in range(n):
    x = data[f"x{i}"]
    y = data[f"y{i}"]
    z = data[f"z{i}"]
    if i == 0:
        color = 'yellow'  
    elif i == 1:
        color = 'grey'
    elif i == 2:
        color = 'orange'
    elif i == 3:
        color = 'green'   
    elif i == 4:
        color = 'red'      
    else:
        color = colors[i]  
    size = 100 if i == 0 else 20
    ax.scatter(x.iloc[0], y.iloc[0], z.iloc[0], color=color, s=size)
    ax.plot(x, y, z, color=color, label=names[i])
    # ax.plot(x, y, z, color=colors[i], label=f"Body {i}")


x_all = data[[f"x{i}" for i in range(n)]].values.flatten()
y_all = data[[f"y{i}" for i in range(n)]].values.flatten()
z_all = data[[f"z{i}" for i in range(n)]].values.flatten()


x_center = (x_all.max() + x_all.min()) / 2
y_center = (y_all.max() + y_all.min()) / 2
z_center = (z_all.max() + z_all.min()) / 2
max_range = max(x_all.max() - x_all.min(),
                y_all.max() - y_all.min(),
                z_all.max() - z_all.min()) / 2

ax.set_xlim(x_center - max_range, x_center + max_range)
ax.set_ylim(y_center - max_range, y_center + max_range)
ax.set_zlim(z_center - max_range, z_center + max_range)

ax.set_box_aspect([1, 1, 1]) 

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
# ax.set_title("n-Body 3D Trajectories")
ax.legend()

# Pokaż wykres
plt.show()