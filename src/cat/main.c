//
// Copyright (C) 2025 愛子あゆみ <ayumi.aiko@outlook.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

int main(const int argc, const char *argv[]) {
    if(argc == 1) {
        char content[1024];
        while(fgets(content, sizeof(content), stdin)) {
            fputs(content, stdout);
        }
        return 0;
    }
    else if(argc == 2 && (strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--number") == 0)) {
        int lines = 1;
        char content[1024];
        char freax[2000];
        while(fgets(content, sizeof(content), stdin)) {
            snprintf(freax, sizeof(freax), "%6d  %s", lines++, content);
            fputs(freax, stdout);
        }
        return 0;
    }
    else if(argc >= 2 && (strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--number") == 0)) {
        int lines = 1;
        char content[1024];
        char freax[2000];
        for(int i = 2; i < argc; i++) {
            FILE *userInputFile = fopen(argv[i], "r");
            if(!userInputFile) {
                printf("Failed to access %d'th file: %s\n", i, argv[i]);
                continue;
            }
            while(fgets(content, sizeof(content), userInputFile)) {
                snprintf(freax, sizeof(freax), "%d  %s", lines++, content);
                fputs(freax, stdout);
            }
            fclose(userInputFile);
        }
        return 0;
    }
    else if(argc == 2 && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--squeeze-blank") == 0)) {
        int lines = 1;
        char content[1024];
        char freax[2000];
        while(fgets(content, sizeof(content), stdin)) {
            if(content[0] == '\n') continue;
            snprintf(freax, sizeof(freax), "%d  %s", lines++, content);
            fputs(freax, stdout);
        }
        return 0;
    }
    else if(argc >= 2 && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--squeeze-blank") == 0)) {
        int lines = 1;
        char content[1024];
        char freax[2000];
        for(int i = 2; i < argc; i++) {
            FILE *userInputFile = fopen(argv[i], "r");
            if(!userInputFile) {
                printf("Failed to access %d'th file: %s\n", i, argv[i]);
                continue;
            }
            while(fgets(content, sizeof(content), userInputFile)) {
                if(content[0] == '\n') continue;
                snprintf(freax, sizeof(freax), "%d  %s", lines++, content);
                fputs(freax, stdout);
            }
            fclose(userInputFile);
        }
        return 0;
    }
    else if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s [OPTION]... [FILE]...\n", basename((char *)argv[0]));
        printf("Concatenate FILE(s) to standard output.\n\n");
        printf("With no FILE, or when FILE is -, read standard input.\n\n");
        printf("  -n, --number             number all output lines\n");
        printf("  -s, --squeeze-blank      suppress repeated empty output lines\n");
        printf("      --help        display this help and exit\n");
        printf("      --version     output version information and exit\n");
        return 1;
    }
    else if(strcmp(argv[1], "--version") == 0) { 
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⠂⢉⠤⠐⠋⠈⠡⡈⠉⠐⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⢀⡀⢠⣤⠔⠁⢀⠀⠀⠀⠀⠀⠀⠀⠈⢢⠀⠀⠈⠱⡤⣤⠄⣀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠰⠁⠀⣰⣿⠃⠀⢠⠃⢸⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠈⢞⣦⡀⠈⡇⠀⠀⠀\n");
        printf("⠀⠀⠀⢇⣠⡿⠁⠀⢀⡃⠀⣈⠀⠀⠀⠀⢰⡀⠀⠀⠀⠀⢢⠰⠀⠀⢺⣧⢰⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠈⣿⠁⡘⠀⡌⡇⠀⡿⠸⠀⠀⠀⠈⡕⡄⠀⠐⡀⠈⠀⢃⠀⠀⠾⠇⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠇⡇⠃⢠⠀⠶⡀⡇⢃⠡⡀⠀⠀⠡⠈⢂⡀⢁⠀⡁⠸⠀⡆⠘⡀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠸⠀⢸⠀⠘⡜⠀⣑⢴⣀⠑⠯⡂⠄⣀⣣⢀⣈⢺⡜⢣⠀⡆⡇⠀⢣⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠇⠀⢸⠀⡗⣰⡿⡻⠿⡳⡅⠀⠀⠀⠀⠈⡵⠿⠿⡻⣷⡡⡇⡇⠀⢸⣇⠀⠀⠀\n");
        printf("⠀⠀⢰⠀⠀⡆⡄⣧⡏⠸⢠⢲⢸⠁⠀⠀⠀⠀⠐⢙⢰⠂⢡⠘⣇⡇⠃⠀⠀⢹⡄⠀⠀\n");
        printf("⠀⠀⠟⠀⠀⢰⢁⡇⠇⠰⣀⢁⡜⠀⠀⠀⠀⠀⠀⠘⣀⣁⠌⠀⠃⠰⠀⠀⠀⠈⠰⠀⠀\n");
        printf("⠀⡘⠀⠀⠀⠀⢊⣤⠀⠀⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠄⠀⢸⠃⠀⠀⠀⠀⠀⠃⠀\n");
        printf("⢠⠁⢀⠀⠀⠀⠈⢿⡀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⢀⠏⠀⠀⠀⠀⠀⠀⠸⠀\n");
        printf("⠘⠸⠘⡀⠀⠀⠀⠀⢣⠀⠀⠀⠀⠀⠀⠁⠀⠃⠀⠀⠀⠀⢀⠎⠀⠀⠀⠀⠀⢠⠀⠀⡇\n");
        printf("⠀⠇⢆⢃⠀⠀⠀⠀⠀⡏⢲⢤⢀⡀⠀⠀⠀⠀⠀⢀⣠⠄⡚⠀⠀⠀⠀⠀⠀⣾⠀⠀⠀\n");
        printf("⢰⠈⢌⢎⢆⠀⠀⠀⠀⠁⣌⠆⡰⡁⠉⠉⠀⠉⠁⡱⡘⡼⠇⠀⠀⠀⠀⢀⢬⠃⢠⠀⡆\n");
        printf("⠀⢢⠀⠑⢵⣧⡀⠀⠀⡿⠳⠂⠉⠀⠀⠀⠀⠀⠀⠀⠁⢺⡀⠀⠀⢀⢠⣮⠃⢀⠆⡰⠀\n");
        printf("⠀⠀⠑⠄⣀⠙⡭⠢⢀⡀⠀⠁⠄⣀⣀⠀⢀⣀⣀⣀⡠⠂⢃⡀⠔⠱⡞⢁⠄⣁⠔⠁⠀\n");
        printf("⠀⠀⠀⠀⠀⢠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠉⠁⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀\n");
        printf("%s 1.0\n", basename((char *)argv[0]));
        printf("Copyright (C) 2025 愛子あゆみ\n");
        printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
        printf("This is free software: you are free to change and redistribute it.\n");
        printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
        printf("Written by Ayumi Aiko\n");
        return 1;
    }
}