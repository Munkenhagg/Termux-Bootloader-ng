#include <gen-tblng-version.h>

void tblng_get_version_struct(struct tblng_version *v) {
	v->major = TBLNG_VERSION_MAJOR;
	v->minor = TBLNG_VERSION_MINOR;
	v->patch = TBLNG_VERSION_PATCH;
	return;
}
