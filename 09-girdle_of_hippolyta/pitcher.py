#!/usr/bin/env python3

import os
import smtplib
from email.mime.text import MIMEText

user = os.environ["GIRDLE_USER"]
password = os.environ["GIRDLE_PASSWORD"]

recipient = "vischlum@student.le-101.fr"

message = MIMEText("https://www.youtube.com/watch?v=RLdpQHCoCso")
message["Subject"] = "Hercules - The Legendary Journeys"
message["From"] = user
message["To"] = recipient

try:
	print("Pre SMTP")
	mailserver = smtplib.SMTP("smtp.laposte.net", 25)
	print("Post SMTP")
	mailserver.ehlo()
	mailserver.starttls()
	mailserver.ehlo()
	mailserver.login(user, password)
	mailserver.sendmail(user, recipient, message.as_string())
	print("Email was sent. Quitting mailserver")
	mailserver.quit()
except:
	print("I like a belt and suspenders approach (or girdle and suspenders, I guess) with try and except. Sadly, this was not enough this time.")
