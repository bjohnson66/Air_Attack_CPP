# Air_Attack_CPP
<h> The gaol of this project is to refactor the messy code I wrote in middle school using the Processing JS library as a C++ project that uses SFML libraries </h>

<p> See SFML: https://www.sfml-dev.org/index.php  </p>

Once SFML is installed in the proper location, use the following steps to ensure that CLion can find it, as copied from the read me of the homeowkr assingment I am learning how to put this togther from.

1. Load CMakeLists.txt
2. Select the Air_Attack_CPP | Debug in the dialog box next to the green triangle if necessary.
3. Compile the Air_Attack_CPP program by clicking on the green triangle.  You should get the following error.
  Process finished with exit code -1073741515 (0xC0000135)
4. Once the file is built, the current CMakeLists.txt does not copy the needed .dll files to the build directory.
   You must add two directories to the PATH in the project debug environment in order to make it work. 
5. Click on the down arrow next to the project debug button, then choose “Edit Configurations”. 
6. In the resulting dialog box click on the folder icon next to Environment variables. In the resulting dialog box
7. click on the plus sign and add a variable named PATH with a value of
"%PATH%;C:\Program Files\SFML-2.5.1\bin;C:\Program Files\mingw-w64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin"
without the quotes. This will allow the compiled Air_Attack_CPP.exe to find the .dll files when you click on run. Click OK.
