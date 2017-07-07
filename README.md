# Arduino-Buttons_Library
Library that identifies button's actions

USE THE EXAMPLES AND READ THE EXPLANATIONS IF YOU DON'T WANT ANY PROBLEMS

The library caontains a Timer's library - used for timing the actions, also used in the examples.

For explanations about both of the libraries use the function help().
Please use the examples to learn how to use the functions correctly, without bugs or any delay.


Explanations:

You need to use delay of at least 1 mili second for the library to work because the loop() does about 8 loops per mili second, and because the library uses Timers to identify the actions it's getting messed together.

If you don't want to use delay (like me) because it stucks your program you can use the Timer library with a stopClock() of at least 20 mili seconds (like I used in the Basic_Actions example).
