#!/bin/sh

java -DUSE_PRECOMPILED_HEADER -cp MakeDeps.jar MakeDeps UnixPlatform platform_i486 src/vm/includeDB

