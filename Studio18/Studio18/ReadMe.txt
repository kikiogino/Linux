studio 18 answers here

Team Members:
Leung Wai Liu
Kyerra Norton
Kiki Ogino

Question 2
2. Factory Methods are methods that can be used for different implementations (in this case, the different types of files).
This makes it very easy to modify createFile because we can override the implementations for each class based on the functionality
needed for that object class. 

Question 3
3. The advantages of abstract factory pattern is that we're able to adapt this one concrete method for multiple classes. The difficult
part is that if we are not careful with how we implement the object within an object, and if we are not careful with how we 
implement this base method for a specific class, we can be referring to the wrong thing. 

The code that needs to be modified is the class that is of the more specifc type (derived) rather than the base (abstract) class.

The same factory can be used to create files for both, because this factory method, as the name suggests, is an all purpose general
method. 

The same concrete factory implementation can be used to create files for both more specific file types. 

Question 4
4. The output for all the tests that we created:
Add text file generated from the file factory function result: 0
Add image file generated from the file factory function result: 0
Add music file generated from the file factory function result - should fail: 2
Text File Name: new_text.txt
Text File Size: 5
Text:
hello
Writing an image:
0
Image File Name: new_image.img
Image File Size: 9
Image:
Reading an image:
X X
 X
X X
Close text file (should be successful): 0
Close image file (should be successful): 0

Question 5
5. SimpleFileSystem does not depend on any concrete file types, but rather depend ont he AbstractFile interface only, because
in the main method, we are creating a pointer to an AbstractFile base class, so the compiler cannot see what type of file
it is actually (image, text, etc.) until during runtime where it dynamically goes to the particular function for that particular 
file type. 
