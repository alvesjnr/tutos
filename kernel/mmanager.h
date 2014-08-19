#ifndef _MMANAGER_H
#define _MMANAGER_H


#define PDE_TABLE_BEGIN		0x00100000
#define GENERAL_MEMORY_BEGIN	0x01000000



typedef unsigned char	byte;


typedef unsigned int page_directory_entry;
typedef unsigned int page_table_entry;

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

#define PDE_PRESENT(pde)	CHECK_FLAG(pde,0)
#define PDE_READ_WRITE(pde)	CHECK_FLAG(pde,1)
#define PDE_USER_ACCESS(pde)	CHECK_FLAG(pde,2)
#define PDE_WRITE_THROUGH(pde)	CHECK_FLAG(pde,3)
#define PDE_CACHE_DISABLE(pde)	CHECK_FLAG(pde,4)
#define PDE_ACCESSED(pde)	CHECK_FLAG(pde,5)
#define PDE_PAGE_SIZE(pde)	CHECK_FLAG(pde,7)

//                                                  GS0ADWURP
#define INITIAL_PDE_ENTRY ((page_directory_entry)(0b000010110))

#endif //_MMANAGER_H
