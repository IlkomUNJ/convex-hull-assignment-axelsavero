[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/T_SwjO2j)
# Identity
Name : Muhammad Axel Savero Fikri

# AI usage
For this assignment, I utilized a generative AI to assist in understanding core concepts, translating pseudocode, and debugging the implementation. The AI model used was Gemini, built by Google.

My interaction with the AI was structured in several phases, reflecting the progression of the assignment. The queries (prompts) I used during each phase are listed below.

Stage 1: Understanding Core Concepts and Algorithms

After reading the reference material (de Berg et al., 2008), I used the AI to clarify some fundamental concepts.

    Query 1: "Can you explain the concept of a Convex Hull using a simple analogy? I've read the formal definition but would like a more intuitive understanding."

    Query 2: "Based on the SLOWCONVEXHULL pseudocode on page 3 of the PDF, what is the main idea behind the algorithm? Why is it considered slow with O(n³) complexity?" 

Query 3: "Compare the SLOWCONVEXHULL algorithm with the incremental CONVEXHULL algorithm on page 6 of the PDF. Why is the incremental approach of building an upper and lower hull faster?" 

    Query 4: "What does a 'right turn' mean in the context of the incremental Convex Hull algorithm in the PDF? How do I test for it mathematically using point coordinates?"

Stage 2: Implementation within the Qt Framework

Once I understood the theory, I began the implementation in Qt. I asked the AI for assistance with aspects specific to the Qt framework.

    Query 5: "I'm using Qt Creator. How do I add a custom drawing area (a canvas) to my mainwindow.ui? What widget should I use?"

    Query 6: "I'm confused about the 'Promote to...' step in Qt. What is its purpose, and how do I use it on my canvas widget to connect it to a new C++ class named CanvasWidget?"

    Query 7: "How do I draw points and lines on a custom QWidget in Qt? Which function do I need to override?"

    Query 8: "How do I connect a button click from the UI (.ui file) to a C++ function in mainwindow.cpp? For example, for a button named generatePointsButton."

Stage 3: Pseudocode Translation and Debugging

In this stage, I focused on translating the pseudocode from the PDF into C++/Qt and resolving compilation errors.

    Query 9: "Help me translate the CONVEXHULL pseudocode from page 6 of the PDF into C++ using Qt's QVector<QPoint> data type." 

    Query 10: "I'm getting a canvaswidget.h: No such file or directory error when compiling. I'm sure the file exists in my project. What's a likely cause for this in a Qt CMake project?"

    Query 11: "After adding canvaswidget.h and .cpp to CMakeLists.txt, I'm now getting an Unknown type name 'CanvasWidget' error. What am I still missing?"

    Query 12: "My orientationTest function sometimes gives wrong results due to integer overflow when multiplying large coordinates. How can I fix this?"

    Query 13: "How should I implement the iteration counter inside the loops of the slowConvexHull and fastConvexHull algorithms to meet the assignment's requirement?"

Stage 4: Finalization and Analysis

In the final stage, I used the AI to compare my implementation results with the theory.

    Query 14: "My initial implementation of fastConvexHull used Graham Scan, while the PDF uses an incremental algorithm. Are both considered valid fast algorithms? What are their fundamental differences?"

    Query 15: "Help me adapt my code to match the incremental algorithm in the PDF, specifically the part about constructing the upper and lower hulls separately."

# Collaboration usage
Explain how you are ***using others*** to complete the assignment in this section. Are they simply copying, learn the ideas, learn how to adapt the AI or anything involving the process. State the people if any & Please be elaborate. Declare self tought if you solved this by yourself. 

# Commit Rules
Use .gitignore to stripe any binaries from the resulting build before commit.  If you cloned directly from the template, you are safe. 

# Due Time
September 30th, 2025. 23: 59 WIB
