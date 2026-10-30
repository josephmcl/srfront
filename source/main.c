#include <stdlib.h>
#include <string.h>

#include <clang-c/Index.h>

#include "io.h"

int main(int argc, char **argv) {
    const char *path = NULL, *function = NULL, *out_path = NULL;
    const char *clang_args[16];
    int         nargs = 0, i, rv;
    char        include[1024];
    CXCursor    fn;

    snprintf(include, sizeof(include), "-I%s", getenv("SR_INCLUDE") 
                                               ? getenv("SR_INCLUDE") 
                                               : "sr");
    
    clang_args[nargs++] = include;
    clang_args[nargs++] = "-std=c11";
    
    for (i = 1; i < argc; i++) {
        
        if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {

            function = argv[++i];
        }
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            
            out_path = argv[++i];
        }
        else if (strncmp(argv[i], "-I", 2) == 0 && nargs < 15) {
            
            clang_args[nargs++] = argv[i];
        }
        else {
            
            path = argv[i];
        
        }
    }
    
    if (!path) {
        error_c("Error");
        return 1;
    }

    return rv;
}
