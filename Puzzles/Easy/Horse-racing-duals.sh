# Solution to the puzzle Horse-racing Duals
# https://www.codingame.com/training/easy/horse-racing-duals

arr=()
read n

for ((i=0 ; i < n ; i++ )); do
    read arr[i]
done

arr=($(printf '%s\n' "${arr[@]}" | sort -g))

diff=0
min_diff=$(( ${arr[1]} - ${arr[0]} ))

for (( i=2 ; i < n ; i++ )); do
   diff=$(( ${arr[$i - 1]} - ${arr[$i]} ))
   if [[ $diff -lt 0 ]]; then
      diff=$((-$diff))
   fi

   if [[ $diff -lt $min_diff ]]; then
      min_diff=$diff
   fi
done

echo $min_diff

