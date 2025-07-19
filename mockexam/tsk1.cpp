// Task 1: 
// You are tasked in creating a framework for analyzing sorting and searching algorithms. 
// Algorithm Template Class 
// Create a templated class Algorithm<T> with the following properties: 
// • algorithmId (string): Unique identifier for the algorithm 
// • name (string): Name of the algorithm (e.g., "Quick Sort", "Binary Search") 
// • category (string): for e.g. Sorting, Searching 
// • timeComplexity (string): Big O notation for time complexity 
// • spaceComplexity (string): Big O notation for space complexity 
// • implementationFunction: Function that implements the algorithm 
// Include appropriate constructors, getters, and setters. 
// AlgorithmAnalyzer Class 
// Implement an AlgorithmAnalyzer class that: 
// • Stores a collection of Algorithm objects in a vector. 
// • Includes the following methods: 
// o registerAlgorithm: Adds a new algorithm to the system 
// o removeAlgorithm: Removes an algorithm by ID 
// o getAlgorithmsByCategory: Returns algorithms filtered by category using ranges 
// o benchmarkAlgorithm: Runs an algorithm with various input sizes and records performance 
// o compareAlgorithms: Compares multiple algorithms on the same input data 
// o getAlgorithmsByComplexity: Uses ranges to filter algorithms by time complexity 
// Benchmark Results Tracking 
// Implement a result logging system 
// • Define a BenchmarkResult struct with: 
// o algorithmId (string): Tells the ID of the Algo. 
// o inputSize (int): The amount of data tested with. 
// o executionTime (std::chrono::microseconds) 
// o success (bool): Whether the algorithm executed correctly 
// Range Operations 
// Implement the following range-based operations: 
// • Create a view of algorithms filtered by time complexity using ranges 
// • Calculate statistics (fastest algorithm for different input sizes) using ranges
// Main Program Requirements 
// Write a main function that: 
// • Registers different sorting algorithms (Bubble Sort, Insertion Sort, Quick Sort, Merge Sort). 
// • Registers different searching algorithms (Linear Search, Binary Search). 
// • Demonstrates all the AlgorithmAnalyzer functionality. 
// • Shows proper use of ranges. (using the | operator). 
// • Benchmarks algorithms with randomly generated datasets of various sizes. 
// • Compares performance across multiple algorithms. 
// • Uses function pointers or functors appropriately for algorithm implementation. 
// • Have to make algorithms by scratch. (Don’t use any pre-built libraries) 