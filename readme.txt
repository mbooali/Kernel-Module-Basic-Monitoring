Write a kernel module that creates a directory in /proc named oslab and a file in it that its name is your student number. This file should accept a number ranged from 1 to 3 when written into it and return the following messages when read based on the number already written into it:
• 1: Current system time (in microseconds precision)
• 2: System uptime
• 3: Number of processes currently in the system

“The Output”
root@Paradise# echo 1 > /proc/oslab/810185100
root@Paradise# cat /proc/oslab/810185100
08:30:24 342us
root@Paradise# echo 2 > /proc/oslab/810185100
root@Paradise# cat /proc/oslab/810185100
up 1 day, 8 min
root@Paradise# echo 3 > /proc/oslab/810185100
root@Paradise# cat /proc/oslab/810185100
process count: 48