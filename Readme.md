# Othello Game in C++

## 1. Compilation and Execution Instructions
The program implements the Othello game where the user ('1') plays against the computer ('0'). The computer uses the **Minimax algorithm with Alpha-Beta Pruning**.

## 2. Compilation
* Open the terminal (cmd) and navigate to the folder containing the `.cpp` and `.h` files.
* Execute the following command for compilation:
  ```bash
  g++ -o othello main.cpp othelo.cpp
  ```
* If no message appears, the compilation was successful.

## 3. Execution
Run the program based on your operating system:
* **On Linux / macOS:**
  ```bash
  ./othello
  ```
* **On Windows (CMD / PowerShell):**
  ```bash
  othello.exe (If othello.exe is not found, simply type othello)
  ```
  

## 4. User Instructions
* **a) First Player Selection:** The program will ask: `First player ? : (0 for pc , 1 for user)`
  * Enter `1` for the user to start.
  * Enter `0` for the computer to start.
* **b) Search Depth Selection:** The player chooses the depth of the minimax algorithm.
* **c) Move Input (Player '1'):** When it is the user's turn, enter the two numbers (row and column, from 0 to 7) separated by a space (they can also be provided one by one, e.g., `2` [Enter], `4` [Enter]). 
  * *Example:* `2 3`
* **d) Game Over:** The game ends when neither of the two players can make a valid move. At the end, the pieces are counted and the result is displayed.

## 5. Algorithm Complexity
* **a)** The time complexity of the standard Minimax algorithm is $O(b^N)$ in the worst-case scenario, where $b$ is the branching factor (average number of valid moves) and $N$ is the search depth.
* **b)** By using **Alpha-Beta Pruning**, the time complexity is significantly reduced, reaching $O(b^{N/2})$ in the best-case scenario. This allows the AI to evaluate a greater depth $N$ in less time.
