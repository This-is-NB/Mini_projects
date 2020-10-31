import webbrowser
import time
import random

while True:
    sites = random.choice(["google.com","facebook.com","twitter.com","linkedin.com"])
    visit = "http://{}".format(sites)
    webbrowser.open(visit)
    time.sleep(random.randrange(5,23))