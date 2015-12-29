import time

def selectionsort(arr):
    sIndex = 0;
    smallestIndex = 0;
    tmp = None;
    i = 0;
    count = len(arr);
    while sIndex < count:
        smallestIndex = sIndex;
        for i in range(sIndex,count):
            if arr[i] < arr[smallestIndex]:
                smallestIndex = i;
        if sIndex < smallestIndex:
            tmp = arr[smallestIndex];
            arr[smallestIndex] = arr[sIndex];
            arr[sIndex] = tmp;
        sIndex = sIndex+1;

start = 0;
after_read = 0;
after_sort = 0;
inputfile = '/Users/alex/temp/random_numbers.txt';
data = [];

#start
start = time.time()
print("Start: {0}".format(start));

#Fill vector:
for line in open(inputfile):
    data.append(int(line))
after_read = time.time()

#sort array:
selectionsort(data);

after_sort = time.time()
fill_time = after_read - start;
sort_time = after_sort - after_read;
print("Fill time: {0}\n".format(fill_time));
print("Sort time: {0}\n".format(sort_time));
print("First nr: {0}, last nr: {1}, count: {2}\n".format(data[0],data[len(data)-1],len(data)));
