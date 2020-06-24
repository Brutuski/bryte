#if !defined (BRYTE_H)
#define BRYTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>
#include <dirent.h>
#include <errno.h>

#define AUTHOR "Adhiraj Sirohi"
#define VERSION "v1.0"
#define GIT "https://github.com/Brutuski/bryte"
#define LOGO "Vasundhara Sharma (https://www.behance.net/vasundhsharma)"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[33m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define BOLD "\033[1m"
#define ITALIC "'\033[3m'"
#define UNDERLINE "'\033[4m'"
#define NOFORMAT "\033[22m"

#define PATH "/sys/class/backlight/"
#define ARCH_WIKI "https://wiki.archlinux.org/index.php/Backlight#Hardware_interfaces"

#define check "ls /sys/class/backlight/"
#define intel_card "intel_backlight"

#define LEN 30

const int MAX_VALUE =  100;
const int MIN_VALUE = 0;
const int STEP_VALUE = 5;

#endif

void version() {
    printf(BOLD"\nAuthor:\t\t "NOFORMAT);
    printf(AUTHOR "\n");
    printf(BOLD"Version:\t "NOFORMAT);
    printf(VERSION "\n");
    printf(BOLD"Git Link:\t "NOFORMAT);
    printf(GIT "\n");
    printf(BOLD"Logo courtsey:\t "NOFORMAT);
    printf(LOGO "\n");
}

void help() {
    printf(YELLOW BOLD"\nBryte: " RESET NOFORMAT "a simple CLI to view or set your screen brightness.\n");
    printf("\nThis CLI was written to be simple and to fulfil the following tasks:\n");
    printf(ITALIC"\t $bryte -c " RESET "\t\tdisplays the current brightness level.\n");;
    printf(ITALIC"\t $bryte -s <num> " RESET "\tsets the <num> entered as the new brightness level.\n");
    printf(ITALIC"\t $bryte -i" RESET "\t\tincrements brightness by 5.\n");
    printf(ITALIC"\t $bryte -d" RESET "\t\tdecrements brightness by 5.\n");
    printf(ITALIC"\t $bryte -p" RESET "\t\tto test out compatibility with your system.\n");
    printf(ITALIC"\t $bryte -h" RESET "\t\tshows this help section.\n");
    printf(ITALIC"\t $bryte -v " RESET "\t\tdisplays version and other information.\n");
    printf("\nDisclaimer: This CLI works by editing %s\n", PATH);
    printf("\t    Refer to Arch Wiki for more information: %s\n", ARCH_WIKI);
}