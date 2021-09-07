import sounddevice as sd
from scipy.io.wavfile import write

import speech_recognition as sr
from pyttsx3 import speak


r = sr.Recognizer()

fs = 44100  # Sample rate
seconds = 3  # Duration of recording
print("Recoding started")
myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2)
sd.wait()  # Wait until recording is finished
write('output.wav', fs, myrecording)  # Save as WAV file

# open the file
with sr.AudioFile("output.wav") as source:
    # listen for the data (load audio to memory)
    audio_data = r.record(source)
    # recognize (convert from speech to text)
    text = r.recognize_google(audio_data)
    print(text)
