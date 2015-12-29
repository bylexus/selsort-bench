<?php
function selectionsort(SplFixedArray $arr) {
    $sIndex = 0;
    $smallestIndex = 0;
    $tmp = null;
    $count = $arr->count();
    while ($sIndex < $count) {
        $smallestIndex = $sIndex;
        for ($i = $sIndex; $i < $count; $i++) {
            if ($arr[$i] < $arr[$smallestIndex]) {
                $smallestIndex = $i;
            }
        }

        if ($sIndex < $smallestIndex) {
            $tmp = $arr[$smallestIndex];
            $arr[$smallestIndex] = $arr[$sIndex];
            $arr[$sIndex] = $tmp;
        }

        $sIndex++;
    }
}

$start = 0;
$after_read = 0;
$after_sort = 0;
$inputfile = '/Users/alex/temp/random_numbers.txt';
$data = array();

// start
$start = microtime(true);
echo "Start: " . $start . "\n";

// Fill vector:
$file = fopen($inputfile, 'r');
while (($line = fgets($file)) !== false) {
    $data[] = (int)$line;
}
$fixedArray = SplFixedArray::fromArray($data);
$after_read = microtime(true);
// sort array:
selectionsort($fixedArray);

$after_sort = microtime(true);

echo "Fill time: " . ($after_read - $start) . "\n";
echo "Sort time: " . ($after_sort - $after_read) . "\n";
echo "First nr: " . $fixedArray[0] . ", last nr: " . $fixedArray[count($fixedArray)-1] . "\n";
