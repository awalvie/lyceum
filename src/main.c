#include "helper.c"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_BUFFER 1024
#define DESCRIPTION_BUFFER 200
#define PAGE_NAME_BUFFER 100
#define FILE_PATH 256
#define CONTENT_BUFFER 8192

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
		"<a id='logo' href='./home.html'><img  src='../media/images/icon.jpg'></a>"
		"</header>";

char *html_footer = "</body></html>";

/* Pretty self explanatory */
typedef struct {
  int year, month, day;
} Date;

/* Structure for parsing the contents of the page */
typedef struct {
  char* name ;
  char* description;
  char* content;
	long date;
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
	char *files[FILE_PATH];
  int number_of_files;
} FileList;

Page createPage(){
	Page page;
	page.name = NULL;
	page.description = NULL;
	page.content = NULL;
	page.date = 0;
	return page;
}

/* return all file names in a directory in a array of strings */
void getFileNames(char *name, FileList *list) {
  DIR *dir;
  struct dirent *ent;
  list->number_of_files = 0;
  if ((dir = opendir(name)) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') {
          list->files[list->number_of_files] = ent->d_name;
          list->number_of_files++;
        }
      }
    }
    closedir(dir);
}

void parseFile(const char *file_name) {
	char* name="";
  printf("%s\n", file_name);
  chdir("../content/");
	FILE *fp;
	fp = fopen(file_name, "r");
	if ( fp == NULL ){
		printf("error: could not open file %s\n", file_name);
		exit(-1);
	}
	printf("%s\n", file_name);
	fclose(fp);
}


void buildSite(FileList list) {
  int i;
  for (i = 0; i < list.number_of_files; i++) {
		parseFile(list.files[i]);
  }

}

int main(void) {

  FileList list;
	getFileNames("../content", &list);
	buildSite(list);

  return 0;
}
