#include "framework.h"
#include "Anti_Baek.h"
#include <objidl.h>
#include <gdiplus.h>
#include <atlbase.h>
#include <atlcom.h>
#include <string.h>
#include <wmp.h>  // Windows Media Player library
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "uuid.lib")

#define MAX_LOADSTRING 100
#define ID_BUTTON_YES 1001
#define ID_BUTTON_NO 1002

// 전역 변수:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
Gdiplus::Image* gpImage = NULL;
ULONG_PTR gdiplusToken;
CComPtr<IWMPPlayer4> spWMPPlayer; // Media player interface
int is_button_click = 0;
int is_debug = 0;
char key[] = "SECRET";

// 함수 선언:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // GDI+ 초기화
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // COM 초기화
    CoInitialize(NULL);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ANTIBAEK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // GDI+ 종료
    Gdiplus::GdiplusShutdown(gdiplusToken);

    // COM 종료
    CoUninitialize();

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ANTIBAEK));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(0, 0, 0)));;
    wcex.lpszMenuName = NULL;  // 메뉴 제거
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 1000, 500, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // Yes 버튼 생성
    CreateWindow(L"BUTTON", L"Yes",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        300, 400, 100, 30,
        hWnd, (HMENU)ID_BUTTON_YES, hInstance, NULL);

    // No 버튼 생성
    CreateWindow(L"BUTTON", L"No",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        600, 400, 100, 30,
        hWnd, (HMENU)ID_BUTTON_NO, hInstance, NULL);

    // JPEG 이미지 로드 (경로를 적절히 수정해주세요)
    gpImage = Gdiplus::Image::FromFile(L"ready.png");

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_BUTTON_YES:
            if (is_debug = IsDebuggerPresent()) {
                gpImage = Gdiplus::Image::FromFile(L"baek.png");
                is_button_click = 1;
                DestroyWindow(GetDlgItem(hWnd, ID_BUTTON_YES));
                DestroyWindow(GetDlgItem(hWnd, ID_BUTTON_NO));
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);  // 즉시 그리기
            }
            else {
                // JFS{D0main_expan5ion?_Just_@void_it!}
                char flag[] = {0x19, 0x03, 0x10, 0x29, 0x01, 0x64, 0x3e, 0x24, 0x2a, 0x3c, 0x1a, 0x31, 0x2b, 0x35, 0x22, 0x3c, 0x70, 0x3d, 0x3c, 0x2b, 0x7c, 0x0d, 0x0f, 0x21, 0x20, 0x31, 0x1c, 0x12, 0x33, 0x3b, 0x3a, 0x21, 0x1c, 0x3b, 0x31, 0x75, 0x2e};
                char result[255] = "";
                is_button_click = 1;
                gpImage = Gdiplus::Image::FromFile(L"success.jpg");
                for (int i = 0; i < strlen(flag); i++) {
                    result[i] = flag[i] ^ key[i % strlen(key)];
                }
                DestroyWindow(GetDlgItem(hWnd, ID_BUTTON_YES));
                DestroyWindow(GetDlgItem(hWnd, ID_BUTTON_NO));
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);  // 즉시 그리기
            }
            break;
        case ID_BUTTON_NO:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 화면을 지우기 (배경을 검정색으로 설정)
        Gdiplus::Graphics graphics(hdc);
        graphics.Clear(Gdiplus::Color(255, 0, 0, 0)); // 배경을 검정색으로 설정

        // 이미지를 그리기 전에 배경을 지운 뒤 이미지 그리기
        if (gpImage != NULL)
        {
            if (is_button_click) {
                if (is_debug) {
                    int imageWidth = gpImage->GetWidth() - 300;
                    int imageHeight = gpImage->GetHeight() - 250;

                    RECT rect;
                    GetClientRect(hWnd, &rect);
                    int x = (rect.right - imageWidth) / 2;
                    int y = 0;

                    graphics.DrawImage(gpImage, x, y, imageWidth, imageHeight);
                }
                else {
                    int imageWidth = gpImage->GetWidth() - 250;
                    int imageHeight = gpImage->GetHeight() - 600;

                    RECT rect;
                    GetClientRect(hWnd, &rect);
                    int x = (rect.right - imageWidth) / 2;
                    int y = 0;

                    graphics.DrawImage(gpImage, x, y, imageWidth, imageHeight);
                }
            }
            else {
                int imageWidth = gpImage->GetWidth() - 400;
                int imageHeight = gpImage->GetHeight() - 400;

                RECT rect;
                GetClientRect(hWnd, &rect);
                int x = (rect.right - imageWidth) / 2;
                int y = 0;

                graphics.DrawImage(gpImage, x, y, imageWidth, imageHeight);
            }
        }

        EndPaint(hWnd, &ps);
    }
    break;
    break;
    case WM_DESTROY:
        if (gpImage != NULL)
        {
            delete gpImage;
            gpImage = NULL;
        }
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
