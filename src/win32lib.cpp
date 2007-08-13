#include "config.hpp"
#ifdef RGL_W32
// ---------------------------------------------------------------------------
// W32 Library Implementation
// $Id: win32lib.cpp 591 2007-08-12 01:18:08Z dmurdoch $
// ---------------------------------------------------------------------------
#include "lib.hpp"
#include "win32gui.hpp"
#include <windows.h>
#include <cassert>
// ---------------------------------------------------------------------------
namespace lib {
// ---------------------------------------------------------------------------
// GUI Factory
// ---------------------------------------------------------------------------
gui::Win32GUIFactory* gpWin32GUIFactory = NULL;
// ---------------------------------------------------------------------------
gui::GUIFactory* getGUIFactory()
{
  return (gui::GUIFactory*) gpWin32GUIFactory;
}
// ---------------------------------------------------------------------------
// printMessage
// ---------------------------------------------------------------------------
void printMessage( const char* string ) {
  ::MessageBox(NULL, string, "RGL library", MB_OK|MB_ICONINFORMATION);
}
// ---------------------------------------------------------------------------
// getTime
// ---------------------------------------------------------------------------
double getTime() {
  return ( (double) ::GetTickCount() ) * ( 1.0 / 1000.0 );
}
// ---------------------------------------------------------------------------
// init
// ---------------------------------------------------------------------------
bool init()
{
  assert(gpWin32GUIFactory == NULL);
  gpWin32GUIFactory = new gui::Win32GUIFactory();  
  return true;
}
// ---------------------------------------------------------------------------
// quit
// ---------------------------------------------------------------------------
void quit()
{
  assert(gpWin32GUIFactory != NULL);
  delete gpWin32GUIFactory;
  gpWin32GUIFactory = NULL;
}
// ---------------------------------------------------------------------------
} // namespace lib
// ---------------------------------------------------------------------------
#endif // RGL_W32

