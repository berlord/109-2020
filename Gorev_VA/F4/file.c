#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>

struct chain // реализация списка файлов
{
	char *name;         // имя файла 
	struct chain *next; // указатель на следующий файл в списке
	                    // если следующего нет, то 0
	struct chain *prev; // указатель на предыдущий файл в списке
	                    // если предыдущего нет, то 0
};

struct chain *List1;
struct chain *List2;

/*
** Строит по полному адресу файла его название в последней директории:
** dir1/dir2/.../dirn/file -> file
** если имя файла или имя какой-то промежуточной директории оказалось пустым, возвращает 0
*/
char *file_name(char *filename);
char *file_name(char *filename)
{
	int i = 0;
	if (strlen(filename) == 0)
		return 0;
	if (filename[0] == '/')
		return 0;
	while (i < strlen(filename))
	{
		if (filename[i] == '/')
			return file_name(filename + i + 1);
		i++;
	}
	if (i == strlen(filename))
		return filename;
}

/*
** Запись файла в список файлов
** filename - имя записываемого файла
** filelist - указатель на какой-то элемент списка
** создается элемент chain между filelist и filelist->next
** возвращается 0, если запись прошла успешно и -1 иначе
*/
int write_in_filelist(char *filename, struct chain *filelist);
int write_in_filelist(char *filename, struct chain *filelist)
{
	struct chain *new_file;
	new_file = (struct chain*)malloc(sizeof(struct chain));
	new_file->name = filename;
	if ((new_file->next = filelist->next) == NULL)
		return -1;
	if ((new_file->prev = filelist) == NULL)
		return -1;
	if ((filelist->next = new_file) == NULL)
		return -1;
	return 0;
}

/*
**
*/
int create_list(const char *fpath, const struct stat *sb, int flag);
int create_list(const char *fpath, const struct stat *sb, int flag)
{
	printf("%s\n", fpath);
	return 0;
}

int main(void)
{
	//ftw("dir2", create_list, 20);
	List1 = (struct chain*)malloc(sizeof(struct chain));
	List1->name = "dir";
	List1->next = List1->prev = 0;
	printf("%s\n", List1->next);
	write_in_filelist("input.txt", List1);
	printf("%s\n", List1->next);
	return 0;
}
