# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### Problem statement 
The problem statement for the online qualification round is available [here](https://github.com/LDevi/GoogleHashCode2018/blob/master/doc/online_qualification_round_2018.pdf)

### Our implementation.
We decided to use the C ++ language to resolve the problem. 
During the qualification round we considered the statement as "a schedule making" problem.
Indeed, the number of cars, positions but also all rides (duration + positions) are known in advance.

### The first try. During the Online Qualification Round.
Certainly not the most optimized, it is nonetheless a primordial step to understand the problem before going further in the process of optimization
The [first_attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt) branch contains a simple algorithm : for each race, seek the first vehicle cappable to finish on time and assign the ride to it.

### Adding greedy behaviour. During the Extended Round and later.
A step further in the optimization process could be adding a greedy behaviour to the algorithm.
The [greedy_without_bonus](https://github.com/LDevi/GoogleHashCode2018/tree/greedy_without_bonus) branch add a simple greedy behavior [first_attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt): for each race, among vehicles cappable to finish on time, seek the fastest vehicle to finish and assign the ride to it.
 
### Taking bonus into account. During the Extended Round and later.
An other way to improove the score could be taking into account the bonus given to each ride when a ride starts at time.
The [greedy_with_bonus](https://github.com/LDevi/GoogleHashCode2018/tree/greedy_with_bonus) branch adds bonus consideration into the greedy_without_bonus algorithm.
 

### Our best score. During the Extended Round and later.
We went up to 36 574 425 pts. The best scores go up to 50 000 000.

![score](https://raw.githubusercontent.com/LDevi/GoogleHashCode2018/master/res/score/best_score.PNG)

There are several other optimization ideas, implementations can be added here if we have time.
