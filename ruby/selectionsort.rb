def selectionsort(arr)
     sIndex = 0;
     smallestIndex = 0;
     tmp = nil;
     i = 0;
     count = arr.length;
    while (sIndex < count) do
        smallestIndex = sIndex;
        for i in sIndex...count do
            if (arr[i] < arr[smallestIndex])
                smallestIndex = i;
            end
        end
        if (sIndex < smallestIndex)
            tmp = arr[smallestIndex];
            arr[smallestIndex] = arr[sIndex];
            arr[sIndex] = tmp;
        end
        sIndex = sIndex+1;
    end
end

start = 0;
after_read = 0;
after_sort = 0;
inputfile = '/Users/alex/temp/random_numbers.txt';
data = [];

#start
start = Time.now;
puts "Start: #{start}";

#Fill vector:
text = File.open(inputfile).read
text.each_line do |line|
    data.push(line.to_i)
end
after_read = Time.now;

#sort array:
selectionsort(data);

after_sort = Time.now;
fill_time = after_read - start;
sort_time = after_sort - after_read;
puts "Fill time: #{fill_time}\n";
puts "Sort time: #{sort_time}\n";
puts "First nr: #{data.first}, last nr: #{data.last}, count: #{data.length}\n";
