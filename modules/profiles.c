void
setuphook(void) {
	if(!useprofiles) return;
	sprintf(profilepath,"%s/%s",profiledir,profilename);
	sprintf(profilesetupcmd,"mkdir -p /%s",profilepath);
	sprintf(profilecmd,"%s/setup",profilepath);
	system(profilesetupcmd);
	system(profilecmd);
}

void
startuphook(void) {
	if(!useprofiles) return;
	sprintf(profilecmd,"%s/startup",profilepath);
	system(profilecmd);
}

void
exithook(void) {
	if(!useprofiles) return;
	sprintf(profilecmd,"%s/exit",profilepath);
	system(profilecmd);
}

void 
externalhook(const Arg *arg) {
	if(!useprofiles) return;
	if (fork() == 0) {
		const char *hookname = arg->v;
		if (dpy)
			close(ConnectionNumber(dpy));
		sprintf(profilecmd,"%s/%s",profilepath,hookname);
		system(profilecmd);
		exit(EXIT_SUCCESS);
	}
}
