#!/usr/bin/env python3

import os
import shutil       # To create and delete directories recursively
import fileinput    # To modify the Makefile inplace
import sys          # To receive commandline arguments

languages = ("python", "ruby", "perl", "lua")
 
def start():
    print("~🤖 ~ Welcome to vischlum's automaton! ~🤖 ~")

    # Ask the name of the project and attempt to create a directory of the same name
    name = input("What's the name of the project?\n")
    if not os.path.exists(name):
        os.makedirs(name)
    else:
        delete = input("A directory of the same name already exists. Do you want to delete it? (y/n)\n")
        if delete == "y":
            shutil.rmtree(name)
            os.makedirs(name)
        else:
            print("Then there's nothing I can do, sorry.")
            exit()

    # Create the author file, based on the environment variable LOGNAME
    file = open(name + "/author", 'w')
    file.write(os.environ['LOGNAME'] + '\n')
    file.close()

    # Ask the language and creates the necessary files and directories
    language = input("Which language do you want to use?\n")

    if language == 'C':
        shutil.copy("stuff/C/.gitignore", name)
        shutil.copy("stuff/C/Makefile", name)
        lib = input("Do you want to include the libft? (y/n)\n")
        if lib == "y":
            shutil.copytree("stuff/C/inc", name + "/inc")
            shutil.copytree("stuff/C/src", name + "/src")
            # Using a 'with' means 'makefile' is properly closed when 'with' is exited
            with fileinput.input(name + "/Makefile", inplace=True) as makefile:
                for line in makefile:
                    print(line.replace("project", name), end='')
        else:
            # Create empty /inc and /src directories and modify the Makefile to remove all references to the libft
            os.makedirs(name + "/inc")
            os.makedirs(name + "/src")
            with fileinput.input(name + "/Makefile", inplace=True) as makefile:
                for line in makefile:
                    if "lib" in line:
                        print(line.replace(line, ""), end='')
                    elif "LFT" in line:
                        print(line.replace("$(LFT)", ""), end='')
                    else:
                        print(line, end='')

    elif language.lower() in languages:
        shutil.copy("stuff/"+ language + "/.gitignore", name)
    else:
        print("Sorry, " + language + " is not supported at the moment, but I still created a new directory with an author file.")

if len(sys.argv) == 1:
    start()
    exit()
elif sys.argv[1] == "--help":
    print("This script will automatically create a folder and an author file.\nIf the project is in C, it will also ask if you want the libft and create the appropriate Makefile.\nIf the project is not in C but in another supported language, a .gitignore will be created.")
    exit()
elif sys.argv[1] == "--languages":
    print("'C', " + str(languages)[1:-1])
    exit()
elif sys.argv[1] == "--bonus":
    print("- Create a new directory based on project's name, and delete any pre-existing directory\n- Add an author file based on the LOGNAME environment variable\n- Add the libft to the src/lib folder\n- Add libft.h to the inc/ folder\n- Modify the Makefile depending on the project's name and on whether the libft was added or not\n- Support several languages and add the appropriate .gitignore")
    exit()
else:
    print("Three arguments are supported: --help, --languages and --bonus")
    exit()
