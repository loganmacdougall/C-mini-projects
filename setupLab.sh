#!/bin/bash

#This will setup all the helper files to run the contracts for CSCI2122
#Aswell as create the proper file structure to pass the first pipelien

# Move into the labs folder (assumes you already cloned the repo
cd ~/Courses/CSCI2122/Labs

#Sets the name of the lab directory
labDir=Lab$1

#If the lab directory doesn't exist, you either put in a parameter wrong, or it's not set up yet
if [ ! -d $labDir ] 
then 
	echo Pass which lab to setup;
	exit 128; 
fi

# Move into the selected  lab folder (assumes you already cloned the repo
cd ./$labDir/$USER/

#Delete the delete me file
rm $labDir/delete_this_file &> /dev/null
git rm $labDir/delete_this_file &> /dev/null

#Create the start to the gitCommit script.
#This script will add all the file that should be included in the repo and then commits with a message
cat > gitCommit.sh << EOF
#!/bin/bash

cd ~/Courses/CSCI2122/Labs/$labDir/$USER

EOF
chmod 755 gitCommit.sh

#Grab all the directory and files mentioned in the yml file
grep -e "test -d Lab" .gitlab-ci.yml | cut -c 18- | { 
while read i; do
	#Make all the directories in the yml
	mkdir $i &> /dev/null; 
done }

grep -e "test -f Lab" .gitlab-ci.yml | cut -c 18- | { 
while read i; do
	#Make all the files in the yml
	touch $i; 
	#Make sure the gitCommit script git adds all the files in yml file is testing
	echo git add $i >> gitCommit.sh 
done }

#Move into the directory with all the contracts
cd ./$labDir

#For each contract, create the start to the compile script to test your code
#as well as make the start of the script to easily grab your libraries
ls -d1 */ | rev | cut -c 2- | rev | while read i; do
	touch $i/compile.sh;
	chmod 755 $i/compile.sh;
	cat > $i/compile.sh << EOF
#!/bin/bash

cd ~/Courses/CSCI2122/Labs/$labDir/$USER

./getLibs.sh

EOF

# This will add a script that will grab all the library files I need
	touch $i/getLibs.sh;
	chmod 755 $i/getLibs.sh;
	cat > $i/getLibs.sh << EOF
#!/bin/bash

# The Lab folder
LABFOLDER="/users/cs/$USER/Courses/CSCI2122/Labs"
# Folder that stores all the libraries
LIBFOLDER="\${LABFOLDER}/libs"
# Script which will grabs the libraries for you
GRABSCRIPT="\${LABFOLDER}/grablibs.sh"

# These are the libraries you want to grab
# *** USER INPUT ***
LIBRARIES=""

# If no libraries are specified, nothing needs to be done
if [ "\${LIBRARIES}" == "" ]; then
    exit 0

# if a star is used (*), grab all the libraries
elif [ "\${LIBRARIES}" == "*" ]; then
    \${GRABSCRIPT}

# Otherwise, grab the libraries specified
else
    \${GRABSCRIPT} \${LIBRARIES}
fi
EOF

#Add all the lib files of each contract if that contract has a lib folder
    cat >> ../gitCommit.sh << EOF
if [ -d $labDir/$i/lib ]; then
    git add $labDir/$i/lib/*
fi
EOF
done

#Finish off the gitCommit script
cd ../
cat >> gitCommit.sh << EOF

git commit -m "\$1"
EOF

# This grep command will gather the code to compile each contract sepratly
# grep -Pzo "(?<=run-)(.*\n){5}(\s{8}-.*\n)*" .gitlab-ci.yml
