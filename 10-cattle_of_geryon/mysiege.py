#!/usr/bin/env python3

import aiohttp
import asyncio
import argparse
import urllib.parse # To check the formal validity of the URL
import urllib.request # To check the validity of the URL
import urllib.error # To display the proper error message if the URL is invalid
from sys import exit # To exit properly
from time import process_time # To clock the execution time

# It is a SyntaxError to use async with outside of an async def function (PEP 492)
async def load_test(url, i):
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            requests = 0
            ok = 0
            while requests < i:
                print(resp.method + " for " + str(resp.url) + " ==> " + resp.reason + " (code " + str(resp.status) + ")")
                if resp.status == 200:
                    ok += 1
                requests += 1
            print("Success rate: " + str(ok) + " out of " + str(requests))
            print("Total execution time: " + str(process_time()) + "s")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("URL", help="The URL of the server you wish to load-test")
    parser.add_argument("Iterations", type=int, help="How many requests you wish to send")
    args = parser.parse_args()

# Check that the URL is formally valid
    page = urllib.parse.urlparse(args.URL)
    if (page.scheme and page.netloc and page.path):
        pass 
    else:
        print("URL not formally valid.\nMake sure it looks like this: http://www.example.com/ (don't forget the http:// nor the / at the end")
        exit()

# Check that the URL is valid
    try:
        page = urllib.request.urlopen(args.URL)
    except urllib.error.HTTPError as e:
        print("HTTP ERROR: " + str(e.code))
        exit()
    except urllib.error.URLError as e:
        print("URL ERROR: " + str(e.reason))
        exit()

# Start the loop
    loop = asyncio.get_event_loop()
    try:
        loop.run_until_complete(load_test(args.URL, args.Iterations))
    finally:
        loop.close()

main()
