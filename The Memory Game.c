#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NEW 1
#define CLOSE 2
#define FINDNUM 3
#define MATCHNUM 4
#define REFRESH 5
#define FINDER1 6
#define FINDER2 7
#define FINDER3 8
#define FINDER4 9
#define FINDER5 10
#define FINDER6 11
#define FINDER7 12
#define FINDER8 13
#define FINDER9 14
#define FINDER10 15
#define FINDER11 16
#define FINDER12 17
#define FINDER13 18
#define FINDER14 19
#define FINDER15 20
#define FINDER16 21
#define FINDER17 22
#define FINDER18 23
#define FINDER19 24
#define FINDER20 25
#define FINDER21 26
#define FINDER22 27
#define FINDER23 28
#define FINDER24 29
#define FINDER25 30
#define BACKMENU 31
#define HELPMATCH 32
#define FINDHELP 33
#define REFRESH2 34
#define MATCH1 35
#define MATCH2 36
#define MATCH3 37
#define MATCH4 38
#define MATCH5 39
#define MATCH6 40
#define MATCH7 41
#define MATCH8 42
#define MATCH9 43
#define MATCH10 44

LRESULT CALLBACK WinProc (HWND, UINT, WPARAM, LPARAM) ;

void AddMenus(HWND);
void AddControls(HWND);
void DestroyAllWindow(HWND);
void DestroyWhich(HWND);
void Generate();
void Generator();
void StartGame(HWND);
void StartMatch (HWND);
void GameEnds(HWND);
void GameEnds2(HWND);
void GameWindow(HWND);
void HelpFind(HWND);
void HelptheMatch(HWND);
void WinBlank(HWND);
void WinBlank2(HWND);
void WinUpdate(HWND);
void WinUpdate2(HWND);

int a[10], b[5][5], c[5], d[5], correctpos, Mistake, Correct, Score, task, in1, in2, push1, push2, check;

