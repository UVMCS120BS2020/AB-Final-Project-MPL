from pydub import AudioSegment
from pydub.playback import play
from pysndfx import AudioEffectsChain
import os
import sys

# Collect CLI arguments
infile = sys.argv[1]
ext = sys.argv[2]
option = sys.argv[3]
outfile = "output.wav"
convert = "convert.wav"

print("Playing original audio...")
orig = AudioSegment.from_file(infile, format=ext)
play(orig)

orig.export(convert, format="wav")
infile = convert
new = AudioSegment.from_file(convert, format="wav")

if option == 'reverse':
    reverse = (
        AudioEffectsChain()
            .reverse()
    )
    reverse(infile, outfile)
    sound = AudioSegment.from_file(outfile, format="wav")
    print("Playing modified audio...")
    play(sound)
elif option == 'speed':
    rate = sys.argv[4]
    speed = (
        AudioEffectsChain()
            .speed(rate)
    )
    speed(infile, outfile)
    sound = AudioSegment.from_file(outfile, format="wav")
    print("Playing modified audio...")
    play(sound)
elif option == 'tempo':
    rate = sys.argv[4]
    tempo = (
        AudioEffectsChain()
            .tempo(rate)
    )
    tempo(infile, outfile)
    sound = AudioSegment.from_file(outfile, format="wav")
    print("Playing modified audio...")
    play(sound)
elif option == 'reverb':
    reverb = (
        AudioEffectsChain()
            .reverb()
    )
    reverb(infile, outfile)
    sound = AudioSegment.from_file(outfile, format="wav")
    print("Playing modified audio...")
    play(sound)

os.remove(outfile)
os.remove(convert)




