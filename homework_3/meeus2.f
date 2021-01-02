! name
      program meeus2
c
! variables
      integer integer i 		! "i" set as interger
      double precision x		! "x" set as flaoting-point value
c
! code
      x = 1.D0/3.D0				! double precision = floating-point
      do i = 0, 30				! for i interger values ranging from 0 to 30
       write(*,'(A4,I3,A5,D29.22)') '  i=', i, ',  x=', x		! print function
       x = (9.D0*x + 1.D0)*x - 1.D0
      end do
c
! end
      stop
      end
	  
	  
	  
! code template stolen from Ian Hoffman
! referenced http://www-classes.usc.edu/engr/ce/108/text/fbk01.htm