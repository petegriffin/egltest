#include <epoxy/gl.h>
#include <epoxy/glx.h>
#include <epoxy/egl.h>
//#include <epoxy/wgl.h>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include <EGL/egl.h>
//#include <GLES/gl.h>

//typedef ... NativeWindowType;

//extern NativeWindowType createNativeWindow(void);
static EGLint const attribute_list[] = {
        EGL_RED_SIZE, 1,
        EGL_GREEN_SIZE, 1,
        EGL_BLUE_SIZE, 1,
        EGL_NONE
};
int main(int argc, char ** argv)
{
        EGLDisplay display;
        EGLConfig config;
        EGLContext context;
        EGLSurface surface;
//        NativeWindowType native_window;
        EGLint num_config;
	EGLBoolean result;
	
	printf("Hello libepoxy world\n");
        /* get an EGL display connection */
        display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

        /* initialize the EGL display connection */
        result = eglInitialize(display, NULL, NULL);

	switch(result) {
	case EGL_FALSE:
		printf("EGL_FALSE is returned if eglInitialize\n");
	case EGL_BAD_DISPLAY:
		printf("EGL_BAD_DISPLAY is generated if display is not an EGL display connection.\n");
	case EGL_NOT_INITIALIZED:
		printf("EGL_NOT_INITIALIZED is generated if display cannot be initialized.");
	case EGL_TRUE:
		printf("EGL_TRUE: everything all good\n");
	}

        /* get an appropriate EGL frame buffer configuration */
        eglChooseConfig(display, attribute_list, &config, 1, &num_config);

        /* create an EGL rendering context */
        context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
#if 0
        /* create a native window */
        native_window = createNativeWindow();

        /* create an EGL window surface */
        surface = eglCreateWindowSurface(display, config, native_window, NULL);

        /* connect the context to the surface */
        eglMakeCurrent(display, surface, surface, context);

        /* clear the color buffer */
        glClearColor(1.0, 1.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();

        eglSwapBuffers(display, surface);

        sleep(10);
#endif
        return EXIT_SUCCESS;
}
