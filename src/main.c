/* necessary to use strdup */
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#define NAME_BUFFER 50
#define DESCRIPTION_BUFFER 256
#define CONTENT_BUFFER 16384

#include "helper.c"
#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_BUFFER 1024

char *html_head =
    "<html lang='en'>\n"
    "<head><meta charset='UTF-8'>\n"
    "<meta name='description'content='an island of personal thought'>\n"
    "<meta name='viewport'content='width=device-width' initial-scale=1.0>\n"
    "<title>Lyceum</title>\n"
    "<link rel='stylesheet' type='text/css' href='../static/main.css'>\n"
    "</head>\n"
    "<body>\n";

char *html_header =
    "<header >"
    "<a id='logo' href='index.html'><img src='../static/images/icon.jpg'></a>"
    "</header>";

char *html_footer = "</body></html>";

/* Pretty self explanatory */
typedef struct {
  int year, month, day;
} Date;

/* Structure for parsing the contents of the page */
typedef struct {
  char name[NAME_BUFFER];
  char description[DESCRIPTION_BUFFER];
  char content[CONTENT_BUFFER];
  Date date;
} Page;

/* fetch all the the files in a specificed directory into a FileList structure
 */
Date to_date(long unformatted) {
  Date date;
  date.day = unformatted % 100;
  unformatted = unformatted / 100;
  date.month = unformatted % 100;
  unformatted = unformatted / 100;
  date.year = unformatted;
  return date;
}

/* Structure for getting list of files in a directory */
typedef struct {
  char *files[FILENAME_MAX];
  int number_of_files;
} FileList;

/* return all file names in a directory in a array of strings */
void getFileNames(const char *name, FileList *list) {
  DIR *dir;
  struct dirent *entry;

  dir = opendir(name);
  if (dir == NULL) {
    perror("opendir");
    exit(-1);
  }

  while ((entry = readdir(dir))) {
    if ((entry->d_name[0] != '.')) {
      char *name = strdup(entry->d_name);
      list->files[list->number_of_files] = name;
      list->number_of_files++;
    }
  }
  closedir(dir);
}

void freeFileList(FileList list) {
  int i;
  for (i = 0; i < list.number_of_files; i++) {
    free(list.files[i]);
  }
}

Page newPage() {
  Page page;
  memset(page.name, 0, sizeof(page.name));
  memset(page.description, 0, sizeof(page.description));
  memset(page.content, 0, sizeof(page.content));
  return page;
}

FileList new_list() {
  FileList list;
  list.number_of_files = 0;
  return list;
}

Page parseFile(char *file_name) {
  Page page;
  long date;
  char *full_path = concat("../content/", file_name);
  FILE *fp;
  if ((fp = fopen(full_path, "r")) == NULL) {
    printf("could not open file %s\n", full_path);
  }
  /* get name from the first line */
  fgets(page.name, NAME_BUFFER, fp);
  strtok(page.name, "\n");

  /* get description from the second line */
  fgets(page.description, DESCRIPTION_BUFFER, fp);
  strtok(page.description, "\n");

  /* get date from third line */
  fscanf(fp, "%ld", &date);
  page.date = to_date(date);

  int c;
  int j = 0;
  while ((c = fgetc(fp)) != EOF) {
    page.content[j] = c;
    j++;
  }
  page.content[j] = '\0';

  free(full_path);
  fclose(fp);
  return page;
}

void removeFileExtension(char *file_name) {

  int j = 0;
  while (file_name[j] != '.') {
    j++;
  }
  file_name[j] = '\0';
}

void buildSite(FileList *list) {
  int i;
  for (i = 0; i < list->number_of_files; i++) {

    Page page;
    page = parseFile(list->files[i]);
    /* remove the .txt extension from the file name */
    char *file_name = list->files[i];
    removeFileExtension(file_name);
    /* full path of the final file */
    char *full_path = concat(concat("../docs/", file_name), ".html");
    puts(full_path);

    FILE *fp;
    fp = fopen(full_path, "w");
    fputs(html_head, fp);
    fputs(html_header, fp);
    fprintf(fp, "<h1>%s</h1>", page.name);
    fputs(page.content, fp);
    fputs(html_footer, fp);

    fclose(fp);
    free(full_path);
  }
}

int main(void) {

  FileList list = new_list();
  getFileNames("../content/", &list);
  buildSite(&list);
  freeFileList(list);

  return 0;
}
