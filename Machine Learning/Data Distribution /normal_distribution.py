import numpy
import matplotlib.pyplot as plt

# Creates an array containing 250 random floats from 0 and 5
x = numpy.random.normal(5.0, 1.0, 100000)

# Creates histogram with 5 bars
plt.hist (x,100)
plt.show()
