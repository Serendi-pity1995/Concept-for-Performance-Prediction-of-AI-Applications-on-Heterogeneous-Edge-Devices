#Generate Pre-processor xo file
export CUR_DIR=$PWD
cd $CUR_DIR/../../../../plugins/blobfromimage/pl
make cleanall
make xo TARGET=hw BLOB_CHANNEL_SWAP_EN=0 BLOB_CROP_EN=0 BLOB_LETTERBOX_EN=0 BLOB_JPEG_EN=0

#Generate xclbin
cd $CUR_DIR
make clean
make all blob_ACCEL=../../../../plugins/blobfromimage/pl DPU_XO=../../../../../dsa/DPUCADF8H-XO/projects/ml_shell/xo_release/