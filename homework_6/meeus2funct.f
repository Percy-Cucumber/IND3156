      program meeus2
c
          integer i
          double precision x
c
          x = 1.D0/3.D0
          do i = 0, 33
              write(*,'(A4,I3,A5,D29.22)') '  i=', i, ',  x=', x
               x = replace(x)
          end do
c
      end program
c
      real function replace(input)
            double precision :: input
            replace =(9.D0*input + 1.D0)*input - 1.D0
            return
      end function
c	  
c	
c	  
! referenced http://www.chem.ox.ac.uk/fortran/subprograms.html
	  