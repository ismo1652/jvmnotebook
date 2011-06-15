#!/bin/sh

cat vm/includeDB_core vm/includeDB_gc vm/includeDB_gc_parallel vm/gc_implementation/includeDB_gc_parallelScavenge vm/gc_implementation/includeDB_gc_concurrentMarkSweep vm/gc_implementation/includeDB_gc_parNew vm/gc_implementation/includeDB_gc_g1 vm/gc_implementation/includeDB_gc_serial vm/gc_implementation/includeDB_gc_shared vm/includeDB_jvmti  vm/includeDB_features vm/includeDB_compiler1 vm/includeDB_compiler2 > includeDB

# End of File
