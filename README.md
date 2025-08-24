🏗️ Tower of Hanoi Visualizer (C++ - ASCII)

A simple **recursive Tower of Hanoi solver** with an **ASCII-based visual output**.  
It shows the movement of disks between rods step by step, either in **real-time animation** or **step-by-step mode**.

---
 🎯 Concept
The Tower of Hanoi is a classic recursive problem:
- Move `n-1` disks to the auxiliary rod
- Move the largest disk to the target rod
- Move the `n-1` disks from the auxiliary to the target rod

This program demonstrates:
- Recursive solution of Tower of Hanoi  
- ASCII visualization of each move  
- Interactive controls (step-by-step / timed delay)

---
 ⚙️ Tech Requirements
- **Recursion** for solving Hanoi  
- **ASCII rendering** for visualization  
- **Cross-platform C++17** (tested on Linux/Windows)  

---

 🚀 How to Run

1. Compile
```bash
g++ -std=c++17 -O2 -pthread hanoi_visual.cpp -o hanoi_visual
2. Run
bash
Copy
Edit
./hanoi_visual
🖥️ Features
✅ Recursive solution to Hanoi
✅ ASCII visualization of rods and disks
✅ Step-by-step mode (press Enter to advance moves)
✅ Animated mode with configurable delay
✅ Works for small and medium disk counts (1–12 recommended)

📷 Example Output
For 3 disks:

diff
Copy
Edit
  =       |       |
 ===      |       |
=====     |       |
---     ---     ---
  A       B       C

Moves: 0
Initial state.
After some moves, disks animate from A → C following recursion.

🧮 Complexity
Number of moves: 2^n - 1

Recursive depth: n

Time complexity: O(2^n)
