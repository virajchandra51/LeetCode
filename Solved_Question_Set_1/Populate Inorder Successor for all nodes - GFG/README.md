# Populate Inorder Successor for all nodes
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a Binary Tree, write a function to populate next pointer for all nodes.&nbsp;The next pointer for every node should be set to point to inorder successor.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
</span>           <span style="font-size:18px">10
&nbsp;      /  \
&nbsp;     8    12
&nbsp;    /
&nbsp;   3
&nbsp; </span>

<span style="font-size:18px"><strong>Output: </strong>3-&gt;8 8-&gt;10 10-&gt;12 12-&gt;-1</span>
<span style="font-size:18px"><strong>Explanation: </strong>The inorder of the above tree is :</span>
<span style="font-size:18px">3 8 10 12. So the next pointer of node 3 is </span>
<span style="font-size:18px">pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is</span>
<span style="font-size:18px">pointing to -1 as there is no inorder successor 
of 12.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:</span></strong>
           <span style="font-size:18px">1
&nbsp;     /   \
&nbsp;    2     3</span>
<strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">2-&gt;1 1-&gt;3 3-&gt;-1 </span></pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">You do not need to read input or print anything. Your task is to complete the function<strong> </strong><strong>populateNext()&nbsp;</strong>that takes the root node of the binary tree as input parameter.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=n&lt;=10^5<br>
1&lt;=data of the node&lt;=10^5</span></p>
</div>