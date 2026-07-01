# Unit 3: Problem Solving by Searching

## 3.1 Definition and State Space Representation

### Problem Solving in AI

Problem solving in AI is the process of finding a sequence of actions that transforms an initial state into a goal state.

It is usually performed by searching through possible actions and states.

General steps:

1. Goal formulation
2. Problem formulation
3. Search for a solution
4. Execute the solution

### Goal Formulation

Goal formulation means deciding what the agent wants to achieve.

Example:

For a route-finding agent, the goal may be:

```text
Reach Kathmandu from Pokhara
```

### Problem Formulation

Problem formulation means defining the problem in a way that a computer can solve using AI techniques, especially search algorithms.

Components of problem formulation:

- Initial state
- State space
- Actions
- Transition model
- Goal test
- Path cost

### State

A state is a representation of a situation at a particular time.

Example:

In the 8-puzzle, a state is one arrangement of the tiles.

### State Space

State space is the set of all possible states reachable from the initial state by applying valid actions.

Example tree:

```text
        A
      /   \
     B     C
    / \     \
   D   E     F
```

The state space contains all nodes such as `A`, `B`, `C`, `D`, `E`, and `F`.

### State Space Representation

A problem can be represented as:

```text
Problem = {S, A, Actions(s), Result(s, a), Cost(s, a)}
```

Where:

- `S` is the initial state.
- `A` is the set of possible actions.
- `Actions(s)` returns actions allowed in state `s`.
- `Result(s, a)` returns the state reached after action `a` in state `s`.
- `Cost(s, a)` gives the cost of applying action `a` in state `s`.

Standard formulation:

```text
Problem = {Initial state, Actions, Transition model, Goal test, Path cost}
```

### Problem as State Space Search

Solving a problem means searching the state space to find a path from the initial state to a goal state.

Example map:

```text
    D   G
   / \ /
  A   F
 /   /
S   E
 \ /
  B
```

If `S` is the initial state and `G` is the goal state, the search algorithm explores possible paths until it finds a path to `G`.

### Well-Defined Problems

A well-defined problem has clear components:

- Initial state
- State description
- State space
- Actions
- Goal test
- Path cost

Example: Route Finding

```text
Initial state: Arad
Actions: Drive from one city to a connected city
Transition model: Result(Arad, drive to Sibiu) = Sibiu
Goal test: Current city is Bucharest
Path cost: Total distance traveled
```

### Ill-Defined Problems

An ill-defined problem lacks clear initial state, actions, goal, or evaluation criteria.

Example:

```text
Become successful
```

This is ill-defined because the goal and steps are not clearly specified.

## 3.2 Solving Problems by Searching

### Search Tree

A search tree represents possible sequences of actions from the initial state.

Each node contains:

- State
- Parent node
- Action that generated it
- Path cost
- Depth

### Search Node vs State

A state is a configuration of the world.

A node is a data structure used by the search algorithm to represent a path to a state.

The same state may appear in multiple nodes if reached by different paths.

### General Tree Search Algorithm

```text
function Tree-Search(problem, strategy) returns solution or failure
    frontier <- initial state node
    loop
        if frontier is empty then return failure
        node <- choose a leaf node from frontier according to strategy
        if node satisfies goal test then return solution
        expand node and add resulting nodes to frontier
```

### Graph Search Algorithm

Graph search avoids repeatedly exploring the same states by keeping an explored set.

```text
function Graph-Search(problem, strategy) returns solution or failure
    frontier <- initial state node
    explored <- empty set
    loop
        if frontier is empty then return failure
        node <- choose a node from frontier according to strategy
        if node satisfies goal test then return solution
        add node.state to explored
        for each child of node
            if child.state is not in explored or frontier
                add child to frontier
```

### Search Strategies

Search strategies decide which node should be expanded next.

Two main types:

- Uninformed search
- Informed search

### Uninformed Search

