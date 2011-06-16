//
// Copyright (c) 1997, 2010, Oracle and/or its affiliates. All rights reserved.
// DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
//
// This code is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License version 2 only, as
// published by the Free Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// version 2 for more details (a copy is included in the LICENSE file that
// accompanied this code).
//
// You should have received a copy of the GNU General Public License version
// 2 along with this work; if not, write to the Free Software Foundation,
// Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
// or visit www.oracle.com if you need additional information or have any
// questions.
//
//

// Machine Generated File.  Do Not Edit!


#include "incls/_precompiled.incl"
#include "incls/_ad_x86_32_pipeline.cpp.incl"


//------------------Pipeline Methods-----------------------------------------
#ifndef PRODUCT
const char * Pipeline::stageName(uint s) {
  static const char * const _stage_names[] = {
    "undefined", "S0", "S1", "S2", "S3", "S4", "S5"
  };

  return (s <= 6 ? _stage_names[s] : "???");
}
#endif

uint Pipeline::functional_unit_latency(uint start, const Pipeline *pred) const {
  // See if the functional units overlap
  uint mask = resourcesUsedExclusively() & pred->resourcesUsedExclusively();
  if (mask == 0)
    return (start);

  for (uint i = 0; i < pred->resourceUseCount(); i++) {
    const Pipeline_Use_Element *predUse = pred->resourceUseElement(i);
    if (predUse->multiple())
      continue;

    for (uint j = 0; j < resourceUseCount(); j++) {
      const Pipeline_Use_Element *currUse = resourceUseElement(j);
      if (currUse->multiple())
        continue;

      if (predUse->used() & currUse->used()) {
        Pipeline_Use_Cycle_Mask x = predUse->mask();
        Pipeline_Use_Cycle_Mask y = currUse->mask();

        for ( y <<= start; x.overlaps(y); start++ )
          y <<= 1;
      }
    }
  }

  // There is the potential for overlap
  return (start);
}

// The following two routines assume that the root Pipeline_Use entity
// consists of exactly 1 element for each functional unit
// start is relative to the current cycle; used for latency-based info
uint Pipeline_Use::full_latency(uint delay, const Pipeline_Use &pred) const {
  for (uint i = 0; i < pred._count; i++) {
    const Pipeline_Use_Element *predUse = pred.element(i);
    if (predUse->_multiple) {
      uint min_delay = 7;
      // Multiple possible functional units, choose first unused one
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        const Pipeline_Use_Element *currUse = element(j);
        uint curr_delay = delay;
        if (predUse->_used & currUse->_used) {
          Pipeline_Use_Cycle_Mask x = predUse->_mask;
          Pipeline_Use_Cycle_Mask y = currUse->_mask;

          for ( y <<= curr_delay; x.overlaps(y); curr_delay++ )
            y <<= 1;
        }
        if (min_delay > curr_delay)
          min_delay = curr_delay;
      }
      if (delay < min_delay)
      delay = min_delay;
    }
    else {
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        const Pipeline_Use_Element *currUse = element(j);
        if (predUse->_used & currUse->_used) {
          Pipeline_Use_Cycle_Mask x = predUse->_mask;
          Pipeline_Use_Cycle_Mask y = currUse->_mask;

          for ( y <<= delay; x.overlaps(y); delay++ )
            y <<= 1;
        }
      }
    }
  }

  return (delay);
}

void Pipeline_Use::add_usage(const Pipeline_Use &pred) {
  for (uint i = 0; i < pred._count; i++) {
    const Pipeline_Use_Element *predUse = pred.element(i);
    if (predUse->_multiple) {
      // Multiple possible functional units, choose first unused one
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        Pipeline_Use_Element *currUse = element(j);
        if ( !predUse->_mask.overlaps(currUse->_mask) ) {
          currUse->_used |= (1 << j);
          _resources_used |= (1 << j);
          currUse->_mask.Or(predUse->_mask);
          break;
        }
      }
    }
    else {
      for (uint j = predUse->_lb; j <= predUse->_ub; j++) {
        Pipeline_Use_Element *currUse = element(j);
        currUse->_used |= (1 << j);
        _resources_used |= (1 << j);
        currUse->_mask.Or(predUse->_mask);
      }
    }
  }
}

uint Pipeline::operand_latency(uint opnd, const Pipeline *pred) const {
  int const default_latency = 1;

  assert(this, "NULL pipeline info");
  assert(pred, "NULL predecessor pipline info");

  if (pred->hasFixedLatency())
    return (pred->fixedLatency());

  // If this is not an operand, then assume a dependence with 0 latency
  if (opnd > _read_stage_count)
    return (0);

  uint writeStage = pred->_write_stage;
  uint readStage  = _read_stages[opnd-1];

  if (writeStage == stage_undefined || readStage == stage_undefined)
    return (default_latency);

  int delta = writeStage - readStage;
  if (delta < 0) delta = 0;

  return (delta);
}

Pipeline_Use_Cycle_Mask operator&(const Pipeline_Use_Cycle_Mask &in1, const Pipeline_Use_Cycle_Mask &in2) {
  return Pipeline_Use_Cycle_Mask(in1._mask & in2._mask);
}

Pipeline_Use_Cycle_Mask operator|(const Pipeline_Use_Cycle_Mask &in1, const Pipeline_Use_Cycle_Mask &in2) {
  return Pipeline_Use_Cycle_Mask(in1._mask | in2._mask);
}

static const Pipeline pipeline_class_Zero_Instructions(0, 0, true, 0, 0, false, false, false, false, NULL, NULL, NULL, Pipeline_Use(0, 0, 0, NULL));

static const Pipeline pipeline_class_Unknown_Instructions(0, 0, true, 0, 0, false, true, true, false, NULL, NULL, NULL, Pipeline_Use(0, 0, 0, NULL));

const Pipeline_Use_Element Pipeline_Use::elaborated_elements[9] = {
  Pipeline_Use_Element(0, 0, 0, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 1, 1, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 2, 2, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 3, 3, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 4, 4, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 5, 5, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 6, 6, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 7, 7, false, Pipeline_Use_Cycle_Mask(0)),
  Pipeline_Use_Element(0, 8, 8, false, Pipeline_Use_Cycle_Mask(0))
};

const Pipeline_Use Pipeline_Use::elaborated_use(0, 0, 9, (Pipeline_Use_Element *)&elaborated_elements[0]);


// Pipeline Class "ialu_reg"
static const enum machPipelineStages pipeline_reads_001[1] = {
  stage_S3 
};

static const enum machPipelineStages pipeline_res_stages_001[9] = {
  stage_S0,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_S3,        // BR
  stage_S3         // FPU
};

