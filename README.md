# LPK (Linux Package Manager)

## 文件后缀

*.lpk

## 需要实现的指令（基础）
- **安装lpk文件**
```shell
lpk install [package]
```
or
```shell
lpk -i [package]
```

- **卸载已安装的安装包**
  
```shell
lpk uninstall [pkName]
```
or
```shell
lpk -u [pkName]
```
Linux中卸载已安装的安装包  

- **打包安装包**
```shell
lpk pkg [directory]
```
``` shell
lpk -P [directory]
```
tips: 此指令会在使用的文件目录下生成一个lpk包

- **解包某个安装包**
```shell
lpk unpkg [package] [directory]
```
```shell
lpk -p [package] [directory]
```

- **显示当前已经安装的安装包**
```shell
lpk list
```
```shell
lpk -l
```

- **显示帮助**
```shell
lpk help
```
```shell
lpk -h
```

- **显示版本**
```shell
lpk version
```
```shell
lpk -v
```

## 实现基础逻辑
- **打包方式**  
采用tar打包方式，将文件打包入tar.xz的包中
- **安装逻辑**  
当文件进行安装的时候，会将elf文件（可执行的文件）放入`${HOME}/.local/bin/`目录下   
当文件有依赖项时，根据`binary.list`的描述，将相应文件放入`${HOME}/.local/lib/${APPLICATION_NAME}`文件夹下  
然后将配置文件放入`${HOME}/.config/${APPLICATION_NAME}`文件夹下  
然后将应用的图标放入`${HOME}/.icon/applications/${APPLICATION_NAME}`文件夹下  
最后在`${HOME}/Desktop`和`${HOME}/.local/share/applications`下创建相应的desktop文件。

- **文件结构**
```text
|---LPK.info
|---LPK
    |---binaries
    |   |---binary.list
    |   |---**(binary files)
    |
    |---configurations
    |   |---config.list   
    |   |---**.config
    |
    |---icons
        |---icon.list
        |---**.svg
        |---**.ico
```
- `LPK.info`: 此文件描述了这个安装包的作者、打包时间、文件大小、版本信息  
- `LPK`: 文件夹，包含了即将安装的应用内容  
- `binaries`: 文件夹，包含了即将安装应用的所有的可执行文件
- `binary.list`: 描述了可执行文件应当放在哪里，以及描述了哪一个二进制文件是主驱动程序
- `**(binary files)`：二进制文件，可执行的文件
- `configurations`: 文件夹，放置安装应用的配置文件  
- `config.list`: 描述了文件需要的配置文件
- `**.config`：安装的应用的配置文件  
- `icons`：文件夹，放置安装应用所需要的图标
- `icon.list`：描述了文件所需要的图标