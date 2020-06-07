#include "helper.c"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_BUFFER 1024

char *html_header =
    "<html lang='en'><head><meta charset='UTF-8'><meta name='description' "
    "content='an island of personal thought'><meta name='viewport' "
    "content='width=device-width' initial-scale=1.0><title>%s</title><link "
    "rel='stylesheet' type='text/css' "
    "href='../style/main.css'></head><body>";

char *html_footer = "</body></html>";

/* Structure for reading the entire contents of a page */
typedef struct {
  char *name;
  char *date;
  char *category;
  char *tags[];
} Page;

/* Structure for getting list of files in a directory */
typedef struct {
  char *files[FILE_BUFFER];
  int number_of_files;
} FileList;

/* fetch all the the files in a specificed directory into a FileList structure
 */
void getFileNames(char *name, FileList *list) {
  DIR *dir;
  struct dirent *ent;
  list->number_of_files = 0;
  if ((dir = opendir(name)) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      if (!(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)) {
        list->files[list->number_of_files] = ent->d_name;
        list->number_of_files++;
      }
    }
    closedir(dir);
  } else {
    perror("");
    exit(EXIT_FAILURE);
  }
}

/* take an array of strings with file names as input, add the header, and footer */
void buildSite(FileList *list) {
  FILE *common_file;
  int i;
	printf("%d\n", list->number_of_files);
  for (i = 0; i < list->number_of_files; i++) {
    char *full_path;
    full_path = concat("../site/", list->files[i]);
    common_file = fopen(full_path, "w");
    fprintf(common_file, html_header, "Lyceum");
		fputs("<h1>Is this working?</h1>", common_file);
		fputs(html_footer, common_file);
		fclose(common_file);
    free(full_path);
  }
}

int main(void) {
  FileList list;
  getFileNames("../content", &list);
  buildSite(&list);
  return 0;
}
