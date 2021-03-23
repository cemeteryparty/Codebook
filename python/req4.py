from matplotlib import pyplot as plt
from scipy.signal import butter, lfilter, firwin
from scipy.io import loadmat
import pandas as pd
import numpy as np

BASE_DIR = "D:/NCTU/109_2/BCI/lab1/"
def main():
	eyeopen_ds = pd.read_csv(BASE_DIR + "eyeOpen.csv")
	eyeclose_ds = pd.read_csv(BASE_DIR + "eyeClosed.csv")
	eoval = eyeopen_ds.values[:, 2]
	ecval = eyeclose_ds.values[:, 2]
	plt.plot(np.array(range(0, eoval.size)), eoval, color = "orange")
	plt.plot(np.array(range(0, ecval.size)), ecval, color = "blue")
	plt.show()
	print(f"open : {eoval.max()} ; {eoval.min()}")
	print(f"close: {ecval.max()} ; {ecval.min()}")
	"""
	x = np.linspace(0, 0.5, 100, endpoint = False)
	yo, yc = np.zeros(100), np.zeros(100)
	for _ in eoval:
		yo[int(_ / 0.005)] += 1
	for _ in ecval:
		yc[int(_ / 0.005)] += 1
	"""
	kwargs = dict(bins = 250, range = (0, 0.5), alpha = 0.3)
	yo = plt.hist(eoval, color = "blue", **kwargs)
	yc = plt.hist(ecval, color = "black", **kwargs)
	plt.show()

	print(yo[0])
	print(yc[0])
if __name__ == "__main__":
	main()