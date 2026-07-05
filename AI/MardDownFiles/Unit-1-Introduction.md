# Unit 1: Introduction to Artificial Intelligence

## 1.1 Intelligence and Artificial Intelligence

### Intelligence

Intelligence is the ability to learn from experience, understand situations, reason, solve problems, make decisions, and adapt behavior to achieve goals.

In AI, intelligence means the ability of a computer program, machine, or software agent to perform tasks that normally require human intelligence.

Important abilities included in intelligence:

- Understanding language
- Learning from data or experience
- Reasoning logically
- Solving problems
- Making decisions
- Planning actions
- Perceiving the environment
- Adapting to new situations

### Intelligent Behavior

Intelligence is the capacity or ability, while intelligent behavior is the visible result of that ability.

Example:

- Intelligence: A machine has the ability to reason about traffic lights.
- Intelligent behavior: The machine stops when the traffic light is red and moves when it is green.

Intelligent behavior is used to judge whether a system appears intelligent.

### Artificial Intelligence

Artificial Intelligence is a branch of computer science that studies how to build machines and software systems that can perform tasks requiring human-like intelligence.

AI systems may perform tasks such as:

- Speech recognition
- Image recognition
- Natural language understanding
- Decision making
- Problem solving
- Game playing
- Robotics
- Expert advice
- Prediction and recommendation

### Types of AI by Capability

#### Narrow AI or Weak AI

Narrow AI is designed to perform a specific task.

Examples:

- Voice assistants
- Recommendation systems
- Spam filters
- Face recognition systems
- Chess engines

Narrow AI is widely used today, but it cannot perform every intellectual task like a human.

#### General AI or Strong AI

General AI is a hypothetical AI that can perform any intellectual task that a human can perform.

It would be able to:

- Learn any subject
- Transfer knowledge between tasks
- Understand context deeply
- Reason generally
- Act flexibly in new environments

General AI has not been fully developed yet.

#### Super AI

Super AI is a hypothetical AI that surpasses human intelligence in most or all fields.

It may be better than humans in:

- Scientific discovery
- Creativity
- Decision making
- Problem solving
- Social intelligence

Super AI is still a theoretical concept.

## AI Perspectives

AI can be understood from four major perspectives:

1. Acting humanly
2. Thinking humanly
3. Thinking rationally
4. Acting rationally

### Acting Humanly: Turing Test Approach

The acting humanly approach tries to make a machine behave like a human.

The Turing Test was proposed by Alan Turing in 1950. In this test, a human interrogator communicates through written questions with both a human and a machine. If the interrogator cannot reliably identify which participant is the machine, then the machine is said to have passed the test.

To pass the Turing Test, a machine needs abilities such as:

- Natural language processing
- Knowledge representation
- Automated reasoning
- Machine learning

For the Total Turing Test, the machine would also need:

- Computer vision
- Speech recognition
- Robotics

Example:

A chatbot that answers questions so naturally that a human judge cannot distinguish it from a human conversation partner follows the acting humanly approach.

### Thinking Humanly: Cognitive Modeling Approach

The thinking humanly approach tries to make machines think like humans.

It studies how humans think, learn, remember, and solve problems. This approach is connected with cognitive science.

Methods used to study human thinking:

- Introspection: observing one's own thoughts
- Psychological experiments: testing human behavior in controlled situations
- Brain imaging and neuroscience: studying brain activity

Goal:

Develop computer models that behave similarly to the human mind.

Example:

A program that solves puzzles by using the same steps and errors commonly seen in human problem solving follows the thinking humanly approach.

### Thinking Rationally: Laws of Thought Approach

The thinking rationally approach tries to make machines reason correctly using logic.

Rational thinking means deriving correct conclusions from available facts.

Example:

Given:

- All humans are mortal.
- Socrates is a human.

Logical conclusion:

- Socrates is mortal.

This approach uses formal logic, such as propositional logic and predicate logic.

Limitations:

- Real-world knowledge is often uncertain or incomplete.
- Logical reasoning can be computationally expensive.
- Not every intelligent action is based only on strict logic.

### Acting Rationally: Rational Agent Approach

The acting rationally approach tries to make an agent choose the best action to achieve its goals.

A rational agent perceives its environment and acts to maximize its expected performance measure.

This is the most widely used modern AI approach because it focuses on useful action.

Example:

A self-driving car should stop at a red light, avoid pedestrians, follow traffic rules, and choose efficient routes.

### Comparison of AI Perspectives

| Perspective | Main Goal | Example |
|---|---|---|
| Acting humanly | Behave like humans | Turing Test chatbot |
| Thinking humanly | Think like humans | Cognitive model of memory |
| Thinking rationally | Reason correctly | Logic theorem prover |
| Acting rationally | Act to achieve best outcome | Self-driving taxi |

## 1.2 History of AI

### Early Foundations

The idea of artificial intelligence is older than computers. Philosophers and mathematicians studied reasoning, logic, and mechanical calculation for centuries.

Important early foundations:

- Aristotle developed formal logic.
- George Boole developed Boolean algebra.
- Alan Turing introduced the idea of computation and proposed the Turing Test.
- Norbert Wiener contributed to cybernetics and control theory.

### Birth of AI: 1950s

Important events:

- 1950: Alan Turing published "Computing Machinery and Intelligence".
- 1956: Dartmouth Conference was held, where the term "Artificial Intelligence" was introduced.
- Early AI programs solved logic problems and played simple games.

Early AI researchers were optimistic because computers could perform symbolic reasoning tasks.

### Early Successes: 1950s to 1960s

Important systems:

- Logic Theorist: proved mathematical theorems.
- General Problem Solver: attempted to solve problems using symbolic reasoning.
- ELIZA: simulated conversation using pattern matching.

Main approach:

Symbolic AI, where knowledge is represented using symbols and rules.

### Knowledge-Based Systems: 1970s to 1980s

AI researchers began building expert systems, which used rules from human experts.

Examples:

- MYCIN: medical diagnosis system for bacterial infections.
- DENDRAL: chemical analysis system.

Strength:

Expert systems worked well in narrow domains.

Weakness:

They were expensive to build and difficult to maintain.

### AI Winters

An AI winter is a period when funding and interest in AI decreased because expectations were not met.

Reasons:

- Computers were too slow.
- Data was limited.
- Real-world problems were harder than expected.
- Rule-based systems were brittle.

Major AI winters occurred around:

- 1970s
- Late 1980s to early 1990s

### Machine Learning Era

From the 1990s onward, AI shifted toward machine learning, where systems learn patterns from data instead of depending only on manually written rules.

Important developments:

- Decision trees
- Support vector machines
- Bayesian networks
- Reinforcement learning
- Neural networks

Example:

Instead of manually writing all spam rules, a spam classifier learns from examples of spam and non-spam emails.

### Deep Learning Era

Deep learning became highly successful after improvements in:

- Large datasets
- Faster processors and GPUs
- Better neural network algorithms
- Cloud computing

Deep learning is used in:

- Image recognition
- Speech recognition
- Machine translation
- Natural language processing
- Medical imaging
- Autonomous driving

### Modern AI

Modern AI combines:

- Machine learning
- Deep learning
- Knowledge representation
- Search
- Planning
- Natural language processing
- Robotics
- Probabilistic reasoning

Modern systems include:

- Chatbots and language models
- Recommendation engines
- Self-driving systems
- Intelligent robots
- AI assistants
- Expert decision support systems

## 1.3 Foundations of AI

AI is an interdisciplinary field. It is built from many areas of knowledge.

### Philosophy

Philosophy contributes ideas about:

- Reasoning
- Knowledge
- Mind
- Consciousness
- Ethics
- Rational action

Important questions:

- Can machines think?
- What is knowledge?
- What is correct reasoning?
- What makes an action rational?

### Economics

Economics contributes ideas about:

- Decision making
- Utility
- Preferences
- Game theory
- Cost-benefit analysis

AI uses economics when an agent must choose actions that maximize expected utility.

Example:

A delivery robot chooses a route by considering time, battery cost, and delivery priority.

### Psychology

Psychology studies human behavior and mental processes.

AI uses psychology for:

- Learning models
- Problem-solving behavior
- Memory models
- Perception models
- Cognitive architectures

### Sociology

Sociology studies social behavior, groups, and institutions.

AI uses sociology in:

- Multi-agent systems
- Social networks
- Human-AI interaction
- Group behavior modeling
- Ethical and social impact analysis

### Linguistics

Linguistics studies language structure and meaning.

AI uses linguistics in natural language processing.

Important linguistic areas:

- Syntax: structure of sentences
- Semantics: meaning of sentences
- Pragmatics: meaning in context
- Morphology: word formation
- Phonetics and phonology: sounds

Examples:

- Machine translation
- Chatbots
- Speech recognition
- Grammar checking

### Neuroscience

Neuroscience studies the brain and nervous system.

AI uses neuroscience for inspiration in:

- Neural networks
- Perception
- Learning
- Memory
- Pattern recognition

Artificial neural networks are inspired by biological neurons, although they are much simpler than the real brain.

### Mathematics

Mathematics provides formal tools for AI.

Important areas:

- Logic
- Probability
- Statistics
- Linear algebra
- Calculus
- Optimization
- Graph theory

Examples:

- Probability is used in uncertain reasoning.
- Graph theory is used in search algorithms.
- Linear algebra is used in machine learning.

### Computer Science

Computer science provides the practical tools for building AI.

Important areas:

- Algorithms
- Data structures
- Programming languages
- Complexity analysis
- Databases
- Computer architecture
- Distributed systems

Examples:

- Search algorithms use queues, stacks, and graphs.
- Machine learning systems require efficient computation and storage.

### Control Theory

Control theory studies systems that act to maintain or reach a desired state.

AI uses control theory in:

- Robotics
- Autonomous vehicles
- Industrial automation
- Feedback systems

Example:

A thermostat measures room temperature and acts to maintain the desired temperature.

## 1.4 Applications of AI

### Data Security and Cybersecurity

AI can detect suspicious behavior, malware, fraud, and attacks.

Examples:

- Intrusion detection systems
- Spam filtering
- Phishing detection
- Fraud detection

### Social Media

AI is used for:

- Content recommendation
- Friend suggestions
- Sentiment analysis
- Image tagging
- Content moderation
- Advertisement targeting

### Healthcare

AI helps in:

- Disease diagnosis
- Medical image analysis
- Drug discovery
- Patient monitoring
- Personalized treatment

Example:

An AI system detects tumors in X-ray or MRI images.

### Education

AI supports:

- Intelligent tutoring systems
- Automatic grading
- Personalized learning
- Plagiarism detection
- Learning analytics

### Transportation

AI is used in:

- Self-driving cars
- Traffic prediction
- Route planning
- Driver assistance systems
- Public transport optimization

### Finance

AI helps in:

- Credit scoring
- Fraud detection
- Algorithmic trading
- Risk analysis
- Customer support chatbots

### Robotics

Robots use AI for:

- Perception
- Motion planning
- Object manipulation
- Navigation
- Human interaction

Examples:

- Industrial robots
- Service robots
- Surgical robots
- Warehouse robots

### Natural Language Processing

AI systems process human language for:

- Translation
- Summarization
- Question answering
- Chatbots
- Speech recognition
- Text classification

### Entertainment and Games

AI is used in:

- Game-playing agents
- NPC behavior
- Recommendation systems
- Music and video generation
- Personalized content

### Agriculture

AI can help with:

- Crop disease detection
- Soil monitoring
- Weather prediction
- Smart irrigation
- Yield prediction

### Business and Industry

AI is applied in:

- Customer service
- Demand forecasting
- Quality control
- Inventory management
- Process automation

## Key Terms

- Intelligence: Ability to learn, reason, solve problems, and adapt.
- Artificial Intelligence: Field of building machines that perform intelligent tasks.
- Rational Agent: Agent that chooses actions to maximize expected performance.
- Turing Test: Test of whether a machine can behave indistinguishably from a human in conversation.
- Cognitive Modeling: Modeling human thought processes.
- Expert System: AI system that uses expert knowledge and rules to solve domain-specific problems.
- AI Winter: Period of reduced funding and interest in AI.

## Short Exam Answers

### What is AI?

AI is the branch of computer science that studies and builds intelligent machines capable of performing tasks such as learning, reasoning, problem solving, decision making, perception, and language understanding.

### What are the four perspectives of AI?

The four perspectives are acting humanly, thinking humanly, thinking rationally, and acting rationally.

### Why is the rational agent approach important?

The rational agent approach is important because it focuses on choosing the best action according to the current percepts, goals, and performance measure. It is practical for real-world AI systems.

