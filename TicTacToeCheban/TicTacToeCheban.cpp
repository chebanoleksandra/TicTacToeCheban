#include <windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
char aField[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int iTurn = 0;
int iMode;

void CheckWinner(HWND hWnd) {
    
    for (int i = 0; i < 3; i++) {
        if (aField[i][0] != ' ' && aField[i][0] == aField[i][1] && aField[i][1] == aField[i][2]) {
            MessageBox(hWnd, aField[i][0] == 'X' ? TEXT("X Wins!") : TEXT("O Wins!"), TEXT("Win"), 0);
            EndDialog(hWnd, 0);
            return;
        }
        if (aField[0][i] != ' ' && aField[0][i] == aField[1][i] && aField[1][i] == aField[2][i]) {
            MessageBox(hWnd, aField[0][i] == 'X' ? TEXT("X Wins!") : TEXT("O Wins!"), TEXT("Win"), 0);
            EndDialog(hWnd, 0);
            return;
        }
    }
    if (aField[0][0] != ' ' && aField[0][0] == aField[1][1] && aField[1][1] == aField[2][2]) {
        MessageBox(hWnd, aField[0][0] == 'X' ? TEXT("X Wins!") : TEXT("O Wins!"), TEXT("Win"), 0);
        EndDialog(hWnd, 0);
        return;
    }
    if (aField[0][2] != ' ' && aField[0][2] == aField[1][1] && aField[1][1] == aField[2][0]) {
        MessageBox(hWnd, aField[0][2] == 'X' ? TEXT("X Wins!") : TEXT("O Wins!"), TEXT("Win"), 0);
        EndDialog(hWnd, 0);
        return;
    }
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (aField[i][j] == ' ') draw = false;
        }
    }
    if (draw) {
        MessageBox(hWnd, TEXT("Draw"), TEXT("Draw"), 0);
        EndDialog(hWnd, 0);
    }
}

