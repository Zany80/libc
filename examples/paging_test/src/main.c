TITLE("Paging test")

void page1();

void main(){
	function a;
	setStack(PAGE2);
	a = PAGED_CALL(page1,3);
	// maps physical page 1 onto virtual page 3
	swapBanks(1,3);
	swapBanks(2,1);
	cls();
	a();
	halt();
}

void page1(){
	PAGE(1);
	puts(PAGED_POINTER("Hello!"));
}