HMENU hMenu;
HWND hWelcome, hFind, hMatch;
HWND hInput1, hInput2, hSubmit, hOut, hRefresh, hFindWindow, hFailFind, hQuestion, hMistake, hBackMenu,hCorrect;
HWND hFinder1, hFinder2, hFinder3, hFinder4, hFinder5, hFinder6, hFinder7, hFinder8, hFinder9, hFinder10, hFinder11, hFinder12, hFinder13, hFinder14, hFinder15;
HWND hFinder16, hFinder17, hFinder18, hFinder19, hFinder20, hFinder21, hFinder22, hFinder23, hFinder24, hFinder25, hHelpFind, hScore;
HWND hMatch1, hMatch2, hMatch3, hMatch4, hMatch5, hMatch6, hMatch7, hMatch8, hMatch9, hMatch10;
wchar_t *number[2];

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
	
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH) COLOR_WINDOW ;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
	wc.hInstance = hInst;
	wc.lpszClassName = L"Memory Game";
	wc.lpfnWndProc = WinProc;
	
	if(!RegisterClassW(&wc)){
		return -1;
	}
	
	CreateWindowExW(0, L"Memory Game", L"The Memory Game", WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 180, 
				300, NULL, NULL, NULL, NULL );
	
	MSG msg = {0};
	
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
	int i, j, x=0, y;
	wchar_t number[2];
	switch (msg){
		case WM_COMMAND:{
			switch(wp){
				case NEW:{
					MessageBeep(MB_ICONINFORMATION);
					break;
				}
				case CLOSE:{
					MessageBeep(MB_OK);
					DestroyWindow(hWnd);
					break;
				}
				case FINDNUM:{
					DestroyAllWindow(hWnd);
					Generate();
					GameWindow(hWnd);
					StartGame(hWnd);
					break;
				}
				case REFRESH:{
					DestroyWindow(hFindWindow);
					DestroyWindow(hRefresh);
					GameWindow(hWnd);
					WinBlank(hWnd);
					WinUpdate(hWnd);
					break;
				}
				case MATCHNUM:{
					DestroyAllWindow(hWnd);
					Generator();
					GameWindow(hWnd);
					StartMatch(hWnd);
					break;
				}
				case FINDER1:{
					in1=0;
					in2=0;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder1);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder1 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 20, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER2:{
					in1=0;
					in2=1;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder2);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder2 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 20, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER3:{
					in1=0;
					in2=2;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder3);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder3 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER ,60, 20, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER4:{
					in1=0;
					in2=3;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder4);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder4 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 20, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER5:{
					in1=0;
					in2=4;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder5);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder5 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 20, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER6:{
					in1=1;
					in2=0;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder6);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder6 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 40, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER7:{
					in1=1;
					in2=1;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder7);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder7 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 40, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER8:{
					in1=1;
					in2=2;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder8);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder8 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 40, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER9:{
					in1=1;
					in2=3;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder9);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder9 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 40, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
								WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER10:{
					in1=1;
					in2=4;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder10);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder10 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 40, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER11:{
					in1=2;
					in2=0;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder11);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder11 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 60, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER12:{
					in1=2;
					in2=1;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder12);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder12 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 60, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER13:{
					in1=2;
					in2=2;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder13);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder13 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 60, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER14:{
					in1=2;
					in2=3;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder14);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder14 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 60, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER15:{
					in1=2;
					in2=4;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder15);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder15 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 60, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER16:{
					in1=3;
					in2=0;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder16);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder16 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 80, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER17:{
					in1=3;
					in2=1;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder17);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder17 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 80, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER18:{
					in1=3;
					in2=2;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder18);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder18 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 80, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER19:{
					in1=3;
					in2=3;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder19);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder19 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 80, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER20:{
					in1=3;
					in2=4;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder20);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder20 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 80, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER21:{
					in1=4;
					in2=0;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder21);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder21 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 100, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER22:{
					in1=4;
					in2=1;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder22);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder22 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 100, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER23:{
					in1=4;
					in2=2;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder23);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder23 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 100, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER24:{
					in1=4;
					in2=3;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder24);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder24 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 100, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case FINDER25:{
					in1=4;
					in2=4;
					if(b[in1][in2]==a[task-1]){
						Correct += 1;
						Score += 50;			
						if(Correct<10){
							DestroyWindow(hFinder25);
							wsprintfW(number, L"%d", b[in1][in2]);
							hFinder25 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 100, 20, 20, hWnd, NULL, NULL, NULL);
							WinUpdate(hWnd);
						} else if(Correct==10){
							GameEnds(hWnd);	
						}
					} else {
						Mistake += 1;
						task--;
						if(Mistake<3){
							WinUpdate(hWnd);
						} else if(Mistake==3){
							GameEnds(hWnd);
						}
					}
					break;
				}
				case REFRESH2:{
					DestroyWindow(hFindWindow);
					DestroyWindow(hRefresh);					
					GameWindow(hWnd);
					WinBlank2(hWnd);
					WinUpdate2(hWnd);
					break;
				}
				case MATCH1:{
					push1=0;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){	
								GameEnds2(hWnd);
							} else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else if(c[push1]!=d[push2]){
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);							
							}
						}
					}
					break;
				}
				case MATCH2:{
					push1=1;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);						
							}
						}			
					}
					break;
				}
				case MATCH3:{
					push1=2;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}	
						}
					}
					break;
				}
				case MATCH4:{
					push1=3;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}		
						}
					}
					break;
				}
				case MATCH5:{
					push1=4;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							} 		
						}
					}
					break;
				}
				case MATCH6:{
					push2=0;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}	
						}
					}
					break;
				}
				case MATCH7:{
					push2=1;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}			
						}
					}
					break;
				}
				case MATCH8:{
					push2=2;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}			
						}
					}
					break;
				}
				case MATCH9:{
					push2=3;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}			
						}
					}
					break;
				}
				case MATCH10:{
					push2=4;
					if(push1!=5&&push2!=5){
						if(c[push1]==d[push2]){
							DestroyWhich(hWnd);
							Correct += 1;
							Score += 50;
							if(Correct==5){
								GameEnds2(hWnd);
							}else if(Correct<5){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							}
						} else {
							Mistake += 1;
							if(Mistake<3){
								WinUpdate2(hWnd);
								push1 = 5;
								push2 = 5;
							} else if(Mistake==3){
								GameEnds2(hWnd);
							}			
						}
					}
					break;
				}
				case HELPMATCH:{
					DestroyAllWindow(hWnd);
					HelptheMatch(hWnd);
					break;
				}
				case FINDHELP:{
					DestroyAllWindow(hWnd);
					HelpFind(hWnd);
					break;
				}
				case BACKMENU:{
					DestroyAllWindow(hWnd);
					AddControls(hWnd);
					break;
				}
			}
			break;
		}
		case WM_CREATE:{
			AddMenus(hWnd);
			AddControls(hWnd);
			break;
		}
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		} default :{
			return DefWindowProcW(hWnd, msg, wp, lp);
		}	
	}
}

