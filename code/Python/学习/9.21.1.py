import numpy as np

import matplotlib.pyplot as plt


# def plot_vector(vector, color='blue'):
#     plt.arrow(0, 0, vector[0], vector[1], head_width=0.1, head_length=0.1, fc=color, ec=color)
#     plt.xlim(-1, max(vector[0], 1) + 1)
#     plt.ylim(-1, max(vector[1], 1) + 1)
#     plt.gca().set_aspect('equal', adjustable='box')
#     plt.show()
#
# # 定义一个向量
# vector1 = np.array([2, 3])
#
# # 以箭头形式打印向量
# plot_vector(vector1)
def plot_vectors(vectors, colors):
    for vector, color in zip(vectors, colors):
        plt.arrow(0, 0, vector[0], vector[1], head_width=0.1, head_length=0.1, fc=color, ec=color)

    plt.axhline(0, color='black', linewidth=0.5)
    plt.axvline(0, color='black', linewidth=0.5)

    plt.xlim(-max(abs(vectors[:, 0])) - 1, max(abs(vectors[:, 0])) + 1)
    plt.ylim(-max(abs(vectors[:, 1])) - 1, max(abs(vectors[:, 1])) + 1)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()
# 定义多个向量
vectors = np.array([[3, 0], [0, -1], [-2, 0], [-3, -3], [0, 3]])
colors = ['blue', 'red', 'green', 'green', 'green']

# 打印多个向量
plot_vectors(vectors, colors)
