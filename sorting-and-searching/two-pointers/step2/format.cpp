// // Common technique to solve these two pointer problems

// // make 3 functions -> add(x), remove(x), good(segment)

// //and follow the following invariant

// // l = 0
// // loop(r, 0, n) {
//     add (x);
//     while (!good) {
//         remove(x)
//         //move left pointer i.e l++
//     }
//     <calculate whatever the result you are needed to calc>
// }