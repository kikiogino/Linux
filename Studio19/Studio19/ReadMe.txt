studio 19 answers here

Team Members:
Leung Wai Liu
Kyerra Norton
Kiki Ogino 

Question 2
2. We first create a text file and image file, similar to Studios 16 and 17. When testing, the text file, we first 
use a vector to input data, and then we write into the file, then we read the file, retrieved the name and the size of the file.

Then we appended the file, and re-read, and re-retrieved the size and the name of the file to ensure that it works. 

Since an image file is not able to append stuff, we added that test to ensure that when appending an image it would 
return an appropriate enum value.

Question 3
3. It first starts in the main method when wanting to display an image file or an abstract file. When doing so, 
since the objects are of the pointer of the AbstractFile, which is the base class, it would then go to the correct
accept method within the ImageFile or TextFile class. In there, we would go to the Visitor object which would then
go back to the Image or Text File class for the visit_ImageFile or visit_TextFile functions. 

Question 4
4. We used delegation in order to display whatever type of file in the command prompt. How that works is that we first
create the visitor object that will be passing through multiple dispatches to get it to display. Then, we pass a pointer to the visitor object to the 
concrete file through the accept function, which will give access to the state of the visitor object, therefore enabling
the visitor object to access the contents of the concrete file to display the object.

Question 5
5. When you have a lot of unique visitors and a lot of unique concrete file types, you would need to define specific functions
for each of the specific concrete file type in the visitors, making it a very inefficient way of programming for the 
programmer. 