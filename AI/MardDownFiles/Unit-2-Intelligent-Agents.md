# Unit 2: Intelligent Agents

## 2.1 Introduction of Agents

### Agent

An agent is anything that can perceive its environment through sensors and act upon that environment through actuators or effectors.

Basic idea:

```text
Environment -> Sensors -> Agent -> Actuators -> Environment
```

Examples:

- Human agent: eyes and ears are sensors; hands, legs, and mouth are actuators.
- Robotic agent: cameras and touch sensors are sensors; motors and grippers are actuators.
- Software agent: file inputs, network packets, and user commands are sensors; screen output, database updates, and API calls are actuators.

### Intelligent Agent

An intelligent agent is an agent that perceives its environment and acts rationally to achieve goals or maximize a performance measure.

An intelligent agent receives percepts one at a time and maps the percept sequence into actions.

Example of percept sequence for a self-driving car:

```text
t1: Red traffic light -> Stop
t2: Light turns green but car is ahead -> Wait
t3: Car ahead moves and path is clear -> Accelerate
```

The updated percept sequence is:

```text
t1 -> t2 -> t3
```

### Percept, Percept Sequence, and Agent Function

#### Percept

A percept is the input received by an agent from the environment at a particular instant.

Example:

For a vacuum cleaner agent, the percept may be:

```text
(current location = A, status = dirty)
```

#### Percept Sequence

A percept sequence is the complete history of everything the agent has perceived.

Example:

```text
[(A, dirty), (A, clean), (B, dirty)]
```

#### Agent Function

An agent function maps percept sequences to actions.

Syntax:

```text
f: P* -> A
```

Where:

- `P*` means all possible percept sequences.
- `A` means the set of possible actions.

Example:

```text
f([(A, dirty)]) = Suck
f([(A, clean)]) = Right
```

#### Agent Program

An agent program is the actual implementation of the agent function inside a physical system or computer program.

### Rational Agent

A rational agent selects the action that is expected to maximize its performance measure, based on:

- Current percept
- Percept sequence
- Built-in knowledge
- Available actions
- Goals
- Environment

A rational agent does not always need to be perfect. It chooses the best expected action from the information available.

## Structure of an Intelligent Agent

General structure:

```text
Sensors receive percepts
Agent program processes percepts
Actuators perform actions
Environment changes
```

Abstract structure:

```text
function Agent(percept) returns action
    update internal state using percept
    choose best action
    return action
```

Important components:

- Sensors: collect information from the environment.
- Actuators or effectors: perform actions.
- Agent program: chooses actions.
- Architecture: hardware or platform on which the program runs.
- Knowledge base or model: stores facts about the environment.
- Performance measure: evaluates success.

## Properties of Intelligent Agents

### Internal Characteristics: LARG

#### Learning

An intelligent agent should learn from previous experience and improve its behavior over time.

Example:

A recommendation system improves suggestions after observing user choices.

#### Autonomy

An autonomous agent controls its own actions and internal states without continuous human guidance.

Example:

A robot vacuum decides where to clean without being manually controlled every second.

#### Reactivity

An agent must react appropriately to changes in the environment.

Example:

A self-driving car brakes when a pedestrian suddenly crosses the road.

#### Goal-Oriented Behavior

An intelligent agent has goals and acts to achieve them.

Example:

A navigation agent has the goal of reaching the destination safely and efficiently.

### External Characteristics: CCMC

#### Communication

Agents may communicate with users, other agents, or external systems.

Example:

A chatbot communicates with users through text.

#### Cooperation

Multiple agents may cooperate to solve complex tasks.

Example:

Warehouse robots coordinate to move goods efficiently.

#### Mobility

Some agents can move through physical space or transfer code/data across systems.

Example:

A mobile robot moves from one room to another.

#### Character

An agent may display human-like behavior or personality.

Example:

A virtual assistant may speak politely and maintain conversation context.

## 2.2 Configuration of Agents

To design a rational agent, we must specify the task environment. A common method is PEAS.

## PEAS Description of Agents

PEAS stands for:

- Performance measure
- Environment
- Actuators
- Sensors

