chmall: jucompiler.l jucompiler.y tree.c tree.h semantics.c semantics.h  symtab.c symtab.h lex.yy.c y.tab.c y.tab.h
	flex jucompiler.l
	yacc -d -v jucompiler.y        
	cc -o jucompiler y.tab.c lex.yy.c tree.c semantics.c symtab.c