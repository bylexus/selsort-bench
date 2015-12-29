function selectionsort(arr) {
    var sIndex = 0;
    var smallestIndex = 0;
    var tmp = null;
    var i = 0;
    var count = arr.length;
    while (sIndex < count) {
        smallestIndex = sIndex;
        for (i = sIndex; i < count; i++) {
            if (arr[i] < arr[smallestIndex]) {
                smallestIndex = i;
            }
        }
        if (sIndex < smallestIndex) {
            tmp = arr[smallestIndex];
            arr[smallestIndex] = arr[sIndex];
            arr[sIndex] = tmp;
        }
        sIndex++;
    }
}

var start = 0;
var after_read = 0;
var after_sort = 0;
var inputfile = '/Users/alex/temp/random_numbers.txt';
var data = [];

// start
start = new Date().getTime() / 1000.0;
console.log("Start: " + start);

// Fill vector:
var     lazy    = require("lazy"),
        fs  = require("fs");

new lazy(fs.createReadStream(inputfile))
     .lines
     .forEach(function(line){
         data.push(Number(line.toString()));
     })
     .join(function() {
        after_read = new Date().getTime() / 1000.0;

        // sort array:
        selectionsort(data);

        after_sort = new Date().getTime() / 1000.0;

        console.log("Fill time: " + (after_read - start));
        console.log("Sort time: " + (after_sort - after_read));
        console.log("First nr: " + data[0] + ", last nr: " + data[data.length-1] + ', count: '+data.length);
    });
