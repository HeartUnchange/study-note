# archlinux 实机安装

整体参考： [知其所以然：在 VirtualBox 里安装 Arch Linux 操作系统](https://www.jianshu.com/p/98b8965b1d10), 这里只补充部分不同的点。

1. U盘名称
在boot启动过程，有一个mount disk by label的操作， 提示说ARCH_201803找不到。主要是用[deepin-boot-maker](http://cdimage.deepin.com/applications/deepin-boot-maker/windows/deepin-boot-maker.exe
)制作的启动盘， U盘名称被置为```DEEPIN```， 然后boot时就识别不到了，，自己手动改一下名称就好了。

2. 连接wifi
需要一个英文名的wifi， 即ssid为英文字母
参考[Wireless network configuration](https://wiki.archlinux.org/index.php/Wireless_network_configuration#Example)
首先```ip a```查看所有的网卡, 确定无线网卡名, 假定为```wlo1```
```sh
ip link set wlo1 up
```
启用名为wlo1的网卡，后连接
```sh
wpa_supplicant -B -i wlo1 -c <(wpa_passphrase MYSSID passphrase)
```
提供MYSSID（wifi名）和passphrase（密码）
之后获取ip
```sh
dhcpcd interface
```

3. 安装grub识别不到原有的系统
除了grub，需要额外安装```os-prober```， 然后在```grub-mkconfig```，就可以了。

4. 添加信任证书
将```*.crt```文件放到```/etc/ca-certificates/trust-source/anchors/```, 然后执行```trust extract-compat```.
