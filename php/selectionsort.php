<?php
function selectionsort(array &$arr) {
    $sIndex = 0;
    $smallestIndex = 0;
    $tmp = null;
    $count = count($arr);
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
$after_read = microtime(true);

// sort array:
selectionsort($data);

$after_sort = microtime(true);

echo "Fill time: " . ($after_read - $start) . "\n";
echo "Sort time: " . ($after_sort - $after_read) . "\n";
echo "First nr: " . $data[0] . ", last nr: " . $data[count($data)-1] . "\n";
