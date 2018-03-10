# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### Problem statement 
The problem statement for the online qualification round is available [here](https://github.com/LDevi/GoogleHashCode2018/blob/master/doc/online_qualification_round_2018.pdf)

### Our implementation.
We decided to use the C ++ language to answer the problem. 
At first, we considered the problem of "self-driving rides" as the construction of a schedule.
Indeed, the number of cars, their positions but also all rides (duration + positions) are known in advance.


### The first try.
Certainly not the most optimized, it is nonetheless a primordial step to understand the problem before going further in the process of optimization
The [first_attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt) branch contains a simple algorithm : for each race, seek the first vehicle cappable to finish on time and assign the ride to it.

### Adding greedy behaviour.
A step further in the optimization process could be adding a greedy behaviour to the algorithm.
The [greedy_without_bonus](https://github.com/LDevi/GoogleHashCode2018/tree/greedy_without_bonus) branch add a simple greedy behavior [first_attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt): for each race, among vehicles cappable to finish on time, seek the fastest vehicle to finish and assign the ride to it.
 
