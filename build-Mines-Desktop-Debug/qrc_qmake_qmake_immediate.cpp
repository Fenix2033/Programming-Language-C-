/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.2.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/xkudla/Documents/Mendel/PCP/Project/save.xml
  0x0,0x0,0x0,0xc6,
  0x0,
  0x0,0x4,0xb3,0x78,0x9c,0x85,0x94,0xcd,0xa,0x83,0x30,0x10,0x84,0xef,0x3e,0x45,
  0xd8,0x7b,0x6b,0x36,0xf1,0x27,0x42,0x8c,0xf,0x53,0x63,0x9,0x68,0xa,0xb5,0x2d,
  0x3e,0x7e,0xa5,0xf4,0xd0,0x82,0xec,0xe4,0x98,0x8f,0x59,0x76,0x86,0x4c,0xfc,0xb0,
  0x2d,0xb3,0x7a,0xc5,0xfb,0x9a,0x6e,0xb9,0x27,0x3e,0x6b,0x52,0x31,0x5f,0x6e,0x63,
  0xca,0xd7,0x9e,0x9e,0x8f,0xe9,0xe4,0x68,0x8,0x85,0x5f,0x52,0x8e,0x6b,0x28,0xd4,
  0x7e,0xfc,0x94,0xe2,0x3c,0xaa,0x94,0xc7,0xb8,0xf5,0xa4,0x29,0x68,0x5f,0x7e,0xae,
  0x8e,0x30,0xcb,0xd8,0xc8,0xd8,0xca,0xb8,0x92,0x71,0xfd,0x8b,0xf,0x78,0x43,0x81,
  0x5,0x79,0x2b,0x63,0x47,0xc1,0x8,0xb8,0x93,0xd5,0xac,0x1,0x67,0xb0,0x3c,0x1b,
  0x30,0x60,0xcf,0xae,0x93,0x78,0x25,0xef,0xcf,0x35,0xd0,0x83,0xf4,0xb8,0x45,0x6,
  0x1c,0x18,0x0,0x12,0x34,0x5a,0x36,0x60,0x18,0xe8,0x41,0x80,0xc6,0x2,0x3,0x6,
  0x3c,0x3f,0x53,0x3,0xde,0x0,0xde,0x2,0xee,0x0,0xef,0x80,0x1,0xb,0xba,0x6b,
  0x41,0x79,0x2d,0x6a,0x2f,0xa8,0xaf,0x5,0x1,0xda,0xbf,0x0,0x7d,0xf9,0xfd,0x83,
  0xde,0xd0,0x33,0x54,0x96,
  
};

static const unsigned char qt_resource_name[] = {
  // save.xml
  0x0,0x8,
  0x8,0xc8,0x50,0x1c,
  0x0,0x73,
  0x0,0x61,0x0,0x76,0x0,0x65,0x0,0x2e,0x0,0x78,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/save.xml
  0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x7d,0x32,0xc9,0xf0,0xf8,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#if defined(__ELF__) || defined(__APPLE__)
static inline unsigned char qResourceFeatureZlib()
{
    extern const unsigned char qt_resourceFeatureZlib;
    return qt_resourceFeatureZlib;
}
#else
unsigned char qResourceFeatureZlib();
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)()
{
    int version = 3;
    version += QT_RCC_PREPEND_NAMESPACE(qResourceFeatureZlib());
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)(); }
   } dummy;
}
