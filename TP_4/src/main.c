/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

int main(void)
{
	setbuf(stdout,NULL);
	printf("hola");

	startTesting(1);  //   (OK)   ll_newLinkedList
	startTesting(2);  //   (OK)   ll_len
	startTesting(3);  //   (OK)   getNode - test_getNode
	startTesting(4);  //   (OK)   addNode - test_addNode
	startTesting(5);  //   (OK)   ll_add
	startTesting(6);  //   (OK)   ll_get
	startTesting(7);  //   (OK)   ll_set
	startTesting(8);  //   (OK)   ll_remove
	startTesting(9);  //   (OK)   ll_clear
	startTesting(10); //   (OK)   ll_deleteLinkedList
	startTesting(11); //   (OK)   ll_indexOf
	startTesting(12); //   (OK)   ll_isEmpty
	startTesting(13); //   (OK)   ll_push
	startTesting(14); //   (OK)   ll_pop
	startTesting(15); //   (OK)   ll_contains
	startTesting(16); //   (OK)   ll_containsAll
	startTesting(17); //   (OK)   ll_subList
	startTesting(18); //   (OK)   ll_clone
	startTesting(19);//   (OK)   ll_sort

    return 0;
}


