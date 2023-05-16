# %%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#
# %%
data = pd.read_csv("headbrain.csv")
data.shape
data.head(5)

# %%
# X = data["Head Size(cm^3)"].values
# Y = data["Brain Weight(grams)"].values
X = [0, 0.25, 0.5, 0.75, 1]
Y = [1, 1.2840, 1.6487, 2.1170, 2.7183]

# %%
mean_x = np.mean(X)
mean_y = np.mean(Y)
n = len(X)
# %%
# Using the formula to calculate 'm' and 'c'
numer = 0
denom = 0
for i in range(n):
    numer += (X[i] - mean_x) * (Y[i] - mean_y)
    denom += (X[i] - mean_x) ** 2
m = numer / denom
c = mean_y - (m * mean_x)
# %%
max_x = 3
min_x = 3

x = np.linspace(min_x, max_x, 1)
y = c + m * x
plt.plot(x, y, color="#58b970", label="Regression Line")
# Ploting Scatter Points
plt.scatter(X, Y, c="#ef5423", label="Scatter Plot")

plt.xlabel("Head Size in cm3")
plt.ylabel("Brain Weight in grams")
plt.legend()
plt.show()

# %%