static const uint pipeline_res_cycles_001[9] = {
  1, // D0
  1, // D1
  1, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  1, // BR
  1  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_001[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_001((uint)stage_undefined, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_long"
static const uint pipeline_res_cycles_002[9] = {
  2, // D0
  2, // D1
  2, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  2, // BR
  2  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_002[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_002((uint)stage_undefined, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_002,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_002[0]));

// Pipeline Class "ialu_reg_fat"
static const enum machPipelineStages pipeline_res_stages_002[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_S3,        // BR
  stage_S3         // FPU
};

static const uint pipeline_res_cycles_003[9] = {
  1, // D0
  0, // D1
  0, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  1, // BR
  1  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_003[2] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_003((uint)stage_undefined, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_003,
  Pipeline_Use(0x181, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_003[0]));

// Pipeline Class "ialu_reg_long_fat"
static const uint pipeline_res_cycles_004[9] = {
  2, // D0
  0, // D1
  0, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  2, // BR
  2  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_004[2] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_004((uint)stage_undefined, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_004,
  Pipeline_Use(0x181, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_004[0]));

// Pipeline Class "ialu_reg_reg"
static const Pipeline pipeline_class_005((uint)stage_S4, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_reg_reg_long"
static const Pipeline pipeline_class_006((uint)stage_S4, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_002,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_002[0]));

// Pipeline Class "ialu_reg_reg_fat"
static const Pipeline pipeline_class_007((uint)stage_S4, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_003,
  Pipeline_Use(0x181, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_003[0]));

// Pipeline Class "ialu_reg_reg_long_fat"
static const Pipeline pipeline_class_008((uint)stage_S4, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_002,
  (uint * const) pipeline_res_cycles_004,
  Pipeline_Use(0x181, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_004[0]));

// Pipeline Class "ialu_reg_mem"
static const enum machPipelineStages pipeline_res_stages_003[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_S4,        // BR
  stage_S4         // FPU
};

static const uint pipeline_res_cycles_005[9] = {
  1, // D0
  0, // D1
  0, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  0, // MEM
  1, // BR
  1  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_005[3] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_009((uint)stage_S5, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_005[0]));

// Pipeline Class "ialu_reg_long_mem"
static const uint pipeline_res_cycles_006[9] = {
  2, // D0
  0, // D1
  0, // D2
  2, // DECODE
  2, // MS0
  0, // MS1
  0, // MEM
  2, // BR
  2  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_006[3] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x00000018)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_010((uint)stage_S5, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_006,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_006[0]));

// Pipeline Class "ialu_mem"
static const enum machPipelineStages pipeline_res_stages_004[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_007[9] = {
  1, // D0
  0, // D1
  0, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_007[2] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_011((uint)stage_undefined, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_007,
  Pipeline_Use(0x019, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_007[0]));

// Pipeline Class "ialu_mem_reg"
static const enum machPipelineStages pipeline_reads_002[2] = {
  stage_S3,
  stage_S5 
};

static const Pipeline pipeline_class_012((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_005[0]));

// Pipeline Class "ialu_mem_long_reg"
static const Pipeline pipeline_class_013((uint)stage_undefined, 2, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_006,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_006[0]));

// Pipeline Class "ialu_mem_imm"
static const Pipeline pipeline_class_014((uint)stage_undefined, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_005[0]));

// Pipeline Class "ialu_reg_reg_alu0"
static const enum machPipelineStages pipeline_res_stages_005[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_S3,        // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_008[9] = {
  1, // D0
  0, // D1
  0, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  1, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_008[2] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x080, 7, 7, false, Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_015((uint)stage_S4, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_005,
  (uint * const) pipeline_res_cycles_008,
  Pipeline_Use(0x081, 0x081, 2, (Pipeline_Use_Element *)&pipeline_res_mask_008[0]));

// Pipeline Class "ialu_reg_mem_alu0"
static const enum machPipelineStages pipeline_res_stages_006[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_S4,        // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_009[9] = {
  1, // D0
  0, // D1
  0, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  0, // MEM
  1, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_009[3] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x080, 7, 7, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_016((uint)stage_S5, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_006,
  (uint * const) pipeline_res_cycles_009,
  Pipeline_Use(0x099, 0x081, 3, (Pipeline_Use_Element *)&pipeline_res_mask_009[0]));

// Pipeline Class "ialu_cr_reg_reg"
static const enum machPipelineStages pipeline_reads_003[2] = {
  stage_S3,
  stage_S3 
};

static const Pipeline pipeline_class_017((uint)stage_S4, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cr_reg_imm"
static const Pipeline pipeline_class_018((uint)stage_S4, 1, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_001,
  (uint * const) pipeline_res_cycles_001,
  Pipeline_Use(0x187, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_001[0]));

// Pipeline Class "ialu_cr_reg_mem"
static const Pipeline pipeline_class_019((uint)stage_S4, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_003,
  (uint * const) pipeline_res_cycles_005,
  Pipeline_Use(0x199, 0x001, 3, (Pipeline_Use_Element *)&pipeline_res_mask_005[0]));

// Pipeline Class "pipe_cmplt"
static const enum machPipelineStages pipeline_reads_004[3] = {
  stage_S3,
  stage_S3,
  stage_S4 
};

static const enum machPipelineStages pipeline_res_stages_007[9] = {
  stage_S0,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_010[9] = {
  4, // D0
  4, // D1
  4, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_010[1] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000008)) 
};

static const Pipeline pipeline_class_020((uint)stage_undefined, 3, false, 0, 4, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_004,
   (enum machPipelineStages * const) pipeline_res_stages_007,
  (uint * const) pipeline_res_cycles_010,
  Pipeline_Use(0x007, 0x000, 1, (Pipeline_Use_Element *)&pipeline_res_mask_010[0]));

// Pipeline Class "pipe_cmov_reg"
static const uint pipeline_res_cycles_011[9] = {
  1, // D0
  1, // D1
  1, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_011[1] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000001)) 
};

static const Pipeline pipeline_class_021((uint)stage_S4, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_007,
  (uint * const) pipeline_res_cycles_011,
  Pipeline_Use(0x007, 0x000, 1, (Pipeline_Use_Element *)&pipeline_res_mask_011[0]));

// Pipeline Class "pipe_cmov_mem"
static const enum machPipelineStages pipeline_reads_005[3] = {
  stage_S3,
  stage_S4,
  stage_S3 
};

static const enum machPipelineStages pipeline_res_stages_008[9] = {
  stage_S0,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_012[9] = {
  1, // D0
  1, // D1
  1, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_012[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_022((uint)stage_S4, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_005,
   (enum machPipelineStages * const) pipeline_res_stages_008,
  (uint * const) pipeline_res_cycles_012,
  Pipeline_Use(0x01f, 0x000, 2, (Pipeline_Use_Element *)&pipeline_res_mask_012[0]));

// Pipeline Class "pipe_cmov_reg_long"
static const uint pipeline_res_cycles_013[9] = {
  2, // D0
  2, // D1
  2, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_013[1] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000002)) 
};

static const Pipeline pipeline_class_023((uint)stage_S4, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_005,
   (enum machPipelineStages * const) pipeline_res_stages_007,
  (uint * const) pipeline_res_cycles_013,
  Pipeline_Use(0x007, 0x000, 1, (Pipeline_Use_Element *)&pipeline_res_mask_013[0]));

// Pipeline Class "pipe_cmovD_reg"
static const Pipeline pipeline_class_024((uint)stage_S4, 3, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_005,
   (enum machPipelineStages * const) pipeline_res_stages_007,
  (uint * const) pipeline_res_cycles_011,
  Pipeline_Use(0x007, 0x000, 1, (Pipeline_Use_Element *)&pipeline_res_mask_011[0]));

// Pipeline Class "fpu_reg"
static const enum machPipelineStages pipeline_res_stages_009[9] = {
  stage_S0,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_S3,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_014[9] = {
  2, // D0
  2, // D1
  2, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  1, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_014[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_025((uint)stage_undefined, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_014,
  Pipeline_Use(0x047, 0x040, 2, (Pipeline_Use_Element *)&pipeline_res_mask_014[0]));

// Pipeline Class "fpu_reg_reg"
static const Pipeline pipeline_class_026((uint)stage_S4, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_014,
  Pipeline_Use(0x047, 0x040, 2, (Pipeline_Use_Element *)&pipeline_res_mask_014[0]));

// Pipeline Class "fpu_reg_reg_reg"
static const uint pipeline_res_cycles_015[9] = {
  3, // D0
  3, // D1
  3, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  2, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_015[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000004)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_027((uint)stage_S4, 2, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_015,
  Pipeline_Use(0x047, 0x040, 2, (Pipeline_Use_Element *)&pipeline_res_mask_015[0]));

// Pipeline Class "fpu_reg_reg_reg_reg"
static const enum machPipelineStages pipeline_reads_006[3] = {
  stage_S3,
  stage_S3,
  stage_S3 
};

static const uint pipeline_res_cycles_016[9] = {
  4, // D0
  4, // D1
  4, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  2, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_016[2] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000008)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_028((uint)stage_S4, 3, false, 0, 4, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_009,
  (uint * const) pipeline_res_cycles_016,
  Pipeline_Use(0x047, 0x040, 2, (Pipeline_Use_Element *)&pipeline_res_mask_016[0]));

// Pipeline Class "fpu_reg_mem_reg_reg"
static const enum machPipelineStages pipeline_res_stages_010[9] = {
  stage_S1,        // D0
  stage_S1,        // D1
  stage_S1,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_S3,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_017[9] = {
  3, // D0
  3, // D1
  3, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  2, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_017[4] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x00000007)),
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x0000000c)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_029((uint)stage_S4, 3, false, 0, 4, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_010,
  (uint * const) pipeline_res_cycles_017,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_017[0]));

// Pipeline Class "fpu_reg_mem"
static const enum machPipelineStages pipeline_res_stages_011[9] = {
  stage_S1,        // D0
  stage_S1,        // D1
  stage_S1,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_S4,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_018[9] = {
  1, // D0
  1, // D1
  1, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  1, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_018[4] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x00000001)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_030((uint)stage_S5, 1, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_018[0]));

// Pipeline Class "fpu_reg_reg_mem"
static const uint pipeline_res_cycles_019[9] = {
  2, // D0
  2, // D1
  2, // D2
  1, // DECODE
  1, // MS0
  0, // MS1
  1, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_019[4] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x00000003)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_031((uint)stage_S5, 2, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_003,
   (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_019[0]));

// Pipeline Class "fpu_mem_reg"
static const enum machPipelineStages pipeline_res_stages_012[9] = {
  stage_S1,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_S4,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_020[4] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x00000001)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_032((uint)stage_undefined, 2, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_002,
   (enum machPipelineStages * const) pipeline_res_stages_012,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_020[0]));

// Pipeline Class "fpu_mem_reg_reg"
static const Pipeline_Use_Element pipeline_res_mask_021[4] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x00000001)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_033((uint)stage_undefined, 3, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_006,
   (enum machPipelineStages * const) pipeline_res_stages_012,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_021[0]));

// Pipeline Class "fpu_mem_reg_mem"
static const enum machPipelineStages pipeline_reads_007[3] = {
  stage_S4,
  stage_S3,
  stage_S3 
};

static const enum machPipelineStages pipeline_res_stages_013[9] = {
  stage_S0,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_S4,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_020[9] = {
  2, // D0
  1, // D1
  1, // D2
  2, // DECODE
  2, // MS0
  0, // MS1
  1, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_022[4] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000001)),
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_034((uint)stage_undefined, 3, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_007,
   (enum machPipelineStages * const) pipeline_res_stages_013,
  (uint * const) pipeline_res_cycles_020,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_022[0]));

// Pipeline Class "fpu_mem_mem"
static const enum machPipelineStages pipeline_reads_008[2] = {
  stage_S4,
  stage_S3 
};

static const uint pipeline_res_cycles_021[9] = {
  2, // D0
  0, // D1
  0, // D2
  2, // DECODE
  2, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_023[2] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000002)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x0000000c)) 
};

static const Pipeline pipeline_class_035((uint)stage_undefined, 2, false, 0, 2, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_008,
   (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_021,
  Pipeline_Use(0x019, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_023[0]));

// Pipeline Class "fpu_mem_mem_mem"
static const enum machPipelineStages pipeline_res_stages_014[9] = {
  stage_S0,        // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_undefined, // MS1
  stage_S4,        // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_022[9] = {
  3, // D0
  0, // D1
  0, // D2
  3, // DECODE
  3, // MS0
  0, // MS1
  1, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_024[3] = {
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x80000004)),
  Pipeline_Use_Element(0x040, 6, 6, false, Pipeline_Use_Cycle_Mask(0x00000008)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x0000001c)) 
};

