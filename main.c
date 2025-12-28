#include <stdio.h>
#include <string.h>

const static char *FLAG_START_PATH = "--start";
const static char *FLAG_START_PATH_SHORT = "-s";
const static char *FLAG_START_PATH_DEFAULT = "./";

const static char *FLAG_EXCLUDE_PATH = "--exclude-path";
const static char *FLAG_EXCLUDE_PATH_SHORT = "-e";

typedef struct {
  const char *start;
  const char *exclude;
} WalkCfg;

static int handle_path(WalkCfg *cfg) {
  printf("Handling path: %s\n", cfg->start);
  return 0;
}

WalkCfg parse_cfg(int argc, char *argv[]) {
  WalkCfg walk_cfg = {NULL, NULL};

  int i = 1;
  for (;;) {
    if (i >= argc) {
      break;
    };

    char *arg = argv[i];

    if (strcmp(arg, FLAG_START_PATH) == 0 ||
        strcmp(arg, FLAG_START_PATH_SHORT) == 0) {
      if (i + 1 >= argc) {
        break;
      }

      walk_cfg.start = argv[i + 1];

      i += 2;
      continue;
    }

    if (strcmp(arg, FLAG_EXCLUDE_PATH) == 0 ||
        strcmp(arg, FLAG_EXCLUDE_PATH_SHORT) == 0) {
      if (i + 1 >= argc) {
        break;
      }

      walk_cfg.exclude = argv[i + 1];

      i += 2;
      continue;
    }

    i++;
  };

  if (!walk_cfg.start) {
    walk_cfg.start = FLAG_START_PATH_DEFAULT;
  };

  return walk_cfg;
}

int main(int argc, char *argv[]) {
  WalkCfg walk_cfg = parse_cfg(argc, argv);

  if (handle_path(&walk_cfg) != 0) {
    printf("ERROR: handle_path\n");
  };
}
