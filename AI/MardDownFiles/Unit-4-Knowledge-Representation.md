# Unit 4: Knowledge Representation

## 4.1 Knowledge and Knowledge Representation

### Knowledge

Knowledge is information, facts, skills, rules, and experience that can be used to understand situations and make decisions.

Examples:

- Kathmandu is the capital city of Nepal.
- Fire is hot.
- If a person falls from a tall building, the person may be injured.
- A doctor knows symptoms and treatments of diseases.

Knowledge is different from intelligence.

- Knowledge is stored information or experience.
- Intelligence is the ability to use knowledge correctly at the right time.

### Reasoning

Reasoning is the process of deriving new conclusions from existing knowledge.

Example:

Knowledge:

```text
All humans are mortal.
Ram is a human.
```

Reasoning conclusion:

```text
Ram is mortal.
```

### Knowledge Representation

Knowledge Representation is the process of storing knowledge in a form that a machine can understand, process, and use for reasoning.

Goal:

Represent facts, rules, objects, relations, events, and uncertain information so that an AI system can make decisions.

Example:

Natural language statement:

```text
If it rains, the road becomes wet.
```

Rule representation:

```text
Rain -> WetRoad
```

### Importance of Knowledge Representation

Knowledge representation is important because:

- It allows machines to store facts and rules.
- It supports reasoning and decision making.
- It helps AI systems explain conclusions.
- It makes expert systems possible.
- It supports planning, diagnosis, language understanding, and learning.

If knowledge is represented incorrectly, the machine may produce wrong results.

Types of errors:

- Syntax error: wrong structure or grammar.
- Semantic error: wrong meaning.

Example syntax problem:

```text
I taking food.
```

Example semantic problem:

```text
I eat bus inside noodles.
```

## Issues in Knowledge Representation

### Important Attributes

The system must decide which properties of an object are important.

Example:

For a car diagnosis system, important attributes may include engine status, fuel level, battery charge, and temperature.

### Relationship Among Attributes

Attributes may be related to each other.

Example:

If:

```text
Ram is son of Shyam.
```

Then the system may infer:

```text
Shyam is father of Ram.
```

This is an inverse relationship.

### Choosing Granularity

Granularity means the level of detail used to represent knowledge.

Example:

A car may be represented simply as:

```text
Car(color, model)
```

Or in more detail:

```text
Car(engine, wheels, brakes, battery, fuelSystem, sensors)
```

Too little detail may be insufficient. Too much detail may make reasoning slow.

### Representing Sets of Objects

Similar objects can be grouped into classes or sets.

Example:

```text
Dog is an animal.
Cat is an animal.
Cow is an animal.
```

This avoids repeating all properties for each object.

### Finding the Right Structure

The system must choose a suitable structure to store and access relevant knowledge.

Example:

If a machine counts money, it should add the value of notes and coins. If it counts students, it should count each student as one object.

### Inferential Adequacy

The representation should allow the system to derive new knowledge from stored knowledge.

### Inferential Efficiency

The representation should allow reasoning to happen efficiently.

### Acquisitional Efficiency

The representation should make it easy to add new knowledge.

## Knowledge Representation Systems

A knowledge representation system stores:

- Facts
- Rules
- Heuristics
- Relations
- Objects
- Events
- Ontologies

It usually includes:

- Knowledge base
- Inference engine
- Working memory
- User interface or input/output mechanism

### Knowledge Base

A knowledge base is a collection of facts and rules about a domain.

Example:

```text
Fact: Fever(Ram)
Rule: Fever(x) and Cough(x) -> Flu(x)
```

### Inference Engine

An inference engine derives new facts or conclusions from the knowledge base.

Common inference methods:

- Deductive inference
- Inductive inference
- Abductive inference

### Deductive Inference

Deductive inference derives logically certain conclusions from general rules.

Example:

```text
All birds have wings.
Sparrow is a bird.
Therefore, sparrow has wings.
```

### Inductive Inference

Inductive inference generalizes from examples.

Example:

```text
Crow 1 is black.
Crow 2 is black.
Crow 3 is black.
Therefore, crows may be black.
```

### Abductive Inference

Abductive inference chooses the most likely explanation.

Example:

```text
The grass is wet.
Possible explanation: It rained.
```

## Properties of Knowledge Representation Systems

A good knowledge representation system should have:

- Representational adequacy: ability to represent required knowledge.
- Inferential adequacy: ability to derive new knowledge.
- Inferential efficiency: ability to reason efficiently.
- Acquisitional efficiency: ability to add and update knowledge easily.

## 4.2 Types of Knowledge Representation Systems

### Semantic Nets

A semantic net represents knowledge as a graph.

Nodes represent objects or concepts.

Edges represent relationships.

Example:

```text
Canary --is-a--> Bird --is-a--> Animal
Bird --has--> Wings
Canary --color--> Yellow
```

Advantages:

- Easy to understand visually
- Good for representing relationships
- Supports inheritance

Disadvantages:

- Can become complex for large knowledge bases
- Meaning of links may be ambiguous

### Frames

A frame represents an object or concept using slots and fillers.

- Slot: attribute or property
- Filler: value of the attribute

Example:

```text
Frame: Car
    Slots:
        color: red
        wheels: 4
        engine: petrol
        owner: Ram
```

Advantages:

- Good for representing structured objects
- Supports default values
- Supports inheritance

Example with default:

```text
Frame: Bird
    wings: 2
    canFly: true

Frame: Penguin
    is-a: Bird
    canFly: false
```

### Conceptual Dependencies

Conceptual Dependency represents the meaning of natural language sentences using primitive actions.

It focuses on meaning rather than sentence structure.

Common primitive actions:

- ATRANS: transfer of ownership or possession
- PTRANS: physical transfer or movement
- MTRANS: transfer of mental information
- INGEST: taking something into the body
- PROPEL: applying force

Example:

Sentence:

```text
Ram gave a book to Sita.
```

Conceptual dependency:

```text
ATRANS(book, from Ram, to Sita)
```

### Scripts

A script represents a stereotyped sequence of events in a particular situation.

Example: Restaurant script

```text
1. Customer enters restaurant.
2. Customer sits at a table.
3. Waiter gives menu.
4. Customer orders food.
5. Food is served.
6. Customer eats.
7. Customer pays bill.
8. Customer leaves.
```

Scripts are useful for understanding stories and common events.

### Rule-Based Systems or Production Systems

A rule-based system represents knowledge using if-then rules.

Syntax:

```text
if condition then action/conclusion
```

Example:

```text
if fever and cough then possible flu
```

Components:

- Rule base
- Working memory
- Inference engine

Advantages:

- Easy to understand
- Good for expert systems
- Rules can be added or modified

Disadvantages:

- Too many rules can be difficult to manage
- Conflicting rules may occur

### Propositional Logic

Propositional logic represents facts as propositions that are either true or false.

Example:

```text
P: It is raining.
Q: The road is wet.
P -> Q
```

### Predicate Logic

Predicate logic represents objects, properties, relations, and quantifiers.

Example:

```text
Human(Ram)
Mortal(Ram)
forall x Human(x) -> Mortal(x)
```

Predicate logic is more expressive than propositional logic.

## 4.3 Propositional Logic

### Definition

Propositional Logic is a formal logic system where each statement is represented as a proposition that is either true or false.

Examples of propositions:

```text
P: The sky is blue.
Q: 2 + 2 = 4.
R: It is raining.
```

Not propositions:

```text
Close the door.
What is your name?
```

### Syntax of Propositional Logic

Symbols:

- Propositional variables: `P`, `Q`, `R`
- Logical connectives: `not`, `and`, `or`, `implies`, `if and only if`
- Parentheses: used for grouping

Common connectives:

| Symbol | Name | Meaning |
|---|---|---|
| `not P` or `~P` | Negation | P is false |
| `P and Q` or `P ^ Q` | Conjunction | Both P and Q are true |
| `P or Q` or `P v Q` | Disjunction | At least one of P or Q is true |
| `P -> Q` | Implication | If P then Q |
| `P <-> Q` | Biconditional | P if and only if Q |

### Well-Formed Formula

A well-formed formula is a valid expression according to the syntax rules of logic.

Examples:

```text
P
not P
P and Q
(P and Q) -> R
```

Invalid:

```text
and P Q ->
P not and Q
```

### Semantics of Propositional Logic

Semantics defines the meaning or truth value of logical sentences.

Truth values:

- True
- False

### Truth Tables

#### Negation

| P | not P |
|---|---|
| T | F |
| F | T |

#### Conjunction

| P | Q | P and Q |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | F |
| F | F | F |

#### Disjunction