PEAS helps describe what the agent must achieve and how it interacts with the world.

### PEAS Syntax

```text
Agent type:
Performance measure:
Environment:
Actuators:
Sensors:
```

### Example: Fully Automated Taxi

```text
Agent type: Automated taxi driver
Performance measure: Safety, legality, speed, comfort, profit, fuel efficiency
Environment: Roads, traffic, pedestrians, passengers, traffic lights, weather
Actuators: Steering, accelerator, brake, horn, display, door control
Sensors: Cameras, GPS, speedometer, lidar, radar, microphone, engine sensors
```

### Example: Vacuum Cleaner Agent

```text
Agent type: Vacuum cleaner
Performance measure: Cleanliness, time, energy use, safety
Environment: Rooms, floor, walls, furniture, dirt
Actuators: Move left, move right, move forward, suck dirt, stop
Sensors: Dirt sensor, location sensor, bump sensor, battery sensor
```

### Example: Medical Diagnosis Agent

```text
Agent type: Medical diagnosis system
Performance measure: Accurate diagnosis, safe treatment, low cost, patient recovery
Environment: Patients, diseases, symptoms, medical records, lab results
Actuators: Diagnosis report, treatment recommendation, alert message
Sensors: User input, test results, medical database, patient history
```

### Example: Chess-Playing Agent

```text
Agent type: Chess player
Performance measure: Win, avoid losing, minimize mistakes, use time efficiently
Environment: Chess board, opponent, clock
Actuators: Move chess pieces
Sensors: Board position, legal moves, opponent move, clock time
```

## PAGE Description

Some notes use PAGE as another way to describe an agent task.

PAGE can be understood as:

- Percepts
- Actions
- Goals
- Environment

Example for automated taxi:

```text
Percepts: Road images, speed, nearby vehicles, traffic lights
Actions: Brake, accelerate, steer, turn, stop
Goals: Reach destination safely and legally
Environment: Roads, traffic, weather, pedestrians
```

## 2.3 Types of Agents

### Simple Reflex Agent

A simple reflex agent chooses actions only on the basis of the current percept. It ignores percept history.

It uses condition-action rules.

Syntax:

```text
if condition then action
```

Example:

```text
if room is dirty then suck dirt
if room is clean then move to next room
```

Properties:

- Simple to design
- Works well in fully observable environments
- Does not store internal state
- Does not learn from past percepts
- Has limited intelligence

Pseudo-code:

```text
function Simple-Reflex-Agent(percept) returns action
    state <- interpret percept
    rule <- rule matching state
    action <- rule action
    return action
```

Limitation:

If the environment is partially observable, the agent may make wrong decisions because it has no memory of previous percepts.

### Model-Based Reflex Agent

A model-based agent maintains an internal state to handle partially observable environments.

It uses:

- Current percept
- Previous internal state
- Knowledge of how the world evolves
- Knowledge of what its actions do

Structure:

```text
Current percept + Previous internal state -> Updated internal state -> Rule -> Action
```

Example:

A robot may remember which rooms have already been cleaned even if it cannot see all rooms at once.

Pseudo-code:

```text
function Model-Based-Agent(percept) returns action
    state <- update state using percept and previous action
    rule <- rule matching state
    action <- rule action
    return action
```

Advantages:

- Can work in partially observable environments
- More flexible than simple reflex agent
- Uses memory

### Goal-Based Agent

A goal-based agent chooses actions according to goals.

It uses current state information and goal information to decide what action should be taken.

Example:

A navigation system considers the goal destination before choosing a road.

Characteristics:

- Uses search and planning
- More flexible than reflex agents
- Can compare possible future action sequences

Pseudo-code:

```text
function Goal-Based-Agent(percept) returns action
    state <- update state using percept
    goal <- current goal
    action <- choose action that moves state toward goal
    return action
```

Limitation:

It may know whether a goal is achieved, but it may not know which successful state is better.

### Utility-Based Agent

A utility-based agent chooses actions using a utility function.

A utility function assigns a numeric value to states, showing how desirable or satisfactory they are.

Syntax:

