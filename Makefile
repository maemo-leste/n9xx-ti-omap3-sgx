armhf:
	ln -snf armhf-files files

armel:
	ln -snf armel-files files

install:
	mkdir -p debian/tmp
	cp -ra files debian/tmp/files
