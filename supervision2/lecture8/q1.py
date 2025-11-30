import sys

version = sys.version
major = sys.version_info.major
minor = sys.version_info.minor
micro = sys.version_info.micro
print(f"Full version info: {version}")
print(f"Major: {major}, Minor: {minor}, Micro: {micro}")

import matplotlib.pyplot as plt
import numpy as np

x = np.log(np.array([20, 40, 60, 80, 200,400,600,800,2000,4000,6000,8000]))
y1 = np.log(np.array([3,6,12,17,94,353,784,1414,8845,35288,79904,140279]))
y2 = np.log(np.array([1,5,8,16,96,361,798,1475,9928,79385,203674,401359]))
y3 = np.log(np.array([2,5,11,21,119,458,1114,1855,11664,46426,103529,182771]))

plt.plot(x, y1, 'o', color='red', label='dm_sumarray0')
plt.plot(x, y2, 's', color='green', label='dm_sumarray1')
plt.plot(x, y3, '^', color='blue', label='dm_sumarray2')

fit1 = np.polyfit(x, y1, 1) 
fit2 = np.polyfit(x, y2, 1)
fit3 = np.polyfit(x, y3, 1)

y1_fit = np.polyval(fit1, x)
y2_fit = np.polyval(fit2, x)
y3_fit = np.polyval(fit3, x)

plt.plot(x, y1_fit, '-', color='red', alpha=0.5)
plt.plot(x, y2_fit, '-', color='green', alpha=0.5)
plt.plot(x, y3_fit, '-', color='blue', alpha=0.5)

plt.legend()
plt.show()