```text
Utility(state) = numeric value of desirability
```

The agent chooses the action that maximizes expected utility.

Example:

For a taxi agent, multiple routes may reach the destination. A utility-based agent can choose the route that is safest, fastest, cheapest, and most comfortable.

Difference between goal and utility:

- Goal-based agent asks: Did I reach the goal?
- Utility-based agent asks: How good is this outcome?

### Learning Agent

A learning agent improves its performance from experience.

Main components:

- Performance element: selects actions.
- Learning element: improves the performance element.
- Critic: evaluates how well the agent is doing.
- Problem generator: suggests exploratory actions to gain useful experience.

Structure:

```text
Environment -> Percepts -> Performance element -> Actions
                              ^
                              |
                         Learning element
                              ^
                              |
                            Critic
```

Example:

A game-playing agent improves by playing many games and learning which moves are successful.

Advantages:

- Can adapt to new situations
- Can improve with experience
- Useful when manual programming is difficult

## 2.4 Environment Types

The environment strongly affects agent design.

### Fully Observable vs Partially Observable

#### Fully Observable

An environment is fully observable if the agent's sensors give complete information about the current state.

Example:

Chess board: all pieces are visible.

#### Partially Observable or Semi-Observable

An environment is partially observable if the agent has incomplete or noisy information.

Example:

A self-driving car may not see behind a large truck.

### Deterministic vs Stochastic

#### Deterministic

An environment is deterministic if the next state is completely determined by the current state and the action.

Example:

Solving an 8-puzzle with legal moves.

#### Stochastic

An environment is stochastic if actions have uncertain outcomes.

Example:

Driving in traffic, where other drivers may behave unpredictably.

### Static vs Dynamic

#### Static

A static environment does not change while the agent is thinking.

Example:

A crossword puzzle.

#### Dynamic

A dynamic environment can change while the agent is deciding.

Example:

Traffic changes continuously while a self-driving car plans.

### Discrete vs Continuous

#### Discrete

A discrete environment has a finite or countable number of states, actions, or percepts.

Example:

Chess has discrete board positions and moves.

#### Continuous

A continuous environment has continuous values for time, location, speed, or actions.

Example:

Driving involves continuous speed, distance, and steering angle.

### Single-Agent vs Multi-Agent

#### Single-Agent

Only one agent is considered.

Example:

A crossword puzzle solver.

#### Multi-Agent

Multiple agents interact in the same environment.

Example:

Chess has two competing agents. Traffic contains many vehicles and pedestrians.

### Episodic vs Sequential

#### Episodic

Each action is independent of previous actions.

Example:

Classifying independent images.

#### Sequential

Current actions affect future states and decisions.

Example:

Playing chess or driving.

### Known vs Unknown

#### Known

The agent knows the rules of the environment.

Example:

A chess agent knows legal chess moves.

#### Unknown

The agent must learn how the environment works.

Example:

A robot exploring a new building.

## Environment Examples

| Agent | Observable | Deterministic | Static | Discrete | Agents |
|---|---|---|---|---|---|
| Chess | Fully | Deterministic | Static | Discrete | Multi-agent |
| Crossword puzzle | Fully | Deterministic | Static | Discrete | Single-agent |
| Taxi driving | Partially | Stochastic | Dynamic | Continuous | Multi-agent |
| Medical diagnosis | Partially | Stochastic | Dynamic | Mixed | Single-agent or multi-agent |
| Vacuum cleaner | Partially | Deterministic or stochastic | Dynamic | Discrete | Single-agent |

## Additional Expanded Notes, Diagrams, and Tables

### Agent-Environment Interaction Loop

An agent does not act only once. It continuously receives percepts, updates its knowledge, chooses an action, and changes the environment.

```text
        percepts                         actions
+----------------+                 +----------------+
|  Environment   | ----sensors----> |     Agent      |
|                | <---actuators--- |                |
+----------------+                 +----------------+
        ^                                  |
        |                                  v
        +---------- state changes ---------+
```

Mathematically, an agent function is:

```text
f: P* → A
```

Where:

- `P*` is the set of all percept sequences.
- `A` is the set of possible actions.
- `f(p1, p2, ..., pt) = at` means the agent returns action `at` after percepts from time `1` to `t`.

### Rational Agent Formula

For each possible percept sequence, a rational agent selects the action that maximizes expected performance:

```text
a* = argmax_a E[PM | p1:t, K, a]
```

Where:

- `a*` is the selected best action.
- `PM` is the performance measure.
- `p1:t` is the percept sequence from time `1` to `t`.
- `K` is built-in or learned knowledge.
- `E` means expected value because the environment may be uncertain.

### What Rationality Depends On

| Factor | Explanation | Example |
|---|---|---|
| Performance measure | Defines success | Safe, legal, fast taxi driving |
| Prior knowledge | What the agent already knows | Traffic rules and road maps |
| Available actions | What the agent can do | Brake, accelerate, steer |
| Percept sequence | What the agent has observed so far | Red light, moving vehicles, weather |

### Performance Measure vs Utility

| Concept | Meaning | Example |
|---|---|---|
| Performance measure | External criterion used to judge agent behavior | Number of rooms cleaned, safety score |
| Utility function | Internal numeric preference used by agent | `U(state) = 0.7 safety + 0.2 speed + 0.1 comfort` |

### Vacuum Cleaner Agent Example

State representation:

```text
State = (Location, StatusA, StatusB)
Location ∈ {A, B}
StatusA ∈ {Clean, Dirty}
StatusB ∈ {Clean, Dirty}
```

Possible states:

| State | Meaning |
|---|---|
| `(A, Dirty, Dirty)` | Agent in A, both rooms dirty |
| `(A, Clean, Dirty)` | Agent in A, A clean, B dirty |
| `(B, Clean, Dirty)` | Agent in B, A clean, B dirty |
| `(B, Clean, Clean)` | Agent in B, both rooms clean |

Simple condition-action rules:

```text
if Status(CurrentRoom) = Dirty then Suck
else if Location = A then Right
else if Location = B then Left
```

### Agent Type Comparison

| Agent Type | Uses Current Percept | Uses Internal State | Uses Goal | Uses Utility | Learns |
|---|---:|---:|---:|---:|---:|
| Simple reflex | Yes | No | No | No | No |
| Model-based reflex | Yes | Yes | No | No | No |
| Goal-based | Yes | Usually | Yes | No | No |
| Utility-based | Yes | Usually | Yes | Yes | No |
| Learning agent | Yes | Usually | Usually | Usually | Yes |

### Simple Reflex Agent Diagram

```text
Sensors
  |
  v
Current percept
  |
  v
Condition-action rules
  |
  v
Action -> Actuators
```

Example:

```text
if Light = Red then Stop
if Light = Green and FrontClear = True then Move
```

### Model-Based Agent Diagram

```text
             +-----------------------+
Percept ---> | Update internal state | ---> Current state
             +-----------------------+
                         |
                         v
              Condition-action rules
                         |
                         v
                       Action

Internal state is updated using:
1. How the world evolves
2. What my actions do
```

Example:

A delivery robot may remember:

```text
Visited(Room101) = True
PackageDelivered(Room101) = True
BatteryLevel = 42%
```

### Goal-Based Agent Search View

Goal-based agents often need search and planning:

```text
Initial state
    |
    +-- action1 --> state1
    |                  |
    |                  +-- action3 --> goal
    |
    +-- action2 --> state2
                       |
                       +-- action4 --> failure
```

The selected action is the first step of a plan that reaches a desirable state.

### Utility-Based Choice Example

Suppose an automated taxi can choose three routes:

| Route | Safety | Time | Comfort | Utility |
|---|---:|---:|---:|---:|
| R1 | 95 | 40 min | 80 | 86 |
| R2 | 70 | 25 min | 60 | 68 |
| R3 | 90 | 35 min | 90 | 88 |

A goal-based agent may accept all routes because all reach the destination. A utility-based agent chooses `R3` because it has the highest utility.

Example formula:

```text
U(route) = 0.5 Safety + 0.3 SpeedScore + 0.2 Comfort
```

