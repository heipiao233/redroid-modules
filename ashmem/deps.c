#include <linux/mm.h>
#include <linux/kallsyms.h>
#include "get_kln.h"

typedef int (*shmem_zero_setup_ptr_t)(struct vm_area_struct *);
static shmem_zero_setup_ptr_t shmem_zero_setup_ptr = NULL;
int shmem_zero_setup(struct vm_area_struct *vma)
{
	kln_p kln = get_kln_p();
	if (kln == NULL) return -1;
	if (!shmem_zero_setup_ptr)
		shmem_zero_setup_ptr = (shmem_zero_setup_ptr_t) kln("shmem_zero_setup");
	return shmem_zero_setup_ptr(vma);
}

