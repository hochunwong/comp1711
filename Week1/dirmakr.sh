cd temp
pwd

for ((i=0, i<5, i++))
    fileformat="calculation_"
    filename="${fileformat} ${i}"
    mkdir filename
    echo filename
done

tree