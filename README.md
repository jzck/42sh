# 42sh

42sh school project.

By alao, ariard, gwojda, jhalford, wescande.  
Final grade : 125/100

More than 10 000 lines of pure C, even the library was written by ourselves. No memory leaks, no crash were allowed. The most impressive project of the first cycle of 42 school cursus.

Mandatory part:
- Prompt without line edition.
- Builtins `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv` with there options.
- Executing simple commands with there parameters using `PATH`.
- Support for redirection `>`, `>>`, `<`and `|`.
- Logical operand `&&`and `||`.
- Separator `;`.

Optional feature (five of theses are mandatory to validate the project):
- Inhibitors `"`, `'`and `\`.
- Advanced redirections: aggregation of file output and heredoc `<<`.
- Globbing: `*`, `?`, `[]`, `{}`, etc.
- Backquotes \`.
- Subshell with operand `()`.
- Local variable and builtin `unset` and `export`.
- History with builtin `history`and `!` with options.
- Advanced line edition.
- File descriptors and builtin `read` with options.
- Dynamical autocompletion.

Optional feature highly appreciated:
- Job Control and builtins `job`, `fg`, `bg` and operand `&`.
- Shell Scripting in POSIX standards: for, while, until, if/elif/else, {}, bang (!), case, functions, variable assignements

## Shell / Subshell

## Line editing

Keys|Functions|
:-:|:--
<kbd>Opt</kbd>+<kbd>C</kbd><br><kbd>Opt</kbd>+<kbd>X</kbd><br><kbd>Opt</kbd>+<kbd>V</kbd>|Copy<br>Cut<br>Paste
<kbd>Opt</kbd>+<kbd><</kbd><br><kbd>Opt</kbd>+<kbd>></kbd>|Move per words.
<kbd>Opt</kbd>+<kbd>^</kbd><br><kbd>Opt</kbd>+<kbd>v</kbd>|Move per line.
<kbd>Ctrl</kbd>+<kbd>L</kbd>|Clear screen.
<kbd>Ctrl</kbd>+<kbd>C</kbd>|Terminate/Kill current foreground process.
<kbd>Ctrl</kbd>+<kbd>Z</kbd>|Suspend/Stop current foreground process.

## History

Keys|Functions|
:-:|:--
<kbd>^</kbd><br><kbd>v</kbd>|Browse the history.
<kbd>Ctrl</kbd>+<kbd>R</kbd>|Research function.
`!!`|Retype the last command.
`!n`|Retype the `n`(numerical value) command from the begin of history.
`!-n`|Retype the `-n`(numerical value) command from the last command.
`!name`|Search for a command beginning with `name`.
`!?name`|Search for a command which contain `name`.

## Autocompletion

Autocompletion works with binary, path and env variable.
Output is colored upon type.
Using arrows to navigate is supported.
Autorefreshing with a new input from the user: modification of the list of possibility.

Commands|Functions|
:-:|:--
`$> l[tab]`|Search for binary.
`$> ls s[tab]`|Search for path/files.
`$> $[tab]`|Search for variables in `env`.

## Globbing

Pattern|Behavior|
:-:|:--
`*`|Everything.
`**`|Match directory and sub-directory.
`?`|Single char.
`[a-z]`|Match range from `a` to `z`.
`[!a-z]` `[^a-z]`|Exclude range from `a` to `z`.
`{ab, ac}`|Match `ab` or `ac`.

## Hash table

Commands|Functions|
:-:|:--
`hash`|List the content of the hash table.
`hash -r`|Clear the memory of the hash table.

## Job Control

Commands|Functions|
:-:|:--
`jobs`|List all the current running jobs.
`fg`|Bring the most recent process to foreground.
`fg n`|Bring the specified jobs to foreground where `n` is the numerical value of the process found in `jobs`.

## scripting
`while compound-list ; do compound-list ; done`  
`until compound-list ; do compound-list ; done`  
`if compound-list ; then compound-list ; elif compound-list ; then compound-list ; else compound-list`  
`for i in list ; do compound-list ; done`  
`case pattern1 in ( pattern2 ) compound-list ;; ( pattern1) compound-list ;; esac`   
`{ compound-list }`  
`! command`  
`func() { compound-list }`  
`VAR="hello world"`  
