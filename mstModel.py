import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import make_blobs
from mst_clustering import MSTClustering
import warnings
sns.set()
warnings.filterwarnings('ignore', message='elementwise')

def plot_minimum_spanning_tree(model, cmap='rainbow'):
    # Utility code to visualize a minimum spanning tree
    X = model.X_fit_
    fig, ax = plt.subplots(1, 2, figsize=(16, 6), sharex=True, sharey=True)
    for axi, full_graph, colors in zip(ax, [True, False], ['lightblue', model.labels_]):
        segments = model.get_graph_segments(full_graph=full_graph)
        axi.plot(segments[0], segments[1], '-k', zorder=1, lw=1)
        axi.scatter(X[:,0], X[:,1], c=colors, cmap=cmap, zorder=2)
        axi.axis('tight')

    ax[0].set_title('Full Minimum Spanning Tree', size=16)
    ax[1].set_title('Trimmed Minimum Spanning Tree', size=16)
X, y = make_blobs(200, centers=4, random_state=42)
plt.scatter(X[:,0], X[:,1], c='lightblue')
plt.show()

model = MSTClustering(cutoff_scale=2, approximate=False)
labels = model.fit_predict(X)
plt.scatter(X[:,0], X[:,1], c=labels, cmap='rainbow')
plt.show()

plot_minimum_spanning_tree(model)
plt.show()


rng = np.random.RandomState(int(100 * y[-1]))
noise = -14 + 28 * rng.rand(200, 2)

X_noisy = np.vstack([X, noise])
y_noisy = np.concatenate([y, np.full(200, -1, dtype=int)])

plt.scatter(X_noisy[:,0], X_noisy[:,1], c='lightblue', cmap='spectral_r')
plt.xlim(-15, 15)
plt.ylim(-15, 15)

plt.show()

noisy_model = MSTClustering(cutoff_scale=1)
noisy_model.fit(X_noisy)
plot_minimum_spanning_tree(noisy_model)
plt.show()

noisy_model = MSTClustering(cutoff_scale=1, min_cluster_size=10)
noisy_model.fit(X_noisy)
plot_minimum_spanning_tree(noisy_model)
plt.show()
