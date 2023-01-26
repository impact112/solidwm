void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewallex(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagallex(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

void
updatestatus(void)
{
	char fsignal[256];
	char cmdind[9] = "sigeval:";
	char statind[9] = "sigstat:";
	char str_sig[50];
	char param[16];
	int i, len_str_sig, n, paramn;
	size_t len_fsignal, len_cmdind = strlen(cmdind), len_statind = strlen(statind);
	Arg arg;

	if (gettextprop(root, XA_WM_NAME, fsignal, sizeof(fsignal))) {
		len_fsignal = strlen(fsignal);
		
		if (len_cmdind > len_fsignal ? 0 : strncmp(cmdind, fsignal, len_cmdind) == 0) {
			paramn = sscanf(fsignal+len_cmdind, "%s%n%s%n", str_sig, &len_str_sig, param, &n);

			if (paramn == 1) arg = (Arg) {0};
			else if (paramn > 2) return;
			else if (strncmp(param, "i", n - len_str_sig) == 0)
				sscanf(fsignal + len_cmdind + n, "%i", &(arg.i));
			else if (strncmp(param, "ui", n - len_str_sig) == 0)
				sscanf(fsignal + len_cmdind + n, "%u", &(arg.ui));
			else if (strncmp(param, "f", n - len_str_sig) == 0)
				sscanf(fsignal + len_cmdind + n, "%f", &(arg.f));
			else return;

			for (i = 0; i < LENGTH(signals); i++)
				if (strncmp(str_sig, signals[i].sig, len_str_sig) == 0 && signals[i].func)
					signals[i].func(&(arg));
			
		}else if (len_statind > len_fsignal ? 0 : strncmp(statind, fsignal, len_statind) == 0) {
			strcpy(statustext,fsignal+8);
			drawbars();
		}
	}
}

