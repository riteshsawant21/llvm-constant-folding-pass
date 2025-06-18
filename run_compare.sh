#!/bin/bash

echo "🔍 Comparing IR file sizes:"
echo "---------------------------"
original_size=$(stat -c%s "input/test.ll")
folded_size=$(stat -c%s "out/folded.ll")
echo "Original IR size : $original_size bytes"
echo "Folded IR size   : $folded_size bytes"

echo ""
echo "⏱️  Measuring execution time:"
echo "---------------------------"
echo "Original:"
time lli input/test.ll

echo ""
echo "Optimized:"
time lli out/folded.ll

