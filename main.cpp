#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class TowerOfHanoi {
private:
    vector<int> towerA, towerB, towerC;
    int diskCount;
    int moveCount;

    // Function to display the current state of all towers
    void displayTowers() {
        int maxHeight = diskCount;
        
        cout << "\nCurrent State (Move " << moveCount << "):\n";
        cout << "┌─────────┬─────────┬─────────┐\n";
        cout << "│ Tower A │ Tower B │ Tower C │\n";
        cout << "├─────────┼─────────┼─────────┤\n";
        
        // Display each level
        for (int level = maxHeight - 1; level >= 0; level--) {
            cout << "│ ";
            displayDisk(level, towerA);
            cout << " │ ";
            displayDisk(level, towerB);
            cout << " │ ";
            displayDisk(level, towerC);
            cout << " │\n";
        }
        
        cout << "└─────────┴─────────┴─────────┘\n";
        cout << string(35, '_') << "\n";
    }

    // Helper function to display a disk at specific level
    void displayDisk(int level, const vector<int>& tower) {
        if (level < tower.size()) {
            int diskSize = tower[level];
            string disk(diskSize * 2 + 1, '█');
            cout << setw(diskCount * 2 + 1) << setfill(' ') << disk;
        } else {
            cout << setw(diskCount * 2 + 1) << setfill(' ') << "│";
        }
    }

    // Function to move a disk from source to destination
    void moveDisk(char from, char to) {
        moveCount++;
        
        int disk;
        vector<int>& source = getTower(from);
        vector<int>& destination = getTower(to);
        
        disk = source.back();
        source.pop_back();
        destination.push_back(disk);
        
        cout << "\nStep " << moveCount << ": Move disk " << disk 
             << " from Tower " << from << " to Tower " << to << "\n";
        
        displayTowers();
        
        // Add a small delay for better visualization (optional)
        // this_thread::sleep_for(chrono::milliseconds(500));
    }

    // Helper function to get reference to the appropriate tower
    vector<int>& getTower(char towerName) {
        switch(towerName) {
            case 'A': return towerA;
            case 'B': return towerB;
            case 'C': return towerC;
            default: return towerA;
        }
    }

public:
    TowerOfHanoi(int n) : diskCount(n), moveCount(0) {
        // Initialize tower A with disks (largest at bottom)
        for (int i = n; i >= 1; i--) {
            towerA.push_back(i);
        }
    }

    // Recursive function to solve Tower of Hanoi
    void solve(int n, char from, char to, char aux) {
        if (n == 1) {
            moveDisk(from, to);
            return;
        }
        
        solve(n - 1, from, aux, to);
        moveDisk(from, to);
        solve(n - 1, aux, to, from);
    }

    // Public method to start the solution
    void start() {
        cout << "=== TOWER OF HANOI VISUALIZER ===\n";
        cout << "Initial State:\n";
        displayTowers();
        
        cout << "\nStarting solution...\n";
        cout << "Minimum moves required: " << (1 << diskCount) - 1 << "\n";
        cout << string(50, '=') << "\n";
        
        solve(diskCount, 'A', 'C', 'B');
        
        cout << "\n=== SOLUTION COMPLETE ===\n";
        cout << "Total moves made: " << moveCount << "\n";
        cout << "All disks have been moved from Tower A to Tower C!\n";
    }
};

int main() {
    int numDisks;
    
    cout << "Welcome to Tower of Hanoi Visualizer!\n";
    cout << "Enter the number of disks (1-8 recommended): ";
    cin >> numDisks;
    
    if (numDisks <= 0 || numDisks > 10) {
        cout << "Please enter a number between 1 and 10.\n";
        return 1;
    }
    
    TowerOfHanoi game(numDisks);
    game.start();
    
    return 0;
}

