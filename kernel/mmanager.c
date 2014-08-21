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
	printk("Number of page table entries: %u\n", pde_entries);
	printk("Physical Memory: %u MiB\n", ram_size/1024);
	

	page_table_entry *pte_table = PTE_TABLE_BEGIN;
	frame_table_entry *fte_table = FTE_TABLE_BEGIN;

	for(table_index = 0; table_index < pde_entries; table_index++){
		
		if (table_index * PAGE_SIZE > ram_size*1024)
			//TODO: as we are not planning virtual memory soon, I will only 
			//	initialize the amount of tables correspondent to the 
			//	physical memory total
			break;

		pte_table[table_index] = INITIAL_PTE_ENTRY | ( (FTE_TABLE_BEGIN + table_index) << 12);
		fte_table[table_index] = INITIAL_FTE_ENTRY;
 
	}

	printk("Initialized PTE/FTE entries: %u\n", table_index);
	printk("\n");

}


void *get_phys_addr(void *virtual_addr){

	unsigned long base;
	unsigned long offset;
	unsigned long *reference;

	base = (unsigned long)virtual_addr >> 12 & 0x03FF;
	offset = (unsigned long)virtual_addr & 0x0FFF;

	reference = (unsigned long *)(( PTE_TABLE_BEGIN + base ) & ~0x03FF);
	
	return (void*)((unsigned long)( FTE_TABLE_BEGIN + reference ) | offset);
	
}

/*
 * Allocate a process on memory
 */
void *allocate(unsigned long size){
	void *virtual_addr;
	unsigned int pages = size / PAGE_SIZE + 1;
	
	virtual_addr = allocate_virtual(pages);
	
	for (index=0; index < pages; index++){
		ADDRESS(PTE_TABLE_BEGIN[index]) + 
	}

	return virtual_addr;
	
}

