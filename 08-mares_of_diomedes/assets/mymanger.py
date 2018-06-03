#!/Users/vischlum/.brew/bin/python3

from PIL import Image
from playsound import playsound
import os

# Need to define the currentdir for the script to work when called by findus.sh
#currentdir = "/Users/vischlum/Documents/hercules/08-mares_of_diomedes/draft/assets/"
currentdir = os.path.dirname(os.path.realpath(__file__)) + '/'

climo = Image.open(currentdir + 'pics/climo.jpg')
findus = Image.open(currentdir + 'pics/findus.jpg')
hbo = Image.open(currentdir + 'pics/siliconvalley.jpg')
ted = Image.open(currentdir + 'pics/lovelyhorse.jpg')

i = 0
while (i == 0):
    playsound(currentdir + 'genial.mp3', 0) # the zero is to play in background
    findus.rotate(45).show()
    hbo.show()
    climo.show()
    ted.show()

print("That's all folks!")
