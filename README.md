# High Level Synthesis
---
This work is about HLS course, Duth ECCE 9 Semester and contains 4 projects on High Level Synthesis working with C++ and  Catapult.
---

## Project 1
---
  In exercise 1 and 2 we have to write simple  C++ code and in exercise 3 we work with a data flow graph.In addition,  src file contains testing.cpp which is a testbench file for ex1.cpp and ex2.cpp.

-  **Exercise 1**: Write  function, c++ code that computes the  sum of each row of a 2-D array.The sum of the elements of the i-th row appears in the position i of the row_sum table. <br/>
  
          template<int N,int M>
          void compute_row_sum(short a[N][M], short row_sum[N])
<br/>


- **Exercise 2**: We have to apply wave sort in 1-D array on two steps.
    - Step 1: Apply sorting algorithm.
  
    - Step 2: Run  through all the elements of the table and change the positions of the neighbouring elements every two. <br/>
     
           template<int N>
           void wave_sort(int a[N]) 
    <br/>

- **Exercise 3:** We have the following data flow graph.
  
  ![ad](photos/graph.png)
   
   - a. We consider that multiplication requires 2 units of time and addition requires one. Also assume that we have as much material as we need. Time the graph operations (either with an ASAP algorithm ) so that the clock period does not exceed two units of time and the calculation is completed in less than 9 clock cycles.
  
  - b. Then we consider that we have at our disposal only one adder and two multipliers and the same limitation on the frequency of the clock. Repeat the scheduling of the calculation graph (we can use any resource constrained scheduling algorithm - resource constrained scheduling). Finally, show which operators of the graph (using the numbers next to each node) are calculated from which numeric unit of the three available to us.
   

  

       
      

## Project 2
---

- In this project we have to use wavesort function we implemented on **Project 1** , but with bubble sort algorithm. In addition we have to write a main function for testing our code.
  
- For Catapult now we have to to make the following steps : <br/>
     
     - 1. In the hierarchy stage you will select as top the function that implements wavesort.
    
     - 2. In the libraries stage we ensure that we select libraries for RAM.
        
     - 3. In the mapping stage we set a 500MHz frequency clock.

     - 4. In the architecture stage, we have to set the input/output interface  to be a memory  with a read port and a write port 1R1W. We select "ccs_sample_mem.ccs_ram_sync_1R1W or  ram_nangate-45nm-separate_beh.RAM_separateRW".

     - 5. We make RTL and we verify the correctness of the circuit through co-simulation.
  
  


