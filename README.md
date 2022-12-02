
# Courses Advisory System

This project is going to be a Courses Advisory System. Here is the goal: by retrieving data such
as, grades, course attendance, or any other sources that can show the performance of all students
in a course, the system will then analyze these data, so that instructor can choose to, for instance,
modify the content or adjust the evaluation scale of the course based on the result. Such result
can be, for example, extending the deadline for assignment/s, placing more focus/explanation on
specific concept, making the class more interactive so that student can have more attendance etc.

A stable user interface (interacting with the user and displaying/rendering the result) and a backend system 
(handling all data gathering task and providing algorithm to generate the result)
was implemented. Also, in this project, there will be a clear separation between the front and back
end, which means the UI will not directly connect to the analyzing system but rather using
QT framework to do so. In other words, this program will be run as a local application.



# User Stories Implemented
- US1. The professor can find how difficult is an assignment or test to students (Algorithm1).
- US2. The professor can find how efficiently students studying his/her course (Algorithm3)
  - note that our program didn't use the second algorithm due to its complexity, but we have implemented the algorithm.
- US3. Professor can get to know how well students can use his/her lecture to achieve better grade. (Algorithm3)
- US4. The professor can find how participated and engaged students in the course activities (Algorithm4).
- US5. The professor can receive a score on how students evaluate him/her (Algorithm5).
- US6. The course itself taught by the professor can get a feedback score from students (Algorithm6).
- US8. The user can use a filter function to filter the input data (Utility).
- US9. Filtering based on different courses (InputSelection)
- US10. Filtering based on period
- US11. Filtering based on student name/s
- US13: The program can receive input data from a csv file uploaded by the user(Utility)
- US14: The program can produce graphical result for each of the above algorithms (Rendering result in graphically) - (GUI and Utility).
- US15: The graph can be either bar chart or line chart.
- US16: The program can produce paragraph that illustrates the result for each of the above algorithms (Rendering result textually).

## How to compile our program
There are three ways to run our program:
1. Use executable file to run the program directly
  - Go to folder ../GUI/build-executable
  - run newProject.exe
2. Open, build and run in Qt5 creator
  - open .pro file in qt and run the program
  - Go to folder ../GUI/newProject/newProject.pro
3. Build and run the program in commend line argument:
  - Go to folder ../GUI/newProject/
  - Open folder in terminal and run following commands
  - qmake newProject.pro
  - make
  - ./newProject

For option 2 and 3, you need to have QT5 creator installed and configured;
Also, in order to run graph system, you need to have the package libqt5charts5-dev installed (sudo apt install libqt5charts5-dev)
# How to operate our program
1. On the top left menu bar, click file -> click open -> select the .csv file we attached.
2. After you see the name of the file under start_analyze button.
on the top menu bar click refresh -> click refresh file button
3. fill out the 3 dropdowns (Year, Course, Student)
4. You all set, click start_analyzing button.
5. You now can view results produced by our 6 algorithms
6. If you want more detail for any of the result, click the graph. Then you will see the detailed result produced by that algorithm.
7. you can close the graph window and repeat 3 - 6 steps
8. Enjoy
# About input file
- Our program has a file system that can read csv file from the file browser, 
but only in the defined csv format (see the attached csv file).
- The input file is by default stored under folder Utility, named group39_test1_100pl.csv. You can store it wherever you want in your local.
- You can insert new data in any fields of this csv file, but try not to change the format
## Running test cases for each module 
- Our program is consisted of 5 modules: Algorithms, InputSelection, GUI, Models(data structures) and Utility(connecting GUI with back end). 
Each module has its own testing unit, you can find them under test folder.
- Simply compile and run the test cpp file to test each module.

## Authors
Ido Chen (yche2692) , Yuebo He (yhe534) , Baishen JIANG (bjiang68) , Yanwen Wang (ywan3625) , Mingyu Yu (myu287)

## Program preview
![mainWindow](https://user-images.githubusercontent.com/106355448/204703495-50420898-63fb-49f5-85db-cecc2d43d88c.png)
![resultWindow](https://user-images.githubusercontent.com/106355448/204703497-c1f55560-257a-4d57-803d-6792a3f20a86.png)
![detailResultWindow](https://user-images.githubusercontent.com/106355448/204703492-70b850e2-b823-43e6-ab91-86a883b24134.png)


