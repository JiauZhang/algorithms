# SHELL_SCRIPT /YOUR/FILES/PATH YOUR_FILTER_RULE /YOUR/LICENSE/FILE

echo "PATH: "$1
echo "FILTER RULE: "$2
echo "LICENSE FILE: "$3
license_file=$3
# blank is illegal! 
target_files=`ls $1/$2`
echo "Target files: "$target_files
# fetch source file content
# touch temp_file

for file in $target_files
do
    echo "add license to file: "$file
    cat $file > temp_file
    # add license
    cat $license_file > $file
    echo >> $file
    echo >> $file
    cat temp_file >> $file
done

rm temp_file