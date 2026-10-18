             ┌─────────────┐
             │    START    │
             └──────┬──────┘
                    │
             ┌──────▼──────┐
             │ Initialize  │
             │ Doubly      │
             │ Linked List │
             └──────┬──────┘
                    │
             ┌──────▼──────┐
             │ Display Main│◄─────────────────────────┐
             │    Menu     │                          │
             └──────┬──────┘                          │
                    │                                 │
             ┌──────▼──────┐                          │
             │ Input Choice│                          │
             └──────┬──────┘                          │
                    │                                 │
             ┌──────▼──────┐                          │
             │ Choice = 1? │── Yes ──► Display Food   │
             └──────┬──────┘           Menu           │
                    │ No               │              │
             ┌──────▼──────┐           ▼              │
             │ Choice = 2? │     Select Food &        │
             └──────┬──────┘     Enter Quantity       │
                    │ No               │              │
             ┌──────▼──────┐           ▼              │
             │ Choice = 3? │     Create New Node      │
             └──────┬──────┘     & Add Order          │
                    │ No               │              │
             ┌──────▼──────┐           ▼              │
             │ Choice = 4? │     Display Order Details│
             └──────┬──────┘           │              │
                    │ No               └──────────────┤
             ┌──────▼──────┐                          │
             │ Choice = 5? │── Yes ──► Search Order   │
             └──────┬──────┘           │              │
                    │ No               ▼              │
             ┌──────▼──────┐       Order Found?        │
             │ Choice = 6? │        /       \         │
             └──────┬──────┘      Yes       No        │
                    │ No            │         │       │
             ┌──────▼──────┐        ▼         ▼       │
             │ Choice = 7? │    Display   Order Not   │
             └──────┬──────┘    Details     Found     │
                    │ No            │         │       │
             ┌──────▼──────┐        └────┬────┘       │
             │ Choice = 8? │             │            │
             └──────┬──────┘             └────────────┤
                    │                                  │
                    │                                  │
       ┌────────────┼─────────────────┐                │
       │            │                 │                │
       ▼            ▼                 ▼                │
 Choice 2       Choice 3           Choice 4            │
 Display        Display            Search              │
 All Orders     Reverse Orders     Order               │
       │            │                 │                │
       └────────────┴─────────────────┴────────────────┤
                                                       │
             Choice 5: Cancel Order ───────────────────┤
             Choice 6: Calculate Total Bill ───────────┤
             Choice 7: Display Food Menu ──────────────┤
                                                       │
             ┌─────────────┐                           │
             │ Choice = 8? │                           │
             └──────┬──────┘                           │
                    │ Yes                              │
             ┌──────▼──────┐                           │
             │ Clear All   │                           │
             │ Remaining  │                           │
             │ Nodes       │                           │
             └──────┬──────┘                           │
                    │                                  │
             ┌──────▼──────┐                           │
             │     END     │                           │
             └─────────────┘                           │
                                                       │
             Invalid Choice ──────────────────────────┤
                                                       │
                  After Operation ─────────────────────┘
