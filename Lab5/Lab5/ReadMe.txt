Lab 5 Readme

Team Members:
Dragonfruit
Leung Wai Liu
Kyerra Norton
Kiki Ogino


We worked on Leung Wai's computer, since it is easier to work from one computer and just contribute verbally and sometimes switch off.

EXTRA Credit:
We made the chmod command that does read-only and writeable files. 

Warnings: 
2 instances of Arithmetic overdlow 4 byte value casting result ot 8 byte value

Tests(Question 10):
1) First, we ran the help command to ensure that all the commands were added to command prompt properly:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ help
cat
chmod
cp
ds
ed
ls
rm
rn
touch

2) The tests we ran were help for the touch command then, touchto create an image file. We also tried and mp3 file, which is not supported. 

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ help touch
touch creates a file, touch can be invoked with the command: touch <filename>
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch text.txt
File created successfully.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch image.img
File created successfully.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch passwordtext.txt -p
What is the password?
testpassword
File created successfully.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch music.mp3
File was not created successfully.
Command failed to run. Please try again.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

We tried to make a password protected file. These tests ran and behaved accordingly, the mp3 failed(as it was supposed to) 
becuase it wasn't supported. We then checked the ls command which lists the file names. 

Then we tried to cat command and then the save and quit method. We also checked that the help for cat command worked as well. We also tried to display after 
saving and quitting. Then we tried quitting without saving. This code behaved correctly.

Then we tried cat command with -a(append), and also checked that appened and then quit without saving was working correctly as well. We tried displaying an 
image file and checking that append was not supported for it. We also tried quitting without saving, which worked as expected, it didn't add to the file. 

We tested appending to a password protected file, it worked as expected as well. Then we tried typing in the wrong password and it worked as well. We checked ls 
command for our text file again it displayed the data in the correct format. Then we made a copy of the text file, which was successful, and then we displayed it. 
Then we made a copy of image(successful), then displayed a copy of the image. 

We checked remove and rename, both of them worked correctly. We tried it on a password protected file as well, this was also carried out to rename the file.

Then we checked edit and display(ed) which we had the option to choose to make from the given commands. It worked succesfully on a password protected and regular 
file. 

Then we tried chmod(Extra Credit). We tried appending on a read-only and switching the file back to writeable and then appending. It worked successfully. 


For cat text.txt output:
$ cat text.txt
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
hello
:wq
New information overwritten to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds text.txt
hello
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat text.txt -a
Current contents of the file:
hello
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
 world
:wq
Additional information appended to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds text.txt
hello world
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat text.txt
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
sdflkjsdflkjsdfklj
:q
Cat command existing, data not saved.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds text.txt
hello world
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat text.txt -a
Current contents of the file:
hello world
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
sdlkfjsdflkjdsf
:q
Cat command existing, data not saved.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds text.txt
hello world
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

For cat image.img output:
$ cat image.img
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
X X X X X3
:wq
New information overwritten to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds image.img
X X
 X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat image.img -a
Current contents of the file:
X X X X X
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
sldkfjsdfkljs
:wq
Cannot append to an image.
Append operation not supported in file. Cat command returning
Command failed to run. Please try again.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat image.img
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
sdlkfjsdkflj
:q
Cat command existing, data not saved.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds image.img
X X
 X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat image.img -a
Current contents of the file:
X X X X X
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
slkdfjskdlfjsldkfj
:q
Cat command existing, data not saved.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds image.img
X X
 X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

Cat passwordtext.txt output:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat passwordtext.txt
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
hello this is password file
:wq
Input a password:
testpassword
New information overwritten to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds passwordtext.txt
Input a password:
testpassword
hello this is password file
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat passwordtext.txt -a
Current contents of the file:
Input a password:
testpassword
hello this is password file
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
 append stuff to back of password file
:wq
Input a password:
testpassword
Additional information appended to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds passwordtext.txt
Input a password:
testpassword
hello this is password file append stuff to back of password file


For copy: original text.txt had hello
$ cp text.txt copy_txt
Copy successful
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds copy_txt
File not found. Display command existing.
Command failed to run. Please try again.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds copy.txt
File not found. Display command existing.
Command failed to run. Please try again.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds copy_text.txt
File not found. Display command existing.
Command failed to run. Please try again.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds copy_txt.txt
hello
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat text.txt -a
Current contents of the file:
hello
End of contents of file. To append to the file please type below.
To save and quit, please type ':wq', to quit without saving please type ':q'.
world
:wq
Additional information appended to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds copy_txt.txt
hello
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

Macro commands
ed
$ ed text.txt
Macro Command running in progress
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
new info
:wq
New information overwritten to file. Cat command returning.
new info
Macro Command completed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

rn output:

$ rn text.txt renamed
Macro Command running in progress
Copy successful
Remove successful
Macro Command completed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
copy_txt.txt        renamed.txt

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds renamed.txt
new info
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

Chmod (extra credit):
$ chmod renamed.txt -
File was set to read-only sucessfully
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat renamed.txt
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
sdlkfjsdlfkj
:wq
File is read only, cannot write to file
New information overwritten to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ chmod renamed.txt +
File set to read-write access successfully
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat renamed.txt
Current contents of the file:
running -a command. To overwrite the file with new content, type in the field below.
Type ':wq' in a new line to save and quit, or ':q' to quit without saving.
now editable again!
:wq
New information overwritten to file. Cat command returning.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ds renamed.txt
now editable again!
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

