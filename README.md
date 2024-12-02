<h1>pipex</h1>

<h2>Introduction</h2>
<p>Welcome to the <strong>pipex</strong> project, part of the curriculum at 42. This project focuses on understanding and implementing basic UNIX commands and concepts related to process creation and management, file descriptors, and inter-process communication.</p>

<h2>Objective</h2>
<p>The objective of the "pipex" project is to recreate the functionality of the pipe (`|`) command in the UNIX shell. The program takes four arguments: the name of an input file, two commands, and the name of an output file. It then executes the two commands in parallel, with the output of the first command being piped as input to the second command, and the final output being written to the specified output file.</p>

<h2>Requirements</h2>
<p>The pipex program must meet the following requirements:</p>
<ul>
    <li>Correctly handle error conditions and display appropriate error messages.</li>
    <li>Properly manage file descriptors and execute commands using the `execve` function.</li>
    <li>Use the `pipe` system call to create a unidirectional communication channel between the two commands.</li>
    <li>Implement proper process management, including forking child processes and waiting for their completion.</li>
</ul>

<h2>Key Concepts</h2>
<ul>
    <li><strong>File Descriptors</strong>: Integer identifiers used by the operating system to access files and other input/output resources.</li>
    <li><strong>Process Creation</strong>: The creation of new processes using functions like `fork` and `execve`.</li>
    <li><strong>Inter-Process Communication</strong>: Communication between processes through methods such as pipes and shared memory.</li>
    <li><strong>Error Handling</strong>: Techniques for detecting and handling errors in programs to ensure robustness.</li>
</ul>

<h2>Example</h2>
<p>Here's an example of how you might use the pipex program:</p>
<pre><code>$ ./pipex infile "ls -l" "wc -w" outfile</code></pre>

<h2>Conclusion</h2>
<p>The <strong>pipex</strong> project provides a hands-on opportunity to deepen your understanding of UNIX systems programming and process management. By completing this project, you will gain practical experience in working with file descriptors, processes, and inter-process communication, essential skills for any systems programmer or UNIX/Linux enthusiast.</p>
