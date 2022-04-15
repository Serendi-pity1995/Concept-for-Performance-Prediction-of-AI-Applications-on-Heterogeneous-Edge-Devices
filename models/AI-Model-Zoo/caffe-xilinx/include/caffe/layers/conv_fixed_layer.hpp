/*
* Copyright 2019 Xilinx Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef CAFFE_CONV_FIXED_LAYER_HPP_
#define CAFFE_CONV_FIXED_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

#include "caffe/layers/conv_layer.hpp"

namespace caffe {

/*
 * This layer directly inherits ConvolutionLayer
*/
template <typename Dtype>
class ConvolutionFixedLayer : public ConvolutionLayer<Dtype> {
 public:
  explicit ConvolutionFixedLayer(const LayerParameter& param)
      : ConvolutionLayer<Dtype>(param), fixed_(false) {}
  void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) override;
  void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) override;

  inline const char* type() const override {
      return "ConvolutionFixed"; }

 protected:
  void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) override;
  void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) override;
  void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down,
      const vector<Blob<Dtype>*>& bottom) override;
  void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down,
      const vector<Blob<Dtype>*>& bottom) override;

  bool enable_fix_;
  bool fixed_;
  FixedParameter_FixedMethod fixed_method_;
  int bit_width_;
  int weight_dec_pos_;
  int bias_dec_pos_;

  shared_ptr<Layer<Dtype> > fixed_forward_conv_layer_;

};

#endif

}  // namespace caffe
