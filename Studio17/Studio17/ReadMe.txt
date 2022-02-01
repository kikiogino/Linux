Answer the studio 17 questions here.

Names:
Kyerra Norton
Leung Wai Liu
Kiki Ogino

Question 2
Test cases:
1. First we created a new file called "new_image_file", and appended "hello".

First test case: retrieving the name
Output:
image File Name: new_image_file
Works as expected

Next test case: retrieving the size of image 
Output:
image File Size: 9
Works as expected

Next test case: printing out the image
Output:
Image:
X X
 X
X X

Final test case, appending " world" to the back of the image and printing out the image
Output: 
Cannot append to an image.

Works as expected, because it is not supposed to be able to append to an image.

 
Question 3
The benefits of programming a client to use an interface are grouping different objects together of the same general type. When 
creating new objects that need the same implementation we can easily do this using an interface.

Question 4
4.1. Output for all the tests that we created: 

Writing an image:
0
Image File Name: new_image_file
Image File Size: 9
Image:
Reading an image:
X X
 X
X X
SimpleFileSystem addFile: 0
SimpleFileSystem createFile text.txt: 0
SimpleFileSystem deleteFile text.txt: 0
X X
 X
X X
Image rewrite on opened file: 0

 X

File system createFile music.mp3 - should be wrong: 6
File system closeFile opened_file: 0

4.2. If we are implementing a music file, then we would need to add a check for if the extension is a mp3 in the
createFile() function in SimpleFileSystem. In that check, similar to .txt and .img files, if it is a music file, 
then we would dynmaically create a new MusicFile object (that class would need to be defined), and then return the 
pointer to that music file object. 