void AddMenus(HWND hWnd){
	
	hMenu = CreateMenu();
	HMENU hPopUp = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	HMENU hSubHelp = CreateMenu();
	
	AppendMenu(hSubHelp, MF_STRING, HELPMATCH, "Match the Numbers");
	AppendMenu(hSubHelp, MF_STRING, FINDHELP, "Find the Numbers");	
	
	AppendMenu(hSubMenu, MF_STRING, MATCHNUM, "Matching Numbers");
	AppendMenu(hSubMenu, MF_STRING, FINDNUM, "Find the Numbers");
	
	AppendMenu(hPopUp, MF_POPUP, (UINT_PTR)hSubMenu, "New");
	AppendMenu(hPopUp, MF_SEPARATOR, 0, NULL);
	AppendMenu(hPopUp, MF_STRING, CLOSE, "Exit");	
	
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR) hPopUp, "File");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR) hSubHelp, "Help");
	
	SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd){
	hWelcome = CreateWindowExW(0, L"static", L"WELCOME!\n\nHere's some games for you", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 10, 130, 70, hWnd, NULL, NULL, NULL);
	hMatch = CreateWindowExW(0, L"Button", L"Matching Numbers", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 82, 130, 20, hWnd, (HMENU) MATCHNUM, NULL, NULL);
	hFind = CreateWindowExW(0, L"Button", L"Find the Numbers", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 104, 130, 20, hWnd, (HMENU) FINDNUM, NULL, NULL);
}

void Generate(){
	int i, j, num, pos1, pos2, totalnum;
	bool number[10]={0}, pos[5][5]={0};
	srand(time(0));
	for(i=0 ; i<10 ; i++){
		num = (rand() % 15) + 1;
		if(!number[num]){
			a[i]=num;
		} else {
			i--;
		}
		number[num]=1;
	}
	for(i = 0 ; i < 10 ; i++){
		pos1 = rand()%5;
		pos2 = rand()%5;
		if(!pos[pos1][pos2]){
			b[pos1][pos2]=a[i];
		} else {
			i--;
		}
		pos[pos1][pos2]=1;
	}
	for(i = 0 ; i<5 ;i++){
		for(j=0;j<5;j++){
			if(!pos[i][j]){
				b[i][j]=0;
			}
			pos[i][j]=1;
		}
	}
}

void GameWindow(HWND hWnd){
	hFindWindow = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD , 0, 0, 180, 250, hWnd, NULL, NULL, NULL);
}

void StartGame(HWND hWnd){
	int x=0, y=0;
	int i, j;
	task=0;
	Correct=0;
	Mistake=0;
	Score=0;
	for(i=0;i<5;i++){
		y+=20;
		for(j=0;j<5;j++){
			x+=20;
			wchar_t number[2];
			wsprintfW(number, L"%d", b[i][j]);
			CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, y, 20, 20, hFindWindow, NULL, NULL, NULL);
		}
		x=0;
	}
	CreateWindowExW(0, L"static", L"Are you ready?", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 122, 100, 20, hFindWindow, NULL, NULL, NULL);
	hRefresh = CreateWindowExW(0, L"Button", L"Ready!", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 144, 100, 20, hWnd, (HMENU) REFRESH, NULL, NULL);
}

