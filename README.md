# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### Adding greedy behaviour.
Based on the [first attempt](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt).
A step further in the optimization process could be adding a greedy behaviour to the algorithm. 
Instead of adding a ride to the first vehicle available, a better strategy could be to give it to the  the fastest vehicle to finish.
So  
```
for r in rides
 for v in allVehicles
  if v can make r 
    then assign r to v
    break
```

Becomes :
```
for r in rides {
    Vehicle fastestVehicle
    int fastestTimeToRide
     for v in allVehicle {
        timeToRide = v.computeTimeToRide(r)
        if fastestTimeToRide>timeToRide
        the fastestTimeToRide = timeToRide
        fastestVehicle = v
       }
      assign r to fastestVehicle
}
```


#### Total score 
We reached the total score of 32 387 097, it's ~10% more than the last score !
![score](https://raw.githubusercontent.com/LDevi/GoogleHashCode2018/greedy_without_bonus/res/score/score.PNG)
