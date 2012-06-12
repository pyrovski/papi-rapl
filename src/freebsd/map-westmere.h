/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    map-westmere.h
* CVS:     $Id:$
* Author:  George Neville-Neil
*          gnn@freebsd.org
*/

#ifndef FreeBSD_MAP_WESTMERE
#define FreeBSD_MAP_WESTMERE

enum NativeEvent_Value_WestmereProcessor {
	PNE_WESTMERE_LOAD_BLOCK_OVERLAP_STORE= PAPI_NATIVE_MASK ,
	PNE_WESTMERE_SB_DRAIN_ANY,
	PNE_WESTMERE_MISALIGN_MEMORY_STORE,
	PNE_WESTMERE_STORE_BLOCKS_AT_RET,
	PNE_WESTMERE_STORE_BLOCKS_L1D_BLOCK,
	PNE_WESTMERE_PARTIAL_ADDRESS_ALIAS,
	PNE_WESTMERE_DTLB_LOAD_MISSES_ANY,
	PNE_WESTMERE_DTLB_LOAD_MISSES_WALK_COMPLETED,
	PNE_WESTMERE_DTLB_LOAD_MISSES_WALK_CYCLES,
	PNE_WESTMERE_DTLB_LOAD_MISSES_STLB_HIT,
	PNE_WESTMERE_DTLB_LOAD_MISSES_PDE_MISS,
	PNE_WESTMERE_MEM_INST_RETIRED_LOADS,
	PNE_WESTMERE_MEM_INST_RETIRED_STORES,
	PNE_WESTMERE_MEM_INST_RETIRED_LATENCY_ABOVE_THRESHOLD,
	PNE_WESTMERE_MEM_STORE_RETIRED_DTLB_MISS,
	PNE_WESTMERE_UOPS_ISSUED_ANY,
	PNE_WESTMERE_UOPS_ISSUED_STALLED_CYCLES,
	PNE_WESTMERE_UOPS_ISSUED_FUSED,
	PNE_WESTMERE_MEM_UNCORE_RETIRED_LOCAL_HITM,
	PNE_WESTMERE_MEM_UNCORE_RETIRED_LOCAL_DRAM_AND_REMOTE_CACHE_HIT,
	PNE_WESTMERE_MEM_UNCORE_RETIRED_LOCAL_DRAM,
	PNE_WESTMERE_MEM_UNCORE_RETIRED_REMOTE_DRAM,
	PNE_WESTMERE_MEM_UNCORE_RETIRED_UNCACHEABLE,
	PNE_WESTMERE_FP_COMP_OPS_EXE_X87,
	PNE_WESTMERE_FP_COMP_OPS_EXE_MMX,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE_FP,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE2_INTEGER,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE_FP_PACKED,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE_FP_SCALAR,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE_SINGLE_PRECISION,
	PNE_WESTMERE_FP_COMP_OPS_EXE_SSE_DOUBLE_PRECISION,
	PNE_WESTMERE_SIMD_INT_128_PACKED_MPY,
	PNE_WESTMERE_SIMD_INT_128_PACKED_SHIFT,
	PNE_WESTMERE_SIMD_INT_128_PACK,
	PNE_WESTMERE_SIMD_INT_128_UNPACK,
	PNE_WESTMERE_SIMD_INT_128_PACKED_LOGICAL,
	PNE_WESTMERE_SIMD_INT_128_PACKED_ARITH,
	PNE_WESTMERE_SIMD_INT_128_SHUFFLE_MOVE,
	PNE_WESTMERE_LOAD_DISPATCH_RS,
	PNE_WESTMERE_LOAD_DISPATCH_RS_DELAYED,
	PNE_WESTMERE_LOAD_DISPATCH_MOB,
	PNE_WESTMERE_LOAD_DISPATCH_ANY,
	PNE_WESTMERE_ARITH_CYCLES_DIV_BUSY,
	PNE_WESTMERE_ARITH_MUL,
	PNE_WESTMERE_INST_QUEUE_WRITES,
	PNE_WESTMERE_INST_DECODED_DEC0,
	PNE_WESTMERE_TWO_UOP_INSTS_DECODED,
	PNE_WESTMERE_INST_QUEUE_WRITE_CYCLES,
	PNE_WESTMERE_LSD_OVERFLOW,
	PNE_WESTMERE_L2_RQSTS_LD_HIT,
	PNE_WESTMERE_L2_RQSTS_LD_MISS,
	PNE_WESTMERE_L2_RQSTS_LOADS,
	PNE_WESTMERE_L2_RQSTS_RFO_HIT,
	PNE_WESTMERE_L2_RQSTS_RFO_MISS,
	PNE_WESTMERE_L2_RQSTS_RFOS,
	PNE_WESTMERE_L2_RQSTS_IFETCH_HIT,
	PNE_WESTMERE_L2_RQSTS_IFETCH_MISS,
	PNE_WESTMERE_L2_RQSTS_IFETCHES,
	PNE_WESTMERE_L2_RQSTS_PREFETCH_HIT,
	PNE_WESTMERE_L2_RQSTS_PREFETCH_MISS,
	PNE_WESTMERE_L2_RQSTS_PREFETCHES,
	PNE_WESTMERE_L2_RQSTS_MISS,
	PNE_WESTMERE_L2_RQSTS_REFERENCES,
	PNE_WESTMERE_L2_DATA_RQSTS_DEMAND_I_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_DEMAND_S_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_DEMAND_E_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_DEMAND_M_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_DEMAND_MESI,
	PNE_WESTMERE_L2_DATA_RQSTS_PREFETCH_I_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_PREFETCH_S_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_PREFETCH_E_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_PREFETCH_M_STATE,
	PNE_WESTMERE_L2_DATA_RQSTS_PREFETCH_MESI,
	PNE_WESTMERE_L2_DATA_RQSTS_ANY,
	PNE_WESTMERE_L2_WRITE_RFO_I_STATE,
	PNE_WESTMERE_L2_WRITE_RFO_S_STATE,
	PNE_WESTMERE_L2_WRITE_RFO_M_STATE,
	PNE_WESTMERE_L2_WRITE_RFO_HIT,
	PNE_WESTMERE_L2_WRITE_RFO_MESI,
	PNE_WESTMERE_L2_WRITE_LOCK_I_STATE,
	PNE_WESTMERE_L2_WRITE_LOCK_S_STATE,
	PNE_WESTMERE_L2_WRITE_LOCK_E_STATE,
	PNE_WESTMERE_L2_WRITE_LOCK_M_STATE,
	PNE_WESTMERE_L2_WRITE_LOCK_HIT,
	PNE_WESTMERE_L2_WRITE_LOCK_MESI,
	PNE_WESTMERE_L1D_WB_L2_I_STATE,
	PNE_WESTMERE_L1D_WB_L2_S_STATE,
	PNE_WESTMERE_L1D_WB_L2_E_STATE,
	PNE_WESTMERE_L1D_WB_L2_M_STATE,
	PNE_WESTMERE_L1D_WB_L2_MESI,
	PNE_WESTMERE_L3_LAT_CACHE_REFERENCE,
	PNE_WESTMERE_L3_LAT_CACHE_MISS,
	PNE_WESTMERE_CPU_CLK_UNHALTED_THREAD_P,
	PNE_WESTMERE_CPU_CLK_UNHALTED_REF_P,
	PNE_WESTMERE_DTLB_MISSES_ANY,
	PNE_WESTMERE_DTLB_MISSES_WALK_COMPLETED,
	PNE_WESTMERE_DTLB_MISSES_WALK_CYCLES,
	PNE_WESTMERE_DTLB_MISSES_STLB_HIT,
	PNE_WESTMERE_DTLB_MISSES_LARGE_WALK_COMPLETED,
	PNE_WESTMERE_LOAD_HIT_PRE,
	PNE_WESTMERE_L1D_PREFETCH_REQUESTS,
	PNE_WESTMERE_L1D_PREFETCH_MISS,
	PNE_WESTMERE_L1D_PREFETCH_TRIGGERS,
	PNE_WESTMERE_EPT_WALK_CYCLES,
	PNE_WESTMERE_L1D_REPL,
	PNE_WESTMERE_L1D_M_REPL,
	PNE_WESTMERE_L1D_M_EVICT,
	PNE_WESTMERE_L1D_M_SNOOP_EVICT,
	PNE_WESTMERE_L1D_CACHE_PREFETCH_LOCK_FB_HIT,
	PNE_WESTMERE_L1D_CACHE_LOCK_FB_HIT,
	PNE_WESTMERE_OFFCORE_REQUESTS_OUTSTANDING_DEMAND_READ_DATA,
	PNE_WESTMERE_OFFCORE_REQUESTS_OUTSTANDING_DEMAND_READ_CODE,
	PNE_WESTMERE_OFFCORE_REQUESTS_OUTSTANDING_DEMAND_RFO,
	PNE_WESTMERE_OFFCORE_REQUESTS_OUTSTANDING_ANY_READ,
	PNE_WESTMERE_CACHE_LOCK_CYCLES_L1D_L2,
	PNE_WESTMERE_CACHE_LOCK_CYCLES_L1D,
	PNE_WESTMERE_IO_TRANSACTIONS,
	PNE_WESTMERE_L1I_HITS,
	PNE_WESTMERE_L1I_MISSES,
	PNE_WESTMERE_L1I_READS,
	PNE_WESTMERE_L1I_CYCLES_STALLED,
	PNE_WESTMERE_LARGE_ITLB_HIT,
	PNE_WESTMERE_ITLB_MISSES_ANY,
	PNE_WESTMERE_ITLB_MISSES_WALK_COMPLETED,
	PNE_WESTMERE_ITLB_MISSES_WALK_CYCLES,
	PNE_WESTMERE_ITLB_MISSES_LARGE_WALK_COMPLETED,
	PNE_WESTMERE_ILD_STALL_LCP,
	PNE_WESTMERE_ILD_STALL_MRU,
	PNE_WESTMERE_ILD_STALL_IQ_FULL,
	PNE_WESTMERE_ILD_STALL_REGEN,
	PNE_WESTMERE_ILD_STALL_ANY,
	PNE_WESTMERE_BR_INST_EXEC_COND,
	PNE_WESTMERE_BR_INST_EXEC_DIRECT,
	PNE_WESTMERE_BR_INST_EXEC_INDIRECT_NON_CALL,
	PNE_WESTMERE_BR_INST_EXEC_NON_CALLS,
	PNE_WESTMERE_BR_INST_EXEC_RETURN_NEAR,
	PNE_WESTMERE_BR_INST_EXEC_DIRECT_NEAR_CALL,
	PNE_WESTMERE_BR_INST_EXEC_INDIRECT_NEAR_CALL,
	PNE_WESTMERE_BR_INST_EXEC_NEAR_CALLS,
	PNE_WESTMERE_BR_INST_EXEC_TAKEN,
	PNE_WESTMERE_BR_INST_EXEC_ANY,
	PNE_WESTMERE_BR_MISP_EXEC_COND,
	PNE_WESTMERE_BR_MISP_EXEC_DIRECT,
	PNE_WESTMERE_BR_MISP_EXEC_INDIRECT_NON_CALL,
	PNE_WESTMERE_BR_MISP_EXEC_NON_CALLS,
	PNE_WESTMERE_BR_MISP_EXEC_RETURN_NEAR,
	PNE_WESTMERE_BR_MISP_EXEC_DIRECT_NEAR_CALL,
	PNE_WESTMERE_BR_MISP_EXEC_INDIRECT_NEAR_CALL,
	PNE_WESTMERE_BR_MISP_EXEC_NEAR_CALLS,
	PNE_WESTMERE_BR_MISP_EXEC_TAKEN,
	PNE_WESTMERE_BR_MISP_EXEC_ANY,
	PNE_WESTMERE_RESOURCE_STALLS_ANY,
	PNE_WESTMERE_RESOURCE_STALLS_LOAD,
	PNE_WESTMERE_RESOURCE_STALLS_RS_FULL,
	PNE_WESTMERE_RESOURCE_STALLS_STORE,
	PNE_WESTMERE_RESOURCE_STALLS_ROB_FULL,
	PNE_WESTMERE_RESOURCE_STALLS_FPCW,
	PNE_WESTMERE_RESOURCE_STALLS_MXCSR,
	PNE_WESTMERE_RESOURCE_STALLS_OTHER,
	PNE_WESTMERE_MACRO_INSTS_FUSIONS_DECODED,
	PNE_WESTMERE_BACLEAR_FORCE_IQ,
	PNE_WESTMERE_LSD_UOPS,
	PNE_WESTMERE_ITLB_FLUSH,
	PNE_WESTMERE_OFFCORE_REQUESTS_DEMAND_READ_DATA,
	PNE_WESTMERE_OFFCORE_REQUESTS_DEMAND_READ_CODE,
	PNE_WESTMERE_OFFCORE_REQUESTS_DEMAND_RFO,
	PNE_WESTMERE_OFFCORE_REQUESTS_ANY_READ,
	PNE_WESTMERE_OFFCORE_REQUESTS_ANY_RFO,
	PNE_WESTMERE_OFFCORE_REQUESTS_L1D_WRITEBACK,
	PNE_WESTMERE_OFFCORE_REQUESTS_ANY,
	PNE_WESTMERE_UOPS_EXECUTED_PORT0,
	PNE_WESTMERE_UOPS_EXECUTED_PORT1,
	PNE_WESTMERE_UOPS_EXECUTED_PORT2_CORE,
	PNE_WESTMERE_UOPS_EXECUTED_PORT3_CORE,
	PNE_WESTMERE_UOPS_EXECUTED_PORT4_CORE,
	PNE_WESTMERE_UOPS_EXECUTED_CORE_ACTIVE_CYCLES_NO_PORT5,
	PNE_WESTMERE_UOPS_EXECUTED_PORT5,
	PNE_WESTMERE_UOPS_EXECUTED_CORE_ACTIVE_CYCLES,
	PNE_WESTMERE_UOPS_EXECUTED_PORT015,
	PNE_WESTMERE_UOPS_EXECUTED_PORT234,
	PNE_WESTMERE_OFFCORE_REQUESTS_SQ_FULL,
	PNE_WESTMERE_SNOOPQ_REQUESTS_OUTSTANDING_DATA,
	PNE_WESTMERE_SNOOPQ_REQUESTS_OUTSTANDING_INVALIDATE,
	PNE_WESTMERE_SNOOPQ_REQUESTS_OUTSTANDING_CODE,
	PNE_WESTMERE_SNOOPQ_REQUESTS_CODE,
	PNE_WESTMERE_SNOOPQ_REQUESTS_DATA,
	PNE_WESTMERE_SNOOPQ_REQUESTS_INVALIDATE,
	PNE_WESTMERE_OFF_CORE_RESPONSE_0,
	PNE_WESTMERE_SNOOP_RESPONSE_HIT,
	PNE_WESTMERE_SNOOP_RESPONSE_HITE,
	PNE_WESTMERE_SNOOP_RESPONSE_HITM,
	PNE_WESTMERE_OFF_CORE_RESPONSE_1,
	PNE_WESTMERE_INST_RETIRED_ANY_P,
	PNE_WESTMERE_INST_RETIRED_X87,
	PNE_WESTMERE_INST_RETIRED_MMX,
	PNE_WESTMERE_UOPS_RETIRED_ANY,
	PNE_WESTMERE_UOPS_RETIRED_RETIRE_SLOTS,
	PNE_WESTMERE_UOPS_RETIRED_MACRO_FUSED,
	PNE_WESTMERE_MACHINE_CLEARS_CYCLES,
	PNE_WESTMERE_MACHINE_CLEARS_MEM_ORDER,
	PNE_WESTMERE_MACHINE_CLEARS_SMC,
	PNE_WESTMERE_BR_INST_RETIRED_ANY_P,
	PNE_WESTMERE_BR_INST_RETIRED_CONDITIONAL,
	PNE_WESTMERE_BR_INST_RETIRED_NEAR_CALL,
	PNE_WESTMERE_BR_INST_RETIRED_ALL_BRANCHES,
	PNE_WESTMERE_BR_MISP_RETIRED_ANY_P,
	PNE_WESTMERE_BR_MISP_RETIRED_CONDITIONAL,
	PNE_WESTMERE_BR_MISP_RETIRED_NEAR_CALL,
	PNE_WESTMERE_BR_MISP_RETIRED_ALL_BRANCHES,
	PNE_WESTMERE_SSEX_UOPS_RETIRED_PACKED_SINGLE,
	PNE_WESTMERE_SSEX_UOPS_RETIRED_SCALAR_SINGLE,
	PNE_WESTMERE_SSEX_UOPS_RETIRED_PACKED_DOUBLE,
	PNE_WESTMERE_SSEX_UOPS_RETIRED_SCALAR_DOUBLE,
	PNE_WESTMERE_SSEX_UOPS_RETIRED_VECTOR_INTEGER,
	PNE_WESTMERE_ITLB_MISS_RETIRED,
	PNE_WESTMERE_MEM_LOAD_RETIRED_L1D_HIT,
	PNE_WESTMERE_MEM_LOAD_RETIRED_L2_HIT,
	PNE_WESTMERE_MEM_LOAD_RETIRED_L3_UNSHARED_HIT,
	PNE_WESTMERE_MEM_LOAD_RETIRED_OTHER_CORE_L2_HIT_HITM,
	PNE_WESTMERE_MEM_LOAD_RETIRED_L3_MISS,
	PNE_WESTMERE_MEM_LOAD_RETIRED_HIT_LFB,
	PNE_WESTMERE_MEM_LOAD_RETIRED_DTLB_MISS,
	PNE_WESTMERE_FP_MMX_TRANS_TO_FP,
	PNE_WESTMERE_FP_MMX_TRANS_TO_MMX,
	PNE_WESTMERE_FP_MMX_TRANS_ANY,
	PNE_WESTMERE_MACRO_INSTS_DECODED,
	PNE_WESTMERE_UOPS_DECODED_STALL_CYCLES,
	PNE_WESTMERE_UOPS_DECODED_MS,
	PNE_WESTMERE_UOPS_DECODED_ESP_FOLDING,
	PNE_WESTMERE_UOPS_DECODED_ESP_SYNC,
	PNE_WESTMERE_RAT_STALLS_FLAGS,
	PNE_WESTMERE_RAT_STALLS_REGISTERS,
	PNE_WESTMERE_RAT_STALLS_ROB_READ_PORT,
	PNE_WESTMERE_RAT_STALLS_SCOREBOARD,
	PNE_WESTMERE_RAT_STALLS_ANY,
	PNE_WESTMERE_SEG_RENAME_STALLS,
	PNE_WESTMERE_ES_REG_RENAMES,
	PNE_WESTMERE_UOP_UNFUSION,
	PNE_WESTMERE_BR_INST_DECODED,
	PNE_WESTMERE_BPU_MISSED_CALL_RET,
	PNE_WESTMERE_BACLEAR_CLEAR,
	PNE_WESTMERE_BACLEAR_BAD_TARGET,
	PNE_WESTMERE_BPU_CLEARS_EARLY,
	PNE_WESTMERE_BPU_CLEARS_LATE,
	PNE_WESTMERE_THREAD_ACTIVE,
	PNE_WESTMERE_L2_TRANSACTIONS_LOAD,
	PNE_WESTMERE_L2_TRANSACTIONS_RFO,
	PNE_WESTMERE_L2_TRANSACTIONS_IFETCH,
	PNE_WESTMERE_L2_TRANSACTIONS_PREFETCH,
	PNE_WESTMERE_L2_TRANSACTIONS_L1D_WB,
	PNE_WESTMERE_L2_TRANSACTIONS_FILL,
	PNE_WESTMERE_L2_TRANSACTIONS_WB,
	PNE_WESTMERE_L2_TRANSACTIONS_ANY,
	PNE_WESTMERE_L2_LINES_IN_S_STATE,
	PNE_WESTMERE_L2_LINES_IN_E_STATE,
	PNE_WESTMERE_L2_LINES_IN_ANY,
	PNE_WESTMERE_L2_LINES_OUT_DEMAND_CLEAN,
	PNE_WESTMERE_L2_LINES_OUT_DEMAND_DIRTY,
	PNE_WESTMERE_L2_LINES_OUT_PREFETCH_CLEAN,
	PNE_WESTMERE_L2_LINES_OUT_PREFETCH_DIRTY,
	PNE_WESTMERE_L2_LINES_OUT_ANY,
	PNE_WESTMERE_SQ_MISC_LRU_HINTS,
	PNE_WESTMERE_SQ_MISC_SPLIT_LOCK,
	PNE_WESTMERE_SQ_FULL_STALL_CYCLES,
	PNE_WESTMERE_FP_ASSIST_ALL,
	PNE_WESTMERE_FP_ASSIST_OUTPUT,
	PNE_WESTMERE_FP_ASSIST_INPUT,
	PNE_WESTMERE_SIMD_INT_64_PACKED_MPY,
	PNE_WESTMERE_SIMD_INT_64_PACKED_SHIFT,
	PNE_WESTMERE_SIMD_INT_64_PACK,
	PNE_WESTMERE_SIMD_INT_64_UNPACK,
	PNE_WESTMERE_SIMD_INT_64_PACKED_LOGICAL,
	PNE_WESTMERE_SIMD_INT_64_PACKED_ARITH,
	PNE_WESTMERE_SIMD_INT_64_SHUFFLE_MOVE,
	PNE_WESTMERE_INSTR_RETIRED_ANY,
	PNE_WESTMERE_CPU_CLK_UNHALTED_CORE,
	PNE_WESTMERE_CPU_CLK_UNHALTED_REF,
	PNE_WESTMERE_GQ_CYCLES_FULL_READ_TRACKER,
	PNE_WESTMERE_GQ_CYCLES_FULL_WRITE_TRACKER,
	PNE_WESTMERE_GQ_CYCLES_FULL_PEER_PROBE_TRACKER,
	PNE_WESTMERE_GQ_CYCLES_NOT_EMPTY_READ_TRACKER,
	PNE_WESTMERE_GQ_CYCLES_NOT_EMPTY_WRITE_TRACKER,
	PNE_WESTMERE_GQ_CYCLES_NOT_EMPTY_PEER_PROBE_TRACKER,
	PNE_WESTMERE_GQ_OCCUPANCY_READ_TRACKER,
	PNE_WESTMERE_GQ_ALLOC_READ_TRACKER,
	PNE_WESTMERE_GQ_ALLOC_RT_L3_MISS,
	PNE_WESTMERE_GQ_ALLOC_RT_TO_L3_RESP,
	PNE_WESTMERE_GQ_ALLOC_RT_TO_RTID_ACQUIRED,
	PNE_WESTMERE_GQ_ALLOC_WT_TO_RTID_ACQUIRED,
	PNE_WESTMERE_GQ_ALLOC_WRITE_TRACKER,
	PNE_WESTMERE_GQ_ALLOC_PEER_PROBE_TRACKER,
	PNE_WESTMERE_GQ_DATA_FROM_QPI,
	PNE_WESTMERE_GQ_DATA_FROM_QMC,
	PNE_WESTMERE_GQ_DATA_FROM_L3,
	PNE_WESTMERE_GQ_DATA_FROM_CORES_02,
	PNE_WESTMERE_GQ_DATA_FROM_CORES_13,
	PNE_WESTMERE_GQ_DATA_TO_QPI_QMC,
	PNE_WESTMERE_GQ_DATA_TO_L3,
	PNE_WESTMERE_GQ_DATA_TO_CORES,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_I_STATE,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_S_STATE,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_FWD_S_STATE,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_FWD_I_STATE,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_CONFLICT,
	PNE_WESTMERE_SNP_RESP_TO_LOCAL_HOME_WB,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_I_STATE,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_S_STATE,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_FWD_S_STATE,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_FWD_I_STATE,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_CONFLICT,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_WB,
	PNE_WESTMERE_SNP_RESP_TO_REMOTE_HOME_HITM,
	PNE_WESTMERE_L3_HITS_READ,
	PNE_WESTMERE_L3_HITS_WRITE,
	PNE_WESTMERE_L3_HITS_PROBE,
	PNE_WESTMERE_L3_HITS_ANY,
	PNE_WESTMERE_L3_MISS_READ,
	PNE_WESTMERE_L3_MISS_WRITE,
	PNE_WESTMERE_L3_MISS_PROBE,
	PNE_WESTMERE_L3_MISS_ANY,
	PNE_WESTMERE_L3_LINES_IN_M_STATE,
	PNE_WESTMERE_L3_LINES_IN_E_STATE,
	PNE_WESTMERE_L3_LINES_IN_S_STATE,
	PNE_WESTMERE_L3_LINES_IN_F_STATE,
	PNE_WESTMERE_L3_LINES_IN_ANY,
	PNE_WESTMERE_L3_LINES_OUT_M_STATE,
	PNE_WESTMERE_L3_LINES_OUT_E_STATE,
	PNE_WESTMERE_L3_LINES_OUT_S_STATE,
	PNE_WESTMERE_L3_LINES_OUT_I_STATE,
	PNE_WESTMERE_L3_LINES_OUT_F_STATE,
	PNE_WESTMERE_L3_LINES_OUT_ANY,
	PNE_WESTMERE_GQ_SNOOP_GOTO_S,
	PNE_WESTMERE_GQ_SNOOP_GOTO_I,
	PNE_WESTMERE_GQ_SNOOP_GOTO_S_HIT,
	PNE_WESTMERE_GQ_SNOOP_GOTO_I_HIT,
	PNE_WESTMERE_QHL_REQUESTS_IOH_READS,
	PNE_WESTMERE_QHL_REQUESTS_IOH_WRITES,
	PNE_WESTMERE_QHL_REQUESTS_REMOTE_READS,
	PNE_WESTMERE_QHL_REQUESTS_REMOTE_WRITES,
	PNE_WESTMERE_QHL_REQUESTS_LOCAL_READS,
	PNE_WESTMERE_QHL_REQUESTS_LOCAL_WRITES,
	PNE_WESTMERE_QHL_CYCLES_FULL_IOH,
	PNE_WESTMERE_QHL_CYCLES_FULL_REMOTE,
	PNE_WESTMERE_QHL_CYCLES_FULL_LOCAL,
	PNE_WESTMERE_QHL_CYCLES_NOT_EMPTY_IOH,
	PNE_WESTMERE_QHL_CYCLES_NOT_EMPTY_REMOTE,
	PNE_WESTMERE_QHL_CYCLES_NOT_EMPTY_LOCAL,
	PNE_WESTMERE_QHL_OCCUPANCY_IOH,
	PNE_WESTMERE_QHL_OCCUPANCY_REMOTE,
	PNE_WESTMERE_QHL_OCCUPANCY_LOCAL,
	PNE_WESTMERE_QHL_ADDRESS_CONFLICTS_2WAY,
	PNE_WESTMERE_QHL_ADDRESS_CONFLICTS_3WAY,
	PNE_WESTMERE_QHL_CONFLICT_CYCLES_IOH,
	PNE_WESTMERE_QHL_CONFLICT_CYCLES_REMOTE,
	PNE_WESTMERE_QHL_CONFLICT_CYCLES_LOCAL,
	PNE_WESTMERE_QHL_TO_QMC_BYPASS,
	PNE_WESTMERE_QMC_ISOC_FULL_READ_CH0,
	PNE_WESTMERE_QMC_ISOC_FULL_READ_CH1,
	PNE_WESTMERE_QMC_ISOC_FULL_READ_CH2,
	PNE_WESTMERE_QMC_ISOC_FULL_WRITE_CH0,
	PNE_WESTMERE_QMC_ISOC_FULL_WRITE_CH1,
	PNE_WESTMERE_QMC_ISOC_FULL_WRITE_CH2,
	PNE_WESTMERE_QMC_BUSY_READ_CH0,
	PNE_WESTMERE_QMC_BUSY_READ_CH1,
	PNE_WESTMERE_QMC_BUSY_READ_CH2,
	PNE_WESTMERE_QMC_BUSY_WRITE_CH0,
	PNE_WESTMERE_QMC_BUSY_WRITE_CH1,
	PNE_WESTMERE_QMC_BUSY_WRITE_CH2,
	PNE_WESTMERE_QMC_OCCUPANCY_CH0,
	PNE_WESTMERE_QMC_OCCUPANCY_CH1,
	PNE_WESTMERE_QMC_OCCUPANCY_CH2,
	PNE_WESTMERE_QMC_OCCUPANCY_ANY,
	PNE_WESTMERE_QMC_ISSOC_OCCUPANCY_CH0,
	PNE_WESTMERE_QMC_ISSOC_OCCUPANCY_CH1,
	PNE_WESTMERE_QMC_ISSOC_OCCUPANCY_CH2,
	PNE_WESTMERE_QMC_ISSOC_READS_ANY,
	PNE_WESTMERE_QMC_NORMAL_READS_CH0,
	PNE_WESTMERE_QMC_NORMAL_READS_CH1,
	PNE_WESTMERE_QMC_NORMAL_READS_CH2,
	PNE_WESTMERE_QMC_NORMAL_READS_ANY,
	PNE_WESTMERE_QMC_HIGH_PRIORITY_READS_CH0,
	PNE_WESTMERE_QMC_HIGH_PRIORITY_READS_CH1,
	PNE_WESTMERE_QMC_HIGH_PRIORITY_READS_CH2,
	PNE_WESTMERE_QMC_HIGH_PRIORITY_READS_ANY,
	PNE_WESTMERE_QMC_CRITICAL_PRIORITY_READS_CH0,
	PNE_WESTMERE_QMC_CRITICAL_PRIORITY_READS_CH1,
	PNE_WESTMERE_QMC_CRITICAL_PRIORITY_READS_CH2,
	PNE_WESTMERE_QMC_CRITICAL_PRIORITY_READS_ANY,
	PNE_WESTMERE_QMC_WRITES_FULL_CH0,
	PNE_WESTMERE_QMC_WRITES_FULL_CH1,
	PNE_WESTMERE_QMC_WRITES_FULL_CH2,
	PNE_WESTMERE_QMC_WRITES_FULL_ANY,
	PNE_WESTMERE_QMC_WRITES_PARTIAL_CH0,
	PNE_WESTMERE_QMC_WRITES_PARTIAL_CH1,
	PNE_WESTMERE_QMC_WRITES_PARTIAL_CH2,
	PNE_WESTMERE_QMC_WRITES_PARTIAL_ANY,
	PNE_WESTMERE_QMC_CANCEL_CH0,
	PNE_WESTMERE_QMC_CANCEL_CH1,
	PNE_WESTMERE_QMC_CANCEL_CH2,
	PNE_WESTMERE_QMC_CANCEL_ANY,
	PNE_WESTMERE_QMC_PRIORITY_UPDATES_CH0,
	PNE_WESTMERE_QMC_PRIORITY_UPDATES_CH1,
	PNE_WESTMERE_QMC_PRIORITY_UPDATES_CH2,
	PNE_WESTMERE_QMC_PRIORITY_UPDATES_ANY,
	PNE_WESTMERE_IMC_RETRY_CH0,
	PNE_WESTMERE_IMC_RETRY_CH1,
	PNE_WESTMERE_IMC_RETRY_CH2,
	PNE_WESTMERE_IMC_RETRY_ANY,
	PNE_WESTMERE_QHL_FRC_ACK_CNFLTS_IOH,
	PNE_WESTMERE_QHL_FRC_ACK_CNFLTS_REMOTE,
	PNE_WESTMERE_QHL_FRC_ACK_CNFLTS_LOCAL,
	PNE_WESTMERE_QHL_FRC_ACK_CNFLTS_ANY,
	PNE_WESTMERE_QHL_SLEEPS_IOH_ORDER,
	PNE_WESTMERE_QHL_SLEEPS_REMOTE_ORDER,
	PNE_WESTMERE_QHL_SLEEPS_LOCAL_ORDER,
	PNE_WESTMERE_QHL_SLEEPS_IOH_CONFLICT,
	PNE_WESTMERE_QHL_SLEEPS_REMOTE_CONFLICT,
	PNE_WESTMERE_QHL_SLEEPS_LOCAL_CONFLICT,
	PNE_WESTMERE_ADDR_OPCODE_MATCH_IOH,
	PNE_WESTMERE_ADDR_OPCODE_MATCH_REMOTE,
	PNE_WESTMERE_ADDR_OPCODE_MATCH_LOCAL,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_HOME_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_SNOOP_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_NDR_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_HOME_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_SNOOP_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_NDR_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_SINGLE_FLIT_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_DRS_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_NCB_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_NCS_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_DRS_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_NCB_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_NCS_LINK_1,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_LINK_0,
	PNE_WESTMERE_QPI_TX_STALLED_MULTI_FLIT_LINK_1,
	PNE_WESTMERE_QPI_TX_HEADER_FULL_LINK_0,
	PNE_WESTMERE_QPI_TX_HEADER_BUSY_LINK_0,
	PNE_WESTMERE_QPI_TX_HEADER_FULL_LINK_1,
	PNE_WESTMERE_QPI_TX_HEADER_BUSY_LINK_1,
	PNE_WESTMERE_QPI_RX_NO_PPT_CREDIT_STALLS_LINK_0,
	PNE_WESTMERE_QPI_RX_NO_PPT_CREDIT_STALLS_LINK_1,
	PNE_WESTMERE_DRAM_OPEN_CH0,
	PNE_WESTMERE_DRAM_OPEN_CH1,
	PNE_WESTMERE_DRAM_OPEN_CH2,
	PNE_WESTMERE_DRAM_PAGE_CLOSE_CH0,
	PNE_WESTMERE_DRAM_PAGE_CLOSE_CH1,
	PNE_WESTMERE_DRAM_PAGE_CLOSE_CH2,
	PNE_WESTMERE_DRAM_PAGE_MISS_CH0,
	PNE_WESTMERE_DRAM_PAGE_MISS_CH1,
	PNE_WESTMERE_DRAM_PAGE_MISS_CH2,
	PNE_WESTMERE_DRAM_READ_CAS_CH0,
	PNE_WESTMERE_DRAM_READ_CAS_AUTOPRE_CH0,
	PNE_WESTMERE_DRAM_READ_CAS_CH1,
	PNE_WESTMERE_DRAM_READ_CAS_AUTOPRE_CH1,
	PNE_WESTMERE_DRAM_READ_CAS_CH2,
	PNE_WESTMERE_DRAM_READ_CAS_AUTOPRE_CH2,
	PNE_WESTMERE_DRAM_WRITE_CAS_CH0,
	PNE_WESTMERE_DRAM_WRITE_CAS_AUTOPRE_CH0,
	PNE_WESTMERE_DRAM_WRITE_CAS_CH1,
	PNE_WESTMERE_DRAM_WRITE_CAS_AUTOPRE_CH1,
	PNE_WESTMERE_DRAM_WRITE_CAS_CH2,
	PNE_WESTMERE_DRAM_WRITE_CAS_AUTOPRE_CH2,
	PNE_WESTMERE_DRAM_REFRESH_CH0,
	PNE_WESTMERE_DRAM_REFRESH_CH1,
	PNE_WESTMERE_DRAM_REFRESH_CH2,
	PNE_WESTMERE_DRAM_PRE_ALL_CH0,
	PNE_WESTMERE_DRAM_PRE_ALL_CH1,
	PNE_WESTMERE_DRAM_PRE_ALL_CH2,
	PNE_WESTMERE_DRAM_THERMAL_THROTTLED,
	PNE_WESTMERE_THERMAL_THROTTLING_TEMP_CORE_0,
	PNE_WESTMERE_THERMAL_THROTTLING_TEMP_CORE_1,
	PNE_WESTMERE_THERMAL_THROTTLING_TEMP_CORE_2,
	PNE_WESTMERE_THERMAL_THROTTLING_TEMP_CORE_3,
	PNE_WESTMERE_THERMAL_THROTTLED_TEMP_CORE_0,
	PNE_WESTMERE_THERMAL_THROTTLED_TEMP_CORE_1,
	PNE_WESTMERE_THERMAL_THROTTLED_TEMP_CORE_2,
	PNE_WESTMERE_THERMAL_THROTTLED_TEMP_CORE_3,
	PNE_WESTMERE_PROCHOT_ASSERTION,
	PNE_WESTMERE_THERMAL_THROTTLING_PROCHOT_CORE_0,
	PNE_WESTMERE_THERMAL_THROTTLING_PROCHOT_CORE_1,
	PNE_WESTMERE_THERMAL_THROTTLING_PROCHOT_CORE_2,
	PNE_WESTMERE_THERMAL_THROTTLING_PROCHOT_CORE_3,
	PNE_WESTMERE_TURBO_MODE_CORE_0,
	PNE_WESTMERE_TURBO_MODE_CORE_1,
	PNE_WESTMERE_TURBO_MODE_CORE_2,
	PNE_WESTMERE_TURBO_MODE_CORE_3,
	PNE_WESTMERE_CYCLES_UNHALTED_L3_FLL_ENABLE,
	PNE_WESTMERE_CYCLES_UNHALTED_L3_FLL_DISABLE,
	PNE_WESTMERE_PNE_WESTMERE_NATNAME_GUARD,
};

extern Native_Event_LabelDescription_t WestmereProcessor_info[];
extern hwi_search_t WestmereProcessor_map[];

#endif
