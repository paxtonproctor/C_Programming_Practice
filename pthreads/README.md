# This has notes over threads
## UNIX environment a thread:
  ### Exists within a process and uses the process resources
  ### Has its own independent flow of control as long as its parent process exists and the OS supports it
  ### Duplicates only the essential resources it needs to be independently schedulable
  ### may share the process resources with other threads that act equally independtly
  ### Dies if the parent process dies
  ### is "lightweight" because most of the overhead has already been accomplished through the creation of its process
## Threads in same process share resources:
  ### Changes made by one thread to shared system resources will be seen by all other threads
  ### two pointers having the same value point to the same data
  ### Reading and writing to the same memory locations is possible, and therefore requires explicit synchronization by the programmer
