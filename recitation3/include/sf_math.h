int add(int, int);

// Fix circular imports by wrapping it in ifndef like this

// This is called a header guard
// It checks if some unique label is already defined
// If not, then add the function declarations and define the label (subsequent #include will see that the label exists and will do nothing)

// #ifndef SF_MATH  
// #define SF_MATH  

// int add(int, int);  

// #endif 