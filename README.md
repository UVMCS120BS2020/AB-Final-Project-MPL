# AB-Final-Project-MPL - Sound Manipulator

## Summary
This program allows a user to take a desired sound file (supports most extensions),
adds an effect to it, then plays it back.

Through any command line interface, navigate to the directory of which the project files are located.
Using the `g++ -std=c++1y main.cpp` command compiles the program, 
and `./a.exe` will execute the program.

The options for audio manipulation are:

- Reverse - Reverses the sound of an audio file.
- Speed - Changes the rate, as well as the pitch, at which an audio file is played.
- Tempo - Changes the rate at which an audio file is played (pitch remains intact).
- Reverb - Adds a reverb, or echo, effect to an audio file.

See _Usage_ for an example of how to use this program.

## Requirements
This program utilizes:

[Pydub](https://github.com/jiaaro/pydub) and its dependencies
- *NOTE: If you have issues installing PyAudio on Windows, download the appropriate binding from [here](https://www.lfd.uci.edu/~gohlke/pythonlibs/#pyaudio),
then install the file using pip.

[pysndfx](https://github.com/carlthome/python-audio-effects) and its dependencies 

## Usage
Here is an example of usage:

```commandline
Welcome to the Sound Manipulator.
This program allows you to take a sound file, and add effects to it!
Here are your options:
Enter (a) to reverse
Enter (b) to change speed
Enter (c) to change tempo
Enter (d) to add reverb
Enter (e) to exit this program
```
Here, we enter in a filename if it is located in the same directory as the program files, or a path to a file located in another directory.
In this case, we chose _test.wav_.
```commandline
Enter filename (example.mp3) or path to file (C:/.../example.wav), or enter nothing to use the default sound file: test.wav
File found...
```
Once the file has been confirmed to be found, we then enter in our manipulation choice.
In this case, we chose _b_, which is the option to change the speed of the audio file.
```commandline
Enter manipulation choice: b
```
Because we chose this particular option, we are prompted again to enter in a number that is strictly greater than zero.
This will be the rate at which the sound will be played.
In this case, we chose _1.5_.
```commandline
Enter the speed rate (must be > 0): 1.5
Processing...
```
Once we have fulfilled all of the inputs, the program will proceed to play the original audio that was entered, followed by the audio that we manipulated.
```commandline
Playing original audio...
Playing modified audio...
```
