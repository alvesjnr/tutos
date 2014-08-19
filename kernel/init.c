/*
tutOS - Tutorial Operating System.
Copyright (C) 2014  Antonio Ribeiro Alves

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include <kernelio.h>
#include <multiboot.h>

#include "mmanager.h"

void kmain(struct multiboot_info *mbi){
	
	printk("tutOS - Tutorial Operating System.\n\n");

	printk("mem lower: %uKB\n", (unsigned) mbi->mem_lower);
	printk("mem upper: %uKB\n", (unsigned) mbi->mem_upper);

	page_directory_entry *pde_table;

	pde_table = mm_initialize(mbi->mem_upper - mbi->mem_lower, 700*1024);//for test: using 200MiB of RAM, starting from 
	printk("pde address: 0x%x\n",pde_table);

}
