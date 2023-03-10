## Initial Program: 

```
ulimit -S -v 9000000; perf stat -e cycles -e instructions -e branch-misses -e LLC-load-misses -e LLC-store-misses ./ramasort 10000000000000
114359 Ramanujan numbers up to 10000000000000, checksum=355033384379411459
occupation=205002588, size=232079541
Memory usage: >=3713272656

 Performance counter stats for './ramasort 10000000000000':

   109,728,455,751      cpu_core/cycles:u/                                                   (100.00%)
     3,305,133,731      cpu_atom/cycles:u/                                                   (0.00%)
   192,354,324,367      cpu_core/instructions:u/                                             (100.00%)
         2,340,746      cpu_atom/instructions:u/                                             (0.00%)
       607,012,180      cpu_core/branch-misses:u/                                            (100.00%)
                 0      cpu_atom/branch-misses:u/                                            (0.00%)
        73,441,348      cpu_core/LLC-load-misses:u/                                          (100.00%)
                 0      cpu_atom/LLC-load-misses:u/                                          (0.00%)
         3,716,526      cpu_core/LLC-store-misses:u/                                         (100.00%)
                 0      cpu_atom/LLC-store-misses:u/                                         (0.00%)

      24.236310607 seconds time elapsed

      23.426162000 seconds user
       0.778852000 seconds sys
```

## 1. Iteration: Reduce Struct Size

Entfernen von unnötigen Einträgen im Struct (integer-Werte)

```
gcc -O -Wall ramasort.c -lm -o ramasort
ulimit -S -v 9000000; perf stat -e cycles -e instructions -e branch-misses -e LLC-load-misses -e LLC-store-misses ./ramasort 10000000000000
table_size: 232079541
114359 Ramanujan numbers up to 10000000000000, checksum=355033384379411459
occupation=205002588, size=232079541
Memory usage: >=1856636328

 Performance counter stats for './ramasort 10000000000000':

    57,369,943,614      cpu_core/cycles:u/                                                 
     <not counted>      cpu_atom/cycles:u/                                            (0.00%)
   120,839,834,607      cpu_core/instructions:u/                                           
     <not counted>      cpu_atom/instructions:u/                                      (0.00%)
       586,809,034      cpu_core/branch-misses:u/                                          
     <not counted>      cpu_atom/branch-misses:u/                                     (0.00%)
        34,321,262      cpu_core/LLC-load-misses:u/                                        
     <not counted>      cpu_atom/LLC-load-misses:u/                                     (0.00%)
         1,353,554      cpu_core/LLC-store-misses:u/                                       
     <not counted>      cpu_atom/LLC-store-misses:u/                                     (0.00%)

      12.666080526 seconds time elapsed

      12.254395000 seconds user
       0.396027000 seconds sys
```

## 2. Iteration - Slicing (basic)

## 3. Optimieren der lower-bound des "j"

## 4. Slicing Improvement

## 5. Austesten des Slicing Memory Limits

## 6. Cubs, ...