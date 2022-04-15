

#
# Copyright 2019 Xilinx Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import torch
import numpy as np
from torch.nn.utils.rnn import PackedSequence
import torch.nn as nn

def deephi_pack_padded_sequence(input, lengths, batch_first=False):
  if isinstance(lengths, list):
    lengths = torch.LongTensor(lengths)
  data = input
  if not batch_first:
    batch_sizes = np.ones(input.size(0)) * input.size(1)
  else:
    batch_sizes = np.ones(input.size(1)) * input.size(0)
  return PackedSequence(data, batch_sizes)

def deephi_pad_packed_sequence(sequence,
                               batch_first=False,
                               padding_value=0.0,
                               total_length=None):
  output = sequence
  if not batch_first:
    lengths = np.ones(sequence.size(0)) * sequence.size(1)
  else:
    lengths = np.ones(sequecne.size(1)) * sequence.size(0)
  return output, torch.LongTensor(lengths)

def pack_padded_sequence(*args, **kwargs):
  quant_mode, _ = maybe_get_quantizer()
  if quant_mode == None:
    return nn.utils.rnn.pack_padded_sequence(*args, **kwargs)
  return deephi_pack_padded_sequence(*args, **kwargs)

def pad_packed_sequence(*args, **kwargs):
  quant_mode, _ = maybe_get_quantizer()
  if quant_mode == None:
    return nn.utils.rnn.pad_packed_sequence(*args, **kwargs)
  return deephi_pad_packed_sequence(*args, **kwargs)
