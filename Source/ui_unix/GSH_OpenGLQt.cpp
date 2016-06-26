#include "GSH_OpenGLQt.h"
#include <QWindow>
#include <QOpenGLContext>

CGSH_OpenGLQt::CGSH_OpenGLQt(QWindow* renderWindow)
: m_renderWindow(renderWindow)
{

}

CGSH_OpenGLQt::~CGSH_OpenGLQt()
{

}

CGSH_OpenGL::FactoryFunction CGSH_OpenGLQt::GetFactoryFunction(QWindow* renderWindow)
{
	return [renderWindow] () { return new CGSH_OpenGLQt(renderWindow); };
}

void CGSH_OpenGLQt::InitializeImpl()
{
    m_context = new QOpenGLContext();
    m_context->setFormat(m_renderWindow->requestedFormat());

	bool succeeded = m_context->create();
	Q_ASSERT(succeeded);

    succeeded = m_context->makeCurrent(m_renderWindow);
    Q_ASSERT(succeeded);

    glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (err != GLEW_OK){
            fprintf(stderr, "glewInit() error: %s\n", glewGetErrorString(err));
            exit(1); // or handle the error in a nicer way
        }

        if (!GLEW_VERSION_2_1){  // check that the machine supports the 2.1 API.
            fprintf(stderr, "ver\n");
            exit(1); // or handle the error in a nicer way
    }

	CGSH_OpenGL::InitializeImpl();
}

void CGSH_OpenGLQt::ReleaseImpl()
{
	CGSH_OpenGL::ReleaseImpl();

	delete m_context;
}

void CGSH_OpenGLQt::PresentBackbuffer()
{
    m_context->swapBuffers(m_renderWindow);
}
