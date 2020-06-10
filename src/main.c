#include "helper.c"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_BUFFER 1024
#define DESCRIPTION_BUFFER 150
#define PAGE_NAME_BUFFER 20
#define FILE_PATH 50
#define CONTENT_BUFFER 32678

char *html_head =
    "<html lang='en'>\n"
    "<head><meta charset='UTF-8'>\n"
    "<meta name='description'content='an island of personal thought'>\n"
    "<meta name='viewport'content='width=device-width' initial-scale=1.0>\n"
    "<title>Lyceum</title>\n"
    "<link rel='stylesheet' type='text/css' href='../media/css/style.css'>\n"
    "</head>\n"
    "<body>\n";

char *html_header =
		"<header >"
		"<a id='logo' href='../site/home.html'><img  src='../media/images/icon_invert.jpg'></a>"
		"</header>";

char *html_footer = "</body></html>";

/* Pretty self explanatory */
typedef struct {
  int year, month, day;
} Date;

/* Structure for parsing the contents of the page */
typedef struct {
  char name[PAGE_NAME_BUFFER];
  Date date;
  char description[DESCRIPTION_BUFFER];
  char content[CONTENT_BUFFER];
} Page;

/* Structure for getting list of files in a directory */
typedef struct {
  char *files[FILE_BUFFER];
  int number_of_files;
} FileList;

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

/* return all file names in a directory in a array of strings */
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
    perror("DIRECTORY DOES NOT EXIST");
    exit(EXIT_FAILURE);
  }
}

Page parseFile(char *file_name) {

  FILE *fp;
  Page page;
  long date;
  char *full_path;
  long metadata_position, content_len;
  full_path = concat("../content/", file_name);
  fp = fopen(full_path, "r");

  if (!fp) {
    perror("File does not exist");
    exit(EXIT_FAILURE);
  }

  /* Reading the metadata on top of the file */
  fgets(page.name, PAGE_NAME_BUFFER, fp);
  /* Remove trailing newline character */
  strtok(page.name, "\n");
  /* read description */
  fgets(page.description, DESCRIPTION_BUFFER, fp);
  /* read date */
  fscanf(fp, "%ld\n", &date);
  page.date = to_date(date);

  /* take the cursor to where the content of the file starts */
  metadata_position = ftell(fp);
  fseek(fp, metadata_position, SEEK_END);
  content_len = ftell(fp);
  fseek(fp, metadata_position, SEEK_SET);

  /*Reading the main content of the file*/
  char *content = malloc(content_len + 1);
  fread(content, 1, content_len, fp);
  content[content_len] = 0;

  int i;
  for (i = 0; i < content_len; i++) {
    page.content[i] = content[i];
  }

  free(full_path);
  free(content);
  fclose(fp);
  return page;
}

void buildSite(FileList *list) {
  int i;
  char *html_path;
  FILE *fp;
  for (i = 0; i < list->number_of_files; i++) {
    Page page;
    printf("%s\n", list->files[i]);
    page = parseFile(list->files[i]);
    html_path = concat(concat("../site/", page.name), ".html");
    fp = fopen(html_path, "w");
    fputs(html_head, fp);
		fputs(html_header, fp);
    fputs(page.content, fp);
    fputs(html_footer, fp);
    fclose(fp);
  }
}

int main(void) {
  FileList list;
  getFileNames("../content", &list);
  buildSite(&list);

  return 0;
}
