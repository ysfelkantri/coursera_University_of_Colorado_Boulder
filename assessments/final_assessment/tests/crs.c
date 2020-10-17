
#include <stdint.h>
#include "course1.h"
#include "platform.h"
#include "memory.h"
#include "stats.h"

int8_t test_memmove1() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memmove1() - NO OVERLAP\n");
  
  set = (uint8_t*)((int32_t *) malloc(sizeof(uint8_t)*32)) ;
  //set = (uint8_t*) reserve_words( MEM_SET_SIZE_W );

  if (! set ) 
  {
    return TEST_ERROR;
  }
  
  ptra = &set[0];
  ptrb = &set[16];
  
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 16] != i)
    {
      ret = TEST_ERROR;
    }
  }
  free( (uint32_t*) set );
  return ret;
}

int8_t test_memmove2() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memmove2() -OVERLAP END OF SRC BEGINNING OF DST\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[8];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 8] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memmove3() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memove3() - OVERLAP END OF DEST BEGINNING OF SRC\n");
  set = (uint8_t*)reserve_words( MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[8];
  ptrb = &set[0];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i] != (i + 8))
    {
      ret = TEST_ERROR;
    }
  }


  free_words( (uint32_t*)set );
  return ret;

}

int8_t test_memcopy() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memcopy()\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memcopy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i+16] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memset() 
{
  uint8_t i;
  uint8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memset()\n");
  set = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) 
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memset(ptra, MEM_SET_SIZE_B, 0xFF);
  print_array(set, MEM_SET_SIZE_B);
  my_memzero(ptrb, MEM_ZERO_LENGTH);
  print_array(set, MEM_SET_SIZE_B);
  
  /* Validate Set & Zero Functionality */
  for (i = 0; i < MEM_ZERO_LENGTH; i++)
  {
    if (set[i] != 0xFF)
    {
      ret = TEST_ERROR;
    }
    if (set[16 + i] != 0)
    {
      ret = TEST_ERROR;
    }
  }
  
  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_reverse()
{
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * copy;
  uint8_t set[MEM_SET_SIZE_B] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68, 0x54
                               };

  PRINTF("test_reverse()\n");
  copy = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! copy )
  {
    return TEST_ERROR;
  }
  
  my_memcopy(set, copy, MEM_SET_SIZE_B);

  print_array(set, MEM_SET_SIZE_B);
  my_reverse(set, MEM_SET_SIZE_B);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < MEM_SET_SIZE_B; i++)
  {
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1])
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)copy );
  return ret;
}

