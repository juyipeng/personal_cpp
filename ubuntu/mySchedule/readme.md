# project info: mySchedule

## author:
- juyip

    (^_^)

## modules:
- main.cpp
- user_management.h
- task_management.h
- reminder.h
- users.txt

***
### main.cpp:
main function of the program.

***
### user_management.h:
functions for user management.

functions:
- user_login
- silent_login
- signup

***
### task_management.h:
functions for task management.

functions:
- addTask
- showTask
- deleteTask

***
### reminder.h:
a reminder to remind the user of their tasks.

functions:
- fReminder

***
### users.txt:
a file to store user information.

structure:
- username@password

***
## flow diagram:
regular mode:
```
login>--->signup>--v
v                  |
|   v--------------<
v   v               
shell<--------<---<--------<
(reminder)    |   |        |
|             |   |        |
>----->addTask^   |        |
|                 |        |
|                 |        |
>----->showTask---^        |
|                          |
|                          |
>----->deleteTask----------^
```

quick process mode:
```
quick addTask
quick showTask
quick deleteTask
```

## technical details:
### reminder:
reminder is based on a thread. the thread keeps running in the background and checks if there are any tasks that need to be reminded. if there are, it will send a reminder to the user.

the reminder will load the task file only when it is started.

if there is any command which might renew the task file, the reminder will be shutted down and started again to reflect the changes.

### password enciphering:
the password is enciphered using a simple hash algorithm. the algorithm is:
- take the password as a string
- hash the string using a simple algorithm:
- h(k+1) = h(k) * 31 + c
- (h is the hash value, k is the iteration number, c is the character ascll code)
- save the ultimate hash value to keep the password
- redo the algorithm when checking the password to ensure the password is correct, by comparing the two hash values.