Uninformed search has no extra information about how close a state is to the goal.

It uses only the problem definition.

Examples:

- Breadth First Search
- Depth First Search
- Depth Limited Search
- Iterative Deepening Search
- Uniform Cost Search
- Bidirectional Search

### Informed Search

Informed search uses extra knowledge, usually a heuristic function, to guide the search toward the goal.

Examples:

- Greedy Best First Search
- A* Search
- Hill Climbing
- Simulated Annealing

## Performance Evaluation of Search Strategies

Search algorithms are evaluated using:

- Completeness
- Optimality
- Time complexity
- Space complexity

### Completeness

A search algorithm is complete if it is guaranteed to find a solution when a solution exists.

### Optimality

A search algorithm is optimal if it always finds the best solution, usually the lowest-cost path.

### Time Complexity

Time complexity measures how many nodes are generated or expanded.

Common variables:

- `b`: branching factor, maximum number of successors per node
- `d`: depth of the shallowest goal
- `m`: maximum depth of the search tree
- `l`: depth limit

### Space Complexity

Space complexity measures the maximum number of nodes stored in memory.

## 3.3 Uninformed Search

### Breadth First Search

Breadth First Search expands the shallowest nodes first.

It uses a FIFO queue.

Algorithm:

```text
function BFS(problem) returns solution or failure
    frontier <- FIFO queue with initial node
    explored <- empty set
    while frontier is not empty
        node <- pop front of frontier
        if goal-test(node.state) then return solution
        add node.state to explored
        for each child of node
            if child.state not in explored or frontier
                push child at back of frontier
    return failure
```

Properties:

- Complete: Yes, if branching factor is finite
- Optimal: Yes, if all step costs are equal
- Time complexity: `O(b^d)`
- Space complexity: `O(b^d)`

Example use:

Finding the shortest path in an unweighted graph.

### Depth First Search

Depth First Search expands the deepest node first.

It uses a LIFO stack or recursion.

Algorithm:

```text
function DFS(problem) returns solution or failure
    frontier <- stack with initial node
    explored <- empty set
    while frontier is not empty
        node <- pop top of frontier
        if goal-test(node.state) then return solution
        add node.state to explored
        for each child of node
            if child.state not in explored or frontier
                push child onto stack
    return failure
```

Properties:

- Complete: No, if infinite-depth paths exist
- Optimal: No
- Time complexity: `O(b^m)`
- Space complexity: `O(bm)`

Advantages:

- Low memory requirement
- Simple implementation

Disadvantages:

- Can get stuck in deep or infinite paths
- May return a non-optimal solution

### Depth Limited Search

Depth Limited Search is DFS with a fixed depth limit `l`.

It prevents DFS from going beyond a certain depth.

Algorithm idea:

```text
function DLS(node, limit)
    if goal-test(node.state) then return solution
    else if limit = 0 then return cutoff
    else
        for each child of node
            result <- DLS(child, limit - 1)
            if result is solution then return result
        return failure or cutoff
```

Properties:

- Complete: Yes, if solution depth is less than or equal to limit
- Optimal: No
- Time complexity: `O(b^l)`
- Space complexity: `O(bl)`

Limitation:

If the limit is too small, the solution will not be found.

### Iterative Deepening Search

Iterative Deepening Search repeatedly applies depth limited search with increasing depth limits.

```text
limit = 0, 1, 2, 3, ...
```

Algorithm:

```text
function IDS(problem)
    for depth from 0 to infinity
        result <- DLS(problem, depth)
        if result is not cutoff then return result
```

Properties:

- Complete: Yes, if branching factor is finite
- Optimal: Yes, if step costs are equal
- Time complexity: `O(b^d)`
- Space complexity: `O(bd)`

Advantage:

It combines the completeness of BFS with the low memory usage of DFS.

### Uniform Cost Search

Uniform Cost Search expands the node with the lowest path cost `g(n)`.

It uses a priority queue ordered by path cost.

