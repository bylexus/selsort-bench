def selectionsort(int[] arr) {
    int sIndex = 0;
    int smallestIndex = 0;
    int tmp;
    int i = 0;
    int count = arr.length;

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

def start = 0;
def after_read = 0;
def after_sort = 0;
def inputfile = '/Users/alex/temp/random_numbers.txt';
def data = [];
int[] intData;

// start
start = Calendar.instance.time.time / 1000.0;
println("Start: ${start}");

// Fill vector:
new File(inputfile).eachLine {
    line -> data.push(line.toInteger().intValue());
}
intData = new int[data.size()];
for(int i = 0; i < data.size();i++) {
    intData[i] = (int)data[i];
}
after_read = Calendar.instance.time.time / 1000.0;

// sort array:
selectionsort(intData);

after_sort = Calendar.instance.time.time / 1000.0;

println("Fill time: ${after_read - start}");
println("Sort time: ${after_sort - after_read}");
println("First nr: ${intData[0]}, last nr: ${intData[intData.length-1]}, count: ${intData.length}");
