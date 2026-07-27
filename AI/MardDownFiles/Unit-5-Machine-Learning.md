````md
# Machine Learning Introduction and Description

## 1. Relationship Between AI, Machine Learning, and Deep Learning

```
+------------------------+
| Artificial Intelligence|
+------------------------+
            |
            v
+------------------------+
| Machine Learning       |
+------------------------+
            |
            v
+------------------------+
| Deep Learning          |
+------------------------+
```

### Artificial Intelligence (AI)
AI is the broad field of making machines perform tasks that normally require human intelligence, such as reasoning, learning, problem-solving, and decision-making.

### Machine Learning (ML)
Machine Learning is a branch of AI where machines learn patterns from data and improve performance without being explicitly programmed for every rule.

### Deep Learning (DL)
Deep Learning is a subset of ML that uses multi-layered artificial neural networks to learn complex patterns from large datasets.

---

## 2. Genetic Algorithm

A **Genetic Algorithm (GA)** is an optimization and search technique inspired by natural evolution.

### Main ideas of GA:
- Population: A group of possible solutions
- Fitness function: Measures how good a solution is
- Selection: Chooses the best solutions
- Crossover: Combines two solutions to create new ones
- Mutation: Introduces small random changes

### Applications:
- Optimization problems
- Scheduling
- Routing
- Feature selection
- Machine learning parameter tuning

---

## 3. Artificial Neural Network (ANN)

An Artificial Neural Network is a computational model inspired by the human brain. It consists of interconnected processing units called neurons or nodes.

### Components of ANN

1. Neurons / Nodes  
   Basic processing units that receive input, compute output, and pass signals forward.

2. Weights  
   Strength of connections between neurons.

3. Bias  
   Extra constant input used to shift the output.

4. Activation Function  
   Determines whether a neuron should be activated or not.

---

## 4. Activation Functions

Activation functions are used to introduce non-linearity into a neural network.

### Common Activation Functions
- Linear Function
- Threshold Function
- Sigmoid Function

### Brief Description

| Function           | Description                                            | Output     |
|------------------|--------------------------------------------------------|------------|
| Linear Function   | Output is directly proportional to input              | Continuous |
| Threshold Function| Output becomes 1 or -1 based on a cutoff value        | Binary     |
| Sigmoid Function  | Smooth S-shaped curve, useful for probabilistic output| 0 to 1     |

---

## 5. Types of Artificial Neural Networks (ANN)

### Based on architecture:

1. Single-Layer Feedforward Network
   - Input layer connected directly to output layer
   - No hidden layer

2. Multilayer Feedforward Network
   - Contains one or more hidden layers
   - Used for complex pattern recognition

3. Recurrent Neural Network (RNN)
   - Has feedback connections
   - Output depends on previous states

4. Convolutional Neural Network (CNN)
   - Mainly used for image and spatial data processing

### Based on learning:

1. Supervised Learning Network
2. Unsupervised Learning Network
3. Reinforcement Learning Network

---

## 6. Hebbian Learning

### Donald Hebb, 1949
Donald Hebb introduced the Hebbian learning principle in 1949.

### Hebbian Network
A Hebbian network is an unsupervised feedforward network based on the rule:

- If two connected neurons are activated synchronously → weight increases
- If two connected neurons are activated asynchronously → weight decreases

### Hebb’s Rule

```
Δw_i = X_i × Y
Δb   = Y
```

New weight:
```
w_new = w_old + Δw
```

---

## 7. Design a Hebb Network to Implement Logical AND Function

### Training Data

```
+-----+-----+-----+-----+
| X1  | X2  |  b  |  Y  |
+-----+-----+-----+-----+
|  1  |  1  |  1  |  1  |
|  1  | -1  |  1  | -1  |
| -1  |  1  |  1  | -1  |
| -1  | -1  |  1  | -1  |
+-----+-----+-----+-----+
```

### Initial Values
- w1 = 0
- w2 = 0
- b  = 0

### Learning Rule
```
Δw1 = X1 × Y
Δw2 = X2 × Y
Δb  = Y
```

---

### Training Table

```
+-----+-----+-----+-----+------+------+------+---------+---------+--------+
| X1  | X2  |  b  |  Y  | ▲w1  | ▲w2  | ▲b   | w1(new) | w2(new) | b(new) |
+-----+-----+-----+-----+------+------+------+---------+---------+--------+
|  1  |  1  |  1  |  1  |   1  |   1  |   1  |    1    |    1    |   1    |
|  1  | -1  |  1  | -1  |  -1  |   1  |  -1  |    0    |    2    |   0    |
| -1  |  1  |  1  | -1  |   1  |  -1  |  -1  |    1    |    1    |  -1    |
| -1  | -1  |  1  | -1  |   1  |   1  |  -1  |    2    |    2    |  -2    |
+-----+-----+-----+-----+------+------+------+---------+---------+--------+
```

### Final Values
- w1 = 2
- w2 = 2
- b  = -2

---

## 8. Key Points to Remember
- AI is the broadest field
- ML is a subset of AI
- DL is a subset of ML
- ANN is inspired by biological neurons
- Activation functions introduce non-linearity
- Hebbian learning: “neurons that fire together wire together”
- Final AND solution:
  - w1 = 2
  - w2 = 2
  - b  = -2
```
````