bool IsTaken(int r)
{
    int row, col = 0;
    r ++;
    if (r == 1 || r == 2 || r == 3)
    {
        row = 0;
    }
    else if (r == 4 || r == 5 || r == 6)
    {
        row = 1;
    }
    else if (r == 7 || r == 8 || r == 9)
    {
        row = 2;
    }
    if (r == 1 || r == 4 || r == 7)
    {
        col = 0;
    }
    else if (r == 2 || r == 5 || r == 8)
    {
        col = 1;
    }
    else if (r == 3 || r == 6 || r == 9)
    {
        col = 2;
    }
    return aField[row][col] == ' ' ? false : true;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{

    // создаём главное окно приложения на основе модального диалога
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    /*HWND hcheck;*/
    WPARAM aButtons[9] = { IDC_BUTTON1, IDC_BUTTON2, IDC_BUTTON3, IDC_BUTTON4, IDC_BUTTON5, IDC_BUTTON6, IDC_BUTTON7, IDC_BUTTON8, IDC_BUTTON9 };
    switch (message)
    {
    case WM_INITDIALOG:
        /*hcheck = GetDlgItem(hWnd, IDC_CHECK2);*/
        SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
        //MessageBox(0, TEXT("Test"), 0, MB_OK);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON1), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON2), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON3), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON4), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON5), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON6), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON7), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON8), FALSE);
        EnableWindow(GetDlgItem(hWnd, IDC_BUTTON9), FALSE);

        return TRUE;
    case WM_CLOSE:
        EndDialog(hWnd, 0); // закрываем модальный диалог
        return TRUE;
    case WM_COMMAND:
        
        if (wParam == IDC_BUTTONSTART)
        {
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON1), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON1), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON2), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON2), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON3), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON3), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON4), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON4), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON5), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON5), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON6), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON6), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON7), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON7), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON8), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON8), TEXT(""));
            EnableWindow(GetDlgItem(hWnd, IDC_BUTTON9), TRUE);
            SetWindowText(GetDlgItem(hWnd, IDC_BUTTON9), TEXT(""));
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    aField[i][j] = ' ';
                }
            }
            LRESULT result  = SendDlgItemMessage(hWnd, IDC_RADIO4, BM_GETCHECK, 0, 0);
            if (result == BST_CHECKED)
            {
                MessageBox(0, TEXT("Person"), TEXT("Game mode"), 0);
                iMode = 0;
                iTurn = 0;
            }
            else {
                result = SendDlgItemMessage(hWnd, IDC_RADIO5, BM_GETCHECK, 0, 0);
                if (result == BST_CHECKED)
                {
                    MessageBox(0, TEXT("Computer"), TEXT("Game mode"), 0);
                    iMode = 1;
                    iTurn = 0;
                }
            }

            result = SendDlgItemMessage(hWnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
            if (result == BST_CHECKED)
            {
                MessageBox(0, TEXT("Level 1"), TEXT("Game level"), 0);
            }
            else {
                result = SendDlgItemMessage(hWnd, IDC_RADIO2, BM_GETCHECK, 0, 0);
                if (result == BST_CHECKED)
                {
                    MessageBox(0, TEXT("Level 2"), TEXT("Game level"), 0);
                }
                else {
                    result = SendDlgItemMessage(hWnd, IDC_RADIO3, BM_GETCHECK, 0, 0);
                    if (result == BST_CHECKED)
                    {
                        MessageBox(0, TEXT("Level 3"), TEXT("Game level"), 0);
                    }
                }
            }
        }
        if (wParam == IDC_BUTTON1 || wParam == IDC_BUTTON2 || wParam == IDC_BUTTON3 || wParam == IDC_BUTTON4 || wParam == IDC_BUTTON5 || wParam == IDC_BUTTON6 || wParam == IDC_BUTTON7 || wParam == IDC_BUTTON8 || wParam == IDC_BUTTON9)
        {
            int row, col = 0;
            if (wParam == IDC_BUTTON1 || wParam == IDC_BUTTON2 || wParam == IDC_BUTTON3)
            {
                row = 0;
            }
            else if (wParam == IDC_BUTTON4 || wParam == IDC_BUTTON5 || wParam == IDC_BUTTON6)
            {
                row = 1;
            }
            else if (wParam == IDC_BUTTON7 || wParam == IDC_BUTTON8 || wParam == IDC_BUTTON9)
            {
                row = 2;
            }
            if (wParam == IDC_BUTTON1 || wParam == IDC_BUTTON4 || wParam == IDC_BUTTON7)
            {
                col = 0;
            }
            else if (wParam == IDC_BUTTON2 || wParam == IDC_BUTTON5 || wParam == IDC_BUTTON8)
            {
                col = 1;
            }
            else if (wParam == IDC_BUTTON3 || wParam == IDC_BUTTON6 || wParam == IDC_BUTTON9)
            {
                col = 2;
            }
            if (iTurn == 0)
            {
                SetWindowText(GetDlgItem(hWnd, wParam), TEXT("❌"));
                aField[row][col] = 'X';
                EnableWindow(GetDlgItem(hWnd, wParam), FALSE);
                CheckWinner(hWnd);
                iTurn = 1;
            }
            else if (iTurn == 1 && iMode == 0)
            {
                SetWindowText(GetDlgItem(hWnd, wParam), TEXT("⭕"));
                aField[row][col] = 'O';
                EnableWindow(GetDlgItem(hWnd, wParam), FALSE);
                CheckWinner(hWnd);
                iTurn = 0;
            }                    
        }
        if (iTurn == 1 && iMode == 1) {
            int r;
            Sleep(1000);
            do {
                r = rand() % 9;
            } while (IsTaken(r));
            SetWindowText(GetDlgItem(hWnd, aButtons[r]), TEXT("⭕"));
            EnableWindow(GetDlgItem(hWnd, aButtons[r]), FALSE);
            CheckWinner(hWnd);
            iTurn = 0;
        }
        return TRUE;
    }
    
    return FALSE;
}