void WinBlank(HWND hWnd){
	hFinder1 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 20, 20, 20, hWnd, (HMENU) FINDER1, NULL, NULL);
	hFinder2 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 20, 20, 20, hWnd, (HMENU) FINDER2, NULL, NULL);
	hFinder3 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 20, 20, 20, hWnd, (HMENU) FINDER3, NULL, NULL);
	hFinder4 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 20, 20, 20, hWnd, (HMENU) FINDER4, NULL, NULL);
	hFinder5 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 20, 20, 20, hWnd, (HMENU) FINDER5, NULL, NULL);
	hFinder6 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 40, 20, 20, hWnd, (HMENU) FINDER6, NULL, NULL);
	hFinder7 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 40, 20, 20, hWnd, (HMENU) FINDER7, NULL, NULL);
	hFinder8 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 40, 20, 20, hWnd, (HMENU) FINDER8, NULL, NULL);
	hFinder9 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 40, 20, 20, hWnd, (HMENU) FINDER9, NULL, NULL);
	hFinder10 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 40, 20, 20, hWnd, (HMENU) FINDER10, NULL, NULL);
	hFinder11 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 60, 20, 20, hWnd, (HMENU) FINDER11, NULL, NULL);
	hFinder12 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 60, 20, 20, hWnd, (HMENU) FINDER12, NULL, NULL);
	hFinder13 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 60, 20, 20, hWnd, (HMENU) FINDER13, NULL, NULL);
	hFinder14 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 60, 20, 20, hWnd, (HMENU) FINDER14, NULL, NULL);
	hFinder15 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 60, 20, 20, hWnd, (HMENU) FINDER15, NULL, NULL);
	hFinder16 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 80, 20, 20, hWnd, (HMENU) FINDER16, NULL, NULL);
	hFinder17 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 80, 20, 20, hWnd, (HMENU) FINDER17, NULL, NULL);
	hFinder18 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 80, 20, 20, hWnd, (HMENU) FINDER18, NULL, NULL);
	hFinder19 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 80, 20, 20, hWnd, (HMENU) FINDER19, NULL, NULL);
	hFinder20 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 80, 20, 20, hWnd, (HMENU) FINDER20, NULL, NULL);
	hFinder21 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 100, 20, 20, hWnd, (HMENU) FINDER21, NULL, NULL);
	hFinder22 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 100, 20, 20, hWnd, (HMENU) FINDER22, NULL, NULL);
	hFinder23 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 100, 20, 20, hWnd, (HMENU) FINDER23, NULL, NULL);
	hFinder24 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 100, 20, 20, hWnd, (HMENU) FINDER24, NULL, NULL);
	hFinder25 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 100, 20, 20, hWnd, (HMENU) FINDER25, NULL, NULL);
}

void WinUpdate(HWND hWnd){
	int i, j, x=0, y=0;
	char out[2], MisCount[2], MisOut[20], CorCount[2], CorOut[20], ScoCount[2], ScoOut[20], sentence[15];
	_itoa(a[task], out, 10);
	strcpy(sentence, "");
	strcat(sentence, "Find number ");
	strcat(sentence, out);
	hQuestion = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 120, 100, 40, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hQuestion, sentence);
	_itoa(Mistake, MisCount, 10);
	strcpy(MisOut, "");
	if(Mistake==1){
		strcat(MisOut, "Mistake : ");
	} else {
		strcat(MisOut, "Mistakes : ");
	}
	strcat(MisOut, MisCount);
	strcat(MisOut, "/3");
	hMistake = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 160, 100, 20, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hMistake, MisOut);	
	_itoa(Correct, CorCount, 10);
	strcpy(CorOut, "");
	if(Correct==1){
		strcat(CorOut, "Correct : ");
	} else {
		strcat(CorOut, "Corrects : ");
	}
	strcat(CorOut, CorCount);
	strcat(CorOut, "/10");
	hCorrect = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 180, 100, 20, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hCorrect, CorOut);	
	_itoa(Score, ScoCount, 10);
	strcpy(ScoOut, "");
	strcat(ScoOut, "Score ");
	strcat(ScoOut, ScoCount);
	hScore = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 130, 20, 40, 40, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hScore, ScoOut);	
	task+=1;
}

void GameEnds(HWND hWnd){
	int i, x=0, j, y=0;
	char ScoCount[2], ScoOut[20];
	DestroyAllWindow(hWnd);
	GameWindow(hWnd);
	for(i=0;i<5;i++){
		y+=20;
		for(j=0;j<5;j++){
			x+=20;
			wchar_t number[2];
			wsprintfW(number, L"%d", b[i][j]);
			CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, y, 20, 20, hFindWindow, NULL, NULL, NULL);
		}
		x=0;
	}
	_itoa(Score, ScoCount, 10);
	strcpy(ScoOut, "");
	strcat(ScoOut, "Final Score : ");
	strcat(ScoOut, ScoCount);
	hScore = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 120, 100, 30, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hScore, ScoOut);	
	if(Mistake==3){
		hFailFind = CreateWindowExW(0, L"static", L"You've failed the game.", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 152, 100, 50, hWnd, NULL, NULL, NULL );
	} else if(Correct==10){
		hFailFind = CreateWindowExW(0, L"static", L"You've finished the game!", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 152, 100, 50, hWnd, NULL, NULL, NULL );		
	}
	hBackMenu = CreateWindowExW(0, L"Button", L"Menu", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 210, 100, 20, hWnd, (HMENU)BACKMENU, NULL, NULL );
}