| P | Q | P or Q |
|---|---|---|
| T | T | T |
| T | F | T |
| F | T | T |
| F | F | F |

#### Implication

| P | Q | P -> Q |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | T |
| F | F | T |

#### Biconditional

| P | Q | P <-> Q |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | F |
| F | F | T |

### Tautology

A tautology is a formula that is true in every interpretation.

Example:

```text
P or not P
```

### Contradiction

A contradiction is a formula that is false in every interpretation.

Example:

```text
P and not P
```

### Contingency

A contingency is a formula that is true in some interpretations and false in others.

Example:

```text
P -> Q
```

### Validity

A sentence is valid if it is true in all possible models.

Validity is closely related to tautology.

### Satisfiability

A sentence is satisfiable if it is true in at least one model.

### Inference in Propositional Logic

Inference means deriving a conclusion from premises.

Example:

Premises:

```text
P -> Q
P
```

Conclusion:

```text
Q
```

This is Modus Ponens.

### Common Inference Rules

#### Modus Ponens

```text
P -> Q
P
Therefore Q
```

#### And-Elimination

```text
P and Q
Therefore P
```

#### And-Introduction

```text
P
Q
Therefore P and Q
```

#### Or-Introduction

```text
P
Therefore P or Q
```

### Resolution in Propositional Logic

Resolution is an inference rule used to prove conclusions by contradiction.

Basic rule:

```text
P or Q
not P or R
Therefore Q or R
```

Steps for resolution proof:

1. Convert all statements into clauses in conjunctive normal form.
2. Negate the goal.
3. Add the negated goal to the knowledge base.
4. Apply resolution repeatedly.
5. If an empty clause is produced, the goal is proved.

Example:

Knowledge base:

```text
P -> Q
P
```

Prove:

```text
Q
```

Convert:

```text
not P or Q
P
not Q
```

Resolution:

```text
not P or Q
not Q
=> not P

not P
P
=> empty clause
```

Therefore, `Q` is proved.

### Forward Chaining

Forward chaining is a data-driven inference method.

It starts with known facts and applies rules to derive new facts until the goal is reached.

Example:

Facts:

```text
Fever(Ram)
Cough(Ram)
```

Rule:

```text
Fever(x) and Cough(x) -> Flu(x)
```

Conclusion:

```text
Flu(Ram)
```

### Backward Chaining

Backward chaining is a goal-driven inference method.

It starts with a goal and works backward to find facts that support the goal.

Example:

Goal:

```text
Flu(Ram)
```

Rule:

```text
Fever(Ram) and Cough(Ram) -> Flu(Ram)
```

The system checks whether:

```text
Fever(Ram)
Cough(Ram)
```

are known facts.

## 4.4 Predicate Logic

### First Order Predicate Logic

First Order Predicate Logic is a formal logic system that represents objects, properties, relations, and quantifiers.

It is more powerful than propositional logic.

### Syntax of FOPL

Main elements:

- Constants
- Variables
- Predicates
- Functions
- Connectives
- Quantifiers

#### Constants

Constants represent specific objects.

Examples:

```text
Ram
Sita
Kathmandu
```

#### Variables

Variables represent arbitrary objects.

Examples:

```text
x
y
z
```

#### Predicates

Predicates represent properties or relations.

Examples:

```text
Human(Ram)
Likes(Ram, Mango)
Father(Shyam, Ram)
```

#### Functions

Functions map objects to objects.

Examples:

```text
FatherOf(Ram)
CapitalOf(Nepal)
```

#### Quantifiers

Universal quantifier:

```text
forall x
```

Meaning:

```text
For all x
```

Existential quantifier:

```text
exists x
```

Meaning:

```text
There exists at least one x
```

### Semantics of FOPL

Semantics defines the meaning of constants, predicates, functions, and quantified sentences in a domain.

Example:

```text
forall x Human(x) -> Mortal(x)
```

Meaning:

Every object `x` in the domain is mortal if `x` is human.

### Quantification Examples

Universal statement:

```text
forall x Student(x) -> Studies(x)
```

Meaning:

All students study.

Existential statement:

```text
exists x Student(x) and Likes(x, AI)
```

Meaning:

There exists at least one student who likes AI.

### Inference with FOPL by Converting into PL

FOPL inference can sometimes be performed by converting quantified statements into propositional statements using instantiation.

#### Universal Instantiation

From:

```text
forall x Human(x) -> Mortal(x)
```

We can infer:

```text
Human(Ram) -> Mortal(Ram)
```

#### Existential Instantiation

From:

```text
exists x Student(x)
```

We can introduce a new constant, such as `A`, and infer:

```text
Student(A)
```

The new constant must not already be used for another known object.

### Unification

Unification is the process of finding substitutions that make two logical expressions identical.

Example:

```text
Knows(Ram, x)
Knows(Ram, Sita)
```

Substitution:

```text
x = Sita
```

After substitution:

```text
Knows(Ram, Sita)
```

### Lifting

Lifting means applying inference rules directly to first-order logic using variables, instead of converting every statement into propositional logic.

It makes reasoning more general and efficient.

### Resolution in FOPL

Resolution in FOPL extends propositional resolution using unification.

General steps:

1. Convert implications.
2. Move negations inward.
3. Standardize variables.
4. Remove existential quantifiers using Skolemization.
5. Drop universal quantifiers.
6. Convert to conjunctive normal form.
7. Apply resolution using unification.

Example:

Knowledge:

```text
forall x Human(x) -> Mortal(x)
Human(Ram)
```

Goal:

```text
Mortal(Ram)
```

Convert rule:

```text
not Human(x) or Mortal(x)
```

Negate goal:

```text
not Mortal(Ram)
```

Resolve:

```text
not Human(x) or Mortal(x)
not Mortal(Ram)
```

Unify:

```text
x = Ram
```

Result:

```text
not Human(Ram)
```

Resolve with:

```text
Human(Ram)
```

Result:

```text
empty clause
```

Therefore, `Mortal(Ram)` is proved.

## 4.5 Handling Uncertain Knowledge

Real-world knowledge is often uncertain.

Examples:

- A patient with fever may have flu, but it is not certain.
- Dark clouds may indicate rain, but rain is not guaranteed.
- A sensor may give noisy readings.

AI handles uncertainty using probability theory and probabilistic reasoning.

### Random Variables

A random variable is a variable whose value depends on uncertain outcomes.

Examples:

```text
Weather = {Sunny, Rainy, Cloudy}
Disease = {Flu, Malaria, None}
Alarm = {True, False}
```

### Probability

Probability measures the degree of belief that an event will occur.

Range:

```text
0 <= P(A) <= 1
```

Where:

- `P(A) = 0` means impossible.
- `P(A) = 1` means certain.

### Prior Probability

Prior probability is the probability of an event before considering new evidence.

Example:

```text
P(Flu) = 0.10
```

This means there is a 10 percent prior probability of flu.

### Posterior Probability

Posterior probability is the probability after considering evidence.

Example:

```text
P(Flu | Fever)
```

This means probability of flu given that fever is observed.

### Conditional Probability

Conditional probability is the probability of event `A` given event `B`.

Syntax:

```text
P(A | B) = P(A and B) / P(B)
```

if `P(B) > 0`.

### Full Joint Distribution

A full joint distribution gives the probability of every possible combination of values of all random variables.

Example with two Boolean variables:

| Rain | WetGrass | Probability |
|---|---|---|
| True | True | 0.30 |
| True | False | 0.10 |
| False | True | 0.05 |
| False | False | 0.55 |

From a full joint distribution, any probability query can be answered by summing relevant entries.

Example:

```text
P(Rain = True) = P(Rain=True, WetGrass=True) + P(Rain=True, WetGrass=False)
               = 0.30 + 0.10
               = 0.40
```

### Bayes' Rule

Bayes' Rule is used to update probability after observing evidence.

Formula:

```text
P(A | B) = [P(B | A) P(A)] / P(B)
```

Where:

- `P(A)` is prior probability.
- `P(B | A)` is likelihood.
- `P(B)` is evidence probability.
- `P(A | B)` is posterior probability.

Example:

Let:

```text
P(Flu) = 0.10
P(Fever | Flu) = 0.80
P(Fever) = 0.20
```

Then:

```text
P(Flu | Fever) = P(Fever | Flu) P(Flu) / P(Fever)
               = 0.80 * 0.10 / 0.20
               = 0.40
```

So the probability of flu given fever is 40 percent.

### Bayesian Networks

A Bayesian Network is a graphical model that represents probabilistic relationships among variables.

It is a directed acyclic graph.

Components:

- Nodes: random variables
- Edges: direct probabilistic dependencies
- Conditional probability tables: probabilities for each node given its parents

Example:

