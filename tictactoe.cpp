// Program that allows two human players to play 3x3 tic-tac-toe

#include "C:\Users\noaha\Desktop\C++\std_lib_facilities.h"

// Declaring const values for marking O or X on the tic-tac-toe grid
const string O = "\u2D54";
const string X = "\u2715";

// Each spot on the tic-tac-toe grid is numbered/indexed 1-9
vector<string> grid = {"1","2","3","4","5","6","7","8","9"};

// Declaring constexpr values indicating the traversal of the tic-tac-toe grid
constexpr int gridDown = 3;
constexpr int gridDownLeft = 2;
constexpr int gridDownRight = 4;
constexpr int gridRight = 1;

void print(vector<string> v);
bool columnWinCheck(int col, string playermark);
bool rowWinCheck(int row, string playermark);
bool diagonalWinCheck1(int diagonal, string playermark);
bool diagonalWinCheck2(int diagonal, string playermark);

int main() try {
    // Set encoding to unicode
    system("chcp 65001");

    bool player1Win = false;
    bool player2Win = false;

    while(true) {
    
        // Resetting the tic-tac-toe grid for a new game
        grid = {"1","2","3","4","5","6","7","8","9"};

        // Player One goes 5 Turns
        for(int turn = 1; turn <= 5; ++turn) {
        
            system("cls");
            print(grid);
        
            cout << "Player One's Turn [O]\n" 
                 << "Enter [1-9]: ";
            int player1Choice = 0;
            cin >> player1Choice;

            if(player1Choice < 0 || player1Choice > 9 || !cin) {
                throw runtime_error("Bad input; exiting program");
            }

            while(grid[player1Choice - 1] == O || grid[player1Choice - 1] == X) {
                system("cls");
                print(grid);

                cout << "Sorry Player 1, spot already chosen. Try again.\n";
                cout << "Player One's Turn [O]\n" 
                     << "Enter [1-9]: ";
                cin >> player1Choice;
            }

            grid[player1Choice - 1] = O;

            system("cls");
            print(grid);
        
            // columnWinCheck
            for(int col = 0; col < 3; ++col) {
                player1Win = columnWinCheck(col,O);
                if(player1Win)
                    break;
            }

            if(player1Win) {
                cout << "Player One [O] Wins!\n";
                break;
            }
        
            // rowWinCheck
            for(int row = 0; row < 7; row += 3) {
                player1Win = rowWinCheck(row,O);
                if(player1Win)
                    break;
            }
        
            if(player1Win) {
                cout << "Player One [O] Wins!\n";
                break;
            }

            // diagonalWinCheck1
            player1Win = diagonalWinCheck1(0,O);

            if(player1Win) {
                cout << "Player One [O] Wins!\n";
                break;
            }

            // diagonalWinCheck2
            player1Win = diagonalWinCheck2(2,O);

            if(player1Win) {
                cout << "Player One [O] Wins!\n";
                break;
            }

            // Player Two goes 4 Turns
            if(turn != 5) {
                cout << "Player Two's Turn [X]\n" 
                     << "Enter [1-9]: ";
                int player2Choice = 0;
                cin >> player2Choice;

                if(player2Choice < 0 || player2Choice > 9 || !cin) {
                    throw runtime_error("Bad input; exiting program");
                }

                while(grid[player2Choice - 1] == O or grid[player2Choice - 1] == X) {
                    system("cls");
                    print(grid);

                    cout << "Sorry Player 2, spot already chosen. Try again.\n";
                    cout << "Player Two's Turn [X]\n" 
                         << "Enter [1-9]: ";
                    cin >> player2Choice;
                }

                grid[player2Choice - 1] = X;

                // columnWinCheck
                for(int col = 0; col < 3; ++col) {
                    player2Win = columnWinCheck(col,X);
                    if(player2Win) {
                        break;
                    }
                }

                if(player2Win) {
                    system("cls");
                    print(grid);

                    cout << "Player Two [X] Wins!\n";
                    break;
                }

                // rowWinCheck
                for(int row = 0; row < 7; row += 3) {
                    player2Win = rowWinCheck(row,X);
                    if(player2Win) {
                        break;
                    }
                }

                if(player2Win) {
                    system("cls");
                    print(grid);

                    cout << "Player Two [X] Wins!\n";
                    break;
                }

                // diagonalWinCheck
                player2Win = diagonalWinCheck1(0,X);

                if(player2Win) {
                    system("cls");
                    print(grid);

                    cout << "Player Two [X] Wins!\n";
                    break;
                }

                player2Win = diagonalWinCheck2(2,X);

                if(player2Win) {
                    system("cls");
                    print(grid);

                    cout << "Player Two [X] Wins!\n";
                    break;
                }
            }
        }

        if(player1Win == false && player2Win == false) {
            cout << "Draw\n";
        }

        cout << "Play Again? (y/n): ";
        string answer = "";
        cin >> answer;

        if(answer != "y" && answer != "yes") {
            break;
        }
    }
    keep_window_open();
    return 0;
}
catch(exception& e) {
    cerr << "Runtime Error: " << e.what() << "\n";
    keep_window_open();
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    keep_window_open();
    return 2;
}

void print(vector<string> v) {
    for(int row = 0; row < 3; ++row) {

        for(int col = 0; col < 3; ++col) {
            int index = row * 3 + col;
            cout << "|" << " " << v[index] << " ";
        }

        cout << "|\n\n";
    }
}

// Checking in which column [0 or 1 or 2] who wins [O/X]
bool columnWinCheck(int col, string playermark) {
    bool playerWin = false;
    if((grid[col] == playermark && grid[col + gridDown] == playermark && grid[col + gridDown + gridDown] == playermark) == true)
        playerWin = true;
    return playerWin;
}

// Checking in which row [0 or 3 or 6] who wins [O/X]
bool rowWinCheck(int row, string playermark) {
    bool playerWin = false;
    if((grid[row] == playermark && grid[row + gridRight] == playermark && grid[row + gridRight + gridRight] == playermark) == true)
        playerWin = true;
    return playerWin;
}

// Checking (\) diagonal from grid[0] who wins [O/X]
bool diagonalWinCheck1(int diagonal, string playermark){
    bool playerWin = false;
    if((grid[diagonal] == playermark && grid[diagonal + gridDownRight] == playermark && grid[diagonal + gridDownRight + gridDownRight] == playermark) == true)
        playerWin = true;
    return playerWin;
}

// Checking (/) diagonal from grid[2] who wins [O/X]
bool diagonalWinCheck2(int diagonal, string playermark) {
    bool playerWin = false;
    if((grid[diagonal] == playermark && grid[diagonal + gridDownLeft] == playermark && grid[diagonal + gridDownLeft + gridDownLeft] == playermark) == true)
        playerWin = true;
    return playerWin;
}