### Learning Agent Feedback Cycle

```text
                 feedback
                  +----+
                  |    v
Percepts -> Performance element -> Actions
              ^          |
              |          v
       Learning element <- Critic
              ^
              |
       Problem generator
```

Example:

In a game-playing agent:

- Performance element chooses moves.
- Critic checks win/loss and move quality.
- Learning element improves strategy.
- Problem generator tries new moves for exploration.

### More PEAS Examples

| Agent | Performance | Environment | Actuators | Sensors |
|---|---|---|---|---|
| Spam filter | Correct classification, low false positives | Email inbox, sender data, message text | Mark spam, allow email, alert user | Email content, headers, user feedback |
| Robot waiter | Safe delivery, correct order, speed | Restaurant, tables, customers, obstacles | Wheels, arm, tray, speaker | Camera, lidar, touch, microphone |
| Stock trading agent | Profit, risk control, legal compliance | Market, prices, news, portfolio | Buy, sell, hold, notify | Price feed, news feed, financial indicators |
| Medical assistant | Accuracy, safety, patient outcome | Patient records, symptoms, lab reports | Diagnosis suggestion, alert, report | User input, medical database, test results |

### PAGE Example Table

| Agent | Percepts | Actions | Goals | Environment |
|---|---|---|---|---|
| Chess agent | Board state, opponent move, clock | Move piece, resign, offer draw | Win or draw | Chess board and opponent |
| Vacuum agent | Dirt, location, bump, battery | Move, suck, dock, stop | Clean rooms efficiently | Rooms and floor |
| Navigation app | GPS, traffic, road closures | Suggest route, reroute, alert | Reach destination quickly | Roads, vehicles, map network |

### Environment Type Matrix

| Environment | Observable | Deterministic | Static | Discrete | Episodic | Agents |
|---|---|---|---|---|---|---|
| Crossword | Fully | Deterministic | Static | Discrete | Sequential | Single |
| Chess | Fully | Deterministic | Static | Discrete | Sequential | Multi |
| Poker | Partially | Stochastic | Static during move | Discrete | Sequential | Multi |
| Taxi driving | Partially | Stochastic | Dynamic | Continuous | Sequential | Multi |
| Image classification | Fully | Deterministic | Static | Discrete output | Episodic | Single |
| Medical diagnosis | Partially | Stochastic | Dynamic | Mixed | Sequential | Multi |

### Fully Observable vs Partially Observable Example

```text
Chess:
∀ piece, position(piece) is visible to both players.
Therefore, the environment is fully observable.

Driving:
∃ object around a corner such that the car's sensors cannot observe it.
Therefore, the environment is partially observable.
```

Here:

- `∀` means all.
- `∃` means there exists.

### Deterministic vs Stochastic Symbolic Form

Deterministic transition:

```text
Result(s, a) = s'
```

The same state `s` and action `a` always produce the same next state `s'`.

Stochastic transition:

```text
P(s' | s, a) ≠ 0 for multiple possible s'
```

The same action may lead to different next states with different probabilities.

## Key Terms

- Agent: Entity that perceives and acts.
- Intelligent Agent: Agent that acts rationally to achieve goals.
- Sensor: Device or mechanism used to perceive the environment.
- Actuator: Device or mechanism used to perform actions.
- Percept: Current input from the environment.
- Percept Sequence: Complete history of percepts.
- Agent Function: Mapping from percept sequences to actions.
- Rational Agent: Agent that selects the best expected action.
- PEAS: Performance, Environment, Actuators, Sensors.
- PAGE: Percepts, Actions, Goals, Environment.

## Short Exam Answers

### Define intelligent agent.

An intelligent agent is a system that perceives its environment through sensors and acts on that environment through actuators in a rational way to achieve goals or maximize a performance measure.

### What is PEAS?

PEAS is a task environment description used in agent design. It stands for Performance measure, Environment, Actuators, and Sensors.

### Why is a model-based agent better than a simple reflex agent?

A model-based agent stores an internal state and can work in partially observable environments. A simple reflex agent depends only on the current percept and works best only when the environment is fully observable.