Algorithm:

```text
function UCS(problem) returns solution or failure
    frontier <- priority queue ordered by g(n)
    add initial node to frontier
    explored <- empty set
    while frontier is not empty
        node <- pop node with lowest g(n)
        if goal-test(node.state) then return solution
        add node.state to explored
        for each child of node
            if child has lower path cost than existing frontier node
                add or replace child in frontier
    return failure
```

Properties:

- Complete: Yes, if step costs are positive
- Optimal: Yes
- Time complexity: depends on path costs, often exponential
- Space complexity: stores many frontier nodes

Use:

Finding the least-cost path when action costs are not equal.

### Bidirectional Search

Bidirectional Search searches forward from the initial state and backward from the goal state. It stops when the two searches meet.

Example:

```text
Start -> A -> B -> C
                  ^
Goal  -> F -> E -> D
```

Properties:

- Complete: Yes, if both searches use BFS and branching factor is finite
- Optimal: Yes, for equal step costs with BFS
- Time complexity: `O(2b^(d/2))`, usually written as `O(b^(d/2))`
- Space complexity: `O(b^(d/2))`

Advantages:

- Much faster than ordinary BFS for large depth

Limitations:

- Need to know the goal state clearly
- Need ability to search backward
- Meeting test can be complex

## 3.4 Informed Search

### Heuristic Function

A heuristic function estimates the cost or distance from a state to the goal.

Syntax:

```text
h(n) = estimated cost from node n to goal
```

Example:

In route finding, straight-line distance to the destination can be used as a heuristic.

### Admissible Heuristic

A heuristic is admissible if it never overestimates the true cost to reach the goal.

Syntax:

```text
h(n) <= h*(n)
```

Where:

- `h(n)` is the estimated cost.
- `h*(n)` is the true lowest cost from `n` to the goal.

Example:

Straight-line distance is admissible for road distance because the actual road distance cannot be shorter than the straight-line distance.

### Greedy Best First Search

Greedy Best First Search expands the node that appears closest to the goal according to the heuristic.

Evaluation function:

```text
f(n) = h(n)
```

Properties:

- Complete: Not always
- Optimal: No
- Time complexity: exponential in worst case
- Space complexity: exponential in worst case

Advantage:

Can be fast if the heuristic is good.

Disadvantage:

May choose a path that looks good locally but is not best globally.

### A* Search

A* Search combines path cost and heuristic estimate.

Evaluation function:

```text
f(n) = g(n) + h(n)
```

Where:

- `g(n)` is the cost from initial state to node `n`.
- `h(n)` is the estimated cost from node `n` to goal.
- `f(n)` is the estimated total cost of the path through `n`.

Algorithm:

```text
function A-Star(problem) returns solution or failure
    frontier <- priority queue ordered by f(n) = g(n) + h(n)
    add initial node
    explored <- empty set
    while frontier is not empty
        node <- pop node with lowest f(n)
        if goal-test(node.state) then return solution
        add node.state to explored
        for each child of node
            compute g(child), h(child), f(child)
            if child is better than existing path
                add or update child in frontier
```

Properties:

- Complete: Yes, under standard conditions with positive costs
- Optimal: Yes, if heuristic is admissible and consistent
- Time complexity: exponential in worst case
- Space complexity: exponential because many nodes are stored

### Optimality and Admissibility in A*

A* is optimal if its heuristic is admissible for tree search.

For graph search, A* is optimal when the heuristic is consistent.

Consistent heuristic:

```text
h(n) <= c(n, a, n') + h(n')
```

This means the estimated cost from `n` to the goal is no greater than the cost of reaching successor `n'` plus the estimated cost from `n'` to the goal.

### Hill Climbing Search

Hill climbing is a local search algorithm. It repeatedly moves to a neighboring state that is better than the current state.

It uses a greedy approach and does not usually allow backtracking.

Algorithm:

