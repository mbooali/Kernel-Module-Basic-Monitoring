#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/atomic.h>
#include <linux/sys.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/sched.h>
#include <linux/file.h>
#include <linux/jiffies.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/seq_file.h>
#include <linux/seqlock.h>
#include <linux/pid_namespace.h>


#define LOAD_INT(x) ((x) >> FSHIFT)
#define LOAD_FRAC(x) LOAD_INT (((x) & (FIXED_1-1)) * 100)

static struct proc_dir_entry *infop;
static int a = 0;
static int b = 0;


static int proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int i;
	int len = 0;
	struct timeval currentTime;	
	do_gettimeofday(&currentTime);

	time_t curr = currentTime.tv_sec;
	while ( currentTime.tv_sec < curr + b)
	{
		do_gettimeofday(&currentTime);
	}
        len = sprintf(page, "CurrentTime : %d\n",currentTime.tv_sec);		
	return len;
}

static int proc_write(struct file *file, const char *buffer, unsigned long count, void *data)
{
	sscanf(buffer, "%d %d", &a, &b);
	return count;
}

int init_module(void)
{
	infop = create_proc_entry("oslab", 0444, (struct proc_dir_entry *) 0);
	if(infop == 0)
		return -EINVAL;
	infop->owner = THIS_MODULE;
	infop->read_proc = proc_read;
	infop->write_proc = proc_write;
	return 0; 
}

void cleanup_module(void)
{
	printk("<1>Goodbye everyone.\n");
}
MODULE_LICENSE("GPL");
