# Digital Egg Drop

## Activity Description

During this activity, students will construct landing capsules for a hypothetical martian expedition. We will measure the acceleration experienced by passengers during a simulated landing using a microcontroller with an accelerometer. This activity is intended to teach students about acceleration, force, and how these concepts are considered when engineers design spacecraft.

**If the microcontroller is not working, you can use a stop watch to time the descent of the landers instead. Then the lander with the largest descent time will be the one with the smallest acceleration.**

## Activity Instructions

##### Time Required: 1 hr (more if redesign allowed)
##### Instructors required: 3+
##### Audience Size: <30
This is limited by the time required to test each design with a single microcontroller. Larger audiences can be accomodated with additional microcontrollers.
##### Ages: 6+
Younger kids might have fun building the landing systems, but may find it difficult to work in groups on the designs if they are unaccompanied.

### Required Materials

- Digiegg Microcontroller w/ DigieggSketch loaded (setup described below)
- Bluetooth equipped iOS or Android phone with the [Bluefruit](https://learn.adafruit.com/bluefruit-le-connect/ios-setup) app installed.
- Paper (3 sheet minimum per group of ~4-5)
- Masking Tape
- (OPTIONAL) Scissors
- (OPTIONAL) Additional building materials (e.g. egg cartons, cardboard)
- Step stool or chair to stand on (or a stairwell) during drop
- Spreadsheet for recording results

### Instructor Instructions

1. **Introduce the concepts of force and acceleration.** Included in this repository are slides for a presentation that covers some introduction to force and acceleration in the context of space flight and unmanned missions. This presentation is at the level of undergraduates, but can work well for advanced middle school and high school students as well. For younger groups, I recommend just sticking to a few basic properties of acceleration and force using the following introduction.

    1. **Acceleration as change in speed.** If you have an open space, have the students stand in a line on one side of the room and then, on your mark, run to the other side and stand there. Explain that as they go from standing still to moving they are accelerating, but they are also accelerating when they slow down (decellerating) and stop at the end of their run.
    1. **Acceleration as change in direction.** Have the students run in a circle at the same speed. Ask them if they think they are accelerating. Explain that even though they are not changing speed, they are changing direction, which is also a form of acceleration.
    1. **Relationship to Force.** Tell them that force is what they have to apply to accelerate objects. Ask them if they need to apply more or less force to move a pebble or a boulder. Explain that more massive objects (heavier) require greater force to move. Ask them to imagine that they have to move a boulder from one side of the room to the other. Ask them if it would require more or less force to move it in one minute or an hour. Explain that it takes more force to accelerate faster than slower.
    1. **Force during decelleration.** Ask them if force is required to slow down or stop moving objects? Explain that force is required for decelleration because it is still a form of acceleration and force depends on acceleration. Ask them why it is ok for someone to jump in a full swimming pool, but not an empty one. Tell them that it's because of acceleration. When there is water in the pool, the water slows you down over a larger distance so that you stop before you hit the bottom, resulting in a smaller acceleration and so you experience a smaller force. When there isn't water in the pool, you slow down extremely quickly when you hit the bottom; a larger acceleration so you experience a larger force.
    1. **Relationship to Astronomy.** Ask them why this might be an important consideration for astronomers. Tell them that both manned and unmanned spacecraft have to make sure that they don't accelerate/decellerate too quickly or the forces they experience could damance the people or equipment inside them (like the example of jumping in an empty swimming pool).
  1. **Landing systems.** Ask them what are some ways to decrease the acceleration of space craft as they land. Be sure to cover things like parachutes, air bags, crumple zones, padded seats, aerodynamics, and landing engines. It would probably be good to have a few slides showing some of these things on actual space craft.
    1. **Explain the activity.** Explain that they are going to design their own landing system for a hypothetical mission to Mars using the materials we provide and that we will have a competition to see who can make the "safest" system.
  
1. **Introducte the sensor.** Tell the students that the sensor is a miniature computer that measures accelerations and sends them to the phone over bluetooth. It might be good to run a demonstration showing that the plot spikes when the accelerations are larger. Ask them what they think the acceleration should be when the sensor is sitting still. Explain that it won't be zero, because we are all accelerating due to Earth's gravity. That is the force that keeps us from floating away when we jump. Tell them that their landing system must have a "capsule" to contain the sensor and that it cannot fall out.
1. **Begin assembly.** Break the students into groups of ~4 (can be larger if they know each other) and pass out the materials.
1. **Assembly.** Give them ~30 minutes to assemble their landing gear. Tell them that when they are done they can come test to make sure that the sensor stays in their "capsule".
1. **Testing.** As groups finish you can begin testing the designs. One instructor will drop the designs, one instructor will record results in a spreadsheet, and one instructor will operate the phone and coordinate drops. Each run should include 3 trials and occur as follows:

    1. Have the design group stand around the instructor with the phone and give their lander to the instructor handling the drop.
    1. The instructor operating the phone will start recording accelerations and tell the dropper to begin dropping.
    1. If it does not take long to retrieve the lander, you will likely be able to do 3 drops within a single recording session (the accelerations are only sent to the phone for a limited time as described below). If it takes longer to retrieve the lander, you may need to use multiple recording sessions (be sure to record data from the previous one before starting the next as the data is not preserved).
    1. Record the peak acceleration for each drop in a spreadsheet and take the average (or minimum) for the groups official value.

1. **Redesign.** If there is time remaining, the groups can try to modify their design and improve their measurements.
1. **Conclusions.** Ask the students what they think worked best (i.e. what design aspects did the teams with the best results use). Ask the students what they think they could do better. Ask the students what materials they wish they had for their design.

## Details and Setup Instructions

### Microcontroller

The microcontroller we use for this experiment is a [TinyDuino Basic Kit](https://tinycircuits.com/products/tinyduino-basic-kit) with a [TinyShield Accelerometer](https://tinycircuits.com/products/accelerometer-tinyshield), and a [TinyShield ST Bluetooth LE](https://tinycircuits.com/products/bluetooth-low-energy-tinyshield) board. This arrangement is really easy to assemble (the boards click together link legos, no soldering required). Instructions on assembling and testing the microcontroller, sensor, and bluetooth assembly can be found [here](http://iotdesign.embedded-computing.com/articles/build-an-internet-connected-bluetooth-wearable-with-arduino-and-cordova-part-one/).

### Instructions for Setting up the Microcontroller

1. Follow the instructions [here](http://learn.tinycircuits.com/Processors/TinyDuino_Setup_Tutorial/) for assembling just the processor board and USB TinyShield and installing/running the "Blink" program. This will include installing the software necessary for loading programs onto the microcontroller.
1. Follow the instructions [here](http://iotdesign.embedded-computing.com/articles/build-an-internet-connected-bluetooth-wearable-with-arduino-and-cordova-part-one/) for adding and testing the accelerometer and bluetooth components.
1. Download this repository
1. Upload the "DigieggSketch" from this repository in the same manner used to upload sketches from the previous tests.

### Instructions for Using the App

1. Download the Bluefruit app appropriate for your phone's operating system as described [here](https://learn.adafruit.com/bluefruit-le-connect/ios-setup).
1. With the Digiegg microcontroller switch in the on position and power supplied via a USB cable or a coin battery, open the Bluefruit app and look for a device called "DigiEgg" in the list on the app's "Central Mode" page. Hit connect to establish a connection. This should open a new "Modules" page display options for interacting with the Digiegg.
1. From the DigiEgg "Modules" page, select the "UART" option. You can use this to send a message to the Diggegg. The DigieggSketch you uploaded is written such that when the Digiegg receives ANY message, it will start transmitting acceleration values at a rate of X for X seconds.
1. Once you have sent any message on the UART page, you will start to see accelerations printed to the screen. These are the total accelerations (absolute) in units internal to the microcontroller code. You can then go back to the "Modules" page and select the "Plotter" option. This will plot the acclerations as they are received from the Digiegg as a function of time. When you move the Digiegg, you should see changes in the accelerations. When the microcontroller is sitting still (such as on a counter), the acceleration plot should be flat.


## Troubleshooting

If you are having trouble connecting with the microcontroller try the following:

1. Turn on Bluetooth. Make sure that your phone's bluetooth is on.
1. Turn on the microcontroller. There is a small switch on the side for turning the device on and off. There is a green LED that should flash when you turn the controller on. If this does not happen, it may need a new battery.
1. Check the battery. If you have replaced the battery, but it is still not working, make sure the battery is in correctly. The positive side (flat) should be facing out and the negative side should be against the controller.
1. Reloading the App. Sometimes the App does not properly repopulate the list of devices and it may need to be refreshed.
1. You may need to reload the DigieggSketch as described above.
1. If none of these works, you should try rebuilding the microcontroller from scratch, including doing the intermediary tests to make sure that each component is working.
