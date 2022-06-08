#include "menu.h"
#include <string.h>
#include <stdlib.h>
#include "split.h"
#include <stdio.h>
#include <dirent.h>
#include "chars.h"
#include "conf.h"
#include "settings.h"
#include "useful.h"

char *strcasestr (const char *, const char *);

ssize_t showMenu (struct StrArray, struct Settings);
void    addDir   (char *, struct StrArray *);


void menu (struct Settings *s)
{
  struct StrArray files;
  files.size = 0;
  files.strings = NULL;

  // open all directories and subdirectories
  // add markdown files to files
  addDir(s->file, &files);


  ssize_t i = showMenu(files, *s);

  if (i == -1)
  {
    free(s->file);
    exit(0);
  }

  printf("%s\n", files.strings[i]);


  // free files
  if (files.size)
  {
    free(files.strings[0]);

    for (--files.size; files.size; files.size--)
    {
      free(files.strings[files.size]);
    }
  }
  free(files.strings);

  // default ***WILL CHANGE***
  s->file = realloc(s->file, sizeof("./README.md"));
  strcpy(s->file, "./README.md");

  free(s->file);
  exit(1);
}

ssize_t showMenu (struct StrArray files, struct Settings s)
{
  printf(DEF_C SETUP);

  char c = 0;
  size_t offset = 0;

  s.win_rows--;

  while (c != 'q')
  {
    printf(REFRESH);

    // draw text
    for (size_t i = 0; i<(s.win_rows/2) && (i+offset)<files.size; i++)
    {
      printf("\n " BOX_C);

      if (!i)
      {
          printf(HBAR HBAR);
      }
      else
      {
        printf(VBAR);
      }

      printf(BOX_TEXT_C " %s\n", files.strings[i+offset]);
    }

    c = keypress();
  }

  printf(END);

  return -1;
}

void addDir (char *path, struct StrArray *files)
{
  struct dirent *pDirent;
  DIR *pDir;

  // open dir
  pDir = opendir(path);

  // leave if you can't open the dir
  if (pDir == NULL)
    return;

  char *hold = NULL;

  while ((pDirent = readdir(pDir)) != NULL)
  {
    if (pDirent->d_name[0] == '.')
      continue;

    if (pDirent->d_type == DT_DIR)
    {
      hold = realloc(hold, (strlen(path) + strlen(pDirent->d_name) + 2) * sizeof(char));
      strcpy(hold, path);
      strcat(hold, "/");
      strcat(hold, pDirent->d_name);

      addDir(hold, files);
    }
    else if (pDirent->d_type == DT_REG && strcasestr(pDirent->d_name, ".md"))
    {
      files->size++;
      files->strings = realloc(files->strings, files->size * sizeof(char*));
      files->strings[files->size-1] = malloc(strlen(path) + strlen(pDirent->d_name) + 2);

      strcpy(files->strings[files->size-1], path);
      strcat(files->strings[files->size-1], "/");
      strcat(files->strings[files->size-1], pDirent->d_name);
    }
  }

  free(hold);

  closedir(pDir);
}
