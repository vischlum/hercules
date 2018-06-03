# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    hind.rb                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/21 17:50:16 by vischlum     #+#   ##    ##    #+#        #
#    Updated: 2018/02/21 19:35:54 by vischlum    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/usr/bin/ruby
# Includes
require "oauth2"
require "colorize"
require "colorized_string"
# Credentials (from environment variables)
if ENV['API_UID'] == nil
	abort("Please export API_UID environment variable")
end
UID = ENV['API_UID']
if ENV['API_SECRET'] == nil
	abort("Please export API_SECRET environment variable")
end
SECRET = ENV['API_SECRET']
# Create the client with your credentials
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
# Get an access token
$token = client.client_credentials.get_token

# Define campus
$campus = ["∅", "Paris", "Cluj", "∅", "∅", "Johannesburg", "Chisinau", "Fremont", "Kyiv", "Lyon", "Bucharest", "Montrouge", "Brussels", "Helsinki", "Amsterdam", "Cape-Town"]

# Try to connect. If it fails, loop until it succeeds.
# Check the username validity and display res.
def find_user(login)
	begin
		sleep(0.6)
		res = $token.get("/v2/users/#{login}/locations")
		until res.status == 200
			puts ("Server might be down. Gonna try again in 3...").red.on_yellow.blink
			sleep(1)
			puts ("2...").red.on_yellow.blink
			sleep(1)
			puts ("1...").red.on_yellow.blink
			sleep(1)
		end
		if !res.parsed[0]["end_at"]
			print (login.ljust(9) + ": " + "available on " + res.parsed[0]["host"]).green
			puts (" on campus " + $campus[res.parsed[0]["campus_id"]]).green
		else
			print (login.ljust(9) + ": unavailable (last seen on " + res.parsed[0]["host"] + ")").light_magenta
			puts (" on campus " + $campus[res.parsed[0]["campus_id"]]).light_magenta
		end
	rescue
		puts (login.ljust(9) + ": invalid username").red
	end
end

# Check if file is valid and open it on mode "read only".
# Display usage if file is invalid.
if ARGV[0]
	if File.file?(ARGV[0])
		file = File.open(ARGV[0], "r").each_line do |line|
			line == "\n" ? next : login = line.strip
			find_user(login)
		end
		file.close
	else
		puts ("Invalid file").bold.red
	end
else
	puts "usage: " + $PROGRAM_NAME + " [text file]"
end