void DestroyAllWindow(HWND hWnd){
	DestroyWindow(hWelcome);
	DestroyWindow(hMatch);
	DestroyWindow(hFind);
	DestroyWindow(hFindWindow);
	DestroyWindow(hFinder1);
	DestroyWindow(hFinder2);
	DestroyWindow(hFinder3);
	DestroyWindow(hFinder4);
	DestroyWindow(hFinder5);
	DestroyWindow(hFinder6);
	DestroyWindow(hFinder7);
	DestroyWindow(hFinder8);
	DestroyWindow(hFinder9);
	DestroyWindow(hFinder10);
	DestroyWindow(hFinder11);
	DestroyWindow(hFinder12);
	DestroyWindow(hFinder13);
	DestroyWindow(hFinder14);
	DestroyWindow(hFinder15);
	DestroyWindow(hFinder16);
	DestroyWindow(hFinder17);
	DestroyWindow(hFinder18);
	DestroyWindow(hFinder19);
	DestroyWindow(hFinder20);
	DestroyWindow(hFinder21);
	DestroyWindow(hFinder22);
	DestroyWindow(hFinder23);
	DestroyWindow(hFinder24);
	DestroyWindow(hFinder25);
	DestroyWindow(hRefresh);
	DestroyWindow(hFailFind);
	DestroyWindow(hBackMenu);
	DestroyWindow(hHelpFind);
	DestroyWindow(hMatch1);
	DestroyWindow(hMatch2);
	DestroyWindow(hMatch3);
	DestroyWindow(hMatch4);
	DestroyWindow(hMatch5);
	DestroyWindow(hMatch6);
	DestroyWindow(hMatch7);
	DestroyWindow(hMatch8);
	DestroyWindow(hMatch9);
	DestroyWindow(hMatch10);
	DestroyWindow(hQuestion);
	DestroyWindow(hScore);
	DestroyWindow(hMistake);
	DestroyWindow(hCorrect);	
}

void HelpFind(HWND hWnd){
	int i, x=0, j, y=0;
	int example1[5][5]={{0,1,0,2,0},{3,0,4,0,5},{0,6,0,7,0},{8,0,9,0,10},{0,0,0,0,0}};
	hHelpFind = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD , 0, 0, 150, 250, hWnd, NULL, NULL, NULL);
	for(i=0;i<5;i++){
		y+=20;
		for(j=0;j<5;j++){
			x+=20;
			wchar_t example[2];
			wsprintfW(example, L"%d", example1[i][j]);
			CreateWindowExW(0, L"static", example, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, y, 20, 20, hHelpFind, NULL, NULL, NULL);
		}
		x=0;
	}
	CreateWindowExW(0, L"static", L"Memorize the location of numbers that aren't 0!", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 120, 100, 70, hHelpFind, NULL, NULL, NULL);
	hBackMenu = CreateWindowExW(0, L"Button", L"Menu", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 190, 100, 20, hWnd, (HMENU)BACKMENU, NULL, NULL );
}

void Generator(){
    int lower = 1, upper = 5; 
    srand(time(0)); 
    int i, j;
	bool arr[5]={0};
	bool brr[5]={0};
    for (i = 0; i < 5; i++) { 
        int num = (rand() % 5) + 1;
        if(!arr[num]){
 	       c[i]=num;
		} else {
			i--;
		}
		arr[num]=1;
    } 
    for (i = 0; i < 5; i++) { 
        int num = (rand() % 5) + 1;
        if(!brr[num]){
 	       d[i]=num;
		} else {
			i--;
		}
		brr[num]=1;
    }
}

