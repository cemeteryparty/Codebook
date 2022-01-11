# 2021 Introduction to Machine Learning Final Project - Mines Identification by Sonar

---
#### Author: 賴品樺 Pin-Hua Lai
#### Student ID: 0716085
---

# Introduction

This work is the final project of 2021 Introduction to Machine Learning course. I use the Connectionist Bench (Sonar, Mines vs. Rocks) Data Set as my datset. In this dataset, it provides some power spectral density (PSD) from the sonar response and we need to use these responses to classify an object is rock or mines. I use few different machine learning models in this work, including **Decision Tree**, **K-NN**, **Support Vector Machine** and neural network approach.

# Relative Work

## Dataset Information

The dataset i used is [Connectionist Bench (Sonar, Mines vs. Rocks) Data Set](https://archive.ics.uci.edu/ml/datasets/Connectionist+Bench+(Sonar,+Mines+vs.+Rocks)). The data is sonar responses collected from a metal cylinder and a cylindrically shaped rock. There is 208 samples in this dataset, 111 of them are the sonor response from the mines, and the remaining 97 samples are the response from the rock. Each sample has 60 numbers that represent the spectral of the sonor response and each number is the energy within a particular frequency band integrated over a certain period of time. The values are normalized between 0.0 and 1.0.

### Data Analyze

![](https://i.imgur.com/HebxVQR.png)
<center> Figure 1: left is rocks' attribute distribution, right is mines' attribute distribution </center>

Figure 1 presents the data distribution of each attribute. The left subfigure is the distribution of the class is rock only, the right one is the distribution of the class is mines only. Compare these two subfigures, most attributes (frequency band in this dataset) share the similar distribution in both classes. By visualization, 25-35 attributes have more difference distribution between two classes. We can get the same conculusion by Figure 2.

![](https://i.imgur.com/yFHgQXJ.png)
<center> Figure 2: Average value over 2 classes in 60 attributes </center>

## Used Model

In this section, there is a brief introduction of 4 different machine learning model I used, and also the parameter setting in each model.

### Decision Tree

Decision Tree is a decision model that use the tree data structure. During the training process, the parent node will try to find an attribute and a threshold to minimize the data impurity of its child nodes or maximum the information gain. By selecting best attribute and threshold, the parents node will split the given data to 2 child nodes (binary case). Under the classification task, with the attribute and the threshold value in each node, we can easily understand the rule of classification.

### K-Nearest Neighbors Algorithm (KNN)

K-Nearest Neighbors is an algorithm without training parameter. This algorithm supposes that the sample in the same class will distribute in a cluster in the data space. Thus, the nearest sample is most likely that has same class with the target sample. The only parameter k is used for preventing bias of single sample. In the prediction stage, the algorithm will find k nearest neighbors and select the highest class of these neighbors to assign the class to the target. In this work, I build the KNN model with 8 different k setting.

### Support Vector Machine (SVM)

Support Vector Machine (SVM) is one kind of supervised learning model. During the training process, SVM will try to find hyperplanes to seperate each class in the data space and maximize the distance from hyperplane to the nearest data point. There is 2 type of SVM kernel design, linear kernel and nonlinear kernel. In this work, I build the SVM model with linear kernel and 2 kind of nonlinear kernel, polynomial and radial basis function (rbf).

### Neural Network

The NN-based machine learning model has been very popular from few years ago. A neural network generally contain an input layer, an output layer and few hidden layers. Each layer is composed by few neurons and the model will use these neurons to extract and amplify the important feature. During the training process, the model will update these feature patterns to minimize the training loss. In this work, I use Tensorflow-Keras to build 2 model structure, a simple NN and a convolutional NN (CNN).

# Result

### Decision Tree

The ratio of testing set size to the training set size is 2:8. To reduce the effect of the data bias, I use 10 differnt seed to split the training and testing set and train and evalute the decision tree model by the splitted set. The average test accurancy is **0.7219** and the standard deveration is ***0.0613***. Below is the box plot of 10 times experiment.
![](https://i.imgur.com/a6yJ0JE.png)

### K-Nearest Neighbors Algorithm (KNN)

I tested 8 KNN model with parameter k from 1 to 8. Each model will train and evalute for 10 times. Below is the table and the box plot of the model performance. The best performance is at k=2, the accurancy is ***0.8302***.
<style>
th, td {
    text-align:center;
}
</style>

<table>
	<tbody>
		<tr>
			<th> k\ </th>
			<th> ACC </th>
			<th> STD </th>
		</tr>
		<tr>
			<th> 1 </th>
			<td> 0.8181 </td>
			<td> 0.0544 </td>
		</tr>
		<tr>
			<th> 2 </th>
			<td> 0.8302 </td>
			<td> 0.0553 </td>
		</tr>
        <tr>
			<th> 3 </th>
			<td> 0.8148 </td>
			<td> 0.0439 </td>
		</tr>
        <tr>
			<th> 4 </th>
			<td> 0.8084 </td>
			<td> 0.0559 </td>
		</tr>
        <tr>
			<th> 5 </th>
			<td> 0.7893 </td>
			<td> 0.0623 </td>
		</tr>
        <tr>
			<th> 6 </th>
			<td> 0.7744 </td>
			<td> 0.0653 </td>
		</tr>
        <tr>
			<th> 7 </th>
			<td> 0.7437 </td>
			<td> 0.0671 </td>
		</tr>
        <tr>
			<th> 8 </th>
			<td> 0.7256 </td>
			<td> 0.0641 </td>
		</tr>
	<tbody>
</table>

![](https://i.imgur.com/dyyxJwX.png)

### Support Vector Machine (SVM)

#### Linear Kernel

In linear kernel, I use the same train-test scheme in the one in decision tree model. The average accurancy over 10 experiments is ***0.7581*** and the std is ***0.0572***.
![](https://i.imgur.com/SpjKnGf.png)

#### Polynominal Kernel

For the polynominal kernel, because the parameter degree, gamma and coef0 need to be determined, we use a fixed random seed to split the training and testing set and use the grid search and 5-fold cross validaion to find a set of parameter that can maximum the validation accurancy. With the set of parameter, I will use this setting to train and evaluate the SVM model for 10 times. The parameter that returned from grid search is coef0=18, degree=4, gamma=1.895. The average accurancy over 10 experiments is ***0.8326*** and the std is ***0.0342***.

![](https://i.imgur.com/dgkkNCu.png)

#### RBF Kernel

For the polynominal kernel, I used grid search and 5-fold cross validaion to find the setting of gamma that can maximum the validation accurancy. The return best gamma is 3.697. The RBF kernel SVM model was trained and evaluted for 10 times with the same scheme above. The average accurancy over 10 experiments can reach ***0.8442*** with std is ***0.0499***.

![](https://i.imgur.com/SA67DlK.png)

### Neural Network

#### Simple ANN




# Conculsion

