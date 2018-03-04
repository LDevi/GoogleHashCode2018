# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### The first try.

At this point we want to make things simples : just give rides to each vehicle until its schedule is full (ie. ride can not be made at time).
We did not worry about bonus points.

#### First part - Give work to the vehicles

For each ride : ask the first vehicle if it can complete.
If it can the assign the ride to that vehicle and reiterate. 
If it can not complete the ride, then ask to the next vehicle.

```c_cpp
for r in rides
 for v in vehicle
  if v can take r 
    then assign r to v
    break
```

#### Second part - How to decide whether or not a vehicle can take a ride.

Second step was to decide how a ride can be assigned to a vehicle.
A first answer could be : "This vehicle can take the ride if the ride can be made at time". 

Vehicle can take a ride if : 
- time to get at the start intersection,
- plus time to wait for the earliest start (if needed), 
- plus time to drive to the finish intersection,
- does not exceed the deadline nor the end of the total time.

We need to calculate the distance between two intersections in the city, fortunately the statement gives us the formula (oh, Pythagoras ...).


```
// All theses belongs to an object that we would instanciate and the start of the program.
// We also could do that without object, then we would need to pass as input parameter the currentPosition, each time.

let currentPosition(xCur, yCur)

fun computeTimeToRide(
    
    input startPosition(xStart, yStart),
    input endPosition(xEnd,yEnd)
    ){
    Vehicle.currentPosition
    tReachStart = abs(xStart-xCur) + abs(yStart - yCur)
    tWait = tDeadLine-tReachStart>0 ? tDeadLine-tReachStart : 0
    tReachEnd = abs(xEnd-xStart) + abs(yEnd - yStart)
    return (tReachStart+tWait+tReachEnd)
}
```
```
fun canTakeRide(
input tDeadLine,
input startPosition(xStart, yStart),
input endPosition(xEnd,yEnd)
) =(computeTimeToRide(startPosition,endPosition) < tDeadLine)

```

We laid the firsts bricks. 

But what happens if the vehicle already has other planned races?
We need to take into account the ride already planned, to tell whether or not the vehicle can make a other ride.

```
fun canTakeRide(
    input tDeadLine,
    input startPosition(xStart, yStart),
    input endPosition(xEnd,yEnd)
    ) {
return canTakeMoreRide() && (computeTimeToRide(startPosition,endPosition) < tDeadLine)
}
```
```

fun canTakeMoreRide(){
    for r in TakenRides
     totalTime += computeTimeToRide(r)
     if totalTime >= r.tDeadLine return false
    
    currentPosition = TakenRides.last.endPosition
}


```

#### Total score 
We reached the total score of 11 649 924  !
![Image of Yaktocat](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt/res/score/score.png)

BUT, when reviewing our code I noticed a little typo.
We were taking into account the earliest start when computing already taken rides but not the one tested when adding.

Fixed branch is [here](https://github.com/LDevi/GoogleHashCode2018/tree/first_attempt_fixed)