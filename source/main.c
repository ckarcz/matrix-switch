#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    // Initialize
    gfxInitDefault();
    consoleInit(NULL);

    printf("Hello World!");

    // Main Loop
    while(appletMainLoop())
    {
        // Get P1 Keys
        hidScanInput();
        u64 p1Keys = hidKeysDown(CONTROLLER_P1_AUTO);

        // On PLUS key press, exit to Homebrew Menu
        if (p1Keys & KEY_PLUS) break;

        // GFX Fefresh
        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }
    
    // Exit
    gfxExit();
    return 0;
}