```text
Rain -> WetGrass
Sprinkler -> WetGrass
```

Meaning:

Rain and sprinkler influence whether grass is wet.

Advantages:

- Compact representation of joint probability distribution
- Supports reasoning under uncertainty
- Useful in diagnosis, prediction, and decision support

### Reasoning in Belief Networks

Reasoning in belief networks means computing probabilities of unknown variables using observed evidence.

Common types:

- Diagnostic reasoning: from effect to cause
- Predictive reasoning: from cause to effect
- Intercausal reasoning: between causes of a common effect

Example diagnostic reasoning:

```text
WetGrass observed -> infer probability of Rain
```

Example predictive reasoning:

```text
Rain observed -> infer probability of WetGrass
```

## 4.6 Fuzzy Logic

### Need for Fuzzy Logic

Classical logic uses only two truth values:

- True
- False

But many real-world concepts are gradual.

Examples:

- Hot temperature
- Tall person
- Fast vehicle
- High risk

Fuzzy logic handles partial truth.

### Fuzzy Set

A fuzzy set is a set where membership can be partial.

Membership value ranges from 0 to 1.

```text
0 means no membership
1 means full membership
0.5 means partial membership
```

Example:

For fuzzy set `Tall`:

```text
MembershipTall(150 cm) = 0.1
MembershipTall(170 cm) = 0.6
MembershipTall(190 cm) = 1.0
```

### Membership Function

A membership function assigns a membership degree to each input value.

Syntax:

```text
mu_A(x) -> [0, 1]
```

Where:

- `mu_A(x)` is membership of `x` in fuzzy set `A`.

Example:

```text
mu_Hot(25 C) = 0.2
mu_Hot(35 C) = 0.8
```

### Difference Between Crisp Set and Fuzzy Set

| Crisp Set | Fuzzy Set |
|---|---|
| Membership is 0 or 1 | Membership ranges from 0 to 1 |
| Sharp boundary | Gradual boundary |
| Example: age >= 18 is adult | Example: temperature is hot to degree 0.7 |

### Fuzzy Rules

Fuzzy logic uses if-then rules.

Syntax:

```text
if condition then conclusion
```

Example:

```text
if temperature is hot then fan speed is high
if temperature is warm then fan speed is medium
if temperature is cold then fan speed is low
```

### Fuzzy Rule-Based System

A fuzzy rule-based system uses fuzzy sets and rules to make decisions.

Main steps:

1. Fuzzification
2. Rule evaluation
3. Aggregation
4. Defuzzification

#### Fuzzification

Fuzzification converts crisp input into fuzzy membership values.

Example:

Input:

```text
Temperature = 32 C
```

Membership:

```text
Warm = 0.6
Hot = 0.4
```

#### Rule Evaluation

Rules are applied using fuzzy logic operations.

Common operations:

```text
AND: min(a, b)
OR: max(a, b)
NOT: 1 - a
```

#### Aggregation

Aggregation combines outputs from multiple rules.

#### Defuzzification

Defuzzification converts fuzzy output into a crisp value.

Example:

Fuzzy output:

```text
Fan speed is medium to degree 0.6 and high to degree 0.4
```

Crisp output:

```text
Fan speed = 65 percent
```

### Applications of Fuzzy Logic

Fuzzy logic is used in:

- Washing machines
- Air conditioners
- Camera autofocus
- Control systems
- Medical decision support
- Risk analysis
- Traffic control

## Additional Expanded Notes, Symbolic Forms, and Worked Examples

### Data, Information, Knowledge, and Intelligence

| Level | Meaning | Example |
|---|---|---|
| Data | Raw facts without context | `38.5` |
| Information | Data with meaning | Body temperature is `38.5°C` |
| Knowledge | Interpretable rule or fact | Fever may indicate infection |
| Intelligence | Correct use of knowledge | Recommend medical checkup when fever and other symptoms appear |

### Knowledge Representation Pipeline

```text
Real-world fact
      |
      v
Natural language statement
      |
      v
Formal representation
      |
      v
Knowledge base
      |
      v
Inference engine
      |
      v
Conclusion / action
```

Example:

```text
Natural language: Every student studies.
Formal form: ∀x (Student(x) → Studies(x))
Fact: Student(Ram)
Conclusion: Studies(Ram)
```

### Syntax vs Semantics in KR

