# MSVC 2010 Node.js C++ Extension Template

## Purpose

The purpose of these project files is to allow quick bootstrap of a Node.js
C++ extension on the Windows platform using the MSVC++ 2010 IDE.

This project includes a `.sln` and `.vcxproj` file containing an empty Node.js
C++ extension.  The project is pre-configured to properly include the needed
needed directories and libraries in the MSVC C++/Linker settings.

The solution and project use the `NODE_SRC` Windows environment variable as
the location of the Node.js source code.  To use the template, the Node.js
source code must be extracted to a directory and built in Debug mode.  The
`NODE_SRC` environment variable must then be set to the directory path
prior to opening the solution in the IDE.

The solution contains the Node.js Debug build executable as the default project
and the output directory of the extension is set to `NODE_SRC\Debug`.  This is
done so that hitting `F5` to debug will automatically launch `node.exe` so that
the compiled extension is accessible by `require("./extension")`.

## Steps

1. Install MSVC++ 2010 (Express or Professional)
2. Install Python
3. Download latest Node.js source code (e.g. `node-v0.6.7.tar.gz`)
4. Extract source code to a directory (e.g. `C:\node-v0.6.7`)
5. Configure system `NODE_SRC` environment variable to source directory.
6. Open command prompt and build Node.js. (`vcbuild.bat`)
7. Open `node-extension.sln`.
8. Hit `F7` to build `NODE_SRC\Debug\extension.node`.
9. Hit `F5` to launch `NODE_SRC\Debug\node.exe`.
10. Load extension by typing `var ext = require("./extension")`.

## Extension

The extension provided is an empty class whose constructor is exposed as
`Extension`.  It is intended to be used in this manner:

    var ext = require("./extension");
    var obj = new ext.Extension();

The template code will print trace statements to standard out showing the
functions being executed as the module is loaded and the constructor is called.

## Release

This document and the project files are not copyrighted and are released
into the public domain.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

Node.js is a trademark of Joyent, Inc.
