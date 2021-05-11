#include "PuzzleBoard.h"

int main()
{
    int size;
    std::cout << "Enter size of the board: ";
    std::cin >> size;

    // 'fields' can be filled with a custom matrix if random generation isn't
    // needed.
    std::vector<std::vector<int>> fields; 

    PuzzleBoard puzzleBoard(size, fields);

    std::cout << "======= PUZZLE BOARD =======\n";
    std::cout << puzzleBoard << "\n";

    int result = puzzleBoard.solve();

    if (result == 1)
    {
        std::cout << "This board is solvable.\n";
    }
    else if (result == -1)
    {
        std::cout << "This board is not solvable.\n";
    }
}