| Concept | Meaning | Example |
|---|---|---|
| Syntax | Rules for valid structure | `P ∧ Q` is syntactically valid |
| Semantics | Meaning or truth of expression | `P ∧ Q` is true only when both `P` and `Q` are true |

Invalid syntax:

```text
∧ P Q →
```

Valid syntax but possibly false semantics:

```text
Fish(Cow)
```

### Semantic Net With Inheritance

```text
             Animal
               ^
              is-a
               |
              Bird ----has----> Wings
               ^
              is-a
               |
            Canary ----color---> Yellow
```

Inference through inheritance:

```text
Canary is-a Bird
Bird is-a Animal
Bird has Wings
Therefore, Canary has Wings
```

Symbolically:

```text
isA(Canary, Bird) ∧ isA(Bird, Animal) → isA(Canary, Animal)
```

### Frame Example With Defaults and Override

```text
Frame: Bird
    is-a: Animal
    wings: 2
    covering: feathers
    canFly: true

Frame: Penguin
    is-a: Bird
    canFly: false
    habitat: cold region
```

Because `Penguin` is a `Bird`, it inherits:

```text
wings = 2
covering = feathers
```

But it overrides:

```text
canFly = false
```

### Production System Cycle

```text
Working memory + Rule base
          |
          v
    Match rules
          |
          v
 Resolve conflict
          |
          v
    Fire rule
          |
          v
 Update working memory
```

Example rules:

```text
R1: Fever(x) ∧ Cough(x) → Flu(x)
R2: Flu(x) → NeedsRest(x)
R3: NeedsRest(x) → Advise(x, "drink fluids and rest")
```

Fact:

```text
Fever(Ram), Cough(Ram)
```

Forward chaining derives:

```text
Flu(Ram)
NeedsRest(Ram)
Advise(Ram, "drink fluids and rest")
```

### Propositional Logic Symbol Table

| Plain Text | Symbol | Name | Example |
|---|---|---|---|
| not | `¬` | Negation | `¬P` |
| and | `∧` | Conjunction | `P ∧ Q` |
| or | `∨` | Disjunction | `P ∨ Q` |
| implies | `→` | Implication | `P → Q` |
| if and only if | `↔` | Biconditional | `P ↔ Q` |
| therefore | `∴` | Conclusion | `P, P → Q ∴ Q` |
| entails | `⊨` | Logical entailment | `KB ⊨ α` |
| proves | `⊢` | Derivability | `KB ⊢ α` |

### Entailment

Entailment means a conclusion logically follows from the knowledge base.

```text
KB ⊨ α
```

Meaning:

In every model where `KB` is true, `α` is also true.

Example:

```text
KB = {P → Q, P}
α = Q
KB ⊨ Q
```

### CNF Conversion Rules

Resolution usually requires Conjunctive Normal Form.

Rules:

```text
P → Q          ≡ ¬P ∨ Q
P ↔ Q          ≡ (P → Q) ∧ (Q → P)
¬(P ∧ Q)       ≡ ¬P ∨ ¬Q
¬(P ∨ Q)       ≡ ¬P ∧ ¬Q
P ∨ (Q ∧ R)    ≡ (P ∨ Q) ∧ (P ∨ R)
```

Example:

```text
(P → Q) ∧ P
≡ (¬P ∨ Q) ∧ P
```

### Resolution Worked Example

Prove:

```text
Q
```

Knowledge base:

```text
P → Q
R → P
R
```

Convert to clauses:

```text
¬P ∨ Q
¬R ∨ P
R
¬Q        ; negated goal
```

Resolution:

```text
¬P ∨ Q, ¬Q      => ¬P
¬R ∨ P, ¬P      => ¬R
R, ¬R           => □
```

`□` is the empty clause, so `Q` is proved by contradiction.

### Forward vs Backward Chaining

| Feature | Forward Chaining | Backward Chaining |
|---|---|---|
| Direction | Facts to conclusion | Goal to supporting facts |
| Also called | Data-driven | Goal-driven |
| Search style | Often breadth-like rule firing | Often depth-first proof search |
| Good for | Deriving all possible conclusions | Answering a specific query |
| Example system | Monitoring and alert systems | Diagnosis and theorem proving |

### Predicate Logic Symbol Examples

Universal statement:

```text
∀x (Student(x) → Human(x))
```

Existential statement:

```text
∃x (Student(x) ∧ Likes(x, AI))
```

Nested quantifier example:

```text
∀x ∃y Loves(x, y)
```

Meaning:

