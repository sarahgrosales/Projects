import numpy
import matplotlib.pyplot as plt

# Creates an array containing 250 random floats from 0 and 5
x = numpy.random.uniform(0.0, 5.0, 250)

# Creates histogram with 5 bars
plt.hist (x,5)
plt.show()
