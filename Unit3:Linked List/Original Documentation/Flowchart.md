          ( START )
              |
              v
     +--------------------+
     | Initialize Linked  |
     |       List         |
     +--------------------+
              |
              v
     /--------------------/
    /    Display Main    /
   /        Menu         /
   /--------------------/
              |
              v
     /--------------------/
    /   Enter User       /
   /      Choice         /
   /--------------------/
              |
              v
          /-------\
         /  Check  \
        <  Choice?  >
         \         /
          \-------/
              |
              v
       Choice = 1?
          /     \
        Yes      No
         |        |
         v        v
    +----------+  Choice = 2?
    | Add      |    /    \
    | Order    |  Yes     No
    +----------+   |       |
         |         v       v
         |    +----------+ Choice = 3?
         |    | Display  |   /    \
         |    | Orders   | Yes     No
         |    +----------+  |       |
         |         |        v       v
         |         |   +----------+ Choice = 4?
         |         |   | Search   |   /    \
         |         |   | Order    | Yes     No
         |         |   +----------+  |       |
         |         |        |        v       v
         |         |        |   +----------+ Choice = 5?
         |         |        |   | Delete   |   /    \
         |         |        |   | Order    | Yes     No
         |         |        |   +----------+  |       |
         |         |        |        |        v       v
         |         |        |        |   +----------+ Choice = 6?
         |         |        |        |   | Calculate|   /    \
         |         |        |        |   | Bill     | Yes     No
         |         |        |        |   +----------+  |       |
         |         |        |        |        |        v       v
         |         |        |        |        |     ( STOP ) Invalid
         |         |        |        |        |              Choice
         |         |        |        |        |                |
         +---------+--------+--------+--------+----------------+
                              |
                              v
                    Display Main Menu
                              |
                              +-------> Repeat
