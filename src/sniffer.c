#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static struct dentry *file;
static struct dentry *subdir;

static int keys_pressed(struct notifier_block *nblock,
                        unsigned long code,
                        void *_param);
                      
static ssize_t dev_read(struct file *filp,
                        char *buffer,
                        size_t len,
                        loff_t *offset);
                        
                        
static int __init sniffer_init(void){
    return 0;
}

static void __exit sniffer_exit(void){

}

module_init(sniffer_init);
module_exit(sniffer_exit);
