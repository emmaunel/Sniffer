#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init main_init(void){
    printk(KERN_INFO "HElllo\n");
    return 0;
}

static void __exit main_exit(void){
    printk(KERN_INFO "Bye\n");
}

module_init(main_init);
module_exit(main_exit);
