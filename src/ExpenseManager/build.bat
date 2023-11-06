@echo off
cls

rem Set the name of the output executable
set outputName=ExpenseManager

rem Set the path to the C++ compiler (g++ in this example)
set compiler=g++

rem Set the project directory path (current directory)
set projectDir=%~dp0

rem Set the source and header file paths
set sourceFiles=src\main.cpp src\ExpenseManager.cpp src\Expense.cpp src\CSVParser.cpp
set headerFiles=-Iinclude

rem Set the name of the CSV file with expenses data
set csvFile=data\expenses.csv

rem Navigate to the project directory
cd /d %projectDir%

rem Compile the project
%compiler% -o %outputName%.exe %sourceFiles% %headerFiles%

rem Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed.
    pause
    exit /b 1
) else (
    echo Compilation successful.

    rem Run the project with the CSV file
    %outputName%.exe %csvFile%
)

rem Pause to keep the console window open
pause
