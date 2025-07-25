#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Angel");
MODULE_DESCRIPTION("Un simple módulo de ejemplo");

static int __init mi_init(void){
    printk(KERN_INFO "Hola mundo bético\n");
    return 0;
}

static void __exit mi_exit(void){
    printk(KERN_INFO "Adiós mundo palangana\n");
}

module_init(mi_init);
module_exit(mi_exit);
