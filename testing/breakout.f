      program point
!
      integer*4 j
      pointer (q, i)
!
      j = 10
      q = loc(j)
      write(6,*) i
      write(6,'(A4,Z12)') '  0x',q
!
      stop
      end program point