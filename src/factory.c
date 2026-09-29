/*
 * Standalone MLT module exposing the "shutterblur" filter (transform with
 * motion blur, 180 degree shutter by default).
 * Filter implementation: RocketJannis, mltframework/mlt PR #1301.
 * License: LGPL-2.1-or-later, same as MLT.
 */
#include <framework/mlt.h>
#include <limits.h>
#include <stdio.h>

extern mlt_filter filter_transformblur_init(mlt_profile profile,
                                            mlt_service_type type,
                                            const char *id,
                                            char *arg);
extern mlt_transition transition_slideblur_init(mlt_profile profile,
                                                 mlt_service_type type,
                                                 const char *id,
                                                 char *arg);

static mlt_properties metadata(mlt_service_type type, const char *id, void *data)
{
    char file[PATH_MAX];
    snprintf(file, PATH_MAX, "%s/shutterblur/%s", mlt_environment("MLT_DATA"), (char *) data);
    return mlt_properties_parse_yaml(file);
}

MLT_REPOSITORY
{
    MLT_REGISTER(mlt_service_filter_type, "shutterblur", filter_transformblur_init);
    MLT_REGISTER_METADATA(mlt_service_filter_type, "shutterblur", metadata, "filter_transformblur.yml");
    MLT_REGISTER(mlt_service_transition_type, "slideblur", transition_slideblur_init);
    MLT_REGISTER_METADATA(mlt_service_transition_type, "slideblur", metadata, "transition_slideblur.yml");
}
