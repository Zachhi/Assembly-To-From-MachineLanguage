//computes sum of 1+2+..+100

@1
M = 1 //sets count equal to  1
@sum 
M = 0
(LOOP)
    @1
    D = M
    @100
    D = D-A //when count equals 100
    @END
    D;JGT //jump to end
    @i 
    D = M
    @sum
    M = D+M //totalSum = totalSum + currentCount
    @1
    M = M + 1
    @LOOP
    0;JMP
(END) //end loop
    @END
    0;JMP