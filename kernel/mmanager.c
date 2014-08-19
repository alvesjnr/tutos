#include "mmanager.h"
#include <kernel.h>
#include <kernelio.h>

/* ram size given in KiB */
void *mm_initialize(unsigned int ram_size){
	unsigned long pde_index;
	const unsigned long pde_entries = (unsigned long)(VIRTUAL_MEMORY_SIZE/PAGE_SIZE);
	
	printk("\n");	
	printk("Virtual Memory size: %u MiB\n", (unsigned int)(VIRTUAL_MEMORY_SIZE/(1024*1024)));
	printk("Page size: %u Bytes\n",PAGE_SIZE);
	printk("Number of page directory entries: %u\n", pde_entries);
	printk("Physical Memory: %u MiB\n", ram_size/1024);

	page_directory_entry pde_table[pde_entries];

	for(pde_index = 0; pde_index < pde_entries; pde_index++){
		//cls();
		//printk("pde: 0x%x\n\n",&(pde_table[pde_index]));
		//pde_table[pde_index] = 10;
	}

	return pde_entries;
}
		

