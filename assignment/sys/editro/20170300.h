#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <elf.h>

bool is_elf(Elf64_Ehdr eh);
void read_elf_header(int32_t fd, Elf64_Ehdr *elf_header);
void print_elf_header(Elf64_Ehdr elf_header);
char *read_section(int32_t fd, Elf64_Shdr sh);
void print_section_headers(int32_t fd, Elf64_Ehdr eh, Elf64_Shdr sh_table[]);

//Implement this function to check whether an input file is an elf file or not.
bool is_elf(Elf64_Ehdr eh)
{
	if(eh.e_ident[EI_MAG0] == 0x7F && eh.e_ident[EI_MAG1] == 'E' && eh.e_ident[EI_MAG2] == 'L' && eh.e_ident[EI_MAG3] == 'F')
		return true;
	else
		return false;
}


void replace_string(char *original_file, char *new_file)
{
	int original_fd = open(original_file, O_RDONLY|O_SYNC);
	int new_fd = open(new_file, O_RDWR|O_CREAT|O_TRUNC, 0777);

	char *original_str = "software";
	char *new_str = "hackers!";
	int original_str_len = 8;
	int new_str_len = 8;

	char input_buffer[10000] = {0};
	char output_buffer[10000] = {0};
	int input_len = read(original_fd, input_buffer, 10000-1);

	int output_idx = 0;
	int input_idx = 0;

	while(input_idx<input_len)
	{
		if(input_idx + original_str_len-1 < input_len)
		{
			bool cmp_flag = true; 
			for(int i=0; i<original_str_len; i++)
			{
				if(input_buffer[input_idx + i] != original_str[i])
				{
					cmp_flag = false;
					break;
				}
			}
			if(cmp_flag == true)
			{
				for(int i=0; i<new_str_len; i++)
				{				
					output_buffer[output_idx + i] = new_str[i];
				}
				output_idx = output_idx + new_str_len;
				input_idx = input_idx + original_str_len;
				continue;
			}
		}
		output_buffer[output_idx++] = input_buffer[input_idx++];
	}

	write(new_fd, output_buffer, output_idx);
	close(original_fd);
	close(new_fd);
}

void read_elf_header(int32_t fd, Elf64_Ehdr *elf_header)
{
	assert(elf_header != NULL);
	assert(lseek(fd, (off_t)0, SEEK_SET) == (off_t)0);
	assert(read(fd, (void *)elf_header, sizeof(Elf64_Ehdr)) == sizeof(Elf64_Ehdr));
}

void print_elf_header(Elf64_Ehdr elf_header)
{
	printf("Storage class\t= ");
	switch(elf_header.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("32-bit objects\n");
			break;

		case ELFCLASS64:
			printf("64-bit objects\n");
			break;

		default:
			printf("Unknwon CLASS\n");
			break;
	}

	printf("Data format\t= ");
	switch(elf_header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;

		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;

		default:
			printf("Unknwon Format\n");
			break;
	}

	printf("OS ABI\t\t= ");
	switch(elf_header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;

		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;

		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;

		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;

		case ELFOSABI_SOLARIS:
			printf("Sun Solaris\n");
			break;

		case ELFOSABI_AIX:
			printf("IBM AIX\n");
			break;

		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;

		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;

		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;

		case ELFOSABI_MODESTO:
			printf("Novell Modesto\n");
			break;

		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;

		case ELFOSABI_ARM_AEABI:
			printf("ARM EABI\n");
			break;

		case ELFOSABI_ARM:
			printf("ARM\n");
			break;

		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) app\n");
			break;

		default:
			printf("Unknown (0x%x)\n", elf_header.e_ident[EI_OSABI]);
			break;
	}

	printf("Filetype \t= ");
	switch(elf_header.e_type)
	{
		case ET_NONE:
			printf("N/A (0x0)\n");
			break;

		case ET_REL:
			printf("Relocatable\n");
			break;

		case ET_EXEC:
			printf("Executable\n");
			break;

		case ET_DYN:
			printf("Shared Object\n");
			break;
		default:
			printf("Unknown (0x%x)\n", elf_header.e_type);
			break;
	}

	printf("Machine\t\t= ");
	switch(elf_header.e_machine)
	{
		case EM_NONE:
			printf("None (0x0)\n");
			break;

		case EM_386:
			printf("INTEL x86 (0x%x)\n", EM_386);
			break;

		case EM_X86_64:
			printf("AMD x86_64 (0x%x)\n", EM_X86_64);
			break;

		case EM_AARCH64:
			printf("AARCH64 (0x%x)\n", EM_AARCH64);
			break;

		default:
			printf(" 0x%x\n", elf_header.e_machine);
			break;
	}
	printf("\n");
}

char *read_section(int32_t fd, Elf64_Shdr sh)
{
	char* buff = malloc(sh.sh_size);
	if(!buff) {
		printf("%s:Failed to allocate %ldbytes\n",
				__func__, sh.sh_size);
	}

	assert(buff != NULL);
	assert(lseek(fd, (off_t)sh.sh_offset, SEEK_SET) == (off_t)sh.sh_offset);
	assert(read(fd, (void *)buff, sh.sh_size) == sh.sh_size);

	return buff;
}

void print_section_headers(int32_t fd, Elf64_Ehdr eh, Elf64_Shdr sh_table[])
{
	uint32_t i;
	char* sh_str;

	assert(lseek(fd, (off_t)eh.e_shoff, SEEK_SET) == (off_t)eh.e_shoff);

	for(i=0; i<eh.e_shnum; i++) {
		assert(read(fd, (void *)&sh_table[i], eh.e_shentsize) == eh.e_shentsize);
	}

	/* section-header string-table */
	sh_str = read_section(fd, sh_table[eh.e_shstrndx]);

	for(i=0; i<eh.e_shnum; i++) {
		if(!strncmp((sh_str + sh_table[i].sh_name), ".rodata", 7))
		{
			printf("%s section info\n", (sh_str + sh_table[i].sh_name));
			printf("    file offset = 0x%08lx\n", sh_table[i].sh_offset);
			printf("           size = 0x%08lx\n", sh_table[i].sh_size);
		}
	}

}
