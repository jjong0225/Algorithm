#include <20170300.h>

int32_t main(int32_t argc, char *argv[])
{
	int32_t fd;

	if(argc!=2) {
		printf("Usage: editro <file>\n");
		return 0;
	}

	fd = open(argv[1], O_RDONLY|O_SYNC);
	if(fd<0) {
		printf("Error %d Unable to open %s\n", fd, argv[1]);
		return 0;
	}

	Elf64_Ehdr ehdr;
	Elf64_Shdr* sh_tbl;
	
	read_elf_header(fd, &ehdr);
	
    if(!is_elf(ehdr)) {
		return 0;
	}
	
	print_elf_header(ehdr);

	sh_tbl = malloc(ehdr.e_shentsize * ehdr.e_shnum);
	if(!sh_tbl) {
		printf("Failed to allocate %d bytes\n", (ehdr.e_shentsize * ehdr.e_shnum));
	}
	print_section_headers(fd, ehdr, sh_tbl);

	char dump_command[100] = "objcopy --dump-section .rodata=original_rodata "; // 47부터 파일 이름 넣기
	for(int i=0; argv[1][i] != 0; i++)
	{
		dump_command[47 + i] = argv[1][i];
		dump_command[47 + i + 1] = 0;
	}
	char update_command[100] = "objcopy --update-section .rodata=new_rodata "; // 44부터 파일 이름 넣기
	for(int i=0; argv[1][i] != 0; i++)
	{
		update_command[44 + i] = argv[1][i];
		update_command[44 + i + 1] = 0;
	}
	printf("%s\n", dump_command);
	printf("%s\n", update_command);

	system(dump_command);
	replace_string("original_rodata", "new_rodata");
	system(update_command);
	system("rm ./original_rodata ./new_rodata");


	return 0;

}

