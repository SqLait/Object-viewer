#define SOKOL_IMPL
#define SOKOL_GLCORE
#define SOKOL_NO_ENTRY
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"

#include <stdio.h>

static struct {
    sg_pass_action pass_action;
} state;

void init(void) {
    sg_setup(&(sg_desc) {
        .environment = sglue_environment()
    });

    state.pass_action = (sg_pass_action) {
        .colors[0] = {.load_action = SG_LOADACTION_CLEAR, .clear_value = {0.4, 0.6, 1.0, 1.0}}
    };
}

void frame(void) {
    sg_begin_pass(&(sg_pass) {
        .action = state.pass_action,
        .swapchain = sglue_swapchain(),
    });
    sg_end_pass();
    sg_commit();
}

void deinit(void) {
    sg_shutdown();
}

void event(const sapp_event* ev) {

}

int main(int argc, char *argv[]) {
    sapp_run(&(sapp_desc) {
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = deinit,
        .event_cb = event
    });

    return 0;
}
