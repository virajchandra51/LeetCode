# Minimum edges
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a <strong>directed</strong> graph with <strong>N</strong> nodes and <strong>M</strong> edges.&nbsp;A&nbsp;<strong>source</strong> node and a&nbsp;<strong>destination</strong> node are also given, we need to find how many edges we need to reverse in order to make at least 1 path from the source node to the destination node.<br>
<strong>Note:&nbsp;</strong>In case there is no way then return <strong>-1</strong>.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=3
M=2
edges[][]={{1,2},{3,2}}
src=1
dst=3
<strong>Output:</strong>
1
<strong>Explanation:</strong>
Reverse the edge 3-&gt;2.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=4
M=3
edges[][]={{1,2},{2,3},{3,4}}
src=1
dst=4
<strong>Output:</strong>
0
<strong>Explanation;</strong>
One path already exists between 1 to 4 it is 1-&gt;2-&gt;3-&gt;4.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>minimumEdgeReversal()</strong>&nbsp;which takes the edge list <strong>edges</strong>, <strong>N</strong> the number of nodes of the graph. <strong>src</strong> (source), and <strong>dst</strong> (destination) vertex<strong>&nbsp;</strong>as input parameters&nbsp;and returns the minimum number of edges to be reversed</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(M*log(M))<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N+M)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N ,M&lt;= 10<sup>5</sup><br>
1&lt;=edges[i][0],edges[i][1]&lt;=N</span></p>
</div>