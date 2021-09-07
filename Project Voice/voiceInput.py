import speech_recognition as sr
from pyttsx3 import speak


def takeinput():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)  # dynamic duration less accuracy
        # audio = r.record(source, duration=30)    #static duration  more accuracy
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(query)
    except Exception as e:
        print(e)
        speak("Say that again please")
        return "None"
    return query


print("yes its here")
