import matplotlib.pyplot as plt

size = []
gflops = []
max_gflops = 3.4 * 4
with open("../build/output.dat", "r") as f:
  for line in f.readlines():
    line = line.strip("\n")
    words = line.split(" ")
    size.append(int(words[0]))
    gflops.append(float(words[1]))
plt.title('Performance')
plt.xscale('linear')
plt.yscale('linear')
plt.ylim(0, max_gflops)
plt.xlim(0, 900)
plt.plot(size, gflops, marker='o')
plt.grid()
plt.show()


