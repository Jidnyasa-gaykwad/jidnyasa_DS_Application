              ┌─────────────┐
              │    START    │
              └──────┬──────┘
                     │
              ┌──────▼──────┐
              │ Initialize  │
              │ Empty BST   │
              └──────┬──────┘
                     │
              ┌──────▼──────┐
              │ Display Menu│◄──────────────────┐
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Input Choice│                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Choice = 1? │── Yes ──► Insert  │
              └──────┬──────┘          Employee │
                     │ No               ID      │
              ┌──────▼──────┐                   │
              │ Choice = 2? │── Yes ──► Search  │
              └──────┬──────┘          Employee │
                     │ No               ID      │
              ┌──────▼──────┐                   │
              │ Choice = 3? │── Yes ──► Delete  │
              └──────┬──────┘          Employee │
                     │ No               ID      │
              ┌──────▼──────┐                   │
              │ Choice = 4? │── Yes ──► Display │
              └──────┬──────┘          Sorted   │
                     │ No               IDs     │
              ┌──────▼──────┐                   │
              │ Choice = 5? │── Yes ──► AVL     │
              └──────┬──────┘          Rotation │
                     │ No                       │
              ┌──────▼──────┐                   │
              │ Select      │                   │
              │ LL, RR, LR  │                   │
              │ or RL Case  │                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Display     │                   │
              │ Balance     │                   │
              │ Factor      │                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Perform     │                   │
              │ AVL Rotation│                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Compare     │                   │
              │ Inorder     │                   │
              │ Traversals  │                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Traversal   │                   │
              │ Unchanged?  │                   │
              └──────┬──────┘                   │
                     │                           │
              ┌──────▼──────┐                   │
              │ Choice = 6? │── Yes ──► EXIT    │
              └──────┬──────┘                   │
                     │ No                        │
              ┌──────▼──────┐                   │
              │ Invalid     │───────────────────┤
              │ Choice      │                   │
              └─────────────┘                   │
                                                │
              After operation ─────────────────┘
