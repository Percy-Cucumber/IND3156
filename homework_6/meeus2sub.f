        program meeus2
c        
        integer i
        double precision x
c        
10      x = 1.0/3.0
20      i = 0
30      if (i .lt. 33) goto 50
40      goto 80
50      i = i + 1
60      call calculation(x)
        write(6,*) 'i=', i, 'x=', x
70      goto 30
80      continue
c
        stop
c
        endprogram meeus2
c
        subroutine calculation(x)
        double precision x
        x = (9.0*x+1)*x-1.0
        return
        end
c
c
c
! referenced http://www.chem.ox.ac.uk/fortran/subprograms.html
