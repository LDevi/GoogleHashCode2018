# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### Our implementation.
We decided to use the C ++ language to answer the problem. 
At first, we considered the problem of "self-driving rides" as the construction of a schedule.
Indeed, the number of cars, their positions but also all rices (duration + positions) are known in advance.

We got into the game and decided to continue working on the problem during the Extended Round.

### The first try. During the Online Qualification Round.
Certainly not the most optimized it is nonetheless a primordial step to understand the problem before going further : in the process of optimization.
The [first_attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt) branch contains a simple algorithm.

### Adding greedy behaviour. During the Extended Round and later.
A step further in the optimization process could be adding a greedy behaviour to the algorithm
The [greedy_without_bonus](https://github.com/LDevi/GoogleHashCode2018/tree/greedy_without_bonus) branch implements a simple greedy behavior : give the ride to the nearest vehicle.
 

### Taking bonus into account. During the Extended Round and later.
An other way to improove the score could be taking into account the bonus given to each ride when a ride starts at time.
The [greedy_with_bonus](https://github.com/LDevi/GoogleHashCode2018/tree/greedy_with_bonus) branch adds bonus consideration into the greedy_without_bonus algorithm.
 

### Our best score. During the Extended Round and later.
We went up to 36 574 425 pts. The best scores go up to 50 000 000.

![score](https://raw.githubusercontent.com/LDevi/GoogleHashCode2018/master/res/score/best_score.PNG)

There are several other optimization ideas, implementations can be added here if we have time.
