// Sets the title in the metadata.
TITLE("Hello, World")

void main(){
	// puts is a standard function for showing text
	// title is an automatic pointer to the title as set by the TITLE macro
	puts((char*)title);
	// halts execution until there is an interrupt
	halt();
}
