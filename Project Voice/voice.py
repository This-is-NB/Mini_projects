import pyttsx3
import os
import time
from pyttsx3 import speak
import speech_recognition as sr

import voiceInput as vi

engine = pyttsx3.init()
engine.setProperty('rate', 150)
# Use female voice
voice_id = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_ZIRA_11.0"
engine.setProperty('voice', voice_id)
engine.setProperty('volume', 3)
engine.runAndWait()
os.system("cls")


if __name__ == "__main__":
    print("Welcome to Voice! your reading companion")
    speak("Welcome to Voice! your reading companion")
    print("Here you'll be given a task to read the given paragraph, and you will be given points related to your performence.. GOOD LUCK!!")
    speak("Here you'll be given a task to read the given paragraph, and you will be given points related to your performence.. GOOD LUCK!!")
    print("\n\tREAD THE FOLLOWING PARAGRAPH:")
    speak("So here is your first task for YOU....READ THE FOLLOWING PARAGRAPH")
    print("""
        The Moon is a barren, rocky world without air and water.It has dark lava plain on its surface.
        """)

    # The Moon is filled wit craters.It has no light of its own.It gets its light from the Sun.
    # The Moo keeps changing its shape as it moves round the Earth.It spins on its axis in 27.3 days
    # stars were named after the Edwin Aldrin were the first ones to set their foot on the Moon on 21
    # July 1969 They reached the Moon in their space craft named Apollo II.
    test = vi.takeinput()
    time.sleep(2)
