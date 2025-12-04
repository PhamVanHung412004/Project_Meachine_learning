import numpy as np
from numpy.linalg import norm

def main():
    array = np.array([1,2,3])
    a = np.array([1,1])
    l1 = norm(a,1)
    l2 = norm(a,2)
    print("l1 = {} l2 = {}".format(l1,l2))
    

if __name__ == "__main__":
    main()