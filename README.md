# Concept for Performance Prediction of AI Applications on Heterogeneous Edge Devices

This repository includes relevant programm and codes from thesis Concept for Performance Prediction of AI Applications on Heterogeneous Edge Devices

It is mainly divided into two parts, in the "host" folder are the programme running on the host machine, in the “on_ultra96" folder are the programme running on the ultra96. For this, it is also necessary to install the corresponding dependency library.

For programs running on the host machine, this requires Vitis AI to be installed. For programs running on ultra96, this requires DPU-PYNQ to be installed.


## Installation of Vitis AI on host machine

### 1. Preparation

- [Install Docker](docs/quick-start/install/install_docker/README.md) - if Docker not installed on your machine yet

- [Ensure your linux user is in the group docker](https://docs.docker.com/install/linux/linux-postinstall/)

- At least 100GB of disk space for the disk partition running Docker

- Clone the Vitis-AI repository 

```shell
git clone --recurse-submodules https://github.com/Xilinx/Vitis-AI  

cd Vitis-AI
```

### 2. Building Docker from Recipe

There are two types of docker recipes provided - CPU recipe and GPU recipe. If you have a compatible nVidia graphics card with CUDA support, you could use GPU recipe; otherwise you could use CPU recipe.

- CPU Docker

```shell
cd setup/docker
./docker_build_cpu.sh
```
To run the CPU docker, use command:

```shell
./docker_run.sh xilinx/vitis-ai-cpu:latest
```

- GPU Docker

```shell
cd setup/docker
./docker_build_gpu.sh
```
To run the GPU docker, use command:

```shell
./docker_run.sh xilinx/vitis-ai-gpu:latest
```



### 3. Lauch jupyter notebook

From inside the docker environment, activate tensorflow2 conda environment and the launch jupyter notebook.

```shell
conda activate vitis-ai-tensorflow2
jupyter notebook --ip=0.0.0.0 --port=8080
```



## Installation of pynq-dpu on Ultra96 

### 1.Preparation

To install the pynq-dpu on Ultra96, simply run:

```shell
pip3 install pynq-dpu --no-build-isolation
```

Then go to jupyter notebook home folder and fetch the notebooks:

```shell
cd $PYNQ_JUPYTER_NOTEBOOKS
pynq get-notebooks pynq-dpu -p .
```

This will make sure the desired notebooks shows up in jupyter notebook 
folder.

### 2. Run

Now in jupyter, you can explore the notebooks in `pynq-dpu` folder.




