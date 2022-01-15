# About Anaconda

## Step 1: Install Wget

```bash
$ sudo apt update
$ sudo apt install wget
$ wget -V
```

## Step 2: Download the Latest Version of Anaconda

The latest version of Anaconda is 2021.11 at this example. Get the latest version and its checksum at [HERE](https://docs.anaconda.com/anaconda/install/hashes/all/).

```bash
$ wget https://repo.anaconda.com/archive/Anaconda3-2021.11-Linux-x86_64.sh
$ sha256sum Anaconda3-2021.11-Linux-x86_64.sh
# The checksum should match the checksum provided by previous link
```

## Step 3: Install Anaconda

```sh
$ sudo bash Anaconda3-2021.11-Linux-x86_64.sh
### sample output ###
# Welcome to Anaconda3 2020.02

# In order to continue the installation process, please review the license
# agreement.
# Please, press ENTER to continue
# >>> ENTER
# Do you approve the license terms? [yes|no] yes
# Anaconda3 will now be installed into this location:
# /root/anaconda3

#     - Press ENTER to confirm the location
#     - Press CTRL-C to abort the installation
#     - Or specify a different location below
# [/root/anaconda3] >>> /opt/anaconda3 # example of specify path
# Installation finished.
# Do you wish the installer to initialize Anaconda3
# by running conda init? [yes|no] yes # init conda to system PATH
```

## Step 4: Initialize Anaconda to User PATH

This is the example of the bash and anaconda is installed at /opt/anaconda3.

Add following line into ```~/.bashrc```
```sh
# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/opt/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/opt/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/opt/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/opt/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

# Show present conda environment in the prompt
PS1="(${CONDA_DEFAULT_ENV}) \[\033[01;32m\]\u\[\e[33m\]@\[\033[01;31m\]\h \[\033[36m\]\W \[\033[00m\]\$ "
```

Confirm the setting
```sh
$ source ~/.bashrc
### sample output ###
# (base) USER_NAME@DOMAIN_NAME ~ $ 
```

## Start using Anaconda

### Create a new anaconda environment

```bash
$ conda create --name ENV_NAME python=3.7
```

### Activate the anaconda environment

```bash
$ conda activate ENV_NAME
```

### Detach the anaconda environment

```bash
$ conda deactivate
```

### Remove the anaconda environment

```bash
$ conda env remove --name ENV_NAME
```

## Shorten Anaconda Command

Add following line into ```~/.bashrc```

```bash
cpyenv() {
	default_env="DEFAULT_ENV"
	if [ -n "${2}" ]; then
		default_env="${2}"
	fi
	if [ "${1}" = "-a" ]; then
		conda activate "${default_env}"
	elif [ "${1}" = "-d" ]; then
		conda deactivate
	else
		printf "usage: cpyenv [-a venv_name | -d]\n\noption:\n"
		printf "\t-a\tactivate python environment\n"
		printf "\t-d\tdeactivate python environment\n"
	fi
}
```
