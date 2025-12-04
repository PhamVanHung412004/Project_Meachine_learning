import numpy as np

from numpy.linalg import norm

def exercise1():
    # Định nghĩa x
    x = np.array([1,2,3])
    
    # Định nghĩa y
    y = np.array([-1,-2,3])
    
    # Tính chuẩn x và gán vào biến x_norm2
    x_norm2 = norm(x,2)
    
    # Tính chuẩn y và gán vào biến y_norm2
    y_norm2 = norm(y,2)
    x_norm2, y_norm2 = exercise1()
    print(round(x_norm2, 2), round(y_norm2,2))
if __name__ == "__main__":
    exercise1()    