```text
function Hill-Climbing(problem) returns state
    current <- initial state
    loop
        neighbor <- best successor of current
        if neighbor is not better than current
            return current
        current <- neighbor
```

Use:

Hill climbing is useful for optimization problems where the goal is to maximize or minimize an objective function.

Limitations:

- Local maxima
- Plateau
- Ridge

#### Local Maxima

A local maximum is a state that is better than its neighbors but not the best overall solution.

Hill climbing stops at a local maximum because all neighboring moves look worse.

Solution:

Use random restart or simulated annealing.

#### Plateau

A plateau is a flat area where neighboring states have the same value.

The algorithm may not know which direction to move.

Solutions:

- Sideways moves
- Random restart
- Jump to another state

#### Ridge

A ridge is a region where progress requires a sequence of moves that may not directly improve the value.

Solution:

Allow more flexible moves, backtracking, or stochastic search.

### Simulated Annealing Search

Simulated annealing is a local search algorithm that sometimes accepts worse moves to escape local maxima.

It is inspired by the annealing process in metallurgy.

Idea:

- At high temperature, the algorithm accepts more random moves.
- As temperature decreases, it becomes more selective.

Probability of accepting a worse move:

```text
P = e^(DeltaE / T)
```

Where:

- `DeltaE` is the change in value.
- `T` is temperature.

For minimization problems, a common form is:

```text
P = e^(-DeltaE / T)
```

Advantages:

- Can escape local maxima
- Useful for optimization

Disadvantage:

Performance depends on cooling schedule.

## 3.5 Game Playing and Adversarial Search

### Game Playing in AI

Game playing is a classic AI problem where an agent chooses moves in a competitive environment.

Examples:

- Chess
- Checkers
- Tic-tac-toe
- Go

Game-playing problems usually involve:

- Multiple agents
- Opposing goals
- Search tree of possible moves
- Evaluation function

### Adversarial Search

Adversarial search is search in a competitive environment where one agent's gain may be another agent's loss.

### Minimax Search

Minimax is used for two-player, zero-sum games.

Assumptions:

- MAX player tries to maximize utility.
- MIN player tries to minimize MAX's utility.
- Both players play optimally.

Algorithm:

```text
function Minimax-Decision(state) returns action
    return action with highest Min-Value(Result(state, action))

function Max-Value(state)
    if terminal-test(state) then return utility(state)
    v <- -infinity
    for each action in Actions(state)
        v <- max(v, Min-Value(Result(state, action)))
    return v

function Min-Value(state)
    if terminal-test(state) then return utility(state)
    v <- +infinity
    for each action in Actions(state)
        v <- min(v, Max-Value(Result(state, action)))
    return v
```

Example:

In tic-tac-toe, MAX may represent `X` and MIN may represent `O`.

Properties:

- Complete: Yes, if game tree is finite
- Optimal: Yes, if opponent is optimal
- Time complexity: `O(b^m)`
- Space complexity: `O(bm)` with depth-first implementation

Where:

- `b` is legal moves per state.
- `m` is maximum depth of game tree.

### Alpha-Beta Pruning

Alpha-beta pruning improves minimax by removing branches that cannot affect the final decision.

Definitions:

- `alpha`: best value found so far for MAX.
- `beta`: best value found so far for MIN.

Pruning condition:

```text
if alpha >= beta then prune
```

Algorithm idea:

```text
function Alpha-Beta-Search(state)
    v <- Max-Value(state, -infinity, +infinity)
    return action with value v
```

Benefits:

- Returns the same result as minimax.
- Expands fewer nodes.
- More efficient with good move ordering.

Time complexity:

- Worst case: `O(b^m)`
- Best case with perfect ordering: `O(b^(m/2))`

## 3.6 Constraint Satisfaction Problems

### Definition

A Constraint Satisfaction Problem is a problem where the solution must satisfy a set of constraints over variables.

A CSP is defined as:

```text
CSP = {V, D, C}
```

Where:

- `V` is a set of variables.
- `D` is a set of domains for the variables.
- `C` is a set of constraints.

### Variables

Variables are the objects whose values must be assigned.

Example:

```text
V = {X1, X2, X3}
```

### Domains

A domain is the set of possible values for a variable.

Example:

```text
D(X1) = {Red, Green, Blue}
```

### Constraints

Constraints restrict the values that variables can take together.

Example:

```text
X1 != X2
```

A constraint may be written as:

```text
C1 = {scope, relation}
```

Example:

```text
C1 = {{V2, V3}, V2 != V3}
```

### Example: Map Coloring

Problem:

Color regions of a map so that neighboring regions have different colors.

```text
Variables: Regions
Domains: {Red, Green, Blue}
Constraints: Adjacent regions must have different colors
```

Example constraint:

```text
Color(A) != Color(B)
```

### Example: N-Queens Problem

Problem:

Place `N` queens on an `N x N` chessboard so that no two queens attack each other.

```text
Variables: Columns
Domains: Rows
Constraints:
    No two queens in same row
    No two queens in same diagonal
```

### Example: Sudoku

```text
Variables: Empty cells
Domains: Digits 1 to 9
Constraints:
    Each row contains 1 to 9 without repetition
    Each column contains 1 to 9 without repetition
    Each 3x3 box contains 1 to 9 without repetition
```

### CSP Solving Methods

Common methods:

- Backtracking search
- Forward checking
- Constraint propagation
- Arc consistency
- Minimum remaining values heuristic
- Degree heuristic
- Least constraining value heuristic

### Backtracking Search

Backtracking assigns values to variables one by one. If a constraint is violated, it goes back and tries another value.

Algorithm:

```text
function Backtracking-Search(csp) returns solution or failure
    return Backtrack({}, csp)

function Backtrack(assignment, csp)
    if assignment is complete then return assignment
    var <- select unassigned variable
    for each value in domain values of var
        if value is consistent with assignment
            add {var = value} to assignment
            result <- Backtrack(assignment, csp)
            if result != failure then return result
            remove {var = value}
    return failure
```

## Search Strategy Summary

| Strategy | Complete | Optimal | Time | Space |
|---|---|---|---|---|
| BFS | Yes | Yes, if equal costs | `O(b^d)` | `O(b^d)` |
| DFS | No in infinite depth | No | `O(b^m)` | `O(bm)` |
| DLS | Yes if limit sufficient | No | `O(b^l)` | `O(bl)` |
| IDS | Yes | Yes, if equal costs | `O(b^d)` | `O(bd)` |
| UCS | Yes if costs positive | Yes | Exponential | Exponential |
| Bidirectional | Yes with BFS | Yes if equal costs | `O(b^(d/2))` | `O(b^(d/2))` |
| Greedy Best First | Not always | No | Exponential | Exponential |
| A* | Yes | Yes with admissible and consistent heuristic | Exponential | Exponential |

## Key Terms

- State: A situation in a problem.
- State Space: Set of all reachable states.
- Search: Process of exploring states to find a goal.
- Frontier: Set of nodes waiting to be expanded.
- Explored Set: Set of already visited states.
- Heuristic: Estimate of closeness to goal.
- Admissible Heuristic: Heuristic that never overestimates true cost.
- CSP: Problem defined by variables, domains, and constraints.

## Short Exam Answers

### What is problem formulation?

Problem formulation is the process of defining an AI problem using initial state, actions, transition model, goal test, and path cost so that a search algorithm can solve it.

### What is the difference between informed and uninformed search?

Uninformed search uses only the problem definition, while informed search uses additional knowledge such as a heuristic function to guide the search toward the goal.

### Why is A* search optimal?

A* search is optimal when its heuristic is admissible and consistent because it expands paths according to the estimated total cost `f(n) = g(n) + h(n)` without overestimating the remaining cost.

