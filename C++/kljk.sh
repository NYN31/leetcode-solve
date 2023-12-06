cd $dir;
g++ -std=c++17 $dir$fileName -o $dir$fileNameWithoutExt;

if [ -f $dir$fileNameWithoutExt ]; then
    $dir$fileNameWithoutExt < input.txt > output.txt;
    rm $dir$fileNameWithoutExt;
fi