void StartMatch(HWND hWnd){
	int x=0, y=0;
	int i, j;
	task=0;
	push1=5;
	push2=5;
	Correct=0;
	Mistake=0;
	Score=0;
	for(i=0;i<5;i++){
		x+=20;
		wchar_t number[2];
		wsprintfW(number, L"%d", c[i]);
		CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, 20, 20, 20, hFindWindow, NULL, NULL, NULL);
	}
	x=0;
	for(i=0;i<5;i++){
		x+=20;
		wchar_t number[2];
		wsprintfW(number, L"%d", d[i]);
		CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, 40, 20, 20, hFindWindow, NULL, NULL, NULL);
	}
	CreateWindowExW(0, L"static", L"Are you ready?", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 62, 100, 20, hFindWindow, NULL, NULL, NULL);
	hRefresh = CreateWindowExW(0, L"Button", L"Ready!", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 84, 100, 20, hWnd, (HMENU) REFRESH2, NULL, NULL);
}

void WinBlank2(HWND hWnd){
	hMatch1 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 20, 20, 20, hWnd, (HMENU) MATCH1, NULL, NULL);
	hMatch2 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 20, 20, 20, hWnd, (HMENU) MATCH2, NULL, NULL);
	hMatch3 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 20, 20, 20, hWnd, (HMENU) MATCH3, NULL, NULL);
	hMatch4 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 20, 20, 20, hWnd, (HMENU) MATCH4, NULL, NULL);
	hMatch5 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 20, 20, 20, hWnd, (HMENU) MATCH5, NULL, NULL);
	hMatch6 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 40, 20, 20, hWnd, (HMENU) MATCH6, NULL, NULL);
	hMatch7 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 40, 20, 20, hWnd, (HMENU) MATCH7, NULL, NULL);
	hMatch8 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 40, 20, 20, hWnd, (HMENU) MATCH8, NULL, NULL);
	hMatch9 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 40, 20, 20, hWnd, (HMENU) MATCH9, NULL, NULL);
	hMatch10 = CreateWindowExW(0, L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 40, 20, 20, hWnd, (HMENU) MATCH10, NULL, NULL);
}

void WinUpdate2(HWND hWnd){
	int i, j, x=0, y=0;
	char out[2], MisCount[2], MisOut[20], CorCount[2], CorOut[20], ScoCount[2], ScoOut[20], sentence[15];
	strcpy(sentence, "");
	strcat(sentence, "Find the matching numbers");
	hQuestion = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 65, 100, 55, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hQuestion, sentence);
	_itoa(Mistake, MisCount, 10);
	strcpy(MisOut, "");
	if(Mistake==1){
		strcat(MisOut, "Mistake : ");
	} else {
		strcat(MisOut, "Mistakes : ");
	}
	strcat(MisOut, MisCount);
	strcat(MisOut, "/3");
	hMistake = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 120, 100, 20, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hMistake, MisOut);	
	_itoa(Correct, CorCount, 10);
	strcpy(CorOut, "");
	if(Correct==1){
		strcat(CorOut, "Correct : ");
	} else {
		strcat(CorOut, "Corrects : ");
	}
	strcat(CorOut, CorCount);
	strcat(CorOut, "/5");
	hCorrect = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 140, 100, 20, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hCorrect, CorOut);	
	_itoa(Score, ScoCount, 10);
	strcpy(ScoOut, "");
	strcat(ScoOut, "Score ");
	strcat(ScoOut, ScoCount);
	hScore = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 130, 20, 40, 40, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hScore, ScoOut);	
}
void DestroyWhich(HWND hWnd){
	wchar_t number[2];
	switch(push1){
		case 0:{
			DestroyWindow(hMatch1);
			wsprintfW(number, L"%d", c[push1]);
			hMatch1 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 20, 20, 20, hWnd, NULL, NULL, NULL);
			push1 = 5;
			break;
		}
		case 1:{
			DestroyWindow(hMatch2);
			wsprintfW(number, L"%d", c[push1]);
			hMatch2 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 20, 20, 20, hWnd, NULL, NULL, NULL);
			push1 = 5;
			break;
		}
		case 2:{
			DestroyWindow(hMatch3);
			wsprintfW(number, L"%d", c[push1]);
			hMatch3 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 20, 20, 20, hWnd, NULL, NULL, NULL);
			push1 = 5;
			break;
		}
		case 3:{
			DestroyWindow(hMatch4);
			wsprintfW(number, L"%d", c[push1]);
			hMatch4 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 20, 20, 20, hWnd, NULL, NULL, NULL);
			push1 = 5;
			break;
		}
		case 4:{
			DestroyWindow(hMatch5);
			wsprintfW(number, L"%d", c[push1]);
			hMatch5 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 20, 20, 20, hWnd, NULL, NULL, NULL);
			push1 = 5;
			break;
		}
	}
	switch(push2){
		case 0:{
			DestroyWindow(hMatch6);
			wsprintfW(number, L"%d", d[push2]);
			hMatch6 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 40, 20, 20, hWnd, NULL, NULL, NULL);
			push2 = 5;
			break;
		}
		case 1:{
			DestroyWindow(hMatch7);
			wsprintfW(number, L"%d", d[push2]);
			hMatch7 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 40, 40, 20, 20, hWnd, NULL, NULL, NULL);
			push2 = 5;
			break;
		}
		case 2:{
			DestroyWindow(hMatch8);
			wsprintfW(number, L"%d", d[push2]);
			hMatch8 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 60, 40, 20, 20, hWnd, NULL, NULL, NULL);
			push2 = 5;
			break;
		}
		case 3:{
			DestroyWindow(hMatch9);
			wsprintfW(number, L"%d", d[push2]);
			hMatch9 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 80, 40, 20, 20, hWnd, NULL, NULL, NULL);
			push2 = 5;
			break;
		}
		case 4:{
			DestroyWindow(hMatch10);
			wsprintfW(number, L"%d", d[push2]);
			hMatch10 = CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | SS_CENTER , 100, 40, 20, 20, hWnd, NULL, NULL, NULL);
			push2 = 5;
			break;
		}
	}
}

