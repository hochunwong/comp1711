echo "Hello World"
echo "What is your name?"
read NAME

for ((i=0; i<20; i++)) do
    echo "Hello $NAME"
done

for ((i=10; i>0; i--)) do
    echo "$i"
    sleep 0.5s
done
echo " > boom < "
sleep 1s

echo "did u like that?"
read RE
echo "why $RE"
read RE2
echo "why $RE2"
read RE3

