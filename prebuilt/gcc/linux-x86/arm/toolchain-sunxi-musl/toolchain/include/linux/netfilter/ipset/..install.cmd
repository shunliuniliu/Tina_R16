cmd_/home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset/.install := bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/uapi/linux/netfilter/ipset ip_set.h ip_set_bitmap.h ip_set_hash.h ip_set_list.h; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/linux/netfilter/ipset ; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/generated/uapi/linux/netfilter/ipset ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset/$$F; done; touch /home/wangyaliang/workspace/tina/out/azalea-m2ultra/compile_dir/toolchain/linux-dev//include/linux/netfilter/ipset/.install