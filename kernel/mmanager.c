#include "mmanager.h"
#include <kernel.h>
#include <kernelio.h>


/**
 * RAM map
 * 0x00100000 -> page directory entry
 * 0x01000000 -> general use memory
**/


/* ram size given in KiB */
void mm_initialize(unsigned int ram_size){
	unsigned long table_index;
	const unsigned long pde_entries = (unsigned long)(VIRTUAL_MEMORY_SIZE/PAGE_SIZE);
	
	printk("\n");	
	printk("Virtual Memory size: %u MiB\n", (unsigned int)(VIRTUAL_MEMORY_SIZE/(1024*1024)));
	printk("Page size: %u Bytes\n",PAGE_SIZE);
	printk("Number of page directory entries: %u\n", pde_entries);
	printk("Physical Memory: %u MiB\n", ram_size/1024);
	

	page_directory_entry *pde_table = PDE_TABLE_BEGIN;
	page_table_entry *pte_table = PTE_TABLE_BEGIN;

	for(table_index = 0; table_index < pde_entries; table_index++){
		
		if (table_index * PAGE_SIZE > ram_size*1024)
			//TODO: as we are not planning virtual memory soon, I will only 
			//	initialize the amount of tables correspondent to the 
			//	physical memory total
			break;

		pde_table[table_index] = INITIAL_PDE_ENTRY;
		pte_table[table_index] = INITIAL_PTE_ENTRY;

	}

	printk("Initialized PDE/PTE entries: %u\n", table_index);
	printk("\n");

	return pde_table;
}


