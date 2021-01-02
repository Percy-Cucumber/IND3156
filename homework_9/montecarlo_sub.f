!!! Change FUNCTION(S) !!!
!!! Define: xmin, xmax, ymin, ymax, and nPoints after ./a.out !!!

! program start
      program montecarlo_sub
      implicit none
c
      character*32 arg
      integer total, sdsz
      logical seeder
      double precision xmin, xmax, ymin, ymax, answer
      double precision f
      external f
c
      call banner
      if ( IARGC() .ne. 5 ) goto 1000
c
      call getarg(1,arg)
      read(arg,'(F16.8)',err=1000) xmin
      call getarg(2,arg)
      read(arg,'(F16.8)',err=1000) xmax
      call getarg(3,arg)
      read(arg,'(F16.8)',err=1000) ymin
      call getarg(4,arg)
      read(arg,'(F16.8)',err=1000) ymax
      call getarg(5,arg)
      read(arg,'(I16)',err=1000) total
c
      call random_seed(size=sdsz)
      if ( seeder(sdsz) ) goto 1000
c
      call monte(f, xmin, xmax, ymin, ymax, total, answer)
      write(6,'(SPF12.8)') 4.*answer
c
1000  continue
      stop
      end
c
c
c
!!! ---- FUNCTIONS ---- !!!
      double precision function f(x)
      double precision x
!      f = x*x*x
!      f = exp(-1D0*x*x)
!      f = sin(x)
      f = sqrt(1d0-x*x)
      end function f
c
c
c
      logical function seeder(n)
      integer i, n, seed(n)
      open (unit=10, file='/dev/urandom', access='stream',
     $         form='unformatted', status='old')
      do i = 1, n
       read(10,err=1300) seed(i)
      end do
      close(10)
      call random_seed(put=seed)
      seeder = .false.
      goto 1400
1300  seeder = .true.
1400  continue
      return
      end function seeder
c
! subroutines
      subroutine monte(func, x1, x2, y1, y2, nPoints, area)
      integer nPoints
      double precision func, x1, x2, y1, y2, area
      integer cntr, nin, nout
      double precision x, y
      cntr = 0
      nin = 0
      nout = 0
      do i = 1, nPoints
       call random_number(x)
       call random_number(y)
       x = (x2-x1)*x+x1
       y = (y2-y1)*y+y1
       if ( 0..le.y .and. y.le.func(x) ) then
        cntr = cntr + 1
        nin = nin + 1
       else if ( func(x).le.y .and. y.lt.0. ) then
        cntr = cntr - 1
        nin = nin + 1
       else
        nout = nout + 1
       end if
      end do
      if ( (nin + nout).ne. nPoints ) then
       write(6,*) 'Problem with point count'
       area = -1.0D+217
      else
       area = (x2-x1)*(y2-y1)*dble(cntr)/dble(nPoints)
      end if
      return
      end subroutine monte
c
! print banner
      subroutine banner
      write(6,*) ''
      write(6,*) '########################################'
      write(6,*) '#        Monte Carlo integrator        #'
      write(6,*) '# usage: a xmin xmax ymin ymax nPoints #'
      write(6,*) '########################################'
      write(6,*) ''
      return
      end subroutine banner
c	  
c	  
c	  
! original code template stolen from Ian Hoffman
! help gotten from Arnaud