Answer studio 16 questions here

Question 1
Team Members: Dragonfruit - Kiki Ogino, Kyerra Norton, Leung Wai Liu

Question 2
2.a. To declare an interface, you declare a class containing pure virtual functions, therefore creating the framework
for the class.

Question 3
3.a. This is an examples of "interface inheritance".

3.b. These member variables should be marked as private. 

Question 4
Test cases:
1. First we created a new file called "new_text_file", and appended "hello".

First test case: retrieving the name
Output:
Text File Name: new_text_file
Works as expected

Next test case: retrieving the size of text 
Output:
Text File Size: 5
Works as expected

Next test case: printing out the text
Output:
Text:
hello
Works as expected

Final test case, appending " world" to the back of the text and printing out the text
Ouput:
Text after appending:
hello world
Works as expected

Question 5
5. Since we are trying to create a variable of the base class type (AbstractFile) pointing to an object of the 
derived class type (TextFile), we need to do interface inheritance, since the base class is purely an interface
with pure virtual function. In order to change it, we need to first create a pointer to the base class, and set 
that equals to a new object of the derived class (this results in dynamic memory allocation). Then, all of the functions
is called using the dereference operator (->) instead of (.).

Entire main function:
AbstractFile * text_file_example = new TextFile("new_text_file");

	vector<char> to_input;
	to_input.push_back('h');
	to_input.push_back('e');
	to_input.push_back('l');
	to_input.push_back('l');
	to_input.push_back('o');

	text_file_example->write(to_input);

	cout << "Text File Name: " << text_file_example->getName() << endl;
	cout << "Text File Size: " << text_file_example->getSize() << endl;

	cout << "Text:" << endl;
	text_file_example->read();

	vector<char> to_append;
	to_append.push_back(' ');
	to_append.push_back('w');
	to_append.push_back('o');
	to_append.push_back('r');
	to_append.push_back('l');
	to_append.push_back('d');

	text_file_example->append(to_append);

	cout << "Text after appending:" << endl;
	text_file_example->read();

Output:
Text File Name: new_text_file
Text File Size: 5
Text:
hello
Text after appending:
hello world

Everything works as expected.

Question 6
6. We ran the tests, everything passed successfully.