void GameEnds2(HWND hWnd){
	int i, x=0;
	char ScoCount[2], ScoOut[20];
	DestroyAllWindow(hWnd);
	GameWindow(hWnd);
	for(i=0;i<5;i++){
		x+=20;
		wchar_t number[2];
		wsprintfW(number, L"%d", c[i]);
		CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, 20, 20, 20, hFindWindow, NULL, NULL, NULL);
	}
	x=0;
	for(i=0;i<5;i++){
		x+=20;
		wchar_t number[2];
		wsprintfW(number, L"%d", d[i]);
		CreateWindowExW(0, L"static", number, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, 40, 20, 20, hFindWindow, NULL, NULL, NULL);
	}
	_itoa(Score, ScoCount, 10);
	strcpy(ScoOut, "");
	strcat(ScoOut, "Final Score : ");
	strcat(ScoOut, ScoCount);
	hScore = CreateWindowExW(0, L"static", 0, WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 60, 100, 40, hFindWindow, NULL, NULL, NULL);
	SetWindowText(hScore, ScoOut);	
	if(Mistake==3){
		hFailFind = CreateWindowExW(0, L"static", L"You've failed the game.", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 100, 100, 40, hWnd, NULL, NULL, NULL );
	} else if(Correct==5){
		hFailFind = CreateWindowExW(0, L"static", L"You've finished the game!", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 100, 100, 60, hWnd, NULL, NULL, NULL );		
	}
	hBackMenu = CreateWindowExW(0, L"Button", L"Menu", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 160, 100, 20, hWnd, (HMENU)BACKMENU, NULL, NULL );
}

void HelptheMatch(HWND hWnd){
	int i, x=0, j, y=0;
	int example1[2][5]={{1,2,3,4,5},{5,4,3,2,1}};
	hHelpFind = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD , 0, 0, 150, 250, hWnd, NULL, NULL, NULL);
	for(i=0;i<2;i++){
		y+=20;
		for(j=0;j<5;j++){
			x+=20;
			wchar_t example[2];
			wsprintfW(example, L"%d", example1[i][j]);
			CreateWindowExW(0, L"static", example, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , x, y, 20, 20, hHelpFind, NULL, NULL, NULL);
		}
		x=0;
	}
	CreateWindowExW(0, L"static", L"Memorize the matching numbers!", WS_VISIBLE | WS_CHILD | SS_CENTER , 20, 60, 100, 70, hHelpFind, NULL, NULL, NULL);
	hBackMenu = CreateWindowExW(0, L"Button", L"Menu", WS_VISIBLE | WS_CHILD | SS_CENTER, 20, 130, 100, 20, hWnd, (HMENU)BACKMENU, NULL, NULL );	
}
