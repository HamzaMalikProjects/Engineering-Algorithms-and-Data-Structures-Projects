Readme File For COE428 Lab 5: XML-based Heap

Author: Hamza Malik
Student # 501112545
Submit Date: Thurs Aug 10, 2023
Lab Due Date: Thurs Aug 11, 2023


Q) Another legal XML tag not used in this lab is the "stand-alone" tag. This kind of tag combines both a start-tag and end-tag in one. It is identified with a '/' (slash) preceding the final >. (For example, the <foo/> is a stand-alone tag that is "self balancing".

Describe briefly how you would modify Requirement 1 to allow this kind of tag.


A) To accommodate self-closing tags in XML notation, the code needs an update to recognize them as distinct tags. This can be achieved by adding a condition for a closing angle bracket (>). If the character just before this bracket is a slash (/), it signifies a self-closing tag. In such instances, we can directly add the tag identifier to the stack without removing any prior opening tag identifier.

