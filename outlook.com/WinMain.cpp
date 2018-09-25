#include <Windows.h>

constexpr auto APP_PATHS_CHROME_EXE = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\chrome.exe";

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       cmdShow)
{
	char *chromeExe;
	DWORD sz;

	if (RegGetValue(HKEY_LOCAL_MACHINE, APP_PATHS_CHROME_EXE, NULL, RRF_RT_ANY, NULL, NULL, &sz) != ERROR_SUCCESS) {
		return 0;
	}
	
	chromeExe = (char *)malloc(sz);

	if (RegGetValue(HKEY_LOCAL_MACHINE, APP_PATHS_CHROME_EXE,
		NULL, RRF_RT_ANY, NULL, chromeExe, &sz) == ERROR_SUCCESS) {
		HWND hwnd = GetDesktopWindow();
		ShellExecute(hwnd, "open", chromeExe, "--app=https://outlook.com", NULL, NULL);
	}

	free(chromeExe);

	return 0;
}
