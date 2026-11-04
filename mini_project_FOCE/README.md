## Data Credit
Airport data from OpenFlights.org, published under the Open Database License.

## Project Structure
- `data/raw/`
  - `airports.dat`: OpenFlights airport database (used by the program)
  - `airports.csv`: the same data as a CSV
- `src/`
  - `airport.h`: Airport record (name, city, country, IATA, ICAO, lat, lon)
  - `airport_bst.h`: AirportBST class (root is private)
  - `reading_file.h`: file reading and CSV line splitting
  - `reading_file.cpp`
  - `airport_main.cpp`: runs the tasks
  - `load.ipynb`: Python notebook for looking at the data
- `MiniProject_Airport_BST.pdf`: project description
- `psuedocode.pdf`: pseudocode for every operation
- `requirements.txt`: Python packages for `load.ipynb`
- `README.md`
## Requirements
- C++ compiler(g++)
- Python 3 with packages in requirements.txt, it's used only for load.ipynb

## Build and Run
- From the src folder
- g++ -std=c++17 -O2 airport_main.cpp reading_file.cpp -o airports
./airports

## What is implemented
### Task 1: Load the data and build the tree
-Reads airports.dat line by line and splits each line into fields, keeping commas that appear inside quoted names, it also skips lines whose IATA code is \N
-Gives the height of the tree and the average depth of a node, both computed with a level-order traversal

### Task 2: Search
- search follows the BST from the root and records every code it compares and the number of comparisons
- Min and max follow the leftmost and the rightmost paths

### Task 3: Delete
- remove deletes an airport iteratively using the three deletion cases:
- D1 leaf, the node is removed.
- D2 one child, the node is replaced by its only child.
- D3 two children, the node is replaced by its inorder successor, and the successor is deleted instead. The successor is found by going right of the node once and then left until it reaches NULL.
- printlevels prints the level order of the top three levels before and after each delete.
### Task 4: Alphabetical listing
- inorder visits the tree iteratively with a stack and returns the airports in alphabetical code order.
- The program prints every airport and checks that consecutive codes are in increasing order.

## Sample session
-Task 4(a), the start of the alphabetical listing:

-AAA:Anaa Airport:Anaa:French Polynesia
-...
-sorted