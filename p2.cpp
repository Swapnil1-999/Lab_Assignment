
#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;
void draw_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "-----------" << endl;
        }
    }
}
bool place_marker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3; //
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    return 0;
}
void swap_player_and_marker()
{

    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}
int main()
{
    cout << "Welcome to Tic Tac Toe" << endl;
    current_player = 1;
    cout << "PLayer 1, choose your marker (X or O): ";
    cin >> current_marker;
    if (current_marker != 'X' && current_marker != 'O')
    {
        cout << "Invalid marker. Choose again: " << endl;
        cin >> current_marker;
    }
    draw_board();
    int player_won;

    for (int i = 0; i < 9; i++)
    {
        int slot;
        cout << "Player " << current_player << " it's your turn, enter a slot number: ";
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << "Invalid input. Try again." << endl;
            i--;
            continue;
        }
        if (!place_marker(slot))
        {
            cout << "Slot already taken. Try again." << endl;
            i--;
            continue;
        }
        draw_board();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "Player 1 won!" << endl;
            break;
        }
        else if (player_won == 2)
        {
            cout << "Player 2 won!" << endl;
            break;
        }
        swap_player_and_marker();
    }
    if (player_won == 0)
    {
        cout << "It's a draw!" << endl;
    }
    return 0;
}
