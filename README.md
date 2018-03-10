# Google Hash Code 2018 participation's 
Self-driving rides - Problem statement for the Online Qualification Round of Hash Code 2018

### What is Google Hash Code ? 
https://hashcode.withgoogle.com/overview.html

### The first try.

At this point we want to make things simples : just give rides to each vehicle until its schedule is full (ie. no other ride can be made at time).
We did not worry about bonus points.

#### First part - Give work to the vehicles

For each ride : ask the first vehicle if it can make the ride.
If it can, then assign the ride to that vehicle. Take next ride and do it again. 
If it can not, then ask to the next vehicle.

```c_cpp
for r in rides
 for v in vehicle
  if v can make r 
    then assign r to v
    break
```

#### Second part - How to decide whether or not a vehicle can take a ride.

Second step was to decide how a vehicle can make or not a ride.
A first answer could be : "This vehicle can make the ride if the ride can be made on time". 

Thus, a vehicle can make a ride if : 
- the time to get to the start intersection;
- plus the time to wait for the earliest start (if needed); 
- plus time to get to the finish intersection;
- does not exceed the deadline nor the end of the total time.

We need to calculate the distance between two intersections in the city, fortunately the statement gives us the formula (oh, Pythagoras ...).


```
Object Ride {
int deadLine
Point startPosition(xStart, yStart),
Point endPosition(xEnd,yEnd)
                
}
Object Vehicle {
Point currentPosition(xCur, yCur)

fun distanceBetweenPoints(input Point start(xStart, yStart), input Point end(xEnd,yEnd)) = abs(xEnd-xStart) + abs(yEnd - yStart)


fun computeTimeToRide(input Point startPosition(xStart, yStart),
    input Point endPosition(xEnd,yEnd)){
    tReachStart = distanceBetweenPoints(currentPosition,startPosition)
    tWait = tDeadLine-tReachStart>0 ? tDeadLine-tReachStart : 0
    tReachEnd = distanceBetweenPoints(startPosition,endPosition)
    return (tReachStart+tWait+tReachEnd)
}

fun canTakeRide(input Ride ride) = (computeTimeToRide(ride.startPosition,ride.endPosition) < ride.deadLine)

}
```

We laid the firsts bricks. 

But what happens if the vehicle already has other planned races?
We need to take into account the rides already assigned to that vehicle to tell whether or not the vehicle can make an other ride.

We need to add the list of already scheduled rides to each vehicle :

```
Object Vehicle {
ListOf:Point scheduledRides
...


```
then, ```fun canTakeRide()``` becomes :
```
fun canTakeRide(input Ride ride){
return canTakeMoreRide() && (computeTimeToRide(ride.startPosition,ride.endPosition) < ride.deadLine)
}

```

```fun canTakeMoreRide()``` defined as below :
```
fun canTakeMoreRide(){
    for r in scheduledRides {
     totalTime += computeTimeToRide(r)
     if totalTime >= r.tDeadLine return false
    } 
    currentPosition = scheduledRides.last.endPosition
}

```

#### Total score 
We reached the total score of 11 649 924  !
![score](https://raw.githubusercontent.com/LDevi/GoogleHashCode2018/first_attempt/res/score/score.PNG)


**EDIT** :

When reviewing our code I noticed a little typo.

We were taking into account the earliest start when computing already taken rides but not the one tested when adding.
https://github.com/LDevi/GoogleHashCode2018/commit/e228d68cfd1de19f96ecbad1f215cb333b39658a
After fix : 

We reached the total score of **29 285 232** !

![score_fixed](https://raw.githubusercontent.com/LDevi/GoogleHashCode2018/first_attempt/res/score/score_fixed.PNG)
