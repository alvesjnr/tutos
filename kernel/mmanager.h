#ifndef _MMANAGER_H
#define _MMANAGER_H

#define PTE_TABLE_SIZE		4*1024
#define FTE_TABLE_SIZE		4*1024

#define PTE_TABLE_BEGIN		0x00100000
#define FTE_TABLE_BEGIN		(PTE_TABLE_BEGIN + PTE_TABLE_SIZE)
#define GENERAL_MEMORY_BEGIN	0x01000000

typedef unsigned char	byte;

typedef unsigned int page_table_entry;
typedef unsigned int frame_table_entry;

#define PAGE_TABBLE_ADDRESS(pde) pde >> 11
#define PHYSICAL_PAGE_ADDRESS(pte) pte >> 11

#define CHECK_FLAG(flags,bit)   (byte)((flags) & (1 << (bit)))

static inline void set_bit(unsigned int *x, int bit) {
	*x |= (1L << bit);
}

static inline void clear_bit(unsigned int *x, int bit) {
	*x &= ~(1L << bit);
}

static inline void toggle_bit(unsigned int *x, int bit){
	*x ^= (1L << bit);
}

#define PTE_PRESENT(pde)	CHECK_FLAG(pde,0)
#define PTE_READ_WRITE(pde)	CHECK_FLAG(pde,1)
#define PTE_USER_ACCESS(pde)	CHECK_FLAG(pde,2)
#define PTE_WRITE_THROUGH(pde)	CHECK_FLAG(pde,3)
#define PTE_CACHE_DISABLE(pde)	CHECK_FLAG(pde,4)
#define PTE_ACCESSED(pde)	CHECK_FLAG(pde,5)
#define PTE_PAGE_SIZE(pde)	CHECK_FLAG(pde,7)

//                                                  GS0ADWURP
#define INITIAL_PTE_ENTRY ((page_table_entry)(0b000010110))

//                                                  G0DACWURP
#define INITIAL_FTE_ENTRY ((frame_table_entry)(0b000010110))

#define ADDRESS(addr)	((addr >> 12) & 0x03FF)

/* prototypes */

void mm_initialize(unsigned int ram_size);


#endif //_MMANAGER_H