Everyone loves someone.

Different meaning:

```text
∃y ∀x Loves(x, y)
```

Meaning:

There exists someone whom everyone loves.

So:

```text
∀x ∃y Loves(x, y) ≠ ∃y ∀x Loves(x, y)
```

### Quantifier Properties

Equivalent:

```text
∀x∀y P(x, y) ≡ ∀y∀x P(x, y)
∃x∃y P(x, y) ≡ ∃y∃x P(x, y)
```

Not generally equivalent:

```text
∀x∃y P(x, y) ≠ ∃y∀x P(x, y)
```

Negation rules:

```text
¬∀x P(x) ≡ ∃x ¬P(x)
¬∃x P(x) ≡ ∀x ¬P(x)
```

### Unification Examples

| Expression 1 | Expression 2 | Substitution |
|---|---|---|
| `Knows(Ram, x)` | `Knows(Ram, Sita)` | `{x/Sita}` |
| `Parent(x, Sita)` | `Parent(Ram, y)` | `{x/Ram, y/Sita}` |
| `Likes(x, x)` | `Likes(Ram, Sita)` | Fails because `x` cannot be both `Ram` and `Sita` |

Most general unifier:

```text
MGU(Knows(Ram, x), Knows(y, Sita)) = {y/Ram, x/Sita}
```

### FOPL Resolution With Symbols

Knowledge:

```text
∀x (Human(x) → Mortal(x))
Human(Socrates)
```

Goal:

```text
Mortal(Socrates)
```

Clauses:

```text
¬Human(x) ∨ Mortal(x)
Human(Socrates)
¬Mortal(Socrates)
```

Resolution:

```text
¬Human(x) ∨ Mortal(x)
¬Mortal(Socrates)
Substitution: {x/Socrates}
=> ¬Human(Socrates)

¬Human(Socrates)
Human(Socrates)
=> □
```

Therefore:

```text
Mortal(Socrates)
```

### Why Uncertainty Needs Probability

A strict logical rule such as:

```text
Toothache → Cavity
```

is too strong because a toothache may be caused by gum disease, injury, sensitivity, or other causes.

A probabilistic version is more realistic:

```text
P(Cavity | Toothache) = 0.65
```

This means:

Given toothache, the probability of cavity is 65 percent, not 100 percent.

### Probability Rules

Product rule:

```text
P(A ∧ B) = P(A | B)P(B)
```

Bayes' rule:

```text
P(A | B) = P(B | A)P(A) / P(B)
```

Normalization:

```text
P(A | B) = α P(B | A)P(A)
```

where `α` is a normalizing constant.

Total probability:

```text
P(B) = Σ_i P(B | Ai)P(Ai)
```

when `{A1, A2, ..., An}` is an exhaustive and mutually exclusive set.

### Full Joint Distribution Example

Variables:

```text
Cloudy ∈ {T, F}
Rain ∈ {T, F}
WetGrass ∈ {T, F}
```

One full joint entry:

```text
P(Cloudy=T, Rain=T, WetGrass=T)
```

Query by summing:

```text
P(Rain=T) = Σ_c Σ_w P(c, Rain=T, w)
```

This is called marginalization.

### Bayesian Network Factorization

For a Bayesian network:

```text
Rain -> WetGrass <- Sprinkler
Rain -> Sprinkler
```

The joint distribution can be factored as:

```text
P(Rain, Sprinkler, WetGrass)
= P(Rain) P(Sprinkler | Rain) P(WetGrass | Rain, Sprinkler)
```

Example:

```text
P(WetGrass ∧ Sprinkler ∧ Rain)
= P(WetGrass | Sprinkler, Rain) P(Sprinkler | Rain) P(Rain)
```

If:

```text
P(WetGrass | Sprinkler, Rain) = 0.99
P(Sprinkler | Rain) = 0.01
P(Rain) = 0.20
```

Then:

```text
P(WetGrass ∧ Sprinkler ∧ Rain)
= 0.99 × 0.01 × 0.20
= 0.00198
```

### Belief Network Reasoning Types

| Reasoning Type | Direction | Example |
|---|---|---|
| Predictive | Cause to effect | Rain observed, infer wet grass |
| Diagnostic | Effect to cause | Wet grass observed, infer rain |
| Intercausal | Between competing causes | Wet grass observed and sprinkler known, reduce belief in rain |
| Mixed | Multiple directions | Symptoms and test results infer disease |

