#include "bryte.h"

const char* CURRENT_PATH     = "/sys/class/backlight/intel_backlight/brightness";
const char* MAX_PATH = "/sys/class/backlight/intel_backlight/max_brightness";

int current;
int max;

void set_value(const char* path, const int prop_value) {
    int fd;
    int numwrite;
    char prop[LEN];

    fd = open(path, O_WRONLY | O_TRUNC);
    if (fd == -1) {
        printf(RED "Unable to open:" RESET);
        printf(" %s\n", path);
    }

    numwrite = snprintf(prop, LEN, "%d", prop_value);

    if (write(fd, prop, numwrite) == -1) {
        printf(RED"Unable to write:" RESET);
        printf(" %s\n", path);
    }
}

int get_value(const char* path) {
    int fd;
    ssize_t numread;
    char prop[LEN];

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf(RED "Unable to open:" RESET);
        printf(" %s\n", path);
    }

    if ((numread = read(fd, prop, LEN)) == -1) {
        printf(RED "Unable to open:" RESET);
        printf(" %s\n", path);;
    }
    prop[numread] = '\0';

    return atoi(prop);
}

void proof_compatibility() {
    char temp[50];

    FILE *fp = popen(check, "r");
    fscanf(fp, "%s", temp);
    pclose(fp);

    if (strcmp(intel_card, temp) == 0) {
        printf(BOLD GREEN"Compatible! %s %s", RESET, NOFORMAT);
        printf("Bryte should work on your system.\n");
    }

    else {
        printf(BOLD RED"Not Compatible! %s %s", RESET, NOFORMAT);
        printf("Bryte isn't compatible with your backlight card.\n");
    }
}

int get_brightness(void) {
    current     = get_value(CURRENT_PATH);
    max = get_value(MAX_PATH);

    int percentage = ((float)current / max) * 100;

    printf("%d%%\n", percentage);

    return ((float)current / max) * 100;
}

void set_brightness(int value) {

    max = get_value(MAX_PATH);

    if (value >= MAX_VALUE) {
            value = MAX_VALUE;
        } 
        else if (value <= MIN_VALUE) {
            value = MIN_VALUE;
        }

    set_value(CURRENT_PATH, ((float)value / 100 * max));
}

void increment() {
    current     = get_value(CURRENT_PATH);
    max = get_value(MAX_PATH);

    int value = 0;

    int percentage = ((float)current / max) * 100;

    if (percentage >= MAX_VALUE) {
        exit(EXIT_SUCCESS);
    }
    else if (percentage <= MIN_VALUE) {
        exit(EXIT_SUCCESS);
    }
    else {
        value = percentage + STEP_VALUE;
        set_brightness(value);
    }
}

void decrement() {
    current     = get_value(CURRENT_PATH);
    max = get_value(MAX_PATH);

    int value = 0;

    int percentage = ((float)current / max) * 100;

    if (percentage <= MIN_VALUE) {
        exit(EXIT_SUCCESS);
    }
    else {
        value = percentage - STEP_VALUE;
        set_brightness(value);
    }
}

int main(int argc, char** argv) {
    int opt;
    int input;

    while ((opt = getopt(argc, argv, "cs:idphv")) != -1) {
        switch (opt) {
            case 'c':
                get_brightness();
                break;

            case 's':
                input = atoi(optarg);
                set_brightness(input);
                break;

            case 'i':
                increment();
                break;

            case 'd':
                decrement();
                break;

            case 'p':
                proof_compatibility();
                break;

            case 'h':
                help();
                break;

            case 'v':
                version();
                break;
        }
    }
}