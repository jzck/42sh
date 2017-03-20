# **42zsh**
---

42sh school project.

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
- Job Control and builtins `job`, `fg`, `bg`and operand `&`.
- Shell Scripting.

<p align="center"><strong>Shell / Subshell</strong></p>

<p align="center"><strong>Line Edition</strong></p>

Keys|Functions|
:-:|:--
<kbd>Opt</kbd>+<kbd>C</kbd><br><kbd>Opt</kbd>+<kbd>X</kbd><br><kbd>Opt</kbd>+<kbd>V</kbd>|Copy<br>Cut<br>Paste
<kbd>Opt</kbd>+<kbd><</kbd><br><kbd>Opt</kbd>+<kbd>></kbd>|Move per words.
<kbd>Opt</kbd>+<kbd>^</kbd><br><kbd>Opt</kbd>+<kbd>v</kbd>|Move per line.
<kbd>Ctrl</kbd>+<kbd>L</kbd>|Clear screen.
<kbd>Ctrl</kbd>+<kbd>C</kbd>|Terminate/Kill current foreground process.
<kbd>Ctrl</kbd>+<kbd>Z</kbd>|Suspend/Stop current foreground process.

<p align="center"><strong>History</strong></p>

Keys|Functions|
:-:|:--
<kbd>^</kbd><br><kbd>v</kbd>|Browse the history.
<kbd>Ctrl</kbd>+<kbd>R</kbd>|Research function.
`!!`|Retype the last command.
`!n`|Retype the `n`(numerical value) command from the begin of history.
`!-n`|Retype the `-n`(numerical value) command from the last command.
`!name`|Search for a command beginning with `name`.
`!?name`|Search for a command which contain `name`.

<p align="center"><strong>Autocompletion</strong></p>

<p align="center"><strong>Globbing</strong></p>

<p align="center"><strong>Hash Table</strong></p>

<p align="center"><strong>Builtin Read</strong></p>

<p align="center"><strong>Job Control</strong></p>

<p align="center"><strong>Scripting</strong></p>