### Decision Theory

Decision theory combines probability and utility:

```text
Decision Theory = Probability Theory + Utility Theory
```

Expected utility:

```text
EU(a) = Σ_s P(s | a, evidence) U(s)
```

Best action:

```text
a* = argmax_a EU(a)
```

Example:

A medical AI should not only choose the most probable disease; it should also consider risk, treatment cost, and harm of wrong treatment.

### Fuzzy Logic Membership Graph

Example fuzzy set: `Hot temperature`

```text
μHot(x)
1.0 |                         ______
    |                       /
0.5 |              ________/
    |            /
0.0 |___________/
    +------------------------------> Temperature
       10     20     30     40
```

Here:

```text
μHot(20°C) = 0.0
μHot(30°C) = 0.5
μHot(40°C) = 1.0
```

### Fuzzy Operations

For membership values `a` and `b`:

```text
μA∧B(x) = min(μA(x), μB(x))
μA∨B(x) = max(μA(x), μB(x))
μ¬A(x) = 1 - μA(x)
```

Example:

```text
μHot(Temperature) = 0.7
μHumid(Humidity) = 0.6
μHot∧Humid = min(0.7, 0.6) = 0.6
```

### Fuzzy Controller Example

Rules:

```text
R1: IF temperature is cold THEN fan_speed is low
R2: IF temperature is warm THEN fan_speed is medium
R3: IF temperature is hot THEN fan_speed is high
```

Input:

```text
Temperature = 32°C
μWarm(32) = 0.6
μHot(32) = 0.4
```

Output:

```text
Medium fan speed activated to degree 0.6
High fan speed activated to degree 0.4
```

After defuzzification, the crisp fan speed may be:

```text
Fan speed = 65%
```

### Logic Type Comparison

| Logic Type | Truth Value | Handles Uncertainty? | Example |
|---|---|---|---|
| Boolean logic | `0` or `1` | No | `Rain=True` |
| Probabilistic logic | Probability from `0` to `1` | Yes, random uncertainty | `P(Rain)=0.7` |
| Fuzzy logic | Degree of truth from `0` to `1` | Yes, vagueness | `μHot(35°C)=0.8` |

## Summary of Knowledge Representation Types

| Type | Representation | Best For |
|---|---|---|
| Semantic Net | Graph of concepts and relations | Relationships and inheritance |
| Frames | Slots and fillers | Structured objects |
| Conceptual Dependency | Primitive actions | Natural language meaning |
| Scripts | Event sequences | Common situations |
| Rule-Based System | If-then rules | Expert systems |
| Propositional Logic | True/false propositions | Simple logical reasoning |
| Predicate Logic | Objects, relations, quantifiers | Complex logical reasoning |
| Bayesian Network | Probabilistic graph | Uncertain reasoning |
| Fuzzy Logic | Partial truth values | Approximate reasoning |

## Key Terms

- Knowledge: Facts, rules, skills, and experience.
- Knowledge Representation: Storing knowledge in machine-usable form.
- Reasoning: Deriving conclusions from knowledge.
- Knowledge Base: Collection of stored facts and rules.
- Inference Engine: Mechanism that derives new conclusions.
- Semantic Net: Graph-based knowledge representation.
- Frame: Object representation using slots and fillers.
- Script: Sequence of events in a common situation.
- Propositional Logic: Logic using true/false propositions.
- Predicate Logic: Logic using objects, relations, and quantifiers.
- Bayesian Network: Probabilistic graphical model.
- Fuzzy Logic: Logic that allows partial truth.

## Short Exam Answers

### What is knowledge representation?

Knowledge representation is the process of storing facts, rules, objects, relations, and experience in a form that a machine can understand and use for reasoning and decision making.

### What are the properties of a good knowledge representation system?

A good knowledge representation system should have representational adequacy, inferential adequacy, inferential efficiency, and acquisitional efficiency.

### What is the difference between propositional logic and predicate logic?

Propositional logic represents complete statements as true or false propositions. Predicate logic represents objects, properties, relations, and quantifiers, so it is more expressive.

### What is Bayes' Rule?

Bayes' Rule is a formula for updating probability after observing evidence:

```text
P(A | B) = [P(B | A) P(A)] / P(B)
```

### What is fuzzy logic?

Fuzzy logic is a reasoning method that allows partial truth values between 0 and 1. It is useful for vague concepts such as hot, tall, fast, and high risk.