static const Pipeline pipeline_class_036((uint)stage_undefined, 3, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_007,
   (enum machPipelineStages * const) pipeline_res_stages_014,
  (uint * const) pipeline_res_cycles_022,
  Pipeline_Use(0x059, 0x041, 3, (Pipeline_Use_Element *)&pipeline_res_mask_024[0]));

// Pipeline Class "fpu_mem_reg_con"
static const enum machPipelineStages pipeline_reads_009[2] = {
  stage_S4,
  stage_S4 
};

static const Pipeline pipeline_class_037((uint)stage_undefined, 2, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_009,
   (enum machPipelineStages * const) pipeline_res_stages_013,
  (uint * const) pipeline_res_cycles_020,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_022[0]));

// Pipeline Class "fpu_reg_con"
static const Pipeline pipeline_class_038((uint)stage_S5, 0, false, 0, 2, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_018,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_018[0]));

// Pipeline Class "fpu_reg_reg_con"
static const Pipeline pipeline_class_039((uint)stage_S5, 1, false, 0, 3, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_011,
  (uint * const) pipeline_res_cycles_019,
  Pipeline_Use(0x05f, 0x041, 4, (Pipeline_Use_Element *)&pipeline_res_mask_019[0]));

// Pipeline Class "pipe_jmp"
static const enum machPipelineStages pipeline_res_stages_015[9] = {
  stage_undefined, // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_S3,        // MS1
  stage_undefined, // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_023[9] = {
  0, // D0
  0, // D1
  0, // D2
  0, // DECODE
  0, // MS0
  1, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_025[1] = {
  Pipeline_Use_Element(0x020, 5, 5, false, Pipeline_Use_Cycle_Mask(0x00000004)) 
};

static const Pipeline pipeline_class_040((uint)stage_undefined, 0, false, 0, 1, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_015,
  (uint * const) pipeline_res_cycles_023,
  Pipeline_Use(0x020, 0x020, 1, (Pipeline_Use_Element *)&pipeline_res_mask_025[0]));

// Pipeline Class "pipe_jcc"
static const enum machPipelineStages pipeline_reads_010[2] = {
  stage_S1,
  stage_undefined 
};

static const Pipeline pipeline_class_041((uint)stage_undefined, 2, false, 0, 1, false, false, false, false,

  (enum machPipelineStages * const) pipeline_reads_010,
   (enum machPipelineStages * const) pipeline_res_stages_015,
  (uint * const) pipeline_res_cycles_023,
  Pipeline_Use(0x020, 0x020, 1, (Pipeline_Use_Element *)&pipeline_res_mask_025[0]));

// Pipeline Class "pipe_cmpxchg"
static const enum machPipelineStages pipeline_res_stages_016[9] = {
  stage_S2,        // D0
  stage_S0,        // D1
  stage_S0,        // D2
  stage_S3,        // DECODE
  stage_S3,        // MS0
  stage_S5,        // MS1
  stage_undefined, // MEM
  stage_S3,        // BR
  stage_S3         // FPU
};

static const uint pipeline_res_cycles_024[9] = {
  3, // D0
  3, // D1
  3, // D2
  1, // DECODE
  1, // MS0
  1, // MS1
  0, // MEM
  2, // BR
  2  // FPU
};

static const Pipeline_Use_Element pipeline_res_mask_026[5] = {
  Pipeline_Use_Element(0x007, 0, 2, true,  Pipeline_Use_Cycle_Mask(0x80000004)),
  Pipeline_Use_Element(0x001, 0, 0, false, Pipeline_Use_Cycle_Mask(0x00000002)),
  Pipeline_Use_Element(0x018, 3, 4, true,  Pipeline_Use_Cycle_Mask(0x00000004)),
  Pipeline_Use_Element(0x180, 7, 8, true,  Pipeline_Use_Cycle_Mask(0x0000000c)),
  Pipeline_Use_Element(0x020, 5, 5, false, Pipeline_Use_Cycle_Mask(0x00000010)) 
};

static const Pipeline pipeline_class_042((uint)stage_S5, 1, true, 6, 1, false, false, true, false,

  (enum machPipelineStages * const) pipeline_reads_001,
   (enum machPipelineStages * const) pipeline_res_stages_016,
  (uint * const) pipeline_res_cycles_024,
  Pipeline_Use(0x1bf, 0x021, 5, (Pipeline_Use_Element *)&pipeline_res_mask_026[0]));

// Pipeline Class "pipe_slow"
static const Pipeline pipeline_class_043((uint)stage_undefined, 0, true, 100, 10, false, true, true, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_004,
  (uint * const) pipeline_res_cycles_021,
  Pipeline_Use(0x019, 0x001, 2, (Pipeline_Use_Element *)&pipeline_res_mask_023[0]));

// Pipeline Class "empty"
static const enum machPipelineStages pipeline_res_stages_017[9] = {
  stage_undefined, // D0
  stage_undefined, // D1
  stage_undefined, // D2
  stage_undefined, // DECODE
  stage_undefined, // MS0
  stage_undefined, // MS1
  stage_undefined, // MEM
  stage_undefined, // BR
  stage_undefined  // FPU
};

static const uint pipeline_res_cycles_025[9] = {
  0, // D0
  0, // D1
  0, // D2
  0, // DECODE
  0, // MS0
  0, // MS1
  0, // MEM
  0, // BR
  0  // FPU
};

static const Pipeline pipeline_class_044((uint)stage_undefined, 0, false, 0, 0, false, false, false, false,
 NULL,  (enum machPipelineStages * const) pipeline_res_stages_017,
  (uint * const) pipeline_res_cycles_025,
  Pipeline_Use(0x000, 0x000, 0, (Pipeline_Use_Element *)NULL));

//------------------Inter-Instruction Latency--------------------------------
uint Node::latency(uint i) {
  uint j;
  // verify in legal range for inputs
  assert(i < len(), "index not in range");

  // verify input is not null
  Node *pred = in(i);
  if (!pred)
    return 0;

  if (pred->is_Proj())
    pred = pred->in(0);

  // if either node does not have pipeline info, use default
  const Pipeline *predpipe = pred->pipeline();
  assert(predpipe, "no predecessor pipeline info");

  if (predpipe->hasFixedLatency())
    return predpipe->fixedLatency();

  const Pipeline *currpipe = pipeline();
  assert(currpipe, "no pipeline info");

  if (!is_Mach())
    return 0;

  const MachNode *m = as_Mach();
  j = m->oper_input_base();
  if (i < j)
    return currpipe->functional_unit_latency(0, predpipe);

  // determine which operand this is in
  uint n = m->num_opnds();
  int delta = 0;

  uint k;
  for (k = 1; k < n; k++) {
    j += m->_opnds[k]->num_edges();
    if (i < j)
      break;
  }
  if (k < n)
    delta = currpipe->operand_latency(k,predpipe);

  return currpipe->functional_unit_latency(delta, predpipe);
}

// Descriptions for emitting different functional unit nops
void Bundle::initialize_nops(MachNode * nop_list[1], Compile *C) {
  nop_list[0] = (MachNode *) new (C) MachNopNode();
};

#ifndef PRODUCT
void Bundle::dump() const {
  static const char * bundle_flags[] = {
    "",
    "use nop delay",
    "use unconditional delay",
    "use conditional delay",
    "used in conditional delay",
    "used in unconditional delay",
    "used in all conditional delays",
  };

  static const char *resource_names[9] = { "D0", "D1", "D2", "DECODE", "MS0", "MS1", "MEM", "BR", "FPU" };

  bool needs_comma = false;

  if (_flags) {
    tty->print("%s", bundle_flags[_flags]);
    needs_comma = true;
  };
  if (instr_count()) {
    tty->print("%s%d instr%s", needs_comma ? ", " : "", instr_count(), instr_count() != 1 ? "s" : "");
    needs_comma = true;
  };
  uint r = resources_used();
  if (r) {
    tty->print("%sresource%s:", needs_comma ? ", " : "", (r & (r-1)) != 0 ? "s" : "");
    for (uint i = 0; i < 9; i++)
      if ((r & (1 << i)) != 0)
        tty->print(" %s", resource_names[i]);
    needs_comma = true;
  };
  tty->print("\n");
}
#endif
const Pipeline *                          Node::pipeline_class() { return (&pipeline_class_Zero_Instructions); }
const Pipeline *                          Node::pipeline() const { return (&pipeline_class_Zero_Instructions); }

const Pipeline *                      MachNode::pipeline_class() { return (&pipeline_class_Unknown_Instructions); }
const Pipeline *                      MachNode::pipeline() const { return pipeline_class(); }

const Pipeline * MachNopNode::pipeline() const { return (&pipeline_class_044); }


const Pipeline *             bytes_reverse_intNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *             bytes_reverse_intNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *            bytes_reverse_longNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *            bytes_reverse_longNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *  bytes_reverse_unsigned_shortNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *  bytes_reverse_unsigned_shortNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           bytes_reverse_shortNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           bytes_reverse_shortNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *            countLeadingZerosINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *            countLeadingZerosINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        countLeadingZerosI_bsrNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        countLeadingZerosI_bsrNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *            countLeadingZerosLNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *            countLeadingZerosLNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *        countLeadingZerosL_bsrNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *        countLeadingZerosL_bsrNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           countTrailingZerosINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           countTrailingZerosINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *           countTrailingZerosLNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *           countTrailingZerosLNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                     popCountINode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     popCountINode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 popCountI_memNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 popCountI_memNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                     popCountLNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     popCountLNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 popCountL_memNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 popCountL_memNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                         loadBNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                         loadBNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadB2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadB2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                        loadUBNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                        loadUBNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadUB2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadUB2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                loadUB2L_immI8Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                loadUB2L_immI8Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                         loadSNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                         loadSNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadS2BNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadS2BNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadS2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadS2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                        loadUSNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                        loadUSNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadUS2BNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadUS2BNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadUS2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadUS2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *             loadUS2L_immI_255Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *             loadUS2L_immI_255Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *               loadUS2L_immI16Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               loadUS2L_immI16Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                         loadINode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                         loadINode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadI2BNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadI2BNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadI2UBNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadI2UBNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadI2SNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadI2SNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadI2USNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadI2USNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadI2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadI2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *              loadI2L_immI_255Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *              loadI2L_immI_255Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *            loadI2L_immI_65535Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *            loadI2L_immI_65535Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                  loadI2L_immINode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                  loadI2L_immINode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      loadUI2LNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                      loadUI2LNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                         loadLNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                         loadLNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                loadL_volatileNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                loadL_volatileNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *               loadLX_volatileNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               loadLX_volatileNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           loadLX_reg_volatileNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           loadLX_reg_volatileNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     loadRangeNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                     loadRangeNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                         loadPNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                         loadPNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                     loadKlassNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                     loadKlassNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                         loadDNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                         loadDNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                        loadXDNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                        loadXDNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                loadXD_partialNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                loadXD_partialNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                         loadXNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                         loadXNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                         loadFNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                         loadFNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                       loadA8BNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       loadA8BNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       loadA4SNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       loadA4SNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       loadA4CNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       loadA4CNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       load2IUNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       load2IUNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       loadA2FNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       loadA2FNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                         leaP8Node::pipeline_class() { return (&pipeline_class_007); }
const Pipeline *                         leaP8Node::pipeline() const { return (&pipeline_class_007); }

const Pipeline *                        leaP32Node::pipeline_class() { return (&pipeline_class_007); }
const Pipeline *                        leaP32Node::pipeline() const { return (&pipeline_class_007); }

const Pipeline *                    leaPIdxOffNode::pipeline_class() { return (&pipeline_class_007); }
const Pipeline *                    leaPIdxOffNode::pipeline() const { return (&pipeline_class_007); }

const Pipeline *                  leaPIdxScaleNode::pipeline_class() { return (&pipeline_class_007); }
const Pipeline *                  leaPIdxScaleNode::pipeline() const { return (&pipeline_class_007); }

const Pipeline *               leaPIdxScaleOffNode::pipeline_class() { return (&pipeline_class_007); }
const Pipeline *               leaPIdxScaleOffNode::pipeline() const { return (&pipeline_class_007); }

const Pipeline *                      loadConINode::pipeline_class() { return (&pipeline_class_003); }
const Pipeline *                      loadConINode::pipeline() const { return (&pipeline_class_003); }

const Pipeline *                     loadConI0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     loadConI0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                      loadConPNode::pipeline_class() { return (&pipeline_class_003); }
const Pipeline *                      loadConPNode::pipeline() const { return (&pipeline_class_003); }

const Pipeline *                      loadConLNode::pipeline_class() { return (&pipeline_class_004); }
const Pipeline *                      loadConLNode::pipeline() const { return (&pipeline_class_004); }

const Pipeline *                     loadConL0Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                     loadConL0Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                      loadConFNode::pipeline_class() { return (&pipeline_class_038); }
const Pipeline *                      loadConFNode::pipeline() const { return (&pipeline_class_038); }

const Pipeline *                      loadConXNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      loadConXNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     loadConX0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     loadConX0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      loadConDNode::pipeline_class() { return (&pipeline_class_038); }
const Pipeline *                      loadConDNode::pipeline() const { return (&pipeline_class_038); }

const Pipeline *                     loadConXDNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     loadConXDNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    loadConXD0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    loadConXD0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       loadSSINode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadSSINode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadSSLNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *                       loadSSLNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *                       loadSSPNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                       loadSSPNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                       loadSSFNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                       loadSSFNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                       loadSSDNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                       loadSSDNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                    prefetchr0Node::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                    prefetchr0Node::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                     prefetchrNode::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                     prefetchrNode::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                  prefetchrNTANode::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                  prefetchrNTANode::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                   prefetchrT0Node::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                   prefetchrT0Node::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                   prefetchrT2Node::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                   prefetchrT2Node::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                    prefetchw0Node::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                    prefetchw0Node::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                     prefetchwNode::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                     prefetchwNode::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                  prefetchwNTANode::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                  prefetchwNTANode::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                   prefetchwT0Node::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                   prefetchwT0Node::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                   prefetchwT2Node::pipeline_class() { return (&pipeline_class_011); }
const Pipeline *                   prefetchwT2Node::pipeline() const { return (&pipeline_class_011); }

const Pipeline *                        storeBNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                        storeBNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                        storeCNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                        storeCNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                        storeINode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                        storeINode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                        storeLNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *                        storeLNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *                      storeL2INode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                      storeL2INode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *               storeL_volatileNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *               storeL_volatileNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *              storeLX_volatileNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *              storeLX_volatileNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *          storeLX_reg_volatileNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *          storeLX_reg_volatileNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                        storePNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                        storePNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                     storeImmINode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                     storeImmINode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                   storeImmI16Node::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                   storeImmI16Node::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                     storeImmPNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                     storeImmPNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                     storeImmBNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                     storeImmBNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                      storeA8BNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      storeA8BNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      storeA4CNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      storeA4CNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      storeA2INode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      storeA2INode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    storeImmCMNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                    storeImmCMNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                        storeDNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                        storeDNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                storeD_roundedNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                storeD_roundedNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                       storeXDNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       storeXDNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                        storeXNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                        storeXNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      storeA2FNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      storeA2FNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                        storeFNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                        storeFNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                storeF_roundedNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *                storeF_roundedNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *               storeF_DroundedNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *               storeF_DroundedNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                    storeF_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                    storeF_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                    storeX_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                    storeX_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                      storeSSINode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                      storeSSINode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                      storeSSPNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                      storeSSPNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                      storeSSLNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *                      storeSSLNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *                membar_acquireNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                membar_acquireNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *           membar_acquire_lockNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *           membar_acquire_lockNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                membar_releaseNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                membar_releaseNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *           membar_release_lockNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *           membar_release_lockNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *               membar_volatileNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               membar_volatileNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *   unnecessary_membar_volatileNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *   unnecessary_membar_volatileNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                       castX2PNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                       castX2PNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                       castP2XNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                       castP2XNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                     cmovI_regNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                     cmovI_regNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                    cmovI_regUNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                    cmovI_regUNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                     cmovI_memNode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *                     cmovI_memNode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *                    cmovI_memUNode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *                    cmovI_memUNode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *                     cmovP_regNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                     cmovP_regNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *               cmovP_reg_nonP6Node::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovP_reg_nonP6Node::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                    cmovP_regUNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *                    cmovP_regUNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *                   fcmovD_regUNode::pipeline_class() { return (&pipeline_class_024); }
const Pipeline *                   fcmovD_regUNode::pipeline() const { return (&pipeline_class_024); }

const Pipeline *                   fcmovF_regUNode::pipeline_class() { return (&pipeline_class_024); }
const Pipeline *                   fcmovF_regUNode::pipeline() const { return (&pipeline_class_024); }

const Pipeline *                   fcmovD_regSNode::pipeline_class() { return (&pipeline_class_024); }
const Pipeline *                   fcmovD_regSNode::pipeline() const { return (&pipeline_class_024); }

const Pipeline *                   fcmovF_regSNode::pipeline_class() { return (&pipeline_class_024); }
const Pipeline *                   fcmovF_regSNode::pipeline() const { return (&pipeline_class_024); }

const Pipeline *                   fcmovX_regSNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   fcmovX_regSNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  fcmovXD_regSNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  fcmovXD_regSNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   fcmovX_regUNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   fcmovX_regUNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  fcmovXD_regUNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  fcmovXD_regUNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     cmovL_regNode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *                     cmovL_regNode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *                    cmovL_regUNode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *                    cmovL_regUNode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *                     addI_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     addI_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                 addI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 addI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                     incI_eRegNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     incI_eRegNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                leaI_eReg_immINode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                leaI_eReg_immINode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                leaP_eReg_immINode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                leaP_eReg_immINode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                     decI_eRegNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     decI_eRegNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                     addP_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     addP_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                 addP_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 addP_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 addI_eReg_memNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                 addI_eReg_memNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *               addI_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               addI_eReg_mem_0Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                 addI_mem_eRegNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                 addI_mem_eRegNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *               addI_mem_eReg_0Node::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *               addI_mem_eReg_0Node::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                  addI_mem_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                  addI_mem_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                      incI_memNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                      incI_memNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                      decI_memNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                      decI_memNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                   checkCastPPNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                   checkCastPPNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                        castPPNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                        castPPNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                        castIINode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *                        castIINode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *                   loadPLockedNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                   loadPLockedNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                   loadLLockedNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                   loadLLockedNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                 loadLX_LockedNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 loadLX_LockedNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             loadLX_reg_LockedNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *             loadLX_reg_LockedNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             storePConditionalNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *             storePConditionalNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *             storeIConditionalNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *             storeIConditionalNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *             storeLConditionalNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *             storeLConditionalNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *               compareAndSwapLNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *               compareAndSwapLNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *               compareAndSwapPNode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *               compareAndSwapPNode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *               compareAndSwapINode::pipeline_class() { return (&pipeline_class_042); }
const Pipeline *               compareAndSwapINode::pipeline() const { return (&pipeline_class_042); }

const Pipeline *                     subI_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     subI_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                 subI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 subI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 subI_eReg_memNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                 subI_eReg_memNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                 subI_mem_eRegNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                 subI_mem_eRegNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                     subP_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     subP_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                     negI_eRegNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                     negI_eRegNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                     mulI_eRegNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                     mulI_eRegNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                 mulI_eReg_immNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                 mulI_eReg_immNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *             loadConL_low_onlyNode::pipeline_class() { return (&pipeline_class_003); }
const Pipeline *             loadConL_low_onlyNode::pipeline() const { return (&pipeline_class_003); }

const Pipeline *                 mulI_imm_highNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 mulI_imm_highNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               mulI_imm_high_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               mulI_imm_high_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *          mulI_imm_RShift_highNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *          mulI_imm_RShift_highNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *        mulI_imm_RShift_high_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *        mulI_imm_RShift_high_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  mulI_mem_immNode::pipeline_class() { return (&pipeline_class_016); }
const Pipeline *                  mulI_mem_immNode::pipeline() const { return (&pipeline_class_016); }

const Pipeline *                          mulINode::pipeline_class() { return (&pipeline_class_016); }
const Pipeline *                          mulINode::pipeline() const { return (&pipeline_class_016); }

const Pipeline *                        mulI_0Node::pipeline_class() { return (&pipeline_class_016); }
const Pipeline *                        mulI_0Node::pipeline() const { return (&pipeline_class_016); }

const Pipeline *                        mulI2LNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                        mulI2LNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                      mulI2L_0Node::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                      mulI2L_0Node::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                    mulIS_eRegNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                    mulIS_eRegNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                  mulIS_eReg_0Node::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                  mulIS_eReg_0Node::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                     mulL_eRegNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     mulL_eRegNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                mulL_eReg_lhi0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                mulL_eReg_lhi0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                mulL_eReg_rhi0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                mulL_eReg_rhi0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 mulL_eReg_hi0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 mulL_eReg_hi0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 mulL_eReg_conNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 mulL_eReg_conNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     divI_eRegNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                     divI_eRegNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                     divL_eRegNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     divL_eRegNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           divModI_eReg_divmodNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           divModI_eReg_divmodNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     modI_eRegNode::pipeline_class() { return (&pipeline_class_015); }
const Pipeline *                     modI_eRegNode::pipeline() const { return (&pipeline_class_015); }

const Pipeline *                     modL_eRegNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     modL_eRegNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   shlI_eReg_1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   shlI_eReg_1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 salI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 salI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  salI_eReg_CLNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                  salI_eReg_CLNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                   sarI_eReg_1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   sarI_eReg_1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                    sarI_mem_1Node::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                    sarI_mem_1Node::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                 sarI_eReg_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                 sarI_eReg_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                  sarI_mem_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                  sarI_mem_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                  sarI_eReg_CLNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                  sarI_eReg_CLNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                   shrI_eReg_1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                   shrI_eReg_1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 shrI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 shrI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                           i2bNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                           i2bNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                           i2sNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                           i2sNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                  shrI_eReg_CLNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                  shrI_eReg_CLNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                     andI_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     andI_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                 andI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 andI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 andI_eReg_memNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                 andI_eReg_memNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *               andI_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               andI_eReg_mem_0Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                 andI_mem_eRegNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                 andI_mem_eRegNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *               andI_mem_eReg_0Node::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *               andI_mem_eReg_0Node::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                  andI_mem_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                  andI_mem_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                      orI_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                      orI_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *              orI_eReg_castP2XNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *              orI_eReg_castP2XNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *            orI_eReg_castP2X_0Node::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *            orI_eReg_castP2X_0Node::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                  orI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                  orI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  orI_eReg_memNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                  orI_eReg_memNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                orI_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                orI_eReg_mem_0Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                  orI_mem_eRegNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                  orI_mem_eRegNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                orI_mem_eReg_0Node::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                orI_mem_eReg_0Node::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                   orI_mem_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                   orI_mem_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                rolI_eReg_imm1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                rolI_eReg_imm1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                rolI_eReg_imm8Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                rolI_eReg_imm8Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  rolI_eReg_CLNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                  rolI_eReg_CLNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                rorI_eReg_imm1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                rorI_eReg_imm1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                rorI_eReg_imm8Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                rorI_eReg_imm8Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                  rorI_eReg_CLNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                  rorI_eReg_CLNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                     xorI_eRegNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                     xorI_eRegNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                 xorI_eReg_im1Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 xorI_eReg_im1Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 xorI_eReg_immNode::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                 xorI_eReg_immNode::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                 xorI_eReg_memNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                 xorI_eReg_memNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *               xorI_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *               xorI_eReg_mem_0Node::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                 xorI_mem_eRegNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *                 xorI_mem_eRegNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *               xorI_mem_eReg_0Node::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *               xorI_mem_eReg_0Node::pipeline() const { return (&pipeline_class_012); }

const Pipeline *                  xorI_mem_immNode::pipeline_class() { return (&pipeline_class_014); }
const Pipeline *                  xorI_mem_immNode::pipeline() const { return (&pipeline_class_014); }

const Pipeline *                   movI_nocopyNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                   movI_nocopyNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                          ci2bNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                          ci2bNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                   movP_nocopyNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                   movP_nocopyNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *                          cp2bNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                          cp2bNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                     cmpLTMaskNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     cmpLTMaskNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    cmpLTMask0Node::pipeline_class() { return (&pipeline_class_001); }
const Pipeline *                    cmpLTMask0Node::pipeline() const { return (&pipeline_class_001); }

const Pipeline *                cadd_cmpLTMaskNode::pipeline_class() { return (&pipeline_class_020); }
const Pipeline *                cadd_cmpLTMaskNode::pipeline() const { return (&pipeline_class_020); }

const Pipeline *              cadd_cmpLTMask_1Node::pipeline_class() { return (&pipeline_class_020); }
const Pipeline *              cadd_cmpLTMask_1Node::pipeline() const { return (&pipeline_class_020); }

const Pipeline *              cadd_cmpLTMask_0Node::pipeline_class() { return (&pipeline_class_020); }
const Pipeline *              cadd_cmpLTMask_0Node::pipeline() const { return (&pipeline_class_020); }

const Pipeline *              cadd_cmpLTMask_2Node::pipeline_class() { return (&pipeline_class_020); }
const Pipeline *              cadd_cmpLTMask_2Node::pipeline() const { return (&pipeline_class_020); }

const Pipeline *                     addL_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                     addL_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 addL_eReg_immNode::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                 addL_eReg_immNode::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                 addL_eReg_memNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                 addL_eReg_memNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *               addL_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *               addL_eReg_mem_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                     subL_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                     subL_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 subL_eReg_immNode::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                 subL_eReg_immNode::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                 subL_eReg_memNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                 subL_eReg_memNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                     negL_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                     negL_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                     andL_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                     andL_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 andL_eReg_immNode::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                 andL_eReg_immNode::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                 andL_eReg_memNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                 andL_eReg_memNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *               andL_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *               andL_eReg_mem_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                      orl_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                      orl_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                  orl_eReg_immNode::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                  orl_eReg_immNode::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                  orl_eReg_memNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                  orl_eReg_memNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                orl_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                orl_eReg_mem_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                     xorl_eRegNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                     xorl_eRegNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                 xorl_eReg_im1Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                 xorl_eReg_im1Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                 xorl_eReg_immNode::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                 xorl_eReg_immNode::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                 xorl_eReg_memNode::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *                 xorl_eReg_memNode::pipeline() const { return (&pipeline_class_010); }

const Pipeline *               xorl_eReg_mem_0Node::pipeline_class() { return (&pipeline_class_010); }
const Pipeline *               xorl_eReg_mem_0Node::pipeline() const { return (&pipeline_class_010); }

const Pipeline *                   shlL_eReg_1Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                   shlL_eReg_1Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                   shlL_eReg_2Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                   shlL_eReg_2Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                   shlL_eReg_3Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                   shlL_eReg_3Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                shlL_eReg_1_31Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                shlL_eReg_1_31Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *               shlL_eReg_32_63Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *               shlL_eReg_32_63Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                  salL_eReg_CLNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  salL_eReg_CLNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                shrL_eReg_1_31Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                shrL_eReg_1_31Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *               shrL_eReg_32_63Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *               shrL_eReg_32_63Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                  shrL_eReg_CLNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  shrL_eReg_CLNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                sarL_eReg_1_31Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *                sarL_eReg_1_31Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *               sarL_eReg_32_63Node::pipeline_class() { return (&pipeline_class_002); }
const Pipeline *               sarL_eReg_32_63Node::pipeline() const { return (&pipeline_class_002); }

const Pipeline *                  sarL_eReg_CLNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  sarL_eReg_CLNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    cmpD_cc_P6Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    cmpD_cc_P6Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  cmpD_cc_P6CFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  cmpD_cc_P6CFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       cmpD_ccNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       cmpD_ccNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                        cmpD_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                        cmpD_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      cmpD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      cmpD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      cmpXD_ccNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      cmpXD_ccNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    cmpXD_ccCFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    cmpXD_ccCFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   cmpXD_ccmemNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   cmpXD_ccmemNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 cmpXD_ccmemCFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 cmpXD_ccmemCFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     cmpXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     cmpXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  cmpXD_regmemNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  cmpXD_regmemNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      subD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      subD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                subD_reg_roundNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                subD_reg_roundNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                  subD_reg_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  subD_reg_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                      absD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      absD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                     absXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     absXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      negD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      negD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                     negXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     negXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      addD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      addD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                addD_reg_roundNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                addD_reg_roundNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                  addD_reg_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  addD_reg_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                addD_reg_mem_0Node::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                addD_reg_mem_0Node::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                  addD_mem_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  addD_mem_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                addD_mem_reg_0Node::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                addD_mem_reg_0Node::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                 addD_reg_imm1Node::pipeline_class() { return (&pipeline_class_025); }
const Pipeline *                 addD_reg_imm1Node::pipeline() const { return (&pipeline_class_025); }

const Pipeline *                  addD_reg_immNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  addD_reg_immNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *            addD_reg_imm_roundNode::pipeline_class() { return (&pipeline_class_037); }
const Pipeline *            addD_reg_imm_roundNode::pipeline() const { return (&pipeline_class_037); }

const Pipeline *                     addXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     addXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     addXD_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     addXD_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     addXD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     addXD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   addXD_mem_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   addXD_mem_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     subXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     subXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     subXD_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     subXD_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     subXD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     subXD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     mulXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     mulXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     mulXD_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     mulXD_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     mulXD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     mulXD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   mulXD_mem_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   mulXD_mem_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     divXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     divXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     divXD_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     divXD_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     divXD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     divXD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      mulD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      mulD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *             strictfp_mulD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *             strictfp_mulD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  mulD_reg_immNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  mulD_reg_immNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                  mulD_reg_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  mulD_reg_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                mulD_reg_mem_0Node::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                mulD_reg_mem_0Node::pipeline() const { return (&pipeline_class_030); }

const Pipeline *             mulD_reg_mem_ciscNode::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *             mulD_reg_mem_ciscNode::pipeline() const { return (&pipeline_class_031); }

const Pipeline *           mulD_reg_mem_cisc_0Node::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *           mulD_reg_mem_cisc_0Node::pipeline() const { return (&pipeline_class_031); }

const Pipeline *                 addD_mulD_regNode::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *                 addD_mulD_regNode::pipeline() const { return (&pipeline_class_027); }

const Pipeline *               addD_mulD_reg_0Node::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *               addD_mulD_reg_0Node::pipeline() const { return (&pipeline_class_027); }

const Pipeline *                 subD_mulD_regNode::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *                 subD_mulD_regNode::pipeline() const { return (&pipeline_class_027); }

const Pipeline *                      divD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      divD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *             strictfp_divD_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *             strictfp_divD_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                divD_reg_roundNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                divD_reg_roundNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                      modD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      modD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     modXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     modXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      sinD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      sinD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     sinXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     sinXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      cosD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      cosD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     cosXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     cosXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      tanD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      tanD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     tanXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     tanXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     atanD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     atanD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    atanXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    atanXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     sqrtD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     sqrtD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      powD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      powD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     powXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     powXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      expD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      expD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     expXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     expXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    log10D_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    log10D_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   log10XD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   log10XD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      logD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      logD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     logXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     logXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    cmpF_cc_P6Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    cmpF_cc_P6Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  cmpF_cc_P6CFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  cmpF_cc_P6CFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       cmpF_ccNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       cmpF_ccNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                        cmpF_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                        cmpF_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      cmpF_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      cmpF_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                       cmpX_ccNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                       cmpX_ccNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     cmpX_ccCFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     cmpX_ccCFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    cmpX_ccmemNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    cmpX_ccmemNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  cmpX_ccmemCFNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  cmpX_ccmemCFNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      cmpX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      cmpX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   cmpX_regmemNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   cmpX_regmemNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    subF24_regNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                    subF24_regNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                      subF_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      subF_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    addF24_regNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                    addF24_regNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                      addF_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      addF_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                      addX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      addX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      addX_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      addX_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      addX_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      addX_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    addX_mem_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    addX_mem_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      subX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      subX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      subX_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      subX_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      subX_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      subX_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      mulX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      mulX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      mulX_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      mulX_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      mulX_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      mulX_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    mulX_mem_0Node::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    mulX_mem_0Node::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      divX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      divX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      divX_immNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      divX_immNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      divX_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      divX_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     sqrtX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     sqrtX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     sqrtX_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     sqrtX_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    sqrtXD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    sqrtXD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    sqrtXD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    sqrtXD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      absF_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      absF_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                      absX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      absX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      negF_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      negF_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                      negX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      negX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                addF24_reg_memNode::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *                addF24_reg_memNode::pipeline() const { return (&pipeline_class_034); }

const Pipeline *              addF24_reg_mem_0Node::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *              addF24_reg_mem_0Node::pipeline() const { return (&pipeline_class_034); }

const Pipeline *                  addF_reg_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                  addF_reg_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                addF_reg_mem_0Node::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                addF_reg_mem_0Node::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                addF24_mem_regNode::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *                addF24_mem_regNode::pipeline() const { return (&pipeline_class_034); }

const Pipeline *               addF24_mem_ciscNode::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *               addF24_mem_ciscNode::pipeline() const { return (&pipeline_class_036); }

const Pipeline *             addF24_mem_cisc_0Node::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *             addF24_mem_cisc_0Node::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                addF24_mem_memNode::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                addF24_mem_memNode::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                addF24_reg_immNode::pipeline_class() { return (&pipeline_class_037); }
const Pipeline *                addF24_reg_immNode::pipeline() const { return (&pipeline_class_037); }

const Pipeline *                  addF_reg_immNode::pipeline_class() { return (&pipeline_class_039); }
const Pipeline *                  addF_reg_immNode::pipeline() const { return (&pipeline_class_039); }

const Pipeline *                    mulF24_regNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                    mulF24_regNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                      mulF_regNode::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *                      mulF_regNode::pipeline() const { return (&pipeline_class_027); }

const Pipeline *                mulF24_reg_memNode::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *                mulF24_reg_memNode::pipeline() const { return (&pipeline_class_034); }

const Pipeline *              mulF24_reg_mem_0Node::pipeline_class() { return (&pipeline_class_034); }
const Pipeline *              mulF24_reg_mem_0Node::pipeline() const { return (&pipeline_class_034); }

const Pipeline *                  mulF_reg_memNode::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *                  mulF_reg_memNode::pipeline() const { return (&pipeline_class_031); }

const Pipeline *                mulF_reg_mem_0Node::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *                mulF_reg_mem_0Node::pipeline() const { return (&pipeline_class_031); }

const Pipeline *                mulF24_mem_memNode::pipeline_class() { return (&pipeline_class_036); }
const Pipeline *                mulF24_mem_memNode::pipeline() const { return (&pipeline_class_036); }

const Pipeline *                mulF24_reg_immNode::pipeline_class() { return (&pipeline_class_037); }
const Pipeline *                mulF24_reg_immNode::pipeline() const { return (&pipeline_class_037); }

const Pipeline *                  mulF_reg_immNode::pipeline_class() { return (&pipeline_class_039); }
const Pipeline *                  mulF_reg_immNode::pipeline() const { return (&pipeline_class_039); }

const Pipeline *                mulF_reg_load1Node::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *                mulF_reg_load1Node::pipeline() const { return (&pipeline_class_031); }

const Pipeline *              mulF_reg_load1_0Node::pipeline_class() { return (&pipeline_class_031); }
const Pipeline *              mulF_reg_load1_0Node::pipeline() const { return (&pipeline_class_031); }

const Pipeline *           addF_mulF_reg_load1Node::pipeline_class() { return (&pipeline_class_029); }
const Pipeline *           addF_mulF_reg_load1Node::pipeline() const { return (&pipeline_class_029); }

const Pipeline *         addF_mulF_reg_load1_1Node::pipeline_class() { return (&pipeline_class_029); }
const Pipeline *         addF_mulF_reg_load1_1Node::pipeline() const { return (&pipeline_class_029); }

const Pipeline *         addF_mulF_reg_load1_0Node::pipeline_class() { return (&pipeline_class_029); }
const Pipeline *         addF_mulF_reg_load1_0Node::pipeline() const { return (&pipeline_class_029); }

const Pipeline *         addF_mulF_reg_load1_2Node::pipeline_class() { return (&pipeline_class_029); }
const Pipeline *         addF_mulF_reg_load1_2Node::pipeline() const { return (&pipeline_class_029); }

const Pipeline *                 addF_mulF_regNode::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *                 addF_mulF_regNode::pipeline() const { return (&pipeline_class_027); }

const Pipeline *               addF_mulF_reg_0Node::pipeline_class() { return (&pipeline_class_027); }
const Pipeline *               addF_mulF_reg_0Node::pipeline() const { return (&pipeline_class_027); }

const Pipeline *                 subF_divF_regNode::pipeline_class() { return (&pipeline_class_028); }
const Pipeline *                 subF_divF_regNode::pipeline() const { return (&pipeline_class_028); }

const Pipeline *                    divF24_regNode::pipeline_class() { return (&pipeline_class_033); }
const Pipeline *                    divF24_regNode::pipeline() const { return (&pipeline_class_033); }

const Pipeline *                      divF_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                      divF_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    modF24_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    modF24_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      modF_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      modF_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      modX_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      modX_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *            roundFloat_mem_regNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *            roundFloat_mem_regNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *           roundDouble_mem_regNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *           roundDouble_mem_regNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *                   convD2X_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convD2X_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  convXD2X_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convXD2X_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convF2D_reg_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *               convF2D_reg_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                   convX2D_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convX2D_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  convX2XD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convX2XD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convD2I_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               convD2I_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *              convXD2I_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *              convXD2I_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convD2L_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               convD2L_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *              convXD2L_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *              convXD2L_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convF2I_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               convF2I_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convX2I_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convX2I_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convF2L_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               convF2L_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *               convX2L_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *               convX2L_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convI2D_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                   convI2D_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                  convI2XD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convI2XD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  convI2XD_memNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convI2XD_memNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 convXI2XD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 convXI2XD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convI2D_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                   convI2D_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                 conv24I2F_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                 conv24I2F_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                   convI2F_SSFNode::pipeline_class() { return (&pipeline_class_035); }
const Pipeline *                   convI2F_SSFNode::pipeline() const { return (&pipeline_class_035); }

const Pipeline *               convI2F_SSF_memNode::pipeline_class() { return (&pipeline_class_035); }
const Pipeline *               convI2F_SSF_memNode::pipeline() const { return (&pipeline_class_035); }

const Pipeline *                   convI2F_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                   convI2F_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                   convI2F_memNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *                   convI2F_memNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *                   convI2X_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convI2X_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  convXI2X_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convXI2X_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convI2L_regNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                   convI2L_regNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *               convI2L_reg_zexNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *               convI2L_reg_zexNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                    zerox_longNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *                    zerox_longNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *                   convL2D_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convL2D_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  convL2XD_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  convL2XD_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convL2X_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convL2X_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convL2F_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   convL2F_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                   convL2I_regNode::pipeline_class() { return (&pipeline_class_005); }
const Pipeline *                   convL2I_regNode::pipeline() const { return (&pipeline_class_005); }

const Pipeline *             MoveF2I_stack_regNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *             MoveF2I_stack_regNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *             MoveF2I_reg_stackNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *             MoveF2I_reg_stackNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *         MoveF2I_reg_stack_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *         MoveF2I_reg_stack_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           MoveF2I_reg_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           MoveF2I_reg_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             MoveI2F_reg_stackNode::pipeline_class() { return (&pipeline_class_012); }
const Pipeline *             MoveI2F_reg_stackNode::pipeline() const { return (&pipeline_class_012); }

const Pipeline *             MoveI2F_stack_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *             MoveI2F_stack_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *         MoveI2F_stack_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *         MoveI2F_stack_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           MoveI2F_reg_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           MoveI2F_reg_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             MoveD2L_stack_regNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *             MoveD2L_stack_regNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *             MoveD2L_reg_stackNode::pipeline_class() { return (&pipeline_class_032); }
const Pipeline *             MoveD2L_reg_stackNode::pipeline() const { return (&pipeline_class_032); }

const Pipeline *         MoveD2L_reg_stack_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *         MoveD2L_reg_stack_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           MoveD2L_reg_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           MoveD2L_reg_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             MoveL2D_reg_stackNode::pipeline_class() { return (&pipeline_class_013); }
const Pipeline *             MoveL2D_reg_stackNode::pipeline() const { return (&pipeline_class_013); }

const Pipeline *             MoveL2D_stack_regNode::pipeline_class() { return (&pipeline_class_030); }
const Pipeline *             MoveL2D_stack_regNode::pipeline() const { return (&pipeline_class_030); }

const Pipeline *         MoveL2D_stack_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *         MoveL2D_stack_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline * MoveL2D_stack_reg_sse_partialNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline * MoveL2D_stack_reg_sse_partialNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *           MoveL2D_reg_reg_sseNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           MoveL2D_reg_reg_sseNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    Repl8B_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                    Repl8B_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  Repl8B_eRegINode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  Repl8B_eRegINode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  Repl8B_immI0Node::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl8B_immI0Node::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    Repl4S_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                    Repl4S_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl4S_eRegINode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl4S_eRegINode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl4S_immI0Node::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl4S_immI0Node::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    Repl4C_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                    Repl4C_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl4C_eRegINode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl4C_eRegINode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl4C_immI0Node::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl4C_immI0Node::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    Repl2I_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                    Repl2I_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl2I_eRegINode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl2I_eRegINode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                  Repl2I_immI0Node::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                  Repl2I_immI0Node::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                    Repl2F_regNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                    Repl2F_regNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                   Repl2F_regXNode::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                   Repl2F_regXNode::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                 Repl2F_immXF0Node::pipeline_class() { return (&pipeline_class_026); }
const Pipeline *                 Repl2F_immXF0Node::pipeline() const { return (&pipeline_class_026); }

const Pipeline *                      rep_stosNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                      rep_stosNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                string_compareNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                string_compareNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 string_equalsNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 string_equalsNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                string_indexofNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                string_indexofNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  array_equalsNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                  array_equalsNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                    compI_eRegNode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *                    compI_eRegNode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *                compI_eReg_immNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                compI_eReg_immNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                compI_eReg_memNode::pipeline_class() { return (&pipeline_class_019); }
const Pipeline *                compI_eReg_memNode::pipeline() const { return (&pipeline_class_019); }

const Pipeline *                     testI_regNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                     testI_regNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                 testI_reg_immNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                 testI_reg_immNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                 testI_reg_memNode::pipeline_class() { return (&pipeline_class_019); }
const Pipeline *                 testI_reg_memNode::pipeline() const { return (&pipeline_class_019); }

const Pipeline *                    compU_eRegNode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *                    compU_eRegNode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *                compU_eReg_immNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                compU_eReg_immNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                compU_eReg_memNode::pipeline_class() { return (&pipeline_class_019); }
const Pipeline *                compU_eReg_memNode::pipeline() const { return (&pipeline_class_019); }

const Pipeline *                     testU_regNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                     testU_regNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                    compP_eRegNode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *                    compP_eRegNode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *                compP_eReg_immNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                compP_eReg_immNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                compP_eReg_memNode::pipeline_class() { return (&pipeline_class_019); }
const Pipeline *                compP_eReg_memNode::pipeline() const { return (&pipeline_class_019); }

const Pipeline *                compP_mem_eRegNode::pipeline_class() { return (&pipeline_class_019); }
const Pipeline *                compP_mem_eRegNode::pipeline() const { return (&pipeline_class_019); }

const Pipeline *                     testP_regNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                     testP_regNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                 testP_Reg_memNode::pipeline_class() { return (&pipeline_class_018); }
const Pipeline *                 testP_Reg_memNode::pipeline() const { return (&pipeline_class_018); }

const Pipeline *                     minI_eRegNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     minI_eRegNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                     maxI_eRegNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                     maxI_eRegNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                      jumpXtndNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                      jumpXtndNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                        jmpDirNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                        jmpDirNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                        jmpConNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                        jmpConNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                    jmpLoopEndNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                    jmpLoopEndNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                   jmpLoopEndUNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                   jmpLoopEndUNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                 jmpLoopEndUCFNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                 jmpLoopEndUCFNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                       jmpConUNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                       jmpConUNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                     jmpConUCFNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                     jmpConUCFNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                    jmpConUCF2Node::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                    jmpConUCF2Node::pipeline() const { return (&pipeline_class_041); }

const Pipeline *           partialSubtypeCheckNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *           partialSubtypeCheckNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *   partialSubtypeCheck_vs_ZeroNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *   partialSubtypeCheck_vs_ZeroNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                  jmpDir_shortNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                  jmpDir_shortNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                  jmpCon_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                  jmpCon_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *              jmpLoopEnd_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *              jmpLoopEnd_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *             jmpLoopEndU_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *             jmpLoopEndU_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *           jmpLoopEndUCF_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *           jmpLoopEndUCF_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                 jmpConU_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *                 jmpConU_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *               jmpConUCF_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *               jmpConUCF_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *              jmpConUCF2_shortNode::pipeline_class() { return (&pipeline_class_041); }
const Pipeline *              jmpConUCF2_shortNode::pipeline() const { return (&pipeline_class_041); }

const Pipeline *                 cmpL3_reg_regNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 cmpL3_reg_regNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *          cmpL_zero_flags_LTGENode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *          cmpL_zero_flags_LTGENode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *           cmpL_reg_flags_LTGENode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *           cmpL_reg_flags_LTGENode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *               cmovLL_reg_LTGENode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_reg_LTGENode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovLL_mem_LTGENode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_mem_LTGENode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovII_reg_LTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovII_reg_LTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *               cmovII_mem_LTGENode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *               cmovII_mem_LTGENode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *               cmovPP_reg_LTGENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovPP_reg_LTGENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *          cmpL_zero_flags_EQNENode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *          cmpL_zero_flags_EQNENode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *           cmpL_reg_flags_EQNENode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *           cmpL_reg_flags_EQNENode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *               cmovLL_reg_EQNENode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_reg_EQNENode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovLL_mem_EQNENode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_mem_EQNENode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovII_reg_EQNENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovII_reg_EQNENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *               cmovII_mem_EQNENode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *               cmovII_mem_EQNENode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *               cmovPP_reg_EQNENode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovPP_reg_EQNENode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *          cmpL_zero_flags_LEGTNode::pipeline_class() { return (&pipeline_class_006); }
const Pipeline *          cmpL_zero_flags_LEGTNode::pipeline() const { return (&pipeline_class_006); }

const Pipeline *           cmpL_reg_flags_LEGTNode::pipeline_class() { return (&pipeline_class_017); }
const Pipeline *           cmpL_reg_flags_LEGTNode::pipeline() const { return (&pipeline_class_017); }

const Pipeline *               cmovLL_reg_LEGTNode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_reg_LEGTNode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovLL_mem_LEGTNode::pipeline_class() { return (&pipeline_class_023); }
const Pipeline *               cmovLL_mem_LEGTNode::pipeline() const { return (&pipeline_class_023); }

const Pipeline *               cmovII_reg_LEGTNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovII_reg_LEGTNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *               cmovII_mem_LEGTNode::pipeline_class() { return (&pipeline_class_022); }
const Pipeline *               cmovII_mem_LEGTNode::pipeline() const { return (&pipeline_class_022); }

const Pipeline *               cmovPP_reg_LEGTNode::pipeline_class() { return (&pipeline_class_021); }
const Pipeline *               cmovPP_reg_LEGTNode::pipeline() const { return (&pipeline_class_021); }

const Pipeline *          CallStaticJavaDirectNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *          CallStaticJavaDirectNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *          CallStaticJavaHandleNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *          CallStaticJavaHandleNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *         CallDynamicJavaDirectNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *         CallDynamicJavaDirectNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *             CallRuntimeDirectNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *             CallRuntimeDirectNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                CallLeafDirectNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                CallLeafDirectNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *            CallLeafNoFPDirectNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *            CallLeafNoFPDirectNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                           RetNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                           RetNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                TailCalljmpIndNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                TailCalljmpIndNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                    tailjmpIndNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *                    tailjmpIndNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *               CreateExceptionNode::pipeline_class() { return (&pipeline_class_044); }
const Pipeline *               CreateExceptionNode::pipeline() const { return (&pipeline_class_044); }

const Pipeline *              RethrowExceptionNode::pipeline_class() { return (&pipeline_class_040); }
const Pipeline *              RethrowExceptionNode::pipeline() const { return (&pipeline_class_040); }

const Pipeline *                   cmpFastLockNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                   cmpFastLockNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                 cmpFastUnlockNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *                 cmpFastUnlockNode::pipeline() const { return (&pipeline_class_043); }

const Pipeline *                safePoint_pollNode::pipeline_class() { return (&pipeline_class_009); }
const Pipeline *                safePoint_pollNode::pipeline() const { return (&pipeline_class_009); }

const Pipeline *                      tlsLoadPNode::pipeline_class() { return (&pipeline_class_003); }
const Pipeline *                      tlsLoadPNode::pipeline() const { return (&pipeline_class_003); }

const Pipeline *            ShouldNotReachHereNode::pipeline_class() { return (&pipeline_class_043); }
const Pipeline *            ShouldNotReachHereNode::pipeline() const { return (&pipeline_class_043); }
// Check consistency of C++ compilation with ADLC options:
// Check adlc -DLINUX=1
#ifndef LINUX
#  error "LINUX must be defined"
#endif // LINUX
// Check adlc -D_GNU_SOURCE=1
#ifndef _GNU_SOURCE
#  error "_GNU_SOURCE must be defined"
#endif // _GNU_SOURCE
// Check adlc -DIA32=1
#ifndef IA32
#  error "IA32 must be defined"
#endif // IA32
// Check adlc -U_LP64
#ifdef _LP64
#  error "_LP64 must not be defined"
#endif